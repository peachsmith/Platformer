#include "Level1.h"

namespace peach
{

Level1::Level1() :
		player_sheet(0), scenery_sheet(0), player(0), x_min(0), x_max(0), y_min(0), y_max(0), y_scroll_correction(0), status(0), state(0), map_x(0), map_y(0)
{

}

Level1::Level1(void* player_sheet, void* scenery_sheet, peach::Player* player, int* state) :
		x_min(270), x_max(410), y_min(330), y_max(360), y_scroll_correction(315), status(0)
{
	Level1::player_sheet = player_sheet;
	Level1::scenery_sheet = scenery_sheet;
	Level1::player = player;
	Level1::state = state;
	Level1::map_x = 240;
	Level1::map_y = 280;

	// alive, collidable, x, y, x_vel, y_vel, x_dir, y_dir, x_bound, y_bound
	terrain_1 = peach::Terrain(true, true, map_x + 0, map_y + 0, 0, 0, 0, 0, 20, 300);
	terrain_2 = peach::Terrain(true, true, map_x + 20, map_y + 140, 0, 0, 0, 0, 420, 20);
	terrain_3 = peach::Terrain(true, true, map_x + 480, map_y + 0, 0, 0, 0, 0, 20, 300);
	terrain_4 = peach::Terrain(true, true, map_x + 60, map_y + 300, 0, 0, 0, 0, 440, 20);
	terrain_5 = peach::Terrain(true, true, map_x + 220, map_y + 260, 0, 0, 0, 0, 40, 40);
	terrain_6 = peach::Terrain(true, true, map_x - 100, map_y + 300, 0, 0, 0, 0, 120, 20);
	terrain_7 = peach::Terrain(true, true, map_x - 100, map_y + 320, 0, 0, 0, 0, 20, 160);
	terrain_8 = peach::Terrain(true, true, map_x - 80, map_y + 460, 0, 0, 0, 0, 240, 20);
	terrain_9 = peach::Terrain(true, true, map_x + 140, map_y + 480, 0, 0, 0, 0, 20, 80);
	terrain_10 = peach::Terrain(true, true, map_x + 160, map_y + 500, 0, 0, 0, 0, 40, 60);
	terrain_11 = peach::Terrain(true, true, map_x + 200, map_y + 540, 0, 0, 0, 0, 20, 20);
	terrain_12 = peach::Terrain(true, true, map_x + 140, map_y + 560, 0, 0, 0, 0, 180, 20);
	terrain_13 = peach::Terrain(true, true, map_x + 300, map_y + 480, 0, 0, 0, 0, 20, 80);
	terrain_14 = peach::Terrain(true, true, map_x + 300, map_y + 460, 0, 0, 0, 0, 180, 20);
	terrain_15 = peach::Terrain(true, true, map_x + 480, map_y + 320, 0, 0, 0, 0, 20, 160);
	terrain_16 = peach::Terrain(true, true, map_x + 200, map_y + 400, 0, 0, 0, 0, 60, 20);

	goal = peach::Entity(peach::GOAL, true, true, map_x + 360, map_y + 420, 0, 0, 0, 0, 20, 40);

	collidables.push_back(&terrain_1);
	collidables.push_back(&terrain_2);
	collidables.push_back(&terrain_3);
	collidables.push_back(&terrain_4);
	collidables.push_back(&terrain_5);
	collidables.push_back(&terrain_6);
	collidables.push_back(&terrain_7);
	collidables.push_back(&terrain_8);
	collidables.push_back(&terrain_9);
	collidables.push_back(&terrain_10);
	collidables.push_back(&terrain_11);
	collidables.push_back(&terrain_12);
	collidables.push_back(&terrain_13);
	collidables.push_back(&terrain_14);
	collidables.push_back(&terrain_15);
	collidables.push_back(&terrain_16);
	collidables.push_back(&goal);
	collidables.push_back(player);

	// x, y, x_bound, y_bound, sheet_x, sheet_y, sprite_sheet
	// terrain 1
	brick_1 = peach::Scenery(map_x + 0, map_y + 0, 20, 20, 40, 0, (void*) scenery_sheet);
	brick_2 = peach::Scenery(map_x + 0, map_y + 20, 20, 20, 40, 0, (void*) scenery_sheet);
	brick_3 = peach::Scenery(map_x + 0, map_y + 40, 20, 20, 40, 0, (void*) scenery_sheet);
	brick_4 = peach::Scenery(map_x + 0, map_y + 60, 20, 20, 40, 0, (void*) scenery_sheet);
	brick_5 = peach::Scenery(map_x + 0, map_y + 80, 20, 20, 40, 0, (void*) scenery_sheet);
	brick_6 = peach::Scenery(map_x + 0, map_y + 100, 20, 20, 40, 0, (void*) scenery_sheet);
	brick_7 = peach::Scenery(map_x + 0, map_y + 120, 20, 20, 40, 0, (void*) scenery_sheet);
	brick_8 = peach::Scenery(map_x + 0, map_y + 140, 20, 20, 40, 0, (void*) scenery_sheet);
	brick_9 = peach::Scenery(map_x + 0, map_y + 160, 20, 20, 40, 0, (void*) scenery_sheet);
	brick_10 = peach::Scenery(map_x + 0, map_y + 180, 20, 20, 40, 0, (void*) scenery_sheet);
	brick_11 = peach::Scenery(map_x + 0, map_y + 200, 20, 20, 40, 0, (void*) scenery_sheet);
	brick_12 = peach::Scenery(map_x + 0, map_y + 220, 20, 20, 40, 0, (void*) scenery_sheet);
	brick_13 = peach::Scenery(map_x + 0, map_y + 240, 20, 20, 40, 0, (void*) scenery_sheet);
	brick_14 = peach::Scenery(map_x + 0, map_y + 260, 20, 20, 40, 0, (void*) scenery_sheet);
	brick_15 = peach::Scenery(map_x + 0, map_y + 280, 20, 20, 40, 0, (void*) scenery_sheet);

	// terrain 2
	brick_16 = peach::Scenery(map_x + 20, map_y + 140, 20, 20, 40, 0, (void*) scenery_sheet);
	brick_17 = peach::Scenery(map_x + 40, map_y + 140, 20, 20, 40, 0, (void*) scenery_sheet);
	brick_18 = peach::Scenery(map_x + 60, map_y + 140, 20, 20, 40, 0, (void*) scenery_sheet);
	brick_19 = peach::Scenery(map_x + 80, map_y + 140, 20, 20, 40, 0, (void*) scenery_sheet);
	brick_20 = peach::Scenery(map_x + 100, map_y + 140, 20, 20, 40, 0, (void*) scenery_sheet);
	brick_21 = peach::Scenery(map_x + 120, map_y + 140, 20, 20, 40, 0, (void*) scenery_sheet);
	brick_22 = peach::Scenery(map_x + 140, map_y + 140, 20, 20, 40, 0, (void*) scenery_sheet);
	brick_23 = peach::Scenery(map_x + 160, map_y + 140, 20, 20, 40, 0, (void*) scenery_sheet);
	brick_24 = peach::Scenery(map_x + 180, map_y + 140, 20, 20, 40, 0, (void*) scenery_sheet);
	brick_25 = peach::Scenery(map_x + 200, map_y + 140, 20, 20, 40, 0, (void*) scenery_sheet);
	brick_26 = peach::Scenery(map_x + 220, map_y + 140, 20, 20, 40, 0, (void*) scenery_sheet);
	brick_27 = peach::Scenery(map_x + 240, map_y + 140, 20, 20, 40, 0, (void*) scenery_sheet);
	brick_28 = peach::Scenery(map_x + 260, map_y + 140, 20, 20, 40, 0, (void*) scenery_sheet);
	brick_29 = peach::Scenery(map_x + 280, map_y + 140, 20, 20, 40, 0, (void*) scenery_sheet);
	brick_30 = peach::Scenery(map_x + 300, map_y + 140, 20, 20, 40, 0, (void*) scenery_sheet);
	brick_31 = peach::Scenery(map_x + 320, map_y + 140, 20, 20, 40, 0, (void*) scenery_sheet);
	brick_32 = peach::Scenery(map_x + 340, map_y + 140, 20, 20, 40, 0, (void*) scenery_sheet);
	brick_33 = peach::Scenery(map_x + 360, map_y + 140, 20, 20, 40, 0, (void*) scenery_sheet);
	brick_34 = peach::Scenery(map_x + 380, map_y + 140, 20, 20, 40, 0, (void*) scenery_sheet);
	brick_35 = peach::Scenery(map_x + 400, map_y + 140, 20, 20, 40, 0, (void*) scenery_sheet);
	brick_36 = peach::Scenery(map_x + 420, map_y + 140, 20, 20, 40, 0, (void*) scenery_sheet);

	// terrain 3
	brick_37 = peach::Scenery(map_x + 480, map_y + 0, 20, 20, 40, 0, (void*) scenery_sheet);
	brick_38 = peach::Scenery(map_x + 480, map_y + 20, 20, 20, 40, 0, (void*) scenery_sheet);
	brick_39 = peach::Scenery(map_x + 480, map_y + 40, 20, 20, 40, 0, (void*) scenery_sheet);
	brick_40 = peach::Scenery(map_x + 480, map_y + 60, 20, 20, 40, 0, (void*) scenery_sheet);
	brick_41 = peach::Scenery(map_x + 480, map_y + 80, 20, 20, 40, 0, (void*) scenery_sheet);
	brick_42 = peach::Scenery(map_x + 480, map_y + 100, 20, 20, 40, 0, (void*) scenery_sheet);
	brick_43 = peach::Scenery(map_x + 480, map_y + 120, 20, 20, 40, 0, (void*) scenery_sheet);
	brick_44 = peach::Scenery(map_x + 480, map_y + 140, 20, 20, 40, 0, (void*) scenery_sheet);
	brick_45 = peach::Scenery(map_x + 480, map_y + 160, 20, 20, 40, 0, (void*) scenery_sheet);
	brick_46 = peach::Scenery(map_x + 480, map_y + 180, 20, 20, 40, 0, (void*) scenery_sheet);
	brick_47 = peach::Scenery(map_x + 480, map_y + 200, 20, 20, 40, 0, (void*) scenery_sheet);
	brick_48 = peach::Scenery(map_x + 480, map_y + 220, 20, 20, 40, 0, (void*) scenery_sheet);
	brick_49 = peach::Scenery(map_x + 480, map_y + 240, 20, 20, 40, 0, (void*) scenery_sheet);
	brick_50 = peach::Scenery(map_x + 480, map_y + 260, 20, 20, 40, 0, (void*) scenery_sheet);
	brick_51 = peach::Scenery(map_x + 480, map_y + 280, 20, 20, 40, 0, (void*) scenery_sheet);

	// terrain 4
	brick_52 = peach::Scenery(map_x + 60, map_y + 300, 20, 20, 40, 0, (void*) scenery_sheet);
	brick_53 = peach::Scenery(map_x + 80, map_y + 300, 20, 20, 40, 0, (void*) scenery_sheet);
	brick_54 = peach::Scenery(map_x + 100, map_y + 300, 20, 20, 40, 0, (void*) scenery_sheet);
	brick_55 = peach::Scenery(map_x + 120, map_y + 300, 20, 20, 40, 0, (void*) scenery_sheet);
	brick_56 = peach::Scenery(map_x + 140, map_y + 300, 20, 20, 40, 0, (void*) scenery_sheet);
	brick_57 = peach::Scenery(map_x + 160, map_y + 300, 20, 20, 40, 0, (void*) scenery_sheet);
	brick_58 = peach::Scenery(map_x + 180, map_y + 300, 20, 20, 40, 0, (void*) scenery_sheet);
	brick_59 = peach::Scenery(map_x + 200, map_y + 300, 20, 20, 40, 0, (void*) scenery_sheet);
	brick_60 = peach::Scenery(map_x + 220, map_y + 300, 20, 20, 40, 0, (void*) scenery_sheet);
	brick_61 = peach::Scenery(map_x + 240, map_y + 300, 20, 20, 40, 0, (void*) scenery_sheet);
	brick_62 = peach::Scenery(map_x + 260, map_y + 300, 20, 20, 40, 0, (void*) scenery_sheet);
	brick_63 = peach::Scenery(map_x + 280, map_y + 300, 20, 20, 40, 0, (void*) scenery_sheet);
	brick_64 = peach::Scenery(map_x + 300, map_y + 300, 20, 20, 40, 0, (void*) scenery_sheet);
	brick_65 = peach::Scenery(map_x + 320, map_y + 300, 20, 20, 40, 0, (void*) scenery_sheet);
	brick_66 = peach::Scenery(map_x + 340, map_y + 300, 20, 20, 40, 0, (void*) scenery_sheet);
	brick_67 = peach::Scenery(map_x + 360, map_y + 300, 20, 20, 40, 0, (void*) scenery_sheet);
	brick_68 = peach::Scenery(map_x + 380, map_y + 300, 20, 20, 40, 0, (void*) scenery_sheet);
	brick_69 = peach::Scenery(map_x + 400, map_y + 300, 20, 20, 40, 0, (void*) scenery_sheet);
	brick_70 = peach::Scenery(map_x + 420, map_y + 300, 20, 20, 40, 0, (void*) scenery_sheet);
	brick_71 = peach::Scenery(map_x + 440, map_y + 300, 20, 20, 40, 0, (void*) scenery_sheet);
	brick_72 = peach::Scenery(map_x + 460, map_y + 300, 20, 20, 40, 0, (void*) scenery_sheet);
	brick_73 = peach::Scenery(map_x + 480, map_y + 300, 20, 20, 40, 0, (void*) scenery_sheet);

	// terrain 5
	brick_74 = peach::Scenery(map_x + 220, map_y + 260, 20, 20, 40, 0, (void*) scenery_sheet);
	brick_75 = peach::Scenery(map_x + 240, map_y + 260, 20, 20, 40, 0, (void*) scenery_sheet);
	brick_76 = peach::Scenery(map_x + 220, map_y + 280, 20, 20, 40, 0, (void*) scenery_sheet);
	brick_77 = peach::Scenery(map_x + 240, map_y + 280, 20, 20, 40, 0, (void*) scenery_sheet);

	// terrain 6
	brick_78 = peach::Scenery(map_x - 100, map_y + 300, 20, 20, 40, 0, (void*) scenery_sheet);
	brick_79 = peach::Scenery(map_x - 80, map_y + 300, 20, 20, 40, 0, (void*) scenery_sheet);
	brick_80 = peach::Scenery(map_x - 60, map_y + 300, 20, 20, 40, 0, (void*) scenery_sheet);
	brick_81 = peach::Scenery(map_x - 40, map_y + 300, 20, 20, 40, 0, (void*) scenery_sheet);
	brick_82 = peach::Scenery(map_x - 20, map_y + 300, 20, 20, 40, 0, (void*) scenery_sheet);
	brick_83 = peach::Scenery(map_x - 0, map_y + 300, 20, 20, 40, 0, (void*) scenery_sheet);

	// terrain 7
	brick_84 = peach::Scenery(map_x - 100, map_y + 320, 20, 20, 40, 0, (void*) scenery_sheet);
	brick_85 = peach::Scenery(map_x - 100, map_y + 340, 20, 20, 40, 0, (void*) scenery_sheet);
	brick_86 = peach::Scenery(map_x - 100, map_y + 360, 20, 20, 40, 0, (void*) scenery_sheet);
	brick_87 = peach::Scenery(map_x - 100, map_y + 380, 20, 20, 40, 0, (void*) scenery_sheet);
	brick_88 = peach::Scenery(map_x - 100, map_y + 400, 20, 20, 40, 0, (void*) scenery_sheet);
	brick_89 = peach::Scenery(map_x - 100, map_y + 420, 20, 20, 40, 0, (void*) scenery_sheet);
	brick_90 = peach::Scenery(map_x - 100, map_y + 440, 20, 20, 40, 0, (void*) scenery_sheet);
	brick_91 = peach::Scenery(map_x - 100, map_y + 460, 20, 20, 40, 0, (void*) scenery_sheet);

	// terrain 8
	brick_92 = peach::Scenery(map_x - 80, map_y + 460, 20, 20, 0, 0, (void*) scenery_sheet);
	brick_93 = peach::Scenery(map_x - 60, map_y + 460, 20, 20, 0, 0, (void*) scenery_sheet);
	brick_94 = peach::Scenery(map_x - 40, map_y + 460, 20, 20, 0, 0, (void*) scenery_sheet);
	brick_95 = peach::Scenery(map_x - 20, map_y + 460, 20, 20, 0, 0, (void*) scenery_sheet);
	brick_96 = peach::Scenery(map_x - 0, map_y + 460, 20, 20, 0, 0, (void*) scenery_sheet);
	brick_97 = peach::Scenery(map_x + 20, map_y + 460, 20, 20, 0, 0, (void*) scenery_sheet);
	brick_98 = peach::Scenery(map_x + 40, map_y + 460, 20, 20, 0, 0, (void*) scenery_sheet);
	brick_99 = peach::Scenery(map_x + 60, map_y + 460, 20, 20, 0, 0, (void*) scenery_sheet);
	brick_100 = peach::Scenery(map_x + 80, map_y + 460, 20, 20, 0, 0, (void*) scenery_sheet);
	brick_101 = peach::Scenery(map_x + 100, map_y + 460, 20, 20, 0, 0, (void*) scenery_sheet);
	brick_102 = peach::Scenery(map_x + 120, map_y + 460, 20, 20, 0, 0, (void*) scenery_sheet);
	brick_103 = peach::Scenery(map_x + 140, map_y + 460, 20, 20, 0, 0, (void*) scenery_sheet);

	// terrain 9
	brick_104 = peach::Scenery(map_x + 140, map_y + 480, 20, 20, 40, 0, (void*) scenery_sheet);
	brick_105 = peach::Scenery(map_x + 140, map_y + 500, 20, 20, 40, 0, (void*) scenery_sheet);
	brick_106 = peach::Scenery(map_x + 140, map_y + 520, 20, 20, 40, 0, (void*) scenery_sheet);
	brick_107 = peach::Scenery(map_x + 140, map_y + 540, 20, 20, 40, 0, (void*) scenery_sheet);

	// terrain 10
	brick_108 = peach::Scenery(map_x + 160, map_y + 500, 20, 20, 40, 0, (void*) scenery_sheet);
	brick_109 = peach::Scenery(map_x + 180, map_y + 500, 20, 20, 40, 0, (void*) scenery_sheet);
	brick_110 = peach::Scenery(map_x + 160, map_y + 520, 20, 20, 40, 0, (void*) scenery_sheet);
	brick_111 = peach::Scenery(map_x + 180, map_y + 520, 20, 20, 40, 0, (void*) scenery_sheet);
	brick_112 = peach::Scenery(map_x + 160, map_y + 540, 20, 20, 40, 0, (void*) scenery_sheet);
	brick_113 = peach::Scenery(map_x + 180, map_y + 540, 20, 20, 40, 0, (void*) scenery_sheet);

	// terrain 11
	brick_114 = peach::Scenery(map_x + 200, map_y + 540, 20, 20, 40, 0, (void*) scenery_sheet);

	// terrain 12
	brick_115 = peach::Scenery(map_x + 140, map_y + 560, 20, 20, 0, 0, (void*) scenery_sheet);
	brick_116 = peach::Scenery(map_x + 160, map_y + 560, 20, 20, 0, 0, (void*) scenery_sheet);
	brick_117 = peach::Scenery(map_x + 180, map_y + 560, 20, 20, 0, 0, (void*) scenery_sheet);
	brick_118 = peach::Scenery(map_x + 200, map_y + 560, 20, 20, 0, 0, (void*) scenery_sheet);
	brick_119 = peach::Scenery(map_x + 220, map_y + 560, 20, 20, 0, 0, (void*) scenery_sheet);
	brick_120 = peach::Scenery(map_x + 240, map_y + 560, 20, 20, 0, 0, (void*) scenery_sheet);
	brick_121 = peach::Scenery(map_x + 260, map_y + 560, 20, 20, 0, 0, (void*) scenery_sheet);
	brick_122 = peach::Scenery(map_x + 280, map_y + 560, 20, 20, 0, 0, (void*) scenery_sheet);
	brick_123 = peach::Scenery(map_x + 300, map_y + 560, 20, 20, 0, 0, (void*) scenery_sheet);

	// terrain 13
	brick_124 = peach::Scenery(map_x + 300, map_y + 480, 20, 20, 40, 0, (void*) scenery_sheet);
	brick_125 = peach::Scenery(map_x + 300, map_y + 500, 20, 20, 40, 0, (void*) scenery_sheet);
	brick_126 = peach::Scenery(map_x + 300, map_y + 520, 20, 20, 40, 0, (void*) scenery_sheet);
	brick_127 = peach::Scenery(map_x + 300, map_y + 540, 20, 20, 40, 0, (void*) scenery_sheet);

	// terrain 14
	brick_128 = peach::Scenery(map_x + 300, map_y + 460, 20, 20, 0, 0, (void*) scenery_sheet);
	brick_129 = peach::Scenery(map_x + 320, map_y + 460, 20, 20, 0, 0, (void*) scenery_sheet);
	brick_130 = peach::Scenery(map_x + 340, map_y + 460, 20, 20, 0, 0, (void*) scenery_sheet);
	brick_131 = peach::Scenery(map_x + 360, map_y + 460, 20, 20, 0, 0, (void*) scenery_sheet);
	brick_132 = peach::Scenery(map_x + 380, map_y + 460, 20, 20, 0, 0, (void*) scenery_sheet);
	brick_133 = peach::Scenery(map_x + 400, map_y + 460, 20, 20, 0, 0, (void*) scenery_sheet);
	brick_134 = peach::Scenery(map_x + 420, map_y + 460, 20, 20, 0, 0, (void*) scenery_sheet);
	brick_135 = peach::Scenery(map_x + 440, map_y + 460, 20, 20, 0, 0, (void*) scenery_sheet);
	brick_136 = peach::Scenery(map_x + 460, map_y + 460, 20, 20, 0, 0, (void*) scenery_sheet);

	// terrain 15
	brick_137 = peach::Scenery(map_x + 480, map_y + 320, 20, 20, 40, 0, (void*) scenery_sheet);
	brick_138 = peach::Scenery(map_x + 480, map_y + 340, 20, 20, 40, 0, (void*) scenery_sheet);
	brick_139 = peach::Scenery(map_x + 480, map_y + 360, 20, 20, 40, 0, (void*) scenery_sheet);
	brick_140 = peach::Scenery(map_x + 480, map_y + 380, 20, 20, 40, 0, (void*) scenery_sheet);
	brick_141 = peach::Scenery(map_x + 480, map_y + 400, 20, 20, 40, 0, (void*) scenery_sheet);
	brick_142 = peach::Scenery(map_x + 480, map_y + 420, 20, 20, 40, 0, (void*) scenery_sheet);
	brick_143 = peach::Scenery(map_x + 480, map_y + 440, 20, 20, 40, 0, (void*) scenery_sheet);
	brick_144 = peach::Scenery(map_x + 480, map_y + 460, 20, 20, 40, 0, (void*) scenery_sheet);

	// terrain 16
	brick_145 = peach::Scenery(map_x + 200, map_y + 400, 20, 20, 40, 0, (void*) scenery_sheet);
	brick_146 = peach::Scenery(map_x + 220, map_y + 400, 20, 20, 40, 0, (void*) scenery_sheet);
	brick_147 = peach::Scenery(map_x + 240, map_y + 400, 20, 20, 40, 0, (void*) scenery_sheet);

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
	drawables.push_back(&brick_11);
	drawables.push_back(&brick_12);
	drawables.push_back(&brick_13);
	drawables.push_back(&brick_14);
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
	drawables.push_back(&brick_35);
	drawables.push_back(&brick_36);
	drawables.push_back(&brick_37);
	drawables.push_back(&brick_38);
	drawables.push_back(&brick_39);
	drawables.push_back(&brick_40);
	drawables.push_back(&brick_41);
	drawables.push_back(&brick_42);
	drawables.push_back(&brick_43);
	drawables.push_back(&brick_44);
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
	drawables.push_back(&brick_80);
	drawables.push_back(&brick_81);
	drawables.push_back(&brick_82);
	drawables.push_back(&brick_83);
	drawables.push_back(&brick_84);
	drawables.push_back(&brick_85);
	drawables.push_back(&brick_86);
	drawables.push_back(&brick_87);
	drawables.push_back(&brick_88);
	drawables.push_back(&brick_89);
	drawables.push_back(&brick_90);
	drawables.push_back(&brick_91);
	drawables.push_back(&brick_92);
	drawables.push_back(&brick_93);
	drawables.push_back(&brick_94);
	drawables.push_back(&brick_95);
	drawables.push_back(&brick_96);
	drawables.push_back(&brick_97);
	drawables.push_back(&brick_98);
	drawables.push_back(&brick_99);
	drawables.push_back(&brick_100);
	drawables.push_back(&brick_101);
	drawables.push_back(&brick_102);
	drawables.push_back(&brick_103);
	drawables.push_back(&brick_104);
	drawables.push_back(&brick_105);
	drawables.push_back(&brick_106);
	drawables.push_back(&brick_107);
	drawables.push_back(&brick_108);
	drawables.push_back(&brick_109);
	drawables.push_back(&brick_110);
	drawables.push_back(&brick_111);
	drawables.push_back(&brick_112);
	drawables.push_back(&brick_113);
	drawables.push_back(&brick_114);
	drawables.push_back(&brick_115);
	drawables.push_back(&brick_116);
	drawables.push_back(&brick_117);
	drawables.push_back(&brick_118);
	drawables.push_back(&brick_119);
	drawables.push_back(&brick_120);
	drawables.push_back(&brick_121);
	drawables.push_back(&brick_122);
	drawables.push_back(&brick_123);
	drawables.push_back(&brick_124);
	drawables.push_back(&brick_125);
	drawables.push_back(&brick_126);
	drawables.push_back(&brick_127);
	drawables.push_back(&brick_128);
	drawables.push_back(&brick_129);
	drawables.push_back(&brick_130);
	drawables.push_back(&brick_131);
	drawables.push_back(&brick_132);
	drawables.push_back(&brick_133);
	drawables.push_back(&brick_134);
	drawables.push_back(&brick_135);
	drawables.push_back(&brick_136);
	drawables.push_back(&brick_137);
	drawables.push_back(&brick_138);
	drawables.push_back(&brick_139);
	drawables.push_back(&brick_140);
	drawables.push_back(&brick_141);
	drawables.push_back(&brick_142);
	drawables.push_back(&brick_143);
	drawables.push_back(&brick_144);
	drawables.push_back(&brick_145);
	drawables.push_back(&brick_146);
	drawables.push_back(&brick_147);

//	drawables.push_back(&goal);
	drawables.push_back(player);

}

Level1::~Level1()
{

}

void Level1::Render()
{
	goal.Render();
	
	for (unsigned int i = 0; i < drawables.size(); i++)
		drawables[i]->Render();
	
//	for (unsigned int i = 0; i < collidables.size(); i++)
//		collidables[i]->Render();
}

void Level1::Update()
{
	float x_depth = 0;
	float y_depth = 0;

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

				// goal reached from x direction
				if ((collidables[i]->GetID() == peach::PLAYER && collidables[j]->GetID() == peach::GOAL) || (collidables[i]->GetID() == peach::GOAL && collidables[j]->GetID() == peach::PLAYER))
				{
					if (*state != peach::END)
					{
						//std::cout << "goal reached from the x direction" << std::endl;
						*state = peach::END;
					}
					continue;
				}

				collidables[i]->SetX(collidables[i]->GetX() - x_depth);

				if (player->GetX() < x_min)
				{
					float x_overshoot = x_min - player->GetX();
					for (unsigned int k = 0; k < collidables.size(); k++)
						collidables[k]->SetX(collidables[k]->GetX() + x_overshoot);
					for (unsigned int k = 0; k < drawables.size() - 1; k++)
						drawables[k]->SetX(drawables[k]->GetX() + x_overshoot);
				}
				else if (player->GetX() >= x_max)
				{
					float x_overshoot = player->GetX() - x_max;
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
				// goal reached from y direction
				if ((collidables[i]->GetID() == peach::PLAYER && collidables[j]->GetID() == peach::GOAL) || (collidables[i]->GetID() == peach::GOAL && collidables[j]->GetID() == peach::PLAYER))
				{
					if (*state != peach::END)
					{
						//std::cout << "goal reached from the y direction" << std::endl;
						*state = peach::END;
					}
					continue;
				}

				// resolve vertical collision
				collidables[i]->SetY(collidables[i]->GetY() - y_depth);

				if (player->GetY() < y_min)
				{
					float y_overshoot = y_min - player->GetY();
					for (unsigned int i = 0; i < collidables.size(); i++)
						collidables[i]->SetY(collidables[i]->GetY() + y_overshoot);
					for (unsigned int i = 0; i < drawables.size() - 1; i++)
						drawables[i]->SetY(drawables[i]->GetY() + y_overshoot);
				}
				else if (player->GetY() >= y_max)
				{
					float y_overshoot = player->GetY() - y_max;
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

	if (player->GetX() < x_min)
		player->SetX(x_min);
	else if (player->GetX() > x_max)
		player->SetX(x_max);

	if (player->GetY() > y_max)
		player->SetY(y_max);
	else if (player->GetY() < y_min)
		player->SetY(y_min);

	// horizontal scrolling
	if ((player->GetX() == x_max || player->GetX() == x_min) && player->GetXVel())
	{
		bool scroll_collision = false;
		unsigned int i;
		for (i = 0; i < collidables.size(); i++)
		{
			if (collidables[i]->GetID() != peach::PLAYER)
			{
				collidables[i]->SetX(collidables[i]->GetX() - player->GetXVel());
				if (collidables[i]->CheckCollision(player, x_depth, y_depth) >= 15)
				{
					if (collidables[i]->GetID() != peach::GOAL)
					{
						scroll_collision = true;
						break;
					}
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
					collidables[i]->SetX(collidables[i]->GetX() + player->GetXVel());
				}
			}
			collidables[i]->SetX(collidables[i]->GetX() + player->GetXVel());
			player->SetXVel(0);
		}
		else
		{
			// scenery horizontal scrolling
			for (unsigned int i = 0; i < drawables.size() - 1; i++)
				drawables[i]->SetX(drawables[i]->GetX() - player->GetXVel());
		}
	}
	// vertical scrolling
	if ((player->GetY() == y_max || player->GetY() == y_min) && player->GetYVel())
	{
		bool scroll_collision = false;
		unsigned int i;
		for (i = 0; i < collidables.size(); i++)
		{
			if (collidables[i]->GetID() != peach::PLAYER)
			{
				collidables[i]->SetY(collidables[i]->GetY() - player->GetYVel());
				if (collidables[i]->CheckCollision(player, x_depth, y_depth) >= 15)
				{
					if (collidables[i]->GetID() != peach::GOAL)
					{
						scroll_collision = true;
						break;
					}
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
					collidables[i]->SetY(collidables[i]->GetY() + player->GetYVel());
				}
			}
			collidables[i]->SetY(collidables[i]->GetY() + player->GetYVel());
			player->SetYVel(0);
		}
		else
		{
			// scenery vertical scrolling
			for (unsigned int i = 0; i < drawables.size() - 1; i++)
				drawables[i]->SetY(drawables[i]->GetY() - player->GetYVel());
		}
	}
	// move everything so the player is closer to the middle
	if (player->GetY() != y_scroll_correction && player->GetYVel() == 0)
	{
		float player_y = player->GetY();
		if (player_y > y_scroll_correction)
		{
			if (player_y - 1 < y_scroll_correction)
			{
				for (unsigned int i = 0; i < collidables.size() - 1; i++)
					collidables[i]->SetY(collidables[i]->GetY() - (player->GetY() - y_scroll_correction));
				for (unsigned int i = 0; i < drawables.size() - 1; i++)
					drawables[i]->SetY(drawables[i]->GetY() - (player->GetY() - y_scroll_correction));
				player->SetY(player->GetY() - (player->GetY() - y_scroll_correction));
			}
			else
			{
				for (unsigned int i = 0; i < collidables.size(); i++)
					collidables[i]->SetY(collidables[i]->GetY() - 1);
				for (unsigned int i = 0; i < drawables.size() - 1; i++)
					drawables[i]->SetY(drawables[i]->GetY() - 1);
			}
			if (player->GetY() < y_scroll_correction)
			{
				player_y = player->GetY();
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
					collidables[i]->SetY(collidables[i]->GetY() + (y_scroll_correction - player->GetY()));
				for (unsigned int i = 0; i < drawables.size() - 1; i++)
					drawables[i]->SetY(drawables[i]->GetY() + (y_scroll_correction - player->GetY()));
				player->SetY(player->GetY() - (player->GetY() - y_scroll_correction));
			}
			else
			{
				for (unsigned int i = 0; i < collidables.size(); i++)
					collidables[i]->SetY(collidables[i]->GetY() + 1);
				for (unsigned int i = 0; i < drawables.size() - 1; i++)
					drawables[i]->SetY(drawables[i]->GetY() + 1);
			}
			if (player->GetY() > y_scroll_correction)
			{
				player_y = player->GetY();
				for (unsigned int i = 0; i < collidables.size() - 1; i++)
					collidables[i]->SetY(collidables[i]->GetY() + (y_scroll_correction - player_y));
				for (unsigned int i = 0; i < drawables.size() - 1; i++)
					drawables[i]->SetY(drawables[i]->GetY() + (y_scroll_correction - player_y));
				player->SetY(player->GetY() - (y_scroll_correction - player_y));
			}
		}
	}

} /* Update */

void Level1::Load()
{
	map_x = 240;
	map_y = 280;

	terrain_1.SetX(map_x + 0);
	terrain_2.SetX(map_x + 20);
	terrain_3.SetX(map_x + 480);
	terrain_4.SetX(map_x + 60);
	terrain_5.SetX(map_x + 220);
	terrain_6.SetX(map_x + -100);
	terrain_7.SetX(map_x + -100);
	terrain_8.SetX(map_x + -80);
	terrain_9.SetX(map_x + 140);
	terrain_10.SetX(map_x + 160);
	terrain_11.SetX(map_x + 200);
	terrain_12.SetX(map_x + 140);
	terrain_13.SetX(map_x + 300);
	terrain_14.SetX(map_x + 300);
	terrain_15.SetX(map_x + 480);
	terrain_16.SetX(map_x + 200);

	terrain_1.SetY(map_y + 0);
	terrain_2.SetY(map_y + 140);
	terrain_3.SetY(map_y + 0);
	terrain_4.SetY(map_y + 300);
	terrain_5.SetY(map_y + 260);
	terrain_6.SetY(map_y + 300);
	terrain_7.SetY(map_y + 320);
	terrain_8.SetY(map_y + 460);
	terrain_9.SetY(map_y + 480);
	terrain_10.SetY(map_y + 500);
	terrain_11.SetY(map_y + 540);
	terrain_12.SetY(map_y + 560);
	terrain_13.SetY(map_y + 480);
	terrain_14.SetY(map_y + 460);
	terrain_15.SetY(map_y + 320);
	terrain_16.SetY(map_y + 400);

	brick_1.SetX(map_x + 0);
	brick_2.SetX(map_x + 0);
	brick_3.SetX(map_x + 0);
	brick_4.SetX(map_x + 0);
	brick_5.SetX(map_x + 0);
	brick_6.SetX(map_x + 0);
	brick_7.SetX(map_x + 0);
	brick_8.SetX(map_x + 0);
	brick_9.SetX(map_x + 0);
	brick_10.SetX(map_x + 0);
	brick_11.SetX(map_x + 0);
	brick_12.SetX(map_x + 0);
	brick_13.SetX(map_x + 0);
	brick_14.SetX(map_x + 0);
	brick_15.SetX(map_x + 0);
	brick_16.SetX(map_x + 20);
	brick_17.SetX(map_x + 40);
	brick_18.SetX(map_x + 60);
	brick_19.SetX(map_x + 80);
	brick_20.SetX(map_x + 100);
	brick_21.SetX(map_x + 120);
	brick_22.SetX(map_x + 140);
	brick_23.SetX(map_x + 160);
	brick_24.SetX(map_x + 180);
	brick_25.SetX(map_x + 200);
	brick_26.SetX(map_x + 220);
	brick_27.SetX(map_x + 240);
	brick_28.SetX(map_x + 260);
	brick_29.SetX(map_x + 280);
	brick_30.SetX(map_x + 300);
	brick_31.SetX(map_x + 320);
	brick_32.SetX(map_x + 340);
	brick_33.SetX(map_x + 360);
	brick_34.SetX(map_x + 380);
	brick_35.SetX(map_x + 400);
	brick_36.SetX(map_x + 420);
	brick_37.SetX(map_x + 480);
	brick_38.SetX(map_x + 480);
	brick_39.SetX(map_x + 480);
	brick_40.SetX(map_x + 480);
	brick_41.SetX(map_x + 480);
	brick_42.SetX(map_x + 480);
	brick_43.SetX(map_x + 480);
	brick_44.SetX(map_x + 480);
	brick_45.SetX(map_x + 480);
	brick_46.SetX(map_x + 480);
	brick_47.SetX(map_x + 480);
	brick_48.SetX(map_x + 480);
	brick_49.SetX(map_x + 480);
	brick_50.SetX(map_x + 480);
	brick_51.SetX(map_x + 480);
	brick_52.SetX(map_x + 60);
	brick_53.SetX(map_x + 80);
	brick_54.SetX(map_x + 100);
	brick_55.SetX(map_x + 120);
	brick_56.SetX(map_x + 140);
	brick_57.SetX(map_x + 160);
	brick_58.SetX(map_x + 180);
	brick_59.SetX(map_x + 200);
	brick_60.SetX(map_x + 220);
	brick_61.SetX(map_x + 240);
	brick_62.SetX(map_x + 260);
	brick_63.SetX(map_x + 280);
	brick_64.SetX(map_x + 300);
	brick_65.SetX(map_x + 320);
	brick_66.SetX(map_x + 340);
	brick_67.SetX(map_x + 360);
	brick_68.SetX(map_x + 380);
	brick_69.SetX(map_x + 400);
	brick_70.SetX(map_x + 420);
	brick_71.SetX(map_x + 440);
	brick_72.SetX(map_x + 460);
	brick_73.SetX(map_x + 480);
	brick_74.SetX(map_x + 220);
	brick_75.SetX(map_x + 240);
	brick_76.SetX(map_x + 220);
	brick_77.SetX(map_x + 240);
	brick_78.SetX(map_x - 100);
	brick_79.SetX(map_x - 80);
	brick_80.SetX(map_x - 60);
	brick_81.SetX(map_x - 40);
	brick_82.SetX(map_x - 20);
	brick_83.SetX(map_x - 0);
	brick_84.SetX(map_x - 100);
	brick_85.SetX(map_x - 100);
	brick_86.SetX(map_x - 100);
	brick_87.SetX(map_x - 100);
	brick_88.SetX(map_x - 100);
	brick_89.SetX(map_x - 100);
	brick_90.SetX(map_x - 100);
	brick_91.SetX(map_x - 100);
	brick_92.SetX(map_x - 80);
	brick_93.SetX(map_x - 60);
	brick_94.SetX(map_x - 40);
	brick_95.SetX(map_x - 20);
	brick_96.SetX(map_x - 0);
	brick_97.SetX(map_x + 20);
	brick_98.SetX(map_x + 40);
	brick_99.SetX(map_x + 60);
	brick_100.SetX(map_x + 80);
	brick_101.SetX(map_x + 100);
	brick_102.SetX(map_x + 120);
	brick_103.SetX(map_x + 140);
	brick_104.SetX(map_x + 140);
	brick_105.SetX(map_x + 140);
	brick_106.SetX(map_x + 140);
	brick_107.SetX(map_x + 140);
	brick_108.SetX(map_x + 160);
	brick_109.SetX(map_x + 180);
	brick_110.SetX(map_x + 160);
	brick_111.SetX(map_x + 180);
	brick_112.SetX(map_x + 160);
	brick_113.SetX(map_x + 180);
	brick_114.SetX(map_x + 200);
	brick_115.SetX(map_x + 140);
	brick_116.SetX(map_x + 160);
	brick_117.SetX(map_x + 180);
	brick_118.SetX(map_x + 200);
	brick_119.SetX(map_x + 220);
	brick_120.SetX(map_x + 240);
	brick_121.SetX(map_x + 260);
	brick_122.SetX(map_x + 280);
	brick_123.SetX(map_x + 300);
	brick_124.SetX(map_x + 300);
	brick_125.SetX(map_x + 300);
	brick_126.SetX(map_x + 300);
	brick_127.SetX(map_x + 300);
	brick_128.SetX(map_x + 300);
	brick_129.SetX(map_x + 320);
	brick_130.SetX(map_x + 340);
	brick_131.SetX(map_x + 360);
	brick_132.SetX(map_x + 380);
	brick_133.SetX(map_x + 400);
	brick_134.SetX(map_x + 420);
	brick_135.SetX(map_x + 440);
	brick_136.SetX(map_x + 460);
	brick_137.SetX(map_x + 480);
	brick_138.SetX(map_x + 480);
	brick_139.SetX(map_x + 480);
	brick_140.SetX(map_x + 480);
	brick_141.SetX(map_x + 480);
	brick_142.SetX(map_x + 480);
	brick_143.SetX(map_x + 480);
	brick_144.SetX(map_x + 480);
	brick_145.SetX(map_x + 200);
	brick_146.SetX(map_x + 220);
	brick_147.SetX(map_x + 240);

	brick_1.SetY(map_y + 0);
	brick_2.SetY(map_y + 20);
	brick_3.SetY(map_y + 40);
	brick_4.SetY(map_y + 60);
	brick_5.SetY(map_y + 80);
	brick_6.SetY(map_y + 100);
	brick_7.SetY(map_y + 120);
	brick_8.SetY(map_y + 140);
	brick_9.SetY(map_y + 160);
	brick_10.SetY(map_y + 180);
	brick_11.SetY(map_y + 200);
	brick_12.SetY(map_y + 220);
	brick_13.SetY(map_y + 240);
	brick_14.SetY(map_y + 260);
	brick_15.SetY(map_y + 280);
	brick_16.SetY(map_y + 140);
	brick_17.SetY(map_y + 140);
	brick_18.SetY(map_y + 140);
	brick_19.SetY(map_y + 140);
	brick_20.SetY(map_y + 140);
	brick_21.SetY(map_y + 140);
	brick_22.SetY(map_y + 140);
	brick_23.SetY(map_y + 140);
	brick_24.SetY(map_y + 140);
	brick_25.SetY(map_y + 140);
	brick_26.SetY(map_y + 140);
	brick_27.SetY(map_y + 140);
	brick_28.SetY(map_y + 140);
	brick_29.SetY(map_y + 140);
	brick_30.SetY(map_y + 140);
	brick_31.SetY(map_y + 140);
	brick_32.SetY(map_y + 140);
	brick_33.SetY(map_y + 140);
	brick_34.SetY(map_y + 140);
	brick_35.SetY(map_y + 140);
	brick_36.SetY(map_y + 140);
	brick_37.SetY(map_y + 0);
	brick_38.SetY(map_y + 20);
	brick_39.SetY(map_y + 40);
	brick_40.SetY(map_y + 60);
	brick_41.SetY(map_y + 80);
	brick_42.SetY(map_y + 100);
	brick_43.SetY(map_y + 120);
	brick_44.SetY(map_y + 140);
	brick_45.SetY(map_y + 160);
	brick_46.SetY(map_y + 180);
	brick_47.SetY(map_y + 200);
	brick_48.SetY(map_y + 220);
	brick_49.SetY(map_y + 240);
	brick_50.SetY(map_y + 260);
	brick_51.SetY(map_y + 280);
	brick_52.SetY(map_y + 300);
	brick_53.SetY(map_y + 300);
	brick_54.SetY(map_y + 300);
	brick_55.SetY(map_y + 300);
	brick_56.SetY(map_y + 300);
	brick_57.SetY(map_y + 300);
	brick_58.SetY(map_y + 300);
	brick_59.SetY(map_y + 300);
	brick_60.SetY(map_y + 300);
	brick_61.SetY(map_y + 300);
	brick_62.SetY(map_y + 300);
	brick_63.SetY(map_y + 300);
	brick_64.SetY(map_y + 300);
	brick_65.SetY(map_y + 300);
	brick_66.SetY(map_y + 300);
	brick_67.SetY(map_y + 300);
	brick_68.SetY(map_y + 300);
	brick_69.SetY(map_y + 300);
	brick_70.SetY(map_y + 300);
	brick_71.SetY(map_y + 300);
	brick_72.SetY(map_y + 300);
	brick_73.SetY(map_y + 300);
	brick_74.SetY(map_y + 260);
	brick_75.SetY(map_y + 260);
	brick_76.SetY(map_y + 280);
	brick_77.SetY(map_y + 280);
	brick_78.SetY(map_y + 300);
	brick_79.SetY(map_y + 300);
	brick_80.SetY(map_y + 300);
	brick_81.SetY(map_y + 300);
	brick_82.SetY(map_y + 300);
	brick_83.SetY(map_y + 300);
	brick_84.SetY(map_y + 320);
	brick_85.SetY(map_y + 340);
	brick_86.SetY(map_y + 360);
	brick_87.SetY(map_y + 380);
	brick_88.SetY(map_y + 400);
	brick_89.SetY(map_y + 420);
	brick_90.SetY(map_y + 440);
	brick_91.SetY(map_y + 460);
	brick_92.SetY(map_y + 460);
	brick_93.SetY(map_y + 460);
	brick_94.SetY(map_y + 460);
	brick_95.SetY(map_y + 460);
	brick_96.SetY(map_y + 460);
	brick_97.SetY(map_y + 460);
	brick_98.SetY(map_y + 460);
	brick_99.SetY(map_y + 460);
	brick_100.SetY(map_y + 460);
	brick_101.SetY(map_y + 460);
	brick_102.SetY(map_y + 460);
	brick_103.SetY(map_y + 460);
	brick_104.SetY(map_y + 480);
	brick_105.SetY(map_y + 500);
	brick_106.SetY(map_y + 520);
	brick_107.SetY(map_y + 540);
	brick_108.SetY(map_y + 500);
	brick_109.SetY(map_y + 500);
	brick_110.SetY(map_y + 520);
	brick_111.SetY(map_y + 520);
	brick_112.SetY(map_y + 540);
	brick_113.SetY(map_y + 540);
	brick_114.SetY(map_y + 540);
	brick_115.SetY(map_y + 560);
	brick_116.SetY(map_y + 560);
	brick_117.SetY(map_y + 560);
	brick_118.SetY(map_y + 560);
	brick_119.SetY(map_y + 560);
	brick_120.SetY(map_y + 560);
	brick_121.SetY(map_y + 560);
	brick_122.SetY(map_y + 560);
	brick_123.SetY(map_y + 560);
	brick_124.SetY(map_y + 480);
	brick_125.SetY(map_y + 500);
	brick_126.SetY(map_y + 520);
	brick_127.SetY(map_y + 540);
	brick_128.SetY(map_y + 460);
	brick_129.SetY(map_y + 460);
	brick_130.SetY(map_y + 460);
	brick_131.SetY(map_y + 460);
	brick_132.SetY(map_y + 460);
	brick_133.SetY(map_y + 460);
	brick_134.SetY(map_y + 460);
	brick_135.SetY(map_y + 460);
	brick_136.SetY(map_y + 460);
	brick_137.SetY(map_y + 320);
	brick_138.SetY(map_y + 340);
	brick_139.SetY(map_y + 360);
	brick_140.SetY(map_y + 380);
	brick_141.SetY(map_y + 400);
	brick_142.SetY(map_y + 420);
	brick_143.SetY(map_y + 440);
	brick_144.SetY(map_y + 460);
	brick_145.SetY(map_y + 400);
	brick_146.SetY(map_y + 400);
	brick_147.SetY(map_y + 400);

	goal.SetX(map_x + 360);
	goal.SetY(map_y + 420);
}

} /* namespace peach */
