#!/bin/bash

. funkcje.f

menu
wybor

case "$wybor" in
	"c") basename $(pwd) ;;
	"u") echo $USER ;;
	"h") ls -l $HOME ;;
	*) echo "Błąd! nie wybrano żadnej opcji z menu." ;;
esac

