.PHONY: clean all run list

all: check.dylib t

clean:
	rm -rf t check.dylib

run: t check.dylib
	./t
	VQUIET=1 v -prod -gc none run load_check.v

list:
	ls -lrt

t: t.c
	gcc -o t t.c

check.dylib: check.v
	v -prod -freestanding -shared -no-builtin -gc none check.v
