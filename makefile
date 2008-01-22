OUTPUT = pacman

all:
	gcc -o $(OUTPUT) src/*.c -g3 -Wall -Werror `pkg-config --libs --cflags cairo` -lglut

clean:
	rm -rf $(OUTPUT)

count:
	wc -l src/*

run:
	./$(OUTPUT)
