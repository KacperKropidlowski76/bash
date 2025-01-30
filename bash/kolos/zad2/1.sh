#!/usr/bin/env bash

tablica=($*)

length=${#tablica[@]}
suma=0

for (( i=0; i<length; i++ )); do
    for (( j=i+1; j<length; j++ )); do
        suma=$((tablica[i] + tablica[j]))
        # echo "${tablica[i]}"
        # echo "${tablica[j]}"
        # echo "suma: ${suma}"
        
        if (( suma < 10 )); then         
            echo "${suma}"
            ./2.sh "${tablica[i]}" "${tablica[j]}" &
            PID1=$!
            wait $PID1
            exit 0
        fi
    done
done

echo 'JD'
./3.sh &
PID2=$!

LAST_SIGNAL=""

trap 'LAST_SIGNAL="USR1"' USR1
trap 'LAST_SIGNAL="USR2"' USR2

wait $PID2

if [ "$LAST_SIGNAL" = "USR1" ]; then
    echo 'Plik istnieje'
    kill $$
elif [ "$LAST_SIGNAL" = "USR2" ]; then
    echo 'Plik nie istnieje'
    kill $$
else
    echo 'Nie odebrano sygnału'
fi

exit 0
