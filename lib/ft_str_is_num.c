/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:30:36 by gcomlan           #+#    #+#             */
/*   Updated: 2022/06/20 16:43:25 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int	ft_str_is_numeric(char *str)
{
	size_t	idx;

	idx = 0;
	while (str[idx] && (str[idx] == '-' || str[idx] == '+'))
		idx++;
	if (idx == ft_strlen(str))
		return (0);
	while (str[idx])
	{
		if (!(str[idx] >= '0' && str[idx] <= '9'))
			return (0);
		idx++;
	}
	return (1);
}
/*
int	ft_str_is_numeric(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx] != 0)
	{
		if (!(str[idx] >= '0' && str[idx] <= '9'))
			return (0);
		idx++;
	}
	return (1);
}*/