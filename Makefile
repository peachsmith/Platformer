SRC=src/main.cpp src/Entity.cpp src/Terrain.cpp src/Player.cpp src/HitBox.cpp src/Scenery.cpp src/Menu.cpp src/MenuItem.cpp src/MenuCursor.cpp src/pxp.cpp src/Level1.cpp

all:
	g++ $(SRC) -O3 -o PeachSmith -L. -I. -lallegro-5.0.10-monolith-md -mwindows

linux:
	g++ $(SRC) -O3 -o PeachSmith `pkg-config --libs allegro-5.0 allegro_primitives-5.0 allegro_image-5.0 allegro_font-5.0 allegro_ttf-5.0`
