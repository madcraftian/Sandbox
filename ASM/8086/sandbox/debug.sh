#!/bin/bash

EXE_NAME="BIN\\8086.exe"
PROJECT_DIR="$( pwd )"

dosbox-debug -c "MOUNT C ${PROJECT_DIR}" -c "C:" -c "DEBUG ${EXE_NAME}" 
