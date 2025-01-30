#!/bin/bash

# Function to reverse a string
reverse_string() {
    local input="$1"
    local reversed=""

    # Loop through the string in reverse order
    for (( i=${#input}-1; i>=0; i-- )); do
        reversed+="${input:$i:1}"
    done

    echo "$reversed"
}

# Check if an argument is provided
if [ "$#" -ne 1 ]; then
    echo "Usage: $0 <string>"
    exit 1
else
    # Call the function with the provided argument
    reverse_string "$1"
fi
