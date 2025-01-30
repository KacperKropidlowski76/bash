#!/bin/bash

if [[ -z "$1" ]]; then
    echo "Podaj ścieżkę do katalogu."
    exit 1
fi

du -ah "$1"
