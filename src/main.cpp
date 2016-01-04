#include "Entity.h"
#include "Player.h"
#include "Terrain.h"
#include "Scenery.h"
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
	bool keys[8] =
	{ false, false, false, false, false, false, false, false };
	int screen_width;
	int screen_height;
	int x_min;
	int x_max;
	int y_min;
	int y_max;
	int y_scroll_correction;

	//=================================
	// ALLEGRO VARIABLES
	//=================================
	ALLEGRO_MONITOR_INFO monitor_info;
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

	al_get_monitor_info(0, &monitor_info);

	if (monitor_info.x2 - monitor_info.x1 > 800)
		screen_width = 700;
	else
		screen_width = monitor_info.x2 - monitor_info.x1 - 1;

	if (monitor_info.y2 - monitor_info.y1 > 800)
		screen_height = 600;
	else
		screen_height = monitor_info.y2 - monitor_info.y1 - 1;

	x_min = screen_width / 5 * 2 - 10;
	x_max = screen_width / 5 * 3 - 10;

	y_min = screen_height / 5 * 3 - 30;
	y_max = screen_height / 5 * 3;

	y_scroll_correction = y_max / 8 * 7;

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
	// COLLIDABLES
	//=================================
	std::vector<peach::Entity*> collidables;

	//=================================
	// DRAWABLES
	//=================================
	std::vector<peach::Entity*> drawables;

	//=================================
	// ENTITIES
	//=================================
	// x, y, x_vel, y_vel, x_dir, y_dir, x_bound, y_bound
	peach::Player player(true, true, 300, 240, 0, 0, 1, 1, 16, 32, (void*) player_sheet);
	peach::Terrain terrain_1(true, true, 145, 280, 0, 0, 0, 0, 200, 20); // lower middle
	peach::Terrain terrain_2(true, true, 365, 320, 0, 0, 0, 0, 80, 20); // left
	peach::Terrain terrain_3(true, true, 380, 210, 0, 0, 0, 0, 200, 20); // right
	peach::Terrain terrain_4(true, true, 145, 130, 0, 0, 0, 0, 200, 20); // upper middle
	peach::Terrain terrain_5(true, true, 430, 150, 0, 0, 0, 0, 100, 20); // upper right
	peach::Terrain terrain_6(true, true, 450, 80, 0, 0, 0, 0, 100, 20); // upper upper right
	peach::Terrain floor(true, true, 10, 390, 0, 0, 0, 0, 680, 20);
	peach::Terrain left_wall(true, true, 0, 0, 0, 0, 0, 0, 10, 400);
	peach::Terrain right_wall(true, true, 690, 0, 0, 0, 0, 0, 10, 400);

	// x, y, x_bound, y_bound, sheet_x, sheet_y, sprite_sheet
	// lower middle
	peach::Scenery brick_1(145, 280, 20, 20, 60, 0, (void*) scenery_sheet);
	peach::Scenery brick_2(165, 280, 20, 20, 40, 0, (void*) scenery_sheet);
	peach::Scenery brick_3(185, 280, 20, 20, 40, 0, (void*) scenery_sheet);
	peach::Scenery brick_4(205, 280, 20, 20, 40, 0, (void*) scenery_sheet);
	peach::Scenery brick_5(225, 280, 20, 20, 40, 0, (void*) scenery_sheet);
	peach::Scenery brick_6(245, 280, 20, 20, 40, 0, (void*) scenery_sheet);
	peach::Scenery brick_7(265, 280, 20, 20, 40, 0, (void*) scenery_sheet);
	peach::Scenery brick_8(285, 280, 20, 20, 40, 0, (void*) scenery_sheet);
	peach::Scenery brick_9(305, 280, 20, 20, 40, 0, (void*) scenery_sheet);
	peach::Scenery brick_10(325, 280, 20, 20, 80, 0, (void*) scenery_sheet);

	// left
	peach::Scenery brick_11(365, 320, 20, 20, 60, 0, (void*) scenery_sheet);
	peach::Scenery brick_12(385, 320, 20, 20, 40, 0, (void*) scenery_sheet);
	peach::Scenery brick_13(405, 320, 20, 20, 40, 0, (void*) scenery_sheet);
	peach::Scenery brick_14(425, 320, 20, 20, 80, 0, (void*) scenery_sheet);

	// right
	peach::Scenery brick_15(380, 210, 20, 20, 60, 0, (void*) scenery_sheet);
	peach::Scenery brick_16(400, 210, 20, 20, 40, 0, (void*) scenery_sheet);
	peach::Scenery brick_17(420, 210, 20, 20, 40, 0, (void*) scenery_sheet);
	peach::Scenery brick_18(440, 210, 20, 20, 40, 0, (void*) scenery_sheet);
	peach::Scenery brick_19(460, 210, 20, 20, 40, 0, (void*) scenery_sheet);
	peach::Scenery brick_20(480, 210, 20, 20, 40, 0, (void*) scenery_sheet);
	peach::Scenery brick_21(500, 210, 20, 20, 40, 0, (void*) scenery_sheet);
	peach::Scenery brick_22(520, 210, 20, 20, 40, 0, (void*) scenery_sheet);
	peach::Scenery brick_23(540, 210, 20, 20, 40, 0, (void*) scenery_sheet);
	peach::Scenery brick_24(560, 210, 20, 20, 80, 0, (void*) scenery_sheet);

	// upper middle
	peach::Scenery brick_25(145, 130, 20, 20, 60, 0, (void*) scenery_sheet);
	peach::Scenery brick_26(165, 130, 20, 20, 40, 0, (void*) scenery_sheet);
	peach::Scenery brick_27(185, 130, 20, 20, 40, 0, (void*) scenery_sheet);
	peach::Scenery brick_28(205, 130, 20, 20, 40, 0, (void*) scenery_sheet);
	peach::Scenery brick_29(225, 130, 20, 20, 40, 0, (void*) scenery_sheet);
	peach::Scenery brick_30(245, 130, 20, 20, 40, 0, (void*) scenery_sheet);
	peach::Scenery brick_31(265, 130, 20, 20, 40, 0, (void*) scenery_sheet);
	peach::Scenery brick_32(285, 130, 20, 20, 40, 0, (void*) scenery_sheet);
	peach::Scenery brick_33(305, 130, 20, 20, 40, 0, (void*) scenery_sheet);
	peach::Scenery brick_34(325, 130, 20, 20, 80, 0, (void*) scenery_sheet);

	// upper right
	peach::Scenery brick_35(430, 150, 20, 20, 60, 0, (void*) scenery_sheet);
	peach::Scenery brick_36(450, 150, 20, 20, 40, 0, (void*) scenery_sheet);
	peach::Scenery brick_37(470, 150, 20, 20, 40, 0, (void*) scenery_sheet);
	peach::Scenery brick_38(490, 150, 20, 20, 40, 0, (void*) scenery_sheet);
	peach::Scenery brick_39(510, 150, 20, 20, 80, 0, (void*) scenery_sheet);

	// upper upper right
	peach::Scenery brick_40(450, 80, 20, 20, 60, 0, (void*) scenery_sheet);
	peach::Scenery brick_41(470, 80, 20, 20, 40, 0, (void*) scenery_sheet);
	peach::Scenery brick_42(490, 80, 20, 20, 40, 0, (void*) scenery_sheet);
	peach::Scenery brick_43(510, 80, 20, 20, 40, 0, (void*) scenery_sheet);
	peach::Scenery brick_44(530, 80, 20, 20, 80, 0, (void*) scenery_sheet);

	// floor
	peach::Scenery brick_45(0, 390, 20, 20, 0, 0, (void*) scenery_sheet);
	peach::Scenery brick_46(20, 390, 20, 20, 0, 0, (void*) scenery_sheet);
	peach::Scenery brick_47(40, 390, 20, 20, 0, 0, (void*) scenery_sheet);
	peach::Scenery brick_48(60, 390, 20, 20, 0, 0, (void*) scenery_sheet);
	peach::Scenery brick_49(80, 390, 20, 20, 0, 0, (void*) scenery_sheet);
	peach::Scenery brick_50(100, 390, 20, 20, 0, 0, (void*) scenery_sheet);
	peach::Scenery brick_51(120, 390, 20, 20, 0, 0, (void*) scenery_sheet);
	peach::Scenery brick_52(140, 390, 20, 20, 0, 0, (void*) scenery_sheet);
	peach::Scenery brick_53(160, 390, 20, 20, 0, 0, (void*) scenery_sheet);
	peach::Scenery brick_54(180, 390, 20, 20, 0, 0, (void*) scenery_sheet);
	peach::Scenery brick_55(200, 390, 20, 20, 0, 0, (void*) scenery_sheet);
	peach::Scenery brick_56(220, 390, 20, 20, 0, 0, (void*) scenery_sheet);
	peach::Scenery brick_57(240, 390, 20, 20, 0, 0, (void*) scenery_sheet);
	peach::Scenery brick_58(260, 390, 20, 20, 0, 0, (void*) scenery_sheet);
	peach::Scenery brick_59(280, 390, 20, 20, 0, 0, (void*) scenery_sheet);
	peach::Scenery brick_60(300, 390, 20, 20, 0, 0, (void*) scenery_sheet);
	peach::Scenery brick_61(320, 390, 20, 20, 0, 0, (void*) scenery_sheet);
	peach::Scenery brick_62(340, 390, 20, 20, 0, 0, (void*) scenery_sheet);
	peach::Scenery brick_63(360, 390, 20, 20, 0, 0, (void*) scenery_sheet);
	peach::Scenery brick_64(380, 390, 20, 20, 0, 0, (void*) scenery_sheet);
	peach::Scenery brick_65(400, 390, 20, 20, 0, 0, (void*) scenery_sheet);
	peach::Scenery brick_66(420, 390, 20, 20, 0, 0, (void*) scenery_sheet);
	peach::Scenery brick_67(440, 390, 20, 20, 0, 0, (void*) scenery_sheet);
	peach::Scenery brick_68(460, 390, 20, 20, 0, 0, (void*) scenery_sheet);
	peach::Scenery brick_69(480, 390, 20, 20, 0, 0, (void*) scenery_sheet);
	peach::Scenery brick_70(500, 390, 20, 20, 0, 0, (void*) scenery_sheet);
	peach::Scenery brick_71(520, 390, 20, 20, 0, 0, (void*) scenery_sheet);
	peach::Scenery brick_72(540, 390, 20, 20, 0, 0, (void*) scenery_sheet);
	peach::Scenery brick_73(560, 390, 20, 20, 0, 0, (void*) scenery_sheet);
	peach::Scenery brick_74(580, 390, 20, 20, 0, 0, (void*) scenery_sheet);
	peach::Scenery brick_75(600, 390, 20, 20, 0, 0, (void*) scenery_sheet);
	peach::Scenery brick_76(620, 390, 20, 20, 0, 0, (void*) scenery_sheet);
	peach::Scenery brick_77(640, 390, 20, 20, 0, 0, (void*) scenery_sheet);
	peach::Scenery brick_78(660, 390, 20, 20, 0, 0, (void*) scenery_sheet);
	peach::Scenery brick_79(680, 390, 20, 20, 0, 0, (void*) scenery_sheet);

	// flowers
	peach::Scenery flower_1(100, 370, 20, 20, 20, 0, (void*) scenery_sheet);
	peach::Scenery flower_2(200, 370, 20, 20, 20, 0, (void*) scenery_sheet);
	peach::Scenery flower_3(300, 370, 20, 20, 20, 0, (void*) scenery_sheet);
	peach::Scenery flower_4(400, 370, 20, 20, 20, 0, (void*) scenery_sheet);

	// add the entities to the list
	collidables.push_back(&terrain_1);
	collidables.push_back(&terrain_2);
	collidables.push_back(&terrain_3);
	collidables.push_back(&terrain_4);
	collidables.push_back(&terrain_5);
	collidables.push_back(&terrain_6);
	collidables.push_back(&floor);
	collidables.push_back(&left_wall);
	collidables.push_back(&right_wall);
	collidables.push_back(&player);

	// lower middle
	drawables.push_back(&brick_1);
	drawables.push_back(&brick_2);
	drawables.push_back(&brick_3);
	drawables.push_back(&brick_4);
	drawables.push_back(&brick_5);
	drawables.push_back(&brick_6);
	drawables.push_back(&brick_7);
	drawables.push_back(&brick_8);
	drawables.push_back(&brick_9);
	drawables.push_back(&brick_10);

	// left
	drawables.push_back(&brick_11);
	drawables.push_back(&brick_12);
	drawables.push_back(&brick_13);
	drawables.push_back(&brick_14);

	// right
	drawables.push_back(&brick_15);
	drawables.push_back(&brick_16);
	drawables.push_back(&brick_17);
	drawables.push_back(&brick_18);
	drawables.push_back(&brick_19);
	drawables.push_back(&brick_20);
	drawables.push_back(&brick_21);
	drawables.push_back(&brick_22);
	drawables.push_back(&brick_23);
	drawables.push_back(&brick_24);

	// lower middle
	drawables.push_back(&brick_25);
	drawables.push_back(&brick_26);
	drawables.push_back(&brick_27);
	drawables.push_back(&brick_28);
	drawables.push_back(&brick_29);
	drawables.push_back(&brick_30);
	drawables.push_back(&brick_31);
	drawables.push_back(&brick_32);
	drawables.push_back(&brick_33);
	drawables.push_back(&brick_34);

	// upper right
	drawables.push_back(&brick_35);
	drawables.push_back(&brick_36);
	drawables.push_back(&brick_37);
	drawables.push_back(&brick_38);
	drawables.push_back(&brick_39);

	// upper upper right
	drawables.push_back(&brick_40);
	drawables.push_back(&brick_41);
	drawables.push_back(&brick_42);
	drawables.push_back(&brick_43);
	drawables.push_back(&brick_44);

	// floor
	drawables.push_back(&brick_45);
	drawables.push_back(&brick_46);
	drawables.push_back(&brick_47);
	drawables.push_back(&brick_48);
	drawables.push_back(&brick_49);
	drawables.push_back(&brick_50);
	drawables.push_back(&brick_51);
	drawables.push_back(&brick_52);
	drawables.push_back(&brick_53);
	drawables.push_back(&brick_54);
	drawables.push_back(&brick_55);
	drawables.push_back(&brick_56);
	drawables.push_back(&brick_57);
	drawables.push_back(&brick_58);
	drawables.push_back(&brick_59);
	drawables.push_back(&brick_60);
	drawables.push_back(&brick_61);
	drawables.push_back(&brick_62);
	drawables.push_back(&brick_63);
	drawables.push_back(&brick_64);
	drawables.push_back(&brick_65);
	drawables.push_back(&brick_66);
	drawables.push_back(&brick_67);
	drawables.push_back(&brick_68);
	drawables.push_back(&brick_69);
	drawables.push_back(&brick_70);
	drawables.push_back(&brick_71);
	drawables.push_back(&brick_72);
	drawables.push_back(&brick_73);
	drawables.push_back(&brick_74);
	drawables.push_back(&brick_75);
	drawables.push_back(&brick_76);
	drawables.push_back(&brick_77);
	drawables.push_back(&brick_78);
	drawables.push_back(&brick_79);

	// flowers
	drawables.push_back(&flower_1);
	drawables.push_back(&flower_2);
	drawables.push_back(&flower_3);
	drawables.push_back(&flower_4);

	drawables.push_back(&player);

	float x_depth = 0;
	float y_depth = 0;

	//=================================
	// PLAYER STUFF
	//=================================
	player.SetFrameDelay(6);
	player.SetMaxFrame(4);

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
	// GAME STATE
	//=================================
	int state = 0;

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

			// handle player jumping
			if (keys[peach::SPACE] && !player.GetJumping())
				player.Jump();

			// update
			for (unsigned int i = 0; i < collidables.size(); i++)
			{
				// set jumping to true in case the entity is in the air
				collidables[i]->UpdateX();
				collidables[i]->SetJumping(true);

				for (unsigned int j = 0; j < collidables.size(); j++)
				{
					if (collidables[i]->GetID() == collidables[j]->GetID())
					{
						continue; // for now, two Entities with the same ID cannot collide
					}

					if (collidables[i]->CheckCollision(collidables[j], x_depth, y_depth) >= 15)
					{
						// ignore false collision due to floating point nonsense
						if (y_depth < 0 && y_depth > -.1)
							continue;
						else if (y_depth > 0 && y_depth < .1)
							continue;

						collidables[i]->SetX(collidables[i]->GetX() - x_depth);

						if (player.GetX() < x_min)
						{
							float x_overshoot = x_min - player.GetX();
							for (unsigned int k = 0; k < collidables.size(); k++)
								collidables[k]->SetX(collidables[k]->GetX() + x_overshoot);
							for (unsigned int k = 0; k < drawables.size() - 1; k++)
								drawables[k]->SetX(drawables[k]->GetX() + x_overshoot);
						}
						else if (player.GetX() >= x_max)
						{
							float x_overshoot = player.GetX() - x_max;
							for (unsigned int k = 0; k < collidables.size(); k++)
								collidables[k]->SetX(collidables[k]->GetX() - x_overshoot);
							for (unsigned int k = 0; k < drawables.size() - 1; k++)
								drawables[k]->SetX(drawables[k]->GetX() - x_overshoot);
						}

						collidables[i]->Collide(collidables[j]->GetID());
						if (x_depth)
							collidables[i]->SetXVel(0);
					}
				}
				collidables[i]->UpdateY();
				for (unsigned int j = 0; j < collidables.size(); j++)
				{
					if (collidables[i]->GetID() == collidables[j]->GetID())
					{
						continue; // for now, two Entities with the same ID cannot collide
					}

					if (collidables[i]->CheckCollision(collidables[j], x_depth, y_depth) >= 15)
					{
						// resolve vertical collision
						collidables[i]->SetY(collidables[i]->GetY() - y_depth);

						if (player.GetY() < y_min)
						{
							float y_overshoot = y_min - player.GetY();
							for (unsigned int i = 0; i < collidables.size(); i++)
								collidables[i]->SetY(collidables[i]->GetY() + y_overshoot);
							for (unsigned int i = 0; i < drawables.size() - 1; i++)
								drawables[i]->SetY(drawables[i]->GetY() + y_overshoot);
						}
						else if (player.GetY() >= y_max)
						{
							float y_overshoot = player.GetY() - y_max;
							for (unsigned int i = 0; i < collidables.size(); i++)
								collidables[i]->SetY(collidables[i]->GetY() - y_overshoot);
							for (unsigned int i = 0; i < drawables.size() - 1; i++)
								drawables[i]->SetY(drawables[i]->GetY() - y_overshoot);
						}

						collidables[i]->Collide(collidables[j]->GetID());
						if (y_depth)
							collidables[i]->SetYVel(0);
						// if the bottom of the entity collides with something, set jumping to false
						if (y_depth > 0)
						{
							collidables[i]->SetJumping(false);
						}
					}
				}
			}

			if (player.GetX() < x_min)
				player.SetX(x_min);
			else if (player.GetX() > x_max)
				player.SetX(x_max);

			if (player.GetY() > y_max)
				player.SetY(y_max);
			else if (player.GetY() < y_min)
				player.SetY(y_min);

			// horizontal scrolling
			if ((player.GetX() == x_max || player.GetX() == x_min) && player.GetXVel())
			{
				bool scroll_collision = false;
				unsigned int i;
				for (i = 0; i < collidables.size(); i++)
				{
					if (collidables[i]->GetID() != peach::PLAYER)
					{
						collidables[i]->SetX(collidables[i]->GetX() - player.GetXVel());
						if (collidables[i]->CheckCollision((&player), x_depth, y_depth) >= 15)
						{
							scroll_collision = true;
							break;
						}
					}
				}
				// resolve collisions due to scrolling
				if (scroll_collision)
				{
					for (; i > 0; i--)
					{
						if (collidables[i]->GetID() != peach::PLAYER)
						{
							collidables[i]->SetX(collidables[i]->GetX() + player.GetXVel());
						}
					}
					collidables[i]->SetX(collidables[i]->GetX() + player.GetXVel());
					player.SetXVel(0);
				}
				else
				{
					// scenery horizontal scrolling
					for (unsigned int i = 0; i < drawables.size() - 1; i++)
						drawables[i]->SetX(drawables[i]->GetX() - player.GetXVel());
				}
			}
			// vertical scrolling
			if ((player.GetY() == y_max || player.GetY() == y_min) && player.GetYVel())
			{
				bool scroll_collision = false;
				unsigned int i;
				for (i = 0; i < collidables.size(); i++)
				{
					if (collidables[i]->GetID() != peach::PLAYER)
					{
						collidables[i]->SetY(collidables[i]->GetY() - player.GetYVel());
						if (collidables[i]->CheckCollision((&player), x_depth, y_depth) >= 15)
						{
							scroll_collision = true;
							break;
						}
					}
				}
				// resolve collisions due to scrolling
				if (scroll_collision)
				{
					for (; i > 0; i--)
					{
						if (collidables[i]->GetID() != peach::PLAYER)
						{
							collidables[i]->SetY(collidables[i]->GetY() + player.GetYVel());
						}
					}
					collidables[i]->SetY(collidables[i]->GetY() + player.GetYVel());
					player.SetYVel(0);
				}
				else
				{
					// scenery vertical scrolling
					for (unsigned int i = 0; i < drawables.size() - 1; i++)
						drawables[i]->SetY(drawables[i]->GetY() - player.GetYVel());
				}
			}
			// move everything so the player is closer to the middle
			if (player.GetY() != y_scroll_correction && player.GetYVel() == 0)
			{
				float player_y = player.GetY();
				if (player_y > y_scroll_correction)
				{
					if (player_y - 1 < y_scroll_correction)
					{
						for (unsigned int i = 0; i < collidables.size() - 1; i++)
							collidables[i]->SetY(collidables[i]->GetY() - (player.GetY() - y_scroll_correction));
						for (unsigned int i = 0; i < drawables.size() - 1; i++)
							drawables[i]->SetY(drawables[i]->GetY() - (player.GetY() - y_scroll_correction));
						player.SetY(player.GetY() - (player.GetY() - y_scroll_correction));
					}
					else
					{
						for (unsigned int i = 0; i < collidables.size(); i++)
							collidables[i]->SetY(collidables[i]->GetY() - 1);
						for (unsigned int i = 0; i < drawables.size() - 1; i++)
							drawables[i]->SetY(drawables[i]->GetY() - 1);
					}
					if (player.GetY() < y_scroll_correction)
					{
						player_y = player.GetY();
						for (unsigned int i = 0; i < collidables.size(); i++)
							collidables[i]->SetY(collidables[i]->GetY() + (y_scroll_correction - player_y));
						for (unsigned int i = 0; i < drawables.size() - 1; i++)
							drawables[i]->SetY(drawables[i]->GetY() + (y_scroll_correction - player_y));
					}
				}
				else if (player_y < y_scroll_correction)
				{
					if (player_y + 1 > y_scroll_correction)
					{
						for (unsigned int i = 0; i < collidables.size() - 1; i++)
							collidables[i]->SetY(collidables[i]->GetY() + (y_scroll_correction - player.GetY()));
						for (unsigned int i = 0; i < drawables.size() - 1; i++)
							drawables[i]->SetY(drawables[i]->GetY() + (y_scroll_correction - player.GetY()));
						player.SetY(player.GetY() - (player.GetY() - y_scroll_correction));
					}
					else
					{
						for (unsigned int i = 0; i < collidables.size(); i++)
							collidables[i]->SetY(collidables[i]->GetY() + 1);
						for (unsigned int i = 0; i < drawables.size() - 1; i++)
							drawables[i]->SetY(drawables[i]->GetY() + 1);
					}
					if (player.GetY() > y_scroll_correction)
					{
						cout << "furp" << endl;
						player_y = player.GetY();
						for (unsigned int i = 0; i < collidables.size() - 1; i++)
							collidables[i]->SetY(collidables[i]->GetY() + (y_scroll_correction - player_y));
						for (unsigned int i = 0; i < drawables.size() - 1; i++)
							drawables[i]->SetY(drawables[i]->GetY() + (y_scroll_correction - player_y));
						player.SetY(player.GetY() - (y_scroll_correction - player_y));
					}
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

//			for (unsigned int i = 0; i < collidables.size(); i++)
//			{
//				collidables[i]->Render();
//			}

			for (unsigned int i = 0; i < drawables.size(); i++)
			{
				drawables[i]->Render();
			}

//			al_draw_rectangle(x_min, y_min, x_min - 10, y_max, al_map_rgb(255, 0, 0), 0);
//			al_draw_rectangle(x_max + 16, y_min, x_max + 26, y_max, al_map_rgb(255, 0, 0), 0);
//
//			al_draw_rectangle(x_min, y_min, x_max + 16, y_min + 10, al_map_rgb(0, 0, 255), 0);
//			al_draw_rectangle(x_min, y_max, x_max + 16, y_max - 10, al_map_rgb(0, 0, 255), 0);

			// player position and velocity
//			al_draw_textf(font, al_map_rgb(250, 250, 250), 15, 5, 0, "x: %.2f", player.GetX());
//			al_draw_textf(font, al_map_rgb(250, 250, 250), 15, 25, 0, "y: %.2f", player.GetY());
//			al_draw_textf(font, al_map_rgb(250, 250, 250), 15, 45, 0, "x_vel: %.2f", player.GetXVel());
//			al_draw_textf(font, al_map_rgb(250, 250, 250), 15, 65, 0, "y_vel: %.2f", player.GetYVel());

//			al_draw_textf(font, al_map_rgb(250, 250, 250), 200, 5, 0, "brick_1 y:   %.6f", brick_1.GetY());
//			al_draw_textf(font, al_map_rgb(250, 250, 250), 200, 25, 0, "terrain_1 y: %.6f", terrain_1.GetY());

			// controls
//			al_draw_textf(font, al_map_rgb(250, 250, 250), 100, 5, 0,
//					"move with arrow keys");
//			al_draw_textf(font, al_map_rgb(250, 250, 250), 100, 25, 0,
//					"jump with space bar");

			al_flip_display();
			al_clear_to_color(al_map_rgb(background[0], background[1], background[2])); // 0 134 179
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
	al_destroy_bitmap(player_sheet);
	al_destroy_bitmap(scenery_sheet);

	return 0;
}
