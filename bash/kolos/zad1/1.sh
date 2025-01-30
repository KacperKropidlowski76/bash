#!/usr/bin/env bash

sciezka=$1
liczba=$2
napis="$3"
dateShort=$(date -I)

echo "${sciezka} ${liczba} ${napis}" > fifo1

read odpowiedz < fifo2
if [ -e ~/info.log ]; then
    if [ "$odpowiedz" == "TAK" ]; then
        echo "$dateShort TAK" >> ~/info.log
    else
        echo "$dateShort NIE" >> ~/info.log
    fi
else
    touch "$HOME"/info.log
    echo 'Utworzylem folder info.log'
    if [ "$odpowiedz" == "TAK" ]; then
        echo "$dateShort TAK" >> ~/info.log
    else
        echo "$dateShort NIE" >> ~/info.log
    fi
fi
    
echo 'Zapisano wartosc w pliku info.log' > fifo1


exit 0