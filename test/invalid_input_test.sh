#!/bin/bash

cd ..
make re

# test invalid arguments
echo "**********************************************************************"
echo "                      TESTING INVALID INPUTS"
echo "**********************************************************************"
echo "* No map:"
./so_long
echo "* Type file different from .ber:"
./so_long map.pdf
echo "* More than 2 arguments:"
./so_long map1.ber map2.ber

# test missing file .ber
echo "* Map file doesn't exist:"
./so_long map.ber
