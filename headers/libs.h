/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:55:29 by coder             #+#    #+#             */
/*   Updated: 2022/04/01 20:15:00 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBS_H
# define LIBS_H

// my libraries and functions
# include "../my_libs/libft/src/libft.h"
# include "../my_libs/gnl/get_next_line.h"
# include "../my_libs/ft_printf/ft_printf.h"

// Minilibx
# include <mlx.h>

// Xlib and Xlib keycode - keysymbol mapping + events and masks
# include <X11/X.h>
# include <X11/keysym.h>

// function open - macro O_RDONLY
# include <fcntl.h>

#endif
