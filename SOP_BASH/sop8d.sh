#!/bin/bash

echo "Stderr jest skierowane do pliku error"
ls -y 2>> ~/error		#Błąd
cat /etc/shadow 2>> ~/error	#Błąd2
