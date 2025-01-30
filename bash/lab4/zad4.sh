#!/usr/bin/env bash

dateShort=$(date -I) # format: yyyy/mm/dd

mkdir "$dateShort";

find "$HOME" -maxdepth 1 -type f -newermt "$dateShort" ! -newermt "$dateShort 23:59:59" -exec cp {} "$dateShort" \;

exit 0