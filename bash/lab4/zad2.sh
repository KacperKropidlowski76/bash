#!/usr/bin/env bash

napis1="$1"
napis2="$2"

length1=${#napis1}
length2=${#napis2}

#echo "${napis1}"
#echo "${napis2}"

if (( "${length1}" > "${length2}" )); then #jezeli int to ten nawias
    echo "napis ${napis1} jest dluzszy"
elif [[ "${length1}" == "${length2}" ]]; then
    echo "Napisy sa takie same"
else
    echo "napis ${napis2} jest dluzszy"
fi

if [[ "${napis1}" < "${napis2}" ]]; then #jezeli string to ten nawias
    echo "napis ${napis1} jest prędzej leksykograficznie"
elif [[ "${napis1}" == "${napis2}" ]]; then
    echo "Napisy sa takie same"
else
    echo "napis ${napis2} prędzej leksykograficznie"
fi




exit 0