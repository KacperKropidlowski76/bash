#!/usr/bin/env bash

if read sciezka liczba napis < fifo1; then
    echo "Sprawdzam katalog: ${sciezka}"
    
    if [ -d "$sciezka" ]; then
        echo "Katalog istnieje"

        # Znajdź pliki w katalogu, które zawierają podciąg w nazwie
        matching_files=$(find "$sciezka" -maxdepth 1 -type f -name "*$napis*")
        matching_count=$(echo "$matching_files" | wc -l)

        echo "Znaleziono ${matching_count} plików pasujących do podciągu '${napis}'"

        # Sprawdzenie, czy liczba znalezionych plików zgadza się z podaną liczbą
        if [ "$matching_count" -eq "$liczba" ]; then
            echo "TAK - Istnieje dokładnie ${liczba} plików zawierających podciąg '${napis}'"
            echo "TAK" > fifo2
        else
            echo "NIE - Liczba plików zawierających podciąg '${napis}' nie zgadza się z ${liczba}"
            echo "NIE" > fifo2
        fi
    else
        echo "Katalog nie istnieje."
        echo "NIE" > fifo2
    fi
fi

cat < fifo1

exit 0
