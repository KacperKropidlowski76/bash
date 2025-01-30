#!/usr/bin/env bash

if find "$HOME" -maxdepth 1 -type f -name "*.txt" | grep -q .; then
    kill -USR1 $PPID
else
    kill -USR2 $PPID
fi

exit 0