SRC=src/main.cpp src/Entity.cpp src/Terrain.cpp src/Player.cpp

all:
	g++ $(SRC) -o PeachSmith -L. -I. -lallegro-5.0.10-monolith-md -mwindows
