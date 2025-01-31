#!/usr/bin/env bash

sciezka=$1
liczba=$2
napis="$3"

echo "$sciezka $liczba $napis" > fifo1

read odp < fifo2;
if [ -e ~/info.log ]; then
    if [ $odp == "TAK" ]; then
        echo "${odp}" >> $HOME/info.log;
    elif [ $odp == "NIE" ]; then
        echo "${odp}" >> $HOME/info.log;     
    fi
else
    touch $HOME/info.log;
    if [ $odp == "TAK" ]; then
        echo "${odp}" >> $HOME/info.log;
    elif [ $odp == "NIE" ]; then
        echo "${odp}" >> $HOME/info.log;     
    fi
fi

echo "Zapisalem wartosc w pliku info.log" > fifo1

exit 0