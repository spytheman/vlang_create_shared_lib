import os
import dl
type FNAdder = fn (u64, u64) u64
library_file_path := os.join_path(os.dir(@FILE), dl.get_libname('check'))
handle := dl.open_opt(library_file_path, dl.rtld_now)!
f := FNAdder(dl.sym_opt(handle, 'check__add')!)
dump(f(123,456))
