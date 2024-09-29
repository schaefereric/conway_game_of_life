CC = g++
CFLAGS =
DEBUG_OPTION = -Wall -g
CPP_STANDARD = -std=c++20
SRC_DIR = /src

all: linux

linux: conwaygame

clean:
	rm -rf build/*.o

makedir:
	mkdir -p build

conwaygame: makedir main.o flexible_array.o gamestate_t.o grid.o guimaster_t.o logic.o mouse_tools.o timer.o
	 $(CC) $(CFLAGS) $(CPP_STANDARD) build/main.o build/flexible_array.o build/gamestate_t.o build/grid.o build/guimaster_t.o build/logic.o build/mouse_tools.o build/timer.o -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -o conwaygame

main.o: src/main.cpp
	$(CC) $(CFLAGS) $(CPP_STANDARD) -c src/main.cpp -o build/main.o

flexible_array.o: src/flexible_array.cpp src/flexible_array.hpp
	$(CC) $(CFLAGS) $(CPP_STANDARD) -c src/flexible_array.cpp -o build/flexible_array.o

gamestate_t.o: src/gamestate_t.cpp src/gamestate_t.hpp
	$(CC) $(CFLAGS) $(CPP_STANDARD) -c src/gamestate_t.cpp -o build/gamestate_t.o

grid.o: src/grid.cpp src/grid.hpp
	$(CC) $(CFLAGS) $(CPP_STANDARD) -c src/grid.cpp -o build/grid.o

guimaster_t.o: src/guimaster_t.cpp src/guimaster_t.hpp
	$(CC) $(CFLAGS) $(CPP_STANDARD) -c src/guimaster_t.cpp -o build/guimaster_t.o

logic.o: src/logic.cpp src/logic.hpp
	$(CC) $(CFLAGS) $(CPP_STANDARD) -c src/logic.cpp -o build/logic.o

mouse_tools.o: src/mouse_tools.cpp src/mouse_tools.hpp
	$(CC) $(CFLAGS) $(CPP_STANDARD) -c src/mouse_tools.cpp -o build/mouse_tools.o

timer.o: src/timer.cpp src/timer.hpp
	$(CC) $(CFLAGS) $(CPP_STANDARD) -c src/timer.cpp -o build/timer.o
