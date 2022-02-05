#!/bin/bash

#cd ..
#make

gcc -Wall -Werror -Wextra src/1_so_long.c src/libft_1.c src/get_next_line.c src/get_next_line_utils.c -D BUFFER_SIZE=10 -o so_long

# input tests
#./input_test.sh

# test invalid maps
#./invalid_maps_test.sh

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
