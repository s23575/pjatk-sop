#!/bin/bash

x=`ls -la $PWD`
echo $x		#Pokazuje rezultat polecenie zapisanego do zmiennej x
echo -e "\nAlternatywny zapis:"
echo $|(ls -la $PWD)
