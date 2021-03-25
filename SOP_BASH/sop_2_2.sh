#!/bin/bash

file="./SOP_display.sh"

if [[ -f $file  ]]

then
	$file

else

	if [[ $# -eq 1 ]]

	then
	        
		file_2="./$1"
		$file_2
		 
	else
		 
	        echo "Błąd! Nie znaleziono pliku SOP_display.sh ani nie podano nazwy innego pliku do uruchomienia." 
			 
	fi 

fi
