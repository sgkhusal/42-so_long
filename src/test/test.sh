#!/bin/bash

cd ..
make

# test invalid maps
./so_long
./so_long "maps/invalid_maps/small.ber"
./so_long "maps/invalid_maps/one_line.ber"
./so_long "maps/invalid_maps/two_lines.ber"
./so_long "maps/invalid_maps/two_columns.ber"
./so_long "maps/invalid_maps/wrong_wall_1.ber"
./so_long "maps/invalid_maps/wrong_wall_2.ber"
./so_long "maps/invalid_maps/no_rectangular_1.ber"
./so_long "maps/invalid_maps/no_rectangular_2.ber"
./so_long "maps/invalid_maps/invalid_character.ber"

#./so_long "maps/small.ber"
#./so_long "maps/pdf_1.ber"
#./so_long "maps/pdf_2.ber"
#./so_long "maps/map_1.ber"
#./so_long "maps/map_2.ber"
#./so_long "maps/map_3.ber"
#./so_long "maps/map_4.ber"

#make bonus
#./so_long_bonus "maps/map_1.ber"
#./so_long_bonus "maps/map_2.ber"
#./so_long_bonus "maps/map_3.ber"
#./so_long_bonus "maps/map_4.ber"
