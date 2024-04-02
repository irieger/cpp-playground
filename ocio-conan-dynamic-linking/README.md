# Sample project to demonstrate OCIO linking problems when building shared

Building OCIO and all its dependencies as shared libraries creates linker problems when
the OCIO tools are build.

Uses a folder based conan repository instead of the official conan-center-index, as there the recipe
is currently preventing a shared build.

Here is an excerpt of the compiler errors:

```
...
[ 94%] Linking CXX executable ociobakelut
cd /root/.conan2/p/b/opencd957e7467fe7e/b/build/Release/src/apps/ociobakelut && /root/.conan2/p/b/cmakefe01bc8c43d70/p/bin/cmake -E cmake_link_script CMakeFiles/ociobakelut.dir/link.txt --verbose=1
/usr/bin/c++ -m64 -O3 -DNDEBUG -m64 CMakeFiles/ociobakelut.dir/main.cpp.o CMakeFiles/ociobakelut.dir/ocioicc.cpp.o -o ociobakelut   -L/root/.conan2/p/b/lcms7be26a6086867/p/lib  -Wl,-rpath,/root/.conan2/p/b/lcms7be26a6086867/p/lib:/root/.conan2/p/b/opencd957e7467fe7e/b/build/Release/src/OpenColorIO:/root/.conan2/p/b/pystr9d85aec3c53c7/p/lib: ../../apputils/libapputils.a ../../OpenColorIO/libOpenColorIO.so.2.3.2 /root/.conan2/p/b/pystr9d85aec3c53c7/p/lib/libpystring.so /root/.conan2/p/b/lcms7be26a6086867/p/lib/liblcms2.so -lm -lpthread
/usr/bin/ld: warning: libiconv.so.2, needed by /root/.conan2/p/b/minizbbeb350604d43/p/lib/libminizip-ng.so.4, not found (try using -rpath or -rpath-link)
/usr/bin/ld: warning: libiconv.so.2, needed by /root/.conan2/p/b/minizbbeb350604d43/p/lib/libminizip-ng.so.4, not found (try using -rpath or -rpath-link)
cd /root/.conan2/p/b/opencd957e7467fe7e/b/build/Release/src/apps/ocioarchive && /usr/bin/strip /root/.conan2/p/b/opencd957e7467fe7e/b/build/Release/src/apps/ocioarchive/ocioarchive
[ 95%] Linking CXX executable ociochecklut
cd /root/.conan2/p/b/opencd957e7467fe7e/b/build/Release/src/apps/ociochecklut && /root/.conan2/p/b/cmakefe01bc8c43d70/p/bin/cmake -E cmake_link_script CMakeFiles/ociochecklut.dir/link.txt --verbose=1
/usr/bin/c++ -m64 -O3 -DNDEBUG -m64 CMakeFiles/ociochecklut.dir/main.cpp.o -o ociochecklut  -Wl,-rpath,/root/.conan2/p/b/opencd957e7467fe7e/b/build/Release/src/OpenColorIO:/root/.conan2/p/b/pystr9d85aec3c53c7/p/lib: ../../apputils/libapputils.a ../../OpenColorIO/libOpenColorIO.so.2.3.2 /root/.conan2/p/b/pystr9d85aec3c53c7/p/lib/libpystring.so
gmake[2]: Leaving directory '/root/.conan2/p/b/opencd957e7467fe7e/b/build/Release'
[ 95%] Built target ocioarchive
/usr/bin/ld: /root/.conan2/p/b/minizbbeb350604d43/p/lib/libminizip-ng.so.4: undefined reference to `libiconv_open'
/usr/bin/ld: /root/.conan2/p/b/minizbbeb350604d43/p/lib/libminizip-ng.so.4: undefined reference to `libiconv_close'
/usr/bin/ld: /root/.conan2/p/b/minizbbeb350604d43/p/lib/libminizip-ng.so.4: undefined reference to `libiconv'
collect2: error: ld returned 1 exit status
gmake[2]: *** [src/apps/ociowrite/CMakeFiles/ociowrite.dir/build.make:103: src/apps/ociowrite/ociowrite] Error 1
gmake[2]: Leaving directory '/root/.conan2/p/b/opencd957e7467fe7e/b/build/Release'
gmake[1]: *** [CMakeFiles/Makefile2:1422: src/apps/ociowrite/CMakeFiles/ociowrite.dir/all] Error 2
gmake[1]: *** Waiting for unfinished jobs....
/usr/bin/ld: /root/.conan2/p/b/minizbbeb350604d43/p/lib/libminizip-ng.so.4: undefined reference to `libiconv_open'
/usr/bin/ld: /root/.conan2/p/b/minizbbeb350604d43/p/lib/libminizip-ng.so.4: undefined reference to `libiconv_close'
/usr/bin/ld: /root/.conan2/p/b/minizbbeb350604d43/p/lib/libminizip-ng.so.4: undefined reference to `libiconv'
collect2: error: ld returned 1 exit status
gmake[2]: *** [src/apps/ociobakelut/CMakeFiles/ociobakelut.dir/build.make:120: src/apps/ociobakelut/ociobakelut] Error 1
gmake[2]: Leaving directory '/root/.conan2/p/b/opencd957e7467fe7e/b/build/Release'
gmake[1]: *** [CMakeFiles/Makefile2:1287: src/apps/ociobakelut/CMakeFiles/ociobakelut.dir/all] Error 2
...
```

To build & run inside docker, with docker readily installed, execute starting in this
`ocio-conan-dynamic-linking` folder:
```
./container/setup-docker-and-run.bash
```
