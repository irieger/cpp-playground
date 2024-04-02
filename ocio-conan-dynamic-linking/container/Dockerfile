# Download base image ubuntu 22.04
FROM ubuntu:22.04

# Update Ubuntu Software repository
RUN apt update
RUN apt upgrade -y

# Install build deps
RUN apt install -y python3-venv python3-pip \
                   build-essential nano \
                   pkg-config

RUN python3 -m venv /opt/venv
RUN /opt/venv/bin/pip3 install --upgrade pip conan cmake
