/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 03:56:32 by jkoskela          #+#    #+#             */
/*   Updated: 2020/08/24 12:15:09 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static double	ft_atof_sub(const char *str, double res)
{
	int			decimal;

	decimal = 0;
	while (ft_isdigit(*str) == 1 && *str != '.')
	{
		res = res * 10 + (*str - 48);
		str++;
	}
	str++;
	if (*str == '\0')
		return (res);
	while (ft_isdigit(*str) == 1)
	{
		res = res * 10 + (*str - 48);
		str++;
		decimal++;
	}
	while (decimal--)
		res = res / 10;
	return (res);
}

double			ft_atof(const char *str)
{
	double		res;
	double		negative;

	negative = 1;
	res = 0;
	while (ft_iswspace(*str) == 1)
		str++;
	if (*str == '-')
		negative = -1;
	if (*str == '-' || *str == '+')
		str++;
	res = ft_atof_sub(str, res);
	return (res * negative);
}
