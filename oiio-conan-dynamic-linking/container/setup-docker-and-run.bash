#!/bin/bash

set -e

docker build -t oiio-experiment container
docker run \
    --mount "type=bind,source=$(pwd),target=/workingdir" \
    --rm \
    -it \
    oiio-experiment \
    /workingdir/container/build-in-container.bash
