#!/usr/bin/env bash

set -e
rm -f -- *.o *.lis *.out

for f in *.cpp; do                  #loop through each .cpp file and compile them
    g++ -c -m64 -Wall -std=c++17 -fno-pie -no-pie -o "$f.o" "$f"            #$f is the name of each cpp file
done

g++ -m64 -std=c++14 -fno-pie -no-pie -o "exe.out" ./*.o

./exe.out

rm -f -- *.o *.lis *.out