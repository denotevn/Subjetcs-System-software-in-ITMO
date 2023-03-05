all: lib

exe: solution.c lib
	gcc main.c -fPIC -L. -lsolution -o solution

lib: solution.c
	gcc -shared solution.c -fPIC -o libsolution.so
	gcc -L. -lsolution main.c -o main

clean:
	-rm solution libsolution.so 2>/dev/null
