# Conan Linux dynamic linking problem example

This intends to demonstrate problems when building dynamicly linked projects with Conan on Linux.
Linking fails due to missing shared libraries that are nested.

(Code also tested on macOS where it builds without resulting in the same linking errors.)

It uses OpenImageIO as this is a library with a number of nested dependencies that I have experience with. To get all dependencies properly building
with shared=True, a branch with a fix for shared building of OpenColorIO is used with the new feature to use a local conan-center-index checkout
as the "remote".

For faster builds in the `conan install` step, the conanfile deactivates a few of the file formats OIIO supports.

**This needs conan>=2.1**


## Comparison: Build on macOS

This intentionally creates a clean (assuming the directory used isn't preexisting) conan home & assigns only the local CCI copy to ensure we get the intended state of everything build.

Working directory is the directory containg this readme.

```
export CONAN_HOME='${HOME}/.conan2_oiio-experiment'
conan remote add -t local-recipes-index cci-mirror "$(pwd)/conan-center-index"
conan remote remove conancenter
conan profile detect
conan install . --build=missing
cmake . --preset conan-release
cd build/Release
cmake --build . -j
```
