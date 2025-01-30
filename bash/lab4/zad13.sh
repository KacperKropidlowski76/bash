#!/bin/bash

# Sprawdzenie, czy podano argument
if [ $# -ne 1 ]; then
    echo "Użycie: $0 <wartość>"
    exit 1
fi

# Tworzenie i eksportowanie zmiennej
export test="$1"

# Wyświetlenie wartości zmiennej test
echo "Zmienna test ustawiona na: $test"
