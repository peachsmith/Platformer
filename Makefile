SRC=src/main.cpp src/Entity.cpp src/Terrain.cpp src/Player.cpp src/HitBox.cpp src/Scenery.cpp src/Menu.cpp src/MenuItem.cpp src/MenuCursor.cpp src/pxp.cpp src/Level1.cpp

all:
	g++ $(SRC) -o PeachSmith -L. -I. -lallegro-5.0.10-monolith-md -mwindows
