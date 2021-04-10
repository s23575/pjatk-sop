#!/bin/bash

if [ $# -gt 0 ]
then	
	if [ -f "./$1" ]
	then
		echo "W bieżącym folderze jest plik $1"
	else
		echo "W bieżącym folderze nie ma pliku $1"
	fi
else
	echo "Błąd! Nie podano argumentu (nazwy pliku do wyszukania)."
fi
