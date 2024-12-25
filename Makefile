.PHONY: clean all

all: t check.dylib

clean:
	rm -rf t check.dylib

t: t.c
	gcc -o t t.c

check.dylib: check.v
	v -shared -no-builtin -gc none check.v
