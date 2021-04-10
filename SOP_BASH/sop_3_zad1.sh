#!/bin/bash

echo -e \
"program nazywa się: `basename $0`\n\
param1: $1\n\
param2: $2\n\
param*: $@\n\
param#: $#\n\
proc PID: $$"
