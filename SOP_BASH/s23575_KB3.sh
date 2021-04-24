#!/bin/bash

x=$1
y=$3
znak=$2

case "$znak" in

	"+") wynik=$(($x + $y)) ;;
	"-") wynik=$(($x - $y))	;;
	*) echo "Błąd! Wprowadzono błędne dane."
	      	exit ;;

esac

echo $wynik
