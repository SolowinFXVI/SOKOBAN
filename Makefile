CFLAGS=-c	-g	-Wall

all:	sokoban
	./sokoban

sokoban: sokoban.o	affichage.o action.o lecture_ecriture.o stack.o
	gcc	-o sokoban sokoban.o affichage.o action.o lecture_ecriture.o stack.o -luvsqgraphics `sdl-config --libs` -lm -lSDL_ttf

sokoban.o: sokoban.c sokoban.h constantes.h
	gcc $(CFLAGS) sokoban.c

affichage.o: affichage.c affichage.h sokoban.h constantes.h
	gcc $(CFLAGS) `sdl-config --cflags` affichage.c

action.o: action.c action.h constantes.h
		gcc $(CFLAGS) `sdl-config --cflags` action.c

lecture_ecriture.o: lecture_ecriture.c lecture_ecriture.h sokoban.h constantes.h
		gcc $(CFLAGS) lecture_ecriture.c

stack.o: constantes.h sokoban.o stack.h stack.c
	gcc $(CFLAGS) stack.c

clean:
	rm -f sokoban
	rm -f sokoban.o
	rm -f affichage.o
	rm -f lecture_ecriture.o
	rm -f action.o
	rm -f stack.o
