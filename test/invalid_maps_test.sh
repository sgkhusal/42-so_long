#!/bin/bash

cd ..
make re

# test invalid maps
echo "**********************************************************************"
echo "                      TESTING INVALID MAPS"
echo "**********************************************************************"
echo "* Small map:"
./so_long assets/maps/invalid_maps/small.ber
echo "* One line map:"
./so_long assets/maps/invalid_maps/one_line.ber #ok
echo "* Two lines map:"
./so_long assets/maps/invalid_maps/two_lines.ber #ok
echo "* Two columns map:"
./so_long assets/maps/invalid_maps/two_columns.ber #ok
echo "* Map not surrounded by walls - test 1:"
./so_long assets/maps/invalid_maps/wrong_wall_1.ber #ok
echo "* Map not surrounded by walls - test 2:"
./so_long assets/maps/invalid_maps/wrong_wall_2.ber #ok
echo "* Map not rectangular - test 1:"
./so_long assets/maps/invalid_maps/no_rectangular_1.ber #ok
echo "* Map not rectangular - test 2:"
./so_long assets/maps/invalid_maps/no_rectangular_2.ber #ok
echo "* Character diferent than 'CEP01':"
./so_long assets/maps/invalid_maps/invalid_character.ber