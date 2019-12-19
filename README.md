# doctest_linker_issue

This is sample code that makes a linker error (at least in macOS) when compiling using doctest.

The test itself is not that useful as is just checking the return value of a constant.

  * Requires meson and ninja

## Building  
  1. meson build
  1. ninja -C build
  
## Sample output
```
FAILED: doctest_issue 
c++  -o doctest_issue 'doctest_issue@exe/issue.cpp.o' -Wl,-dead_strip_dylibs -Wl,-undefined,error -Wl,-headerpad_max_install_names
Undefined symbols for architecture x86_64:
  "has_is_option<good_is_opt>::value", referenced from:
      _DOCTEST_ANON_FUNC_6() in issue.cpp.o
ld: symbol(s) not found for architecture x86_64
```
