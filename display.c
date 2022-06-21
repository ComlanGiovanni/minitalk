/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 16:26:21 by gcomlan           #+#    #+#             */
/*   Updated: 2022/06/21 01:33:05 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*
	THIS FCT DISPLAY THE PID AND SOME TIPS FOR THE USAGE OF CLIENT
*/

void	simple_menu(pid_t	pid)
{
	char	*pid_str;

	pid_str = ft_itoa(pid);
	_color(TEXT_COLOR_CYAN, "=================================");
	_color(TEXT_COLOR_CYAN, "=================================\n");
	_color(TEXT_COLOR_GREEN, "📟 <Minitalk Server>\n");
	_color(TEXT_COLOR_GREEN, "🔢 PID : ");
	_color(TEXT_COLOR_RED, pid_str);
	_color(TEXT_COLOR_NO_COLOR, "\n📕 ");
	_color(TEXT_COLOR_GREEN, "USAGE : ");
	_color(TEXT_COLOR_GREEN, "./client ");
	_color(TEXT_COLOR_RED, "[PID] ");
	_color(TEXT_COLOR_GREEN, "\"message\"");
	_color(TEXT_COLOR_GREEN, "\nSupport Unicode -> 🔱");
	_color(TEXT_COLOR_GREEN, "\nHAVE FUN!🤙\n");
	_color(TEXT_COLOR_CYAN, "=================================");
	_color(TEXT_COLOR_CYAN, "=================================\n");
	free(pid_str);
}

/*
	THIS FCT DISLAY THE USAGE OF CLIENT PROGRAM
*/

void	usage(void)
{
	_color(TEXT_COLOR_NO_COLOR, "📕 ");
	_color(TEXT_COLOR_GREEN, " USAGE : ");
	_color(TEXT_COLOR_GREEN, "./client ");
	_color(TEXT_COLOR_RED, "[PID] ");
	_color(TEXT_COLOR_GREEN, "\"message\"");
	exit(0);
}

/*
	THIS FCT DISPLAY IN COLOR A SUCEES MESSAGE
	WHEM THE SIGNAL USER 1 GET KILL IN THE NEX BIT
	AFTE THE PRINT OF THE CHAR TO SPECIY THE RECEPTION
*/

void	success(int sig)
{
	if (sig == SIGUSR1)
	{
		_color(TEXT_COLOR_GREEN, "Server ");
		_color(TEXT_COLOR_LIGHT_GREEN, ">");
		_color(TEXT_COLOR_RED, " Bytes");
		_color(TEXT_COLOR_GREEN, " has been received ! ");
		_color(TEXT_COLOR_NO_COLOR, "✅\n");
	}
}

/*
	THIS FCT DISPLAY AN ERROR MESSAGE IN A
	FILE DESCRIPTOR WITH THE LEN
	END EXIT WITH INT STATUS 0 1 ETC	
*/

void	exit_msg(int fd, char *str, int len, int status)
{
	write(fd, str, len);
	_color(TEXT_COLOR_NO_COLOR, "❌\n");
	exit(status);
}
