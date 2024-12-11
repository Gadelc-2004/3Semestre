all: clean
	gcc -c -Wall ./src/retangulo.c -I ./include/ -o ./obj/retangulo.o
	gcc -Wall ./apps/main.c ./obj/retangulo.o -I ./include/ -o ./bin/main
	tree

debug:
	gcc -Wall ./apps/main.c ./src/retangulo.c -I ./include/ -o ./src/debug/main_debug
	tree

run:
	./bin/main

debug_run:
	gdb ./src/debug/main_debug

clean:
	rm -rf ./bin/main
	rm -rf ./obj/*.o
	rm -rf ./src/debug/main_debug
