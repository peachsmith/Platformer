#include "Entity.h"
#include "Player.h"
#include "Terrain.h"
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
	//=================================
	// BASIC LOGIC
	//=================================
	const int FPS = 60;
	bool done = false;
	bool redraw = true;
	bool keys[8] =
	{ false, false, false, false, false, false, false, false };

	//=================================
	// ALLEGRO VARIABLES
	//=================================
	ALLEGRO_DISPLAY* display = 0;
	ALLEGRO_EVENT_QUEUE* event_queue = 0;
	ALLEGRO_TIMER* timer = 0;
	ALLEGRO_FONT* font = 0;

	//=================================
	// ALLEGRO INITIALIZATION
	//=================================
	if (!al_init())
		return -1;

	al_install_keyboard();
	al_init_primitives_addon();
	al_init_image_addon();
	al_init_font_addon();
	al_init_ttf_addon();

	//al_set_new_display_flags(ALLEGRO_FRAMELESS);
	display = al_create_display(500, 400);
	event_queue = al_create_event_queue();
	timer = al_create_timer(1.0 / FPS);
	font = al_load_font("courbd.ttf", 18, 0);

	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_display_event_source(display));

	al_start_timer(timer);

	srand(time(NULL));

	//=================================
	// ENTITIES
	//=================================
	std::list<peach::Entity*> entities;
	std::list<peach::Entity*>::iterator itr;
	std::list<peach::Entity*>::iterator itr2;

	//=================================
	// ENTITIES
	//=================================
	// x, y, x_vel, y_vel, x_dir, y_dir, x_bound, y_bound
	peach::Player player(true, true, 225, 240, 0, 0, 1, 1, 20, 20);
	peach::Terrain brick_1(true, true, 145, 280, 0, 0, 0, 0, 200, 20); // lower middle
	peach::Terrain brick_2(true, true, 365, 320, 0, 0, 0, 0, 70, 20); // left
	peach::Terrain brick_3(true, true, 380, 210, 0, 0, 0, 0, 200, 20); // right
	peach::Terrain brick_4(true, true, 145, 130, 0, 0, 0, 0, 200, 20); // upper middle
	peach::Terrain brick_5(true, true, 430, 150, 0, 0, 0, 0, 100, 20); // very upper right
	peach::Terrain brick_6(true, true, 450, 80, 0, 0, 0, 0, 100, 20); // very upper upper right
	peach::Terrain floor(true, true, 10, 390, 0, 0, 0, 0, 680, 10);
	peach::Terrain left_wall(true, true, 0, 0, 0, 0, 0, 0, 10, 400);
	peach::Terrain right_wall(true, true, 690, 0, 0, 0, 0, 0, 10, 400);

	// add the entities to the list
	entities.push_back(&brick_1);
	entities.push_back(&brick_2);
	entities.push_back(&brick_3);
	entities.push_back(&brick_4);
	entities.push_back(&brick_5);
	entities.push_back(&brick_6);
	entities.push_back(&floor);
	entities.push_back(&left_wall);
	entities.push_back(&right_wall);
	entities.push_back(&player); // for rendering, player should be last

	float x_depth = 0;
	float y_depth = 0;

	//=================================
	// MAIN GAME LOOP
	//=================================
	while (!done)
	{
		ALLEGRO_EVENT al_event;
		al_wait_for_event(event_queue, &al_event);

		if (al_event.type == ALLEGRO_EVENT_TIMER)
		{
			redraw = true;

			// move the player
			if (keys[peach::LEFT] && !keys[peach::RIGHT])
			{
				player.Move(2); // move player left
			}
			else if (keys[peach::RIGHT] && !keys[peach::LEFT])
			{
				player.Move(3); // move player right
			}
			else if ((!keys[peach::RIGHT] && !keys[peach::LEFT]) || (keys[peach::RIGHT] && keys[peach::LEFT]))
				player.SlowDown(); // slow to s stop

			// temporary position reset
			if (keys[peach::Z])
			{
				player.SetX(150);
				player.SetY(250);
			}

			if (keys[peach::A])
			{
				player.SetX(150);
				player.SetY(100);
			}

			// handle player jumping
			if (keys[peach::SPACE] && !player.GetJumping())
				player.Jump();

			// update
			for (itr = entities.begin(); itr != entities.end(); ++itr)
			{
				// set jumping to true in case the entity is in the air
				(*itr)->SetJumping(true);
				(*itr)->UpdateX();

				for (itr2 = entities.begin(); itr2 != entities.end(); ++itr2)
				{
					if ((*itr)->GetID() == (*itr2)->GetID())
					{
						continue; // for now, two Entities with the same ID cannot collide
					}

					if ((*itr)->CheckCollision((*itr2), x_depth, y_depth) >= 15)
					{
						(*itr)->SetX((*itr)->GetX() - x_depth);

						if (player.GetX() < 140)
						{
							float x_overshoot = 140 - player.GetX();
							for (std::list<peach::Entity*>::iterator scr_itr = entities.begin(); scr_itr != entities.end(); ++scr_itr)
							{
								(*scr_itr)->SetX((*scr_itr)->GetX() + x_overshoot);
							}
						}
						else if (player.GetX() >= 320)
						{
							float x_overshoot = player.GetX() - 320;
							for (std::list<peach::Entity*>::iterator scr_itr = entities.begin(); scr_itr != entities.end(); ++scr_itr)
							{
								(*scr_itr)->SetX((*scr_itr)->GetX() - x_overshoot);
							}
						}

						(*itr)->Collide((*itr2)->GetID());
						if (x_depth)
							(*itr)->SetXVel(0);
					}
				}
				(*itr)->UpdateY();
				for (itr2 = entities.begin(); itr2 != entities.end(); ++itr2)
				{
					if ((*itr)->GetID() == (*itr2)->GetID())
					{
						continue; // for now, two Entities with the same ID cannot collide
					}

					if ((*itr)->CheckCollision((*itr2), x_depth, y_depth) >= 15)
					{
						// resolve vertical collision
						(*itr)->SetY((*itr)->GetY() - y_depth);

						if (player.GetY() < 190)
						{
							float y_overshoot = 190 - player.GetY();
							for (std::list<peach::Entity*>::iterator scr_itr = entities.begin(); scr_itr != entities.end(); ++scr_itr)
							{
								(*scr_itr)->SetY((*scr_itr)->GetY() + y_overshoot);
							}
						}
						else if (player.GetY() >= 260)
						{
							float y_overshoot = player.GetY() - 260;
							for (std::list<peach::Entity*>::iterator scr_itr = entities.begin(); scr_itr != entities.end(); ++scr_itr)
							{
								(*scr_itr)->SetY((*scr_itr)->GetY() - y_overshoot);
							}
						}

						(*itr)->Collide((*itr2)->GetID());
						if (y_depth)
							(*itr)->SetYVel(0);
						// if the bottom of the entity collides with something, set jumping to false
						if (y_depth > 0)
						{
							(*itr)->SetJumping(false);
						}
					}
				}
			}

			if (player.GetX() < 140)
				player.SetX(140);
			else if (player.GetX() > 320)
				player.SetX(320);

			if (player.GetY() > 260)
				player.SetY(260);
			else if (player.GetY() < 190)
				player.SetY(190);

			// scrolling
			if ((player.GetX() == 320 || player.GetX() == 140) && player.GetXVel())
			{
				bool scroll_collision = false;
				for (itr = entities.begin(); itr != entities.end(); ++itr)
				{
					if ((*itr)->GetID() != peach::PLAYER)
					{
						(*itr)->SetX((*itr)->GetX() - player.GetXVel());
						if ((*itr)->CheckCollision((&player), x_depth, y_depth) >= 15)
						{
							scroll_collision = true;
							break;
						}
					}
				}
				// resolve collisions due to scrolling
				if (scroll_collision)
				{
					for (; itr != entities.begin(); --itr)
					{
						if ((*itr)->GetID() != peach::PLAYER)
						{
							(*itr)->SetX((*itr)->GetX() + player.GetXVel());
						}
					}
					(*itr)->SetX((*itr)->GetX() + player.GetXVel());
					player.SetXVel(0);
				}
			}
			if ((player.GetY() == 260 || player.GetY() == 190) && player.GetYVel())
			{
				bool scroll_collision = false;
				for (itr = entities.begin(); itr != entities.end(); ++itr)
				{
					if ((*itr)->GetID() != peach::PLAYER)
					{
						(*itr)->SetY((*itr)->GetY() - player.GetYVel());
						if ((*itr)->CheckCollision((&player), x_depth, y_depth) >= 15)
						{
							scroll_collision = true;
							break;
						}
					}
				}
				// resolve collisions due to scrolling
				if (scroll_collision)
				{
					for (; itr != entities.begin(); --itr)
					{
						if ((*itr)->GetID() != peach::PLAYER)
						{
							(*itr)->SetY((*itr)->GetY() + player.GetYVel());
						}
					}
					(*itr)->SetY((*itr)->GetY() + player.GetYVel());
					player.SetYVel(0);
				}
			}
		}

		else if (al_event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		{
			done = true;
		}
		//=================================
		// CAPTURE KEYBOARD INPUT
		//=================================
		else if (al_event.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			switch (al_event.keyboard.keycode)
			{
			case ALLEGRO_KEY_UP:
				keys[peach::UP] = true;
				break;
			case ALLEGRO_KEY_DOWN:
				keys[peach::DOWN] = true;
				break;
			case ALLEGRO_KEY_LEFT:
				keys[peach::LEFT] = true;
				break;
			case ALLEGRO_KEY_RIGHT:
				keys[peach::RIGHT] = true;
				break;
			case ALLEGRO_KEY_A:
				keys[peach::A] = true;
				break;
			case ALLEGRO_KEY_Z:
				keys[peach::Z] = true;
				break;
			case ALLEGRO_KEY_X:
			{
				keys[peach::X] = true;
				// launch projectile
				break;
			}
			case ALLEGRO_KEY_SPACE:
				keys[peach::SPACE] = true;
				break;
			default:
				break;
			}
		}
		else if (al_event.type == ALLEGRO_EVENT_KEY_UP)
		{
			switch (al_event.keyboard.keycode)
			{
			case ALLEGRO_KEY_ESCAPE:
				done = true;
				break;
			case ALLEGRO_KEY_UP:
				keys[peach::UP] = false;
				break;
			case ALLEGRO_KEY_DOWN:
				keys[peach::DOWN] = false;
				break;
			case ALLEGRO_KEY_LEFT:
				keys[peach::LEFT] = false;
				break;
			case ALLEGRO_KEY_RIGHT:
				keys[peach::RIGHT] = false;
				break;
			case ALLEGRO_KEY_A:
				keys[peach::A] = false;
				break;
			case ALLEGRO_KEY_Z:
				keys[peach::Z] = false;
				break;
			case ALLEGRO_KEY_X:
				keys[peach::X] = false;
				break;
			case ALLEGRO_KEY_SPACE:
				keys[peach::SPACE] = false;
				break;
			default:
				break;
			}
		}

		//=================================
		// RENDER
		//=================================
		if (redraw && al_is_event_queue_empty(event_queue))
		{
			redraw = false;

			for (itr = entities.begin(); itr != entities.end(); ++itr)
			{
				(*itr)->Render();
			}

			// player position and velocity
			al_draw_textf(font, al_map_rgb(250, 250, 250), 15, 5, 0, "x: %.2f", player.GetX());
			al_draw_textf(font, al_map_rgb(250, 250, 250), 15, 25, 0, "y: %.2f", player.GetY());
			al_draw_textf(font, al_map_rgb(250, 250, 250), 15, 45, 0, "x_vel: %.2f", player.GetXVel());
			al_draw_textf(font, al_map_rgb(250, 250, 250), 15, 65, 0, "y_vel: %.2f", player.GetYVel());

			// controls
//			al_draw_textf(font, al_map_rgb(250, 250, 250), 100, 5, 0,
//					"move with arrow keys");
//			al_draw_textf(font, al_map_rgb(250, 250, 250), 100, 25, 0,
//					"jump with space bar");

			al_flip_display();
			al_clear_to_color(al_map_rgb(0, 0, 0));
		}

	}

	if (keys[peach::X])
	{
		// just to get rid of the warning
	}

	al_destroy_display(display);
	al_destroy_event_queue(event_queue);
	al_destroy_timer(timer);
	al_destroy_font(font);

	return 0;
}