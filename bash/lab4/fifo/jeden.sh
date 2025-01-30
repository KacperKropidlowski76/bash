#!/usr/bin/env bash

mkfifo mojfif

# while true; do
    { echo "Linia 1"; sleep 1; echo "Linia 2"; } > mojfif
# done

exit 0