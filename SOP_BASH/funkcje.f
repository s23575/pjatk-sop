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
}

