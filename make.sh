#!/bin/bash -e
export TASKING_PATH=
export OBJDIR=
make clean
make all -j $(nproc) "$@"
