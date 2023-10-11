#!/bin/bash

rm -rf libmy.a

for file in my_*.c; do
    basename="${file##*/}"
    gcc -c "$file" -o "${basename%.*}.o" -Wall -Wextra
done

ar rcs libmy.a my_*.o
rm -rf my_*.o
