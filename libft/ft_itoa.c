/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 08:08:39 by jkoskela          #+#    #+#             */
/*   Updated: 2020/07/05 16:32:19 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	char	*str;
	int		size;
	int		sign;

	size = ft_sizeofint(n);
	sign = ft_sign(n);
	str = (char *)ft_memalloc(size + 1 + sign);
	if (!str)
		return (NULL);
	if (n == -2147483648)
		return (ft_strcpy(str, "-2147483648"));
	if (n < 0)
	{
		str[0] = '-';
		size++;
		n = n * -1;
	}
	while (size - sign)
	{
		str[size - 1] = 48 + n % 10;
		n = n / 10;
		size--;
	}
	return (str);
}
