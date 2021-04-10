#!/bin/bash

function menu
{
	echo "Wybierz z menu poniżej, co powinno zostać wyświetlone:
[ c ] – nazwa aktualnego katalogu
[ u ] – nazwa użytkownika
[ h ] – zawartość katalogu domowego"
}

function wybor
{ 
	read -p "Wybierz: " wybor
#	if [ "$wybor" != "c" ] && [ "$wybor" != "u" ] &&  [ "$wybor" != "h" ] || [ -z "$wybor" ]
#	then
#		echo "Błąd! nie wybrano żadnej opcji z menu."
#		exit
#	fi
}

menu
wybor

case "$wybor" in
	"c") basename $(pwd) ;;
	"u") echo $USER ;;
	"h") ls -l $HOME ;;
	*) echo "Błąd! nie wybrano żadnej opcji z menu." ;;
esac

