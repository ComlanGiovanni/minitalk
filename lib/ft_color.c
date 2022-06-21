/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:04:01 by gcomlan           #+#    #+#             */
/*   Updated: 2022/06/20 18:18:36 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	_color(char *color, char *str)
{
	ft_putstr(color);
	ft_putstr(str);
	ft_putstr(TEXT_COLOR_NO_COLOR);
}
