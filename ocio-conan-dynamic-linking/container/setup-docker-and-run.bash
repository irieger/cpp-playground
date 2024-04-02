#!/bin/bash

set -e

docker build -t ocio-experiment container
docker run \
    --mount "type=bind,source=$(pwd),target=/workingdir" \
    --rm \
    -it \
    ocio-experiment \
    /workingdir/container/build-in-container.bash
