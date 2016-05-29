#!/bin/bash
./komunikat.c
if [[ $(date +%u) -lt 5 ]]
then
./dbior.c | aspell -a -l pl
fi