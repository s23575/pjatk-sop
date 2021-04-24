#!/bin/bash

testowa1=`pwd`
testowa2=$(pwd)

echo $testowa1
echo $testowa2

$testowa1
$testowa2

echo $?
echo $$

tablica=($1 $2 $3)
echo ${tablica[@]}
echo ${#tablica[*]}
echo ${#tablica[0]}
tablica[3]=$4
unset tablica[2]
echo ${tablica[*]}
