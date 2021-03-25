#!/bin/bash

lines_count="ls -la | wc -l"

lines_count_eval=$(eval "$lines_count")

if [[ $lines_count_eval -gt 5 ]]

then

	echo "W bieżącym katalogu jest więcej niż 5 plików."

fi
