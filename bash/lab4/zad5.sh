#!/usr/bin/env bash

tablica=($*);

length=${#tablica[@]}

# echo "${length}"

until [[ $length == -1 ]]; do
    echo "${tablica[$length]}"
    length=$((length-1))
done


# echo "${tablica[1]}"


exit 0