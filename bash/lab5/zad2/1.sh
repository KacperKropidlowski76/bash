#!/usr/bin/env bash

odcinek1="$1"
odcinek2="$2"
odcinek3="$3"

if [ "$odcinek1" -ge 0 ] && [ "$odcinek2" -ge 0 ] && [ "$odcinek3" -ge 0 ]; then
    
    # echo 'jd'
    exit 1
else
    
    # echo 'kd'
    exit 0
fi