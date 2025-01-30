#!/bin/bash

# Obliczanie średniej zaokrąglanej w dół
calculate_average() {
    local sum=0
    local count=0

    # Sumowanie argumentów i liczenie ich ilości
    echo "$@" | tr ' ' '\n' | awk '{sum += $1; count++} END {print int(sum / count)}'
}

# Uruchomienie funkcji z przekazanymi argumentami
calculate_average "$@"


# suma=0
# for liczba in "$@"; do
#     suma=$((suma + liczba))
# done

# srednia=$((suma / $#))

# echo "Średnia zaokrąglona w dół: $srednia"
