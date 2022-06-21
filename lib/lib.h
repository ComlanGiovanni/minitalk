/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:05:22 by gcomlan           #+#    #+#             */
/*   Updated: 2022/06/20 18:30:54 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H

# include <stdlib.h>
# include <stdio.h>
# include <stddef.h>
# include <unistd.h>

# define TEXT_COLOR_BLACK			"\033[0;30m"
# define TEXT_COLOR_RED				"\033[0;31m"
# define TEXT_COLOR_GREEN			"\033[0;32m"
# define TEXT_COLOR_ORANGE			"\033[0;33m"
# define TEXT_COLOR_BLUE			"\033[0;34m"
# define TEXT_COLOR_PURPLE			"\033[0;35m"
# define TEXT_COLOR_CYAN			"\033[0;36m"
# define TEXT_COLOR_LIGHT_GRAY		"\033[0;37m"
# define TEXT_COLOR_DARK_GRAY		"\033[1;30m"
# define TEXT_COLOR_LIGHT_RED		"\033[1;31m"
# define TEXT_COLOR_LIGHT_GREEN		"\033[1;32m"
# define TEXT_COLOR_YELLOW			"\033[1;33m"
# define TEXT_COLOR_LIGHT_BLUE		"\033[1;34m"
# define TEXT_COLOR_LIGHT_PURPLE	"\033[1;35m"
# define TEXT_COLOR_LIGHT_CYAN		"\033[1;36m"
# define TEXT_COLOR_WHITE			"\033[1;37m"
# define TEXT_COLOR_NO_COLOR		"\033[0m"

void	_color(char *color, char *str);
int		len_nb(long nb);
char	*ft_itoa(int n);
void	ft_putchar(const char c);
void	ft_putstr(const char *s);
size_t	ft_strlen(const char *str);
int		ft_str_is_numeric(char *str);

#endif