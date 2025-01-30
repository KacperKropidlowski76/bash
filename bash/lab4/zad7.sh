#!/usr/bin/env bash

sciezka="$1";
jest=1;

if [ -z "$sciezka" ]; then
    echo 'Brak argumentu'
    jest=0;
fi

if [ -e "$sciezka" ] && [ "$jest" == 1 ]; then
    if [[ $sciezka  == *.txt ]]; then
    nano "$sciezka"
    elif [[ $sciezka  == *.sh ]]; then
    bash "$sciezka"
    fi
elif [ $jest == 1 ]; then
    echo 'Nieznany plik'
fi


exit 0
