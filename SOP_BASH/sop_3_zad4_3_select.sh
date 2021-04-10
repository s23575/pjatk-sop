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
select w in c u h
do
        case "$w" in
                "c") basename $(pwd) ;;
                "u") echo $USER ;;
                "h") ls -l $HOME ;;
                *) echo "Błąd! nie wybrano żadnej opcji z menu." ;;
        esac
break
done
}

menu
wybor
