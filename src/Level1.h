#ifndef LEVEL1_H_
#define LEVEL1_H_

#include "peach_base.h"
#include "IDrawable.h"
#include "Entity.h"
#include "Player.h"
#include "Terrain.h"
#include "Scenery.h"

namespace peach
{

class Level1: public IDrawable
{
private:
	void* player_sheet;
	void* scenery_sheet;
	peach::Player* player;
	std::vector<peach::Entity*> collidables;
	std::vector<peach::Entity*> drawables;
	int x_min;
	int x_max;
	int y_min;
	int y_max;
	int y_scroll_correction;

	peach::Terrain terrain_1;
	peach::Terrain terrain_2;
	peach::Terrain terrain_3;
	peach::Terrain terrain_4;
	peach::Terrain terrain_5;
	peach::Terrain terrain_6;
	peach::Terrain terrain_7;
	peach::Terrain terrain_8;
	peach::Terrain terrain_9;
	peach::Terrain terrain_10;
	peach::Terrain terrain_11;
	peach::Terrain terrain_12;
	peach::Terrain terrain_13;
	peach::Terrain terrain_14;
	peach::Terrain terrain_15;
	peach::Terrain terrain_16;

	peach::Entity goal;

	peach::Scenery brick_1;
	peach::Scenery brick_2;
	peach::Scenery brick_3;
	peach::Scenery brick_4;
	peach::Scenery brick_5;
	peach::Scenery brick_6;
	peach::Scenery brick_7;
	peach::Scenery brick_8;
	peach::Scenery brick_9;

	peach::Scenery brick_10;

	// left
	peach::Scenery brick_11;
	peach::Scenery brick_12;
	peach::Scenery brick_13;
	peach::Scenery brick_14;

	// right
	peach::Scenery brick_15;
	peach::Scenery brick_16;
	peach::Scenery brick_17;
	peach::Scenery brick_18;
	peach::Scenery brick_19;
	peach::Scenery brick_20;
	peach::Scenery brick_21;
	peach::Scenery brick_22;
	peach::Scenery brick_23;
	peach::Scenery brick_24;

	// upper middle
	peach::Scenery brick_25;
	peach::Scenery brick_26;
	peach::Scenery brick_27;
	peach::Scenery brick_28;
	peach::Scenery brick_29;
	peach::Scenery brick_30;
	peach::Scenery brick_31;
	peach::Scenery brick_32;
	peach::Scenery brick_33;
	peach::Scenery brick_34;

	// upper right
	peach::Scenery brick_35;
	peach::Scenery brick_36;
	peach::Scenery brick_37;
	peach::Scenery brick_38;
	peach::Scenery brick_39;

	// upper upper right
	peach::Scenery brick_40;
	peach::Scenery brick_41;
	peach::Scenery brick_42;
	peach::Scenery brick_43;
	peach::Scenery brick_44;

	// floor
	peach::Scenery brick_45;
	peach::Scenery brick_46;
	peach::Scenery brick_47;
	peach::Scenery brick_48;
	peach::Scenery brick_49;
	peach::Scenery brick_50;
	peach::Scenery brick_51;
	peach::Scenery brick_52;
	peach::Scenery brick_53;
	peach::Scenery brick_54;
	peach::Scenery brick_55;
	peach::Scenery brick_56;
	peach::Scenery brick_57;
	peach::Scenery brick_58;
	peach::Scenery brick_59;
	peach::Scenery brick_60;
	peach::Scenery brick_61;
	peach::Scenery brick_62;
	peach::Scenery brick_63;
	peach::Scenery brick_64;
	peach::Scenery brick_65;
	peach::Scenery brick_66;
	peach::Scenery brick_67;
	peach::Scenery brick_68;
	peach::Scenery brick_69;
	peach::Scenery brick_70;
	peach::Scenery brick_71;
	peach::Scenery brick_72;
	peach::Scenery brick_73;
	peach::Scenery brick_74;
	peach::Scenery brick_75;
	peach::Scenery brick_76;
	peach::Scenery brick_77;
	peach::Scenery brick_78;
	peach::Scenery brick_79;

	peach::Scenery brick_80;
	peach::Scenery brick_81;
	peach::Scenery brick_82;
	peach::Scenery brick_83;
	peach::Scenery brick_84;

	peach::Scenery brick_85;
	peach::Scenery brick_86;
	peach::Scenery brick_87;
	peach::Scenery brick_88;
	peach::Scenery brick_89;
	peach::Scenery brick_90;
	peach::Scenery brick_91;
	peach::Scenery brick_92;
	peach::Scenery brick_93;
	peach::Scenery brick_94;
	peach::Scenery brick_95;
	peach::Scenery brick_96;
	peach::Scenery brick_97;
	peach::Scenery brick_98;
	peach::Scenery brick_99;
	peach::Scenery brick_100;
	peach::Scenery brick_101;
	peach::Scenery brick_102;
	peach::Scenery brick_103;
	peach::Scenery brick_104;
	peach::Scenery brick_105;
	peach::Scenery brick_106;
	peach::Scenery brick_107;
	peach::Scenery brick_108;
	peach::Scenery brick_109;
	peach::Scenery brick_110;
	peach::Scenery brick_111;
	peach::Scenery brick_112;
	peach::Scenery brick_113;
	peach::Scenery brick_114;
	peach::Scenery brick_115;
	peach::Scenery brick_116;
	peach::Scenery brick_117;
	peach::Scenery brick_118;
	peach::Scenery brick_119;
	peach::Scenery brick_120;
	peach::Scenery brick_121;
	peach::Scenery brick_122;
	peach::Scenery brick_123;
	peach::Scenery brick_124;
	peach::Scenery brick_125;
	peach::Scenery brick_126;
	peach::Scenery brick_127;
	peach::Scenery brick_128;
	peach::Scenery brick_129;
	peach::Scenery brick_130;
	peach::Scenery brick_131;
	peach::Scenery brick_132;
	peach::Scenery brick_133;
	peach::Scenery brick_134;
	peach::Scenery brick_135;
	peach::Scenery brick_136;
	peach::Scenery brick_137;
	peach::Scenery brick_138;
	peach::Scenery brick_139;
	peach::Scenery brick_140;
	peach::Scenery brick_141;
	peach::Scenery brick_142;
	peach::Scenery brick_143;
	peach::Scenery brick_144;
	peach::Scenery brick_145;
	peach::Scenery brick_146;
	peach::Scenery brick_147;


	int status; // for things like whether or not the goal has been reached
	int* state;

	int map_x;
	int map_y;

public:
	Level1();
	Level1(void* player_sheet, void* scenery_sheet, peach::Player* player, int* state);
	virtual ~Level1();
	void Render();
	void Update();
	void Load();
};

} /* namespace peach */

#endif /* LEVEL1_H_ */
