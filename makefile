
DCC = g++ -std=c++11 -pedantic-errors -Wall -Wextra -g
RCC = g++ -std=c++11 -pedantic-errors -Wall -Wextra -DNDEBUG -O3
FILES = main.cpp game.cpp board.cpp snake.cpp controler.cpp

debug: $(FILES)
	$(DCC) $(FILES) -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -o snake.out
        
realese: $(FILES)
	$(RCC) $(FILES) -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -o snake.out   
