COMP= gcc -c -g -Wall `sdl-config --cflags` $<

run: slider

test: slider
	./slider dir_slider

# Edition de liens
slider: main.o read_write.o display.o move.o undo.o custom.o message.o
	gcc $^ -o slider -luvsqgraphics `sdl-config --libs` -lm -lSDL_ttf

# Compilation des fichiers
%.o: %.c %.h
	$(COMP)

# Ouverture des fichiers
open:
	geany Makefile *.c *.h &

# Organisation des fichiers
indent:
	indent -linux *.c

clean:
	rm -rf *.o
	rm -rf slider
