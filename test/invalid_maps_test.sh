#!/bin/bash

cd ..

# test invalid maps
./so_long assets/maps/invalid_maps/small.ber
./so_long assets/maps/invalid_maps/one_line.ber #ok
./so_long assets/maps/invalid_maps/two_lines.ber #ok
./so_long assets/maps/invalid_maps/two_columns.ber #ok
./so_long assets/maps/invalid_maps/wrong_wall_1.ber #ok
./so_long assets/maps/invalid_maps/wrong_wall_2.ber #ok
./so_long assets/maps/invalid_maps/no_rectangular_1.ber
./so_long assets/maps/invalid_maps/no_rectangular_2.ber
./so_long assets/maps/invalid_maps/invalid_character.ber