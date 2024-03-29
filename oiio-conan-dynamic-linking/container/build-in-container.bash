#!/bin/bash

export PATH="/opt/venv/bin:$PATH"

cd /workingdir

conan remote add -t local-recipes-index cci-mirror "/workingdir/conan-center-index"
conan remote remove conancenter
conan profile detect

conan install . --build=missing

cd build/Release
cmake ../.. --preset conan-release

# Implicitly run a bash to continue investigation if needed etc.
/bin/bash
