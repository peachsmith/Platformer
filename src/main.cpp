#include "Entity.h"
#include "Player.h"
#include "Terrain.h"
#include "Scenery.h"
#include "Level1.h"
#include "Menu.h"
#include "pxp.h"

using namespace std;

int main(int argc, char** argv)
{
	//=================================
	// BASIC GAME PROPERTIES
	//=================================
	const int FPS = 60;
	bool done = false;
	bool redraw = true;
	bool keys[9] =
	{ false, false, false, false, false, false, false, false, false };
	int screen_width = 700;
	int screen_height = 600;
	int info = 0;
	int state = peach::START;
	int pause = 0;

	//=================================
	// ALLEGRO VARIABLES
	//=================================
	ALLEGRO_DISPLAY* display = 0;
	ALLEGRO_EVENT_QUEUE* event_queue = 0;
	ALLEGRO_TIMER* timer = 0;
	ALLEGRO_FONT* font = 0;
	ALLEGRO_BITMAP* player_sheet = 0;
	ALLEGRO_BITMAP* scenery_sheet = 0;

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
	display = al_create_display(screen_width, screen_height);
	event_queue = al_create_event_queue();
	timer = al_create_timer(1.0 / FPS);
	font = al_load_font("res/courbd.ttf", 18, 0);
	player_sheet = al_load_bitmap("res/player.bmp");
	scenery_sheet = al_load_bitmap("res/scenery.bmp");
	al_convert_mask_to_alpha(player_sheet, al_map_rgb(255, 0, 255));
	al_convert_mask_to_alpha(player_sheet, al_map_rgb(120, 0, 120));
	al_convert_mask_to_alpha(scenery_sheet, al_map_rgb(255, 0, 255));
	al_convert_mask_to_alpha(scenery_sheet, al_map_rgb(120, 0, 120));

	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_display_event_source(display));

	al_start_timer(timer);

	srand(time(NULL));

	//=================================
	// DRAWABLES
	//=================================
	//std::vector<peach::Entity*> drawables;

	//=================================
	// ENTITIES
	//=================================
	// x, y, x_vel, y_vel, x_dir, y_dir, x_bound, y_bound
	peach::Player player(true, true, 300, 240, 0, 0, 1, 1, 16, 32, (void*) player_sheet);

	//=================================
	// PLAYER STUFF
	//=================================
	player.SetFrameDelay(6);
	player.SetMaxFrame(4);

	//=================================
	// LEVELS
	//=================================
	peach::Level1 level_1((void*) player_sheet, (void*) scenery_sheet, &player, &state);

	//=================================
	// CONFIGURATION
	//=================================
	ifstream config("res/configuration.xml");
	int background[3] =
	{ 0, 139, 174 };
	if (config.is_open())
	{
		stringstream parse_stream;
		stringstream config_stream;
		config_stream << config.rdbuf();
		string source = config_stream.str();

		int config_error = peach::validate(source, parse_stream);

		if (!config_error)
		{
			peach::elem_t* root = peach::parse(parse_stream.str());
			if (root)
			{
				vector<peach::elem_t*> bg, bg_r, bg_g, bg_b;

				bg = peach::getElementsByName(root, "background");

				// set the background color
				if (bg.size() > 0)
				{
					bg_r = peach::getElementsByName(bg[0], "red");
					bg_g = peach::getElementsByName(bg[0], "green");
					bg_b = peach::getElementsByName(bg[0], "blue");

					if (bg_r.size() > 0 && bg_g.size() > 0 && bg_b.size() > 0)
					{
						if (bg_r[0]->text.size() > 0 && bg_g[0]->text.size() > 0 && bg_b[0]->text.size() > 0)
						{
							background[0] = atof(bg_r[0]->text[0].c_str());
							background[1] = atof(bg_g[0]->text[0].c_str());
							background[2] = atof(bg_b[0]->text[0].c_str());
						}
					}
				}
				peach::destroyElements(root);
			}
		}
		else
		{
			cout << "xml validation error: " << config_error << endl;
		}
	}
	else
	{
		cout << "could not open configuration file" << endl;
	}

	//=================================
	// MENUS
	//=================================
	float pause_x = screen_width / 4;
	float pause_y = screen_height / 4;
	int pause_w = screen_width / 2;
	int pause_h = screen_height / 2;

	vector<peach::MenuItem> pause_items;
	peach::MenuItem resume_item(peach::PAUSE_MENU_RESUME, "resume", pause_x + 35, pause_y + 20, (void*) font);
	peach::MenuItem quit_item(peach::PAUSE_MENU_QUIT, "quit", pause_x + 35, pause_y + 40, (void*) font);
	peach::MenuItem info_item(peach::PAUSE_MENU_INFO, "info", pause_x + 130, pause_y + 20, (void*) font);
	pause_items.push_back(resume_item);
	pause_items.push_back(quit_item);
	pause_items.push_back(info_item);

	int** pause_cursor_coords = new int*[2];
	for (int i = 0; i < 2; i++)
		pause_cursor_coords[i] = new int[2];

	pause_cursor_coords[0][0] = pause_x + 35 - 15;
	pause_cursor_coords[0][1] = pause_x + 130 - 15;

	pause_cursor_coords[1][0] = pause_x + 35 - 15;
	pause_cursor_coords[1][1] = -1;

	peach::MenuCursor pause_cursor(pause_cursor_coords, 0, 0, 2, 2, pause_y + 25);

	peach::Menu pause_menu(pause_x, pause_y, pause_w, pause_h, pause_items, &pause_cursor);

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

			if (state == peach::PLAY && pause == 0)
			{
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

				// handle player jumping
				if (keys[peach::SPACE] && !player.GetJumping())
					player.Jump();

				// update positions, resolve collisions, scroll the screen
				level_1.Update();

			}
			else if (state == peach::START)
			{
				// start screen
			}
			else if (state == peach::END)
			{
				// this is the end of the game credits will most likely go here
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
			if (pause == 1)
			{
				int action;
				action = pause_menu.HandleKeyboardInput(al_event.keyboard.keycode);
				switch (action)
				{
				case peach::PAUSE_MENU_RESUME:
					pause_menu.Close();
					pause = 0;
					break;
				case peach::PAUSE_MENU_QUIT:
					done = true;
					break;
				case peach::PAUSE_MENU_INFO:
					if (info == 0)
						info = 1;
					else
						info = 0;
					break;
				default:
					break;
				}
			}
			switch (al_event.keyboard.keycode)
			{
			case ALLEGRO_KEY_ESCAPE:
				if (state == peach::PLAY)
				{
					if (pause == 0)
					{
						pause = 1;
						pause_menu.Open();
					}
					else
					{
						pause = 0;
						pause_menu.Close();
					}
				}
				else if (state == peach::START)
				{
					done = true;
				}
				break;
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
				if (state == peach::START)
				{
					state = peach::PLAY;
					level_1.Load();
					player.SetX(300);
					player.SetY(240);
					player.SetXVel(0);
					player.SetYVel(0);
					player.SetJumping(false);
				}
				else if (state == peach::END)
				{
					state = peach::START;
				}
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
			case ALLEGRO_KEY_ENTER:
				keys[peach::ENTER] = true;
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
			case ALLEGRO_KEY_ENTER:
				keys[peach::ENTER] = false;
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

			if (state == peach::PLAY)
			{
				level_1.Render();
			}
			else if (state == peach::START)
			{
				al_draw_text(font, al_map_rgb(250, 250, 250), 265, 150, 0, "Peach Smith");
				al_draw_text(font, al_map_rgb(250, 250, 250), 160, 225, 0, "Objective: get to the green rectangle");
				al_draw_text(font, al_map_rgb(250, 250, 250), 160, 250, 0, "Controls:");
				al_draw_text(font, al_map_rgb(250, 250, 250), 160, 275, 0, "    move: arrow keys");
				al_draw_text(font, al_map_rgb(250, 250, 250), 160, 300, 0, "    jump: space bar");
				al_draw_text(font, al_map_rgb(250, 250, 250), 160, 325, 0, "    pause: Esc");
				al_draw_text(font, al_map_rgb(250, 250, 250), 160, 350, 0, "    choose menu option: z");
				al_draw_text(font, al_map_rgb(250, 250, 250), 240, 410, 0, "Press z to start");
				al_draw_text(font, al_map_rgb(250, 250, 250), 240, 435, 0, "Press Esc to quit");
			}
			else if (state == peach::END)
			{
				al_draw_text(font, al_map_rgb(250, 250, 250), 310, 250, 0, "The End");
				al_draw_text(font, al_map_rgb(250, 250, 250), 180, 350, 0, "Press z to return to start screen");
			}

			if (pause == 1)
			{
				pause_menu.Render();
			}

//			// x scroll boundariess
//			al_draw_rectangle(x_min, y_min, x_min - 10, y_max, al_map_rgb(255, 0, 0), 0);
//			al_draw_rectangle(x_max + 16, y_min, x_max + 26, y_max, al_map_rgb(255, 0, 0), 0);
//
//			// y scroll boundariess
//			al_draw_rectangle(x_min, y_min - 10, x_max + 16, y_min, al_map_rgb(0, 0, 255), 0);
//			al_draw_rectangle(x_min, y_max + 10, x_max + 16, y_max, al_map_rgb(0, 0, 255), 0);

			// info
			if (info == 1)
			{
				// player position and velocity
				al_draw_textf(font, al_map_rgb(250, 250, 250), 15, 5, 0, "x: %.2f", player.GetX());
				al_draw_textf(font, al_map_rgb(250, 250, 250), 15, 25, 0, "y: %.2f", player.GetY());
				al_draw_textf(font, al_map_rgb(250, 250, 250), 15, 45, 0, "x_vel: %.2f", player.GetXVel());
				al_draw_textf(font, al_map_rgb(250, 250, 250), 15, 65, 0, "y_vel: %.2f", player.GetYVel());

				al_draw_textf(font, al_map_rgb(250, 250, 250), 200, 5, 0, "state: %i", state);
				if (pause == 1)
					al_draw_text(font, al_map_rgb(250, 250, 250), 200, 25, 0, "paused");
			}

			al_flip_display();
			if (state == peach::PLAY)
			{
				al_clear_to_color(al_map_rgb(background[0], background[1], background[2])); // 0 134 179
			}
			else if (state == peach::END || state == peach::START)
			{
				al_clear_to_color(al_map_rgb(0, 0, 0)); // 0 134 179
			}
		}

	}

	if (keys[peach::X])
	{
		// just to get rid of the warning
	}

	//=================================
	// CLEAN UP
	//=================================
	for (int i = 0; i < 2; i++)
		delete[] pause_cursor_coords[i];

	delete[] pause_cursor_coords;

	al_destroy_display(display);
	al_destroy_event_queue(event_queue);
	al_destroy_timer(timer);
	al_destroy_font(font);
	al_destroy_bitmap(player_sheet);
	al_destroy_bitmap(scenery_sheet);
	
	return 0;
}
