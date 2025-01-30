#!/usr/bin/env bash
licznik=0
if read wyraz sciezka < fifo; then
    echo "Otrzymano: $wyraz, $sciezka"
    for ((i=0; i<${#wyraz}; i++)); do
        if [ "${wyraz:$i:1}" == "a" ] || [ "${wyraz:$i:1}" == "e" ] || [ "${wyraz:$i:1}" == "i" ] || [ "${wyraz:$i:1}" == "o" ] || [ "${wyraz:$i:1}" == "u" ] || [ "${wyraz:$i:1}" == "y" ]; then
            licznik=$((licznik+1));
        fi
    done
    # echo "Liczba samoglosek to: $licznik"
    echo "$licznik" > "$sciezka"
fi

# vowel_count=$(echo "$slowo" | grep -o -i "[aeiouAEIOU]" | wc -l)
exit 0