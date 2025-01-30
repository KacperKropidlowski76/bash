#!/bin/bash

sciezka=$1;
prawa="";

if [ -r "${sciezka}" ]; then
    prawa+="Odczyt ";
fi
if [ -w "${sciezka}" ]; then
    prawa+="Zapis ";
fi
if [ -x "${sciezka}" ]; then
    prawa+="Wykonanie";
fi

if [ -e "${sciezka}" ]; then
    echo "Sciezka \"${sciezka}\" istnieje"
    if [ -f "${sciezka}" ]; then
        echo "Plik \"${sciezka}\" to plik, jego prawa to \"${prawa}"\"
    elif [ -d "${sciezka}" ]; then
        echo "Plik \"${sciezka}\" to katalog, jego prawa to \"${prawa}"\"
    elif [ -c "${sciezka}" ]; then
        echo "Plik \"${sciezka}\" to plikiem specjalny znakowy, jego prawa to \"${prawa}"\"
    fi
    
else
    echo 'Sciezka nie istnieje'
fi


exit 0
