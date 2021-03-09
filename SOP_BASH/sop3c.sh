#!/bin/bash

x=`ls -la $PWD`
echo $x		#pokazuje rezultat polecenie zapisanego do zmiennej x
echo -e "\nAlternatywny zapis:"
echo $|(ls -la $PWD)
