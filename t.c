#include <dlfcn.h>
#include <stdint.h>
#include <stdio.h>

int main() {
  const char *library_path =
      "/Users/delyanangelov/code/misc/2024_12_25__09/check.dylib";
  void *lib = dlopen(library_path, RTLD_NOW);
  if (lib == NULL) {
    fprintf(stderr, "ERROR: could not load %s . error: %s\n", library_path,
            dlerror());
    return 1;
  }
  printf("INFO: %s OK\n", library_path);
  uint64_t (*add_fn)(uint64_t, uint64_t) = dlsym(lib, "check__add");
  if (add_fn == NULL) {
    fprintf(
        stderr,
        "ERROR: check_add could not be found in shared library. error: %s\n",
        dlerror());
    return 1;
  }
  uint64_t a, b, c;
  a = 123;
  b = 456;
  c = add_fn(a, b);
  printf("     a: %llu\n", a);
  printf("     b: %llu\n", b);
  printf("     c: %llu\n", c);
  return 0;
}