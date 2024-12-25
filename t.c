#include <stdio.h>
#include <dlfcn.h>

int main(){
   const char *library_path = "/Users/delyanangelov/code/misc/2024_12_25__09/check.dylib";
   void *lib = dlopen(library_path, RTLD_NOW);
   if(lib==NULL){
      fprintf(stderr, "ERROR: could not load %s . error: %s\n", library_path, dlerror());
      return 1;
   }
   printf("INFO: %s OK\n", library_path);
   return 0;
}