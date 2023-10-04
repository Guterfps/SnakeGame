
DCC = g++ -std=c++11 -pedantic-errors -Wall -Wextra -g
RCC = g++ -std=c++11 -pedantic-errors -Wall -Wextra -DNDEBUG -O3
ZCC = zig c++ -std=c++11 -pedantic-errors -Wall -Wextra -DNDEBUG -O3
TARGET = -target x86_64-windows
FILES = main.cpp game.cpp board.cpp snake.cpp controler.cpp
RAYLIB = ../raylib/src
LIBS = /usr/lib/x86_64-linux-gnu

debug: $(FILES)
	$(DCC) $(FILES) -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -o snake.out
        
realese: $(FILES)
	$(RCC) $(FILES) -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -o snake.out   

zig: $(FILES)
	$(ZCC) $(FILES) -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -o snake.out

cross: $(FILES)
	$(ZCC) $(TARGET) $(FILES) -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 \
	-L$(RAYLIB) -L$(LIBS) -I$(RAYLIB) -o snake.exe