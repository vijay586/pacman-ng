SRC = main.c opengl-render.c ground.c glut-extra.c wall.c bille.c man.c
OUTPUT = pacman

all:
	cd src && gcc -o ../$(OUTPUT) $(SRC) -g3 -Wall -Werror `pkg-config --libs --cflags cairo` -lglut

clean:
	rm -rf $(OUTPUT)

count:
	wc -l src/*

run:
	./$(OUTPUT)
