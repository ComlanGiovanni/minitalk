/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 22:37:51 by gcomlan           #+#    #+#             */
/*   Updated: 2022/06/21 14:01:25 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_msg	g_msg;

/*
	8 BITS SOIT 1 CHAR 
	SO WE CHECK IF THE IDX IS >=8
	TO PRINT BYTES BY BYTES
	AND WE RESET THE BUFFER
	FOR THE NEXT CHAR
	THE KILL TRIGGER IS FOR THE RECIEVE BONUS
	INFO->SI_PID from SA_INFO MACHIN PID DU CLIENT
	WALLAH FAUT FAIRE DODO JSUI KO
*/

void	next_bit(siginfo_t *info)
{
	g_msg.idx++;
	if (g_msg.idx >= 8)
	{
		g_msg.idx = 0;
		write(1, &g_msg.c_buff, 1);
		kill(info->si_pid, SIGUSR1);
		g_msg.c_buff = 0;
	}
}

/*
	LISTEN FOR 0 AND 1 FROM SEND_CHAR
	AND SHIFT THE BUFF CHAR IF 1
	VARIABLE = VARIABLE | NOMBRE
	LOPERATEUR OU INCLUSIF | DONNERA 1
	SI AU MOINS  UN DES DEUX BITS DE LA PAIRE EST A 1
	SO 0 OU 1 EN FONCTION DU SIGNAL
*/

void	listen(int sig, siginfo_t *info, void *tmp)
{
	(void)tmp;
	if (sig == SIGUSR1)
		g_msg.c_buff <<= 1;
	if (sig == SIGUSR2)
	{
		g_msg.c_buff <<= 1;
		g_msg.c_buff |= 1;
	}
	next_bit(info);
}

/*
	INT THIS MAIN WE GET THE PID FOR THE CLIENT
	
	2 SIG ACTION WITH USR 1 2 SIGNAL FOR THE KILLTRIGGER
	IN THE SEND_CHAR FCT
	THE LISTEN FCT ITS THE SIG ACTION FCT WHO GET CALL
	SIGACION STRUCT SA_HANDLER GET A POINTE TO A FCT
	IN CASE THE SIGNAL GET TRIGGERED

	///////sa_sigaction/sa-handler only one of them

	sigaction(SIGUSR1, &sig_struct, NULL);
	NULL BECAUSE WE DONT WANT TO RESTORE THE OLD SIG
	sig_struct.sa_flags = SA_SIGINFO;
	THIS FLAGS GOT : si_(signo errno pid status value...)
	SIGACTION BIND THE HANDLER HAND THE STRUCT
*/

int	main(void)
{
	struct sigaction	sig_struct;
	pid_t				pid;

	pid = getpid();
	simple_menu(pid);
	g_msg.c_buff = 0;
	g_msg.idx = 0;
	sig_struct.sa_sigaction = &listen;
	sig_struct.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sig_struct, NULL);
	sigaction(SIGUSR2, &sig_struct, NULL);
	while ("The prophecy is true")
		pause();
	return (0);
}

/**
 * @brief
 * SO BAD WE CAN NOT SEND A SIG KILL OR SIG STOP
 * I WOULD LIKE TO KILL CLIENT WHEN SERV GET KILLED
 * sig_atomic_t >>>....????? the fuck
 * try to have only one recpetion message lol one day
 * msg > prompt
 * ft_print ? 
 * invalid pid atoi color
 * 
 * pstree
 * pidof server
 * lsof
 * pgrep server
 * ps
 * 
 */