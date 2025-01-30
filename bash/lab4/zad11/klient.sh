#!/usr/bin/env bash

read -p "Podaj wyraz: " wyraz

mkfifo fifoKlient

fifoKlient=fifoKlient

sciezka=$(realpath $fifoKlient)

echo "$wyraz $sciezka" > fifo


if read licznik < $fifoKlient; then
    echo "Liczba samoglosek to: ${licznik}"
fi

rm $fifoKlient

exit 0