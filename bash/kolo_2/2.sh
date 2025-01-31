#!/usr/bin/env bash

read sciezka liczba napis < fifo1

# echo "sciezka: ${sciezka}"
# echo "liczba: ${liczba}"
# echo "napis: ${napis}"

if [ -e $sciezka ]; then
    echo 'Sciezka istnieje'
    ilosc=$(find "$sciezka" -maxdepth 1 -type f -name "*$napis*"| wc -l)
    if [ $ilosc == $liczba ]; then
        echo "TAK" > fifo2
    else
        echo 'NIE' > fifo2
    fi
    echo "${ilosc}"
    
fi

cat < fifo1




exit 0