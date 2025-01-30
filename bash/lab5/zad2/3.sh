#!/usr/bin/env bash

arg1="$1"
arg2="$2"
arg3="$3"

./1.sh $arg1 $arg2 $arg3 &
PID1=$!
./2.sh $arg1 $arg2 $arg3 &
PID2=$!

wait $PID1
STATUS1=$?

wait $PID2
STATUS2=$?

if [ "$STATUS1" -eq 1 ] && [ "$STATUS2" -eq 1 ]; then
    echo "Można zbudować trójkąt z boków: $1, $2, $3"
else
    echo "Nie można zbudować trójkąta!"
fi

exit 0