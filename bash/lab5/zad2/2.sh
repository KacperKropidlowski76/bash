#!/usr/bin/env bash

odcinek1="$1"
odcinek2="$2"
odcinek3="$3"

if [ $(("$odcinek1" + "$odcinek2")) -ge "$odcinek3" ] && [ $(("$odcinek1" + "$odcinek3")) -ge "$odcinek2" ] && [ $(("$odcinek2" + "$odcinek3")) -ge "$odcinek1" ]; then
    
    # echo 'jd'
    exit 1
else
    
    # echo 'kd'
    exit 0
fi

exit 0