.PHONY: clean all run list

all: t check.dylib

clean:
	rm -rf t check.dylib

run: t check.dylib
	./t

list:
	ls -lrt

t: t.c
	gcc -o t t.c

check.dylib: check.v
	v -freestanding -shared -no-builtin -gc none check.v
