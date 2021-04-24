#!/bin/bash

j=1

echo -e "program nazywa się: `basename $0`"
for i in $@
do
	echo "param$j: $i"
	((j+=1))
done

echo -e "param*: $@\nparam#: $#"
