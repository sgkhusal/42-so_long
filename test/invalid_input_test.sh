#!/bin/bash

cd ..

# test invalid arguments
./so_long
./so_long map.pdf
./so_long map1.ber map2.ber

# test missing file .ber
./so_long map.ber