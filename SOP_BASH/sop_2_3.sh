#!/bin/bash

# if [[ "${0: -3}" != ".sh" ]]

if [[ ! "${0: -3}" =~ ^.*[.][s][h]$ ]]

then

	file_sh_name="$0.sh"
	mv $0 $file_sh_name

fi
