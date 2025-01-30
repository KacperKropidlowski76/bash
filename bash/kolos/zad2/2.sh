#!/usr/bin/env bash

liczba1=$1
liczba2=$2
max=0
min=0

if (( liczba1 > liczba2 )); then
    max=$liczba1
    min=$liczba2
else
    max=$liczba2
    min=$liczba1
fi

wylosowana=$(( RANDOM % (max - min + 1) + min ))

echo "Losowa to: ${wylosowana}"


# echo "wieksza: ${wieksza}"
# echo "mniejsza: ${mniejsza}"



exit 0