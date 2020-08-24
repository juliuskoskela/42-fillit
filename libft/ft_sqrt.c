/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 21:07:56 by jkoskela          #+#    #+#             */
/*   Updated: 2020/08/23 21:16:57 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

float		ft_sqrt(float x)
{
	float	xhalf;
	int		i;

	xhalf = 0.5f * x;
	i = *(int *)&x;
	i = 0x5f3759df - (i >> 1);
	x = *(float *)&i;
	x = x * (1.5f - xhalf * x * x);
	return (1 / x);
}