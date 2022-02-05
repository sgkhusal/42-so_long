#!/bin/bash

#cd ..
#make

clang -Wall -Werror -Wextra 1_so_long.c libft_1.c get_next_line.c get_next_line_utils.c -D BUFFER_SIZE=10 -o so_long

# test invalid arguments
#./so_long
#./so_long map.pdf
#./so_long map1.ber map2.ber

# test missing file .ber
#./so_long map.ber

# test invalid maps
./so_long "../maps/invalid_maps/small.ber"
#./so_long "../maps/invalid_maps/one_line.ber"
#./so_long "../maps/invalid_maps/two_lines.ber"
#./so_long "../maps/invalid_maps/two_columns.ber"
#./so_long "../maps/invalid_maps/wrong_wall_1.ber"
#./so_long "../maps/invalid_maps/wrong_wall_2.ber"
#./so_long "../maps/invalid_maps/no_rectangular_1.ber"
#./so_long "../maps/invalid_maps/no_rectangular_2.ber"
./so_long "../maps/invalid_maps/invalid_character.ber"

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
