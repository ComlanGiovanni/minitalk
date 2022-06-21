/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 22:37:51 by gcomlan           #+#    #+#             */
/*   Updated: 2022/06/21 14:00:02 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <stdlib.h>
# include "./lib/lib.h"

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

typedef struct msg
{
	char	c_buff;
	int		idx;
}	t_msg;

//short
void	simple_menu(pid_t	pid);
void	usage(void);
void	success(int sig);
void	exit_msg(int fd, char *str, int len, int status);

#endif
