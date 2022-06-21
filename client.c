/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 22:37:51 by gcomlan           #+#    #+#             */
/*   Updated: 2022/06/21 13:44:34 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*
	THIS FCT IS A CUSTOM ATOI WITH MESSAGE IN CASE OF INVALID PID
	PID NEED TO HAVE ONLY 0 1 2 3 4 5 6 7 8 9 AND CAN BE NEGETIF BECAUSE PID_T
	IS UNSIGNED INT
*/

int	check_pid(const char *nptr)
{
	int	storage;
	int	sign;

	storage = 0;
	if (*nptr == '-' && nptr++)
		sign = 1;
	while (*nptr)
	{
		if (*nptr >= '0' && *nptr <= '9')
			storage = storage * 10 - *nptr++ + '0';
		else
			exit_msg(2, "Error: Invalid pid", 18, 1);
	}
	if (!storage)
		exit_msg(2, "Error: Invalid pid", 18, 1);
	if (!sign)
		return (-storage);
	return (storage);
}

/*
	THIS FCT TRIGGER THE SERV SIGNAL
	CHAR BY CHAR TO PRINT IT IN NEXTBIT
	1 CHAR 8 BYTES
	SO WE SHIFT TO RIGHT C BY THE --IDX TO 0

	Opérateur et & i one 0 get -> 0
	
*/

void	send_char(int pid, char c)
{
	int	idx;

	idx = 8;
	while (--idx >= 0)
	{
		if (c >> idx & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(150);
	}
}

/*
	THIS FCT SEND EVERY CHAR OF THE MESSAGE AT SEND_CHAR
	AND AT THE END A NEW LINE FOR THE NEXT STR(MSG)
*/

void	send_str(int pid, char *str)
{
	size_t	idx;

	idx = 0;
	while (str[idx])
	{
		send_char(pid, str[idx]);
		idx++;
	}
	send_char(pid, '\n');
}

/*
	IN THE MAIN WE CHECK THE LEN OF THE PID
	TO CHECK IF IT > LEN(MAX PID) = 4,194,304
	IF THE PID IS TRUELY A NUM AND IF THE PID IS
	CORRECT, SO WE SEND THE MESSAGE AT SEND_STR
	AND WAIT FOR RECIEVE SIGNAL
	SIGACION STRUC SA_HANDLER GET A POINTE TO A FCT
	IN CASE THE SIGNAL GET TRIGGERED
	sigaction(SIGUSR1, &sig_struct, NULL);
	NULL BECAUSE WE DONT WANT TO RESTORE THE OLD SIG
*/

int	main(int argc, char **argv)
{
	struct sigaction	sig_struct;
	pid_t				pid;

	sig_struct.sa_handler = &success;
	if ((ft_strlen(argv[1]) > 11 && !ft_str_is_numeric(argv[1])) || argc != 3)
		usage();
	else
	{
		pid = check_pid(argv[1]);
		sigaction(SIGUSR1, &sig_struct, NULL);
		send_str(pid, argv[2]);
		while ("The prophecy is true")
			pause();
	}
	return (0);
}
