#!/bin/bash

if [[ -z "$1" ]]; then
    echo "Podaj login użytkownika."
    exit 1
fi

who | awk -v user="$1" '$1 == user {print "Ścieżka do terminala:", $2}'
