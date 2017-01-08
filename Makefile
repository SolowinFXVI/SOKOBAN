CFLAGS=-c	-g	-Wall

all:	sokoban
	./sokoban	sasquatch1.xsb

test: *
	make	clean	&&	make	compil && ./sokoban -n	8	sasquatch1.xsb

creation: sokoban
	./sokoban -c	niveau_cree.xsb

compil: sokoban
	make	sokoban

sokoban: sokoban.o	affichage.o	action.o	lecture.o	stack.o	creationNiveau.o
	gcc	-o	sokoban	sokoban.o	affichage.o	action.o	lecture.o	stack.o	creationNiveau.o -luvsqgraphics `sdl-config --libs` -lm -lSDL_ttf

sokoban.o: sokoban.c	sokoban.h	constantes.h	creationNiveau.h	lecture.h	affichage.h
	gcc $(CFLAGS) sokoban.c

affichage.o: affichage.c	affichage.h	sokoban.h	constantes.h	action.h	lecture.h
	gcc $(CFLAGS) `sdl-config --cflags` affichage.c

action.o: action.c	action.h	constantes.h	stack.h	sokoban.h
	gcc $(CFLAGS) `sdl-config --cflags` action.c

lecture.o: lecture.c	lecture.h	sokoban.h	constantes.h
	gcc $(CFLAGS) lecture.c

stack.o: constantes.h	sokoban.o	stack.h	stack.c
	gcc $(CFLAGS) stack.c

creationNiveau.o:	constantes.h	sokoban.h	creationNiveau.h	creationNiveau.c
	gcc $(CFLAGS) `sdl-config --cflags` creationNiveau.c

clean:
	rm -f	sokoban
	rm -f	sokoban.o
	rm -f	affichage.o
	rm -f	lecture.o
	rm -f	action.o
	rm -f	stack.o
	rm -f	creationNiveau.o
