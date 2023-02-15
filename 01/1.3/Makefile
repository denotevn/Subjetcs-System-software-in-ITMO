all: exe lib

exe: main.c solution.h lib
	gcc main.c -fPIC -ldl -o solution

lib: solution.c solution.h
	gcc -shared solution.c -fPIC -o libsolution.so

clean:
	-rm solution libsolution.so 2>/dev/null
