all: SOKOBAN.c
	./SOKOBAN
	
SOKOBAN:
	gcc -o SOKOBAN SOKOBAN.c -Wall -luvsqgraphics `sdl-config --libs` -lm -lSDL_ttf
	
clean:
	rm -f SOKOBAN.o
