Running on macos:
=====================

```sh
make clean all run list
```
... produces:
```
rm -rf t check.dylib
v -prod -freestanding -shared -no-builtin -gc none check.v
gcc -o t t.c
./t
INFO: /Users/delyanangelov/code/misc/2024_12_25__09/check.dylib OK
     a: 123
     b: 456
     c: 579
VQUIET=1 v -prod -gc none run load_check.v
ls -lrt
total 336
-rw-r--r--  1 delyanangelov  staff     62 Dec 25 09:07 check.v
-rw-r--r--  1 delyanangelov  staff    800 Dec 25 09:33 t.c
-rw-r--r--  1 delyanangelov  staff    247 Dec 25 09:38 load_check.v
-rw-r--r--@ 1 delyanangelov  staff    266 Dec 25 09:46 Makefile
-rw-r--r--@ 1 delyanangelov  staff   1071 Dec 25 09:50 LICENSE
-rwxr-xr-x  1 delyanangelov  staff  16792 Dec 25 09:51 check.dylib
-rwxr-xr-x  1 delyanangelov  staff  33648 Dec 25 09:51 t
-rwxr-xr-x  1 delyanangelov  staff  86136 Dec 25 09:51 load_check
-rw-r--r--  1 delyanangelov  staff    251 Dec 25 09:51 README.md
[load_check.v:7] f(123, 456): 579
```
