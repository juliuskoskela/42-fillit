/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bf_new.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 18:26:21 by jkoskela          #+#    #+#             */
/*   Updated: 2020/09/24 01:50:04 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_field			*bf_new(size_t w, size_t h)
{
	t_field		*newfield;

	newfield = (t_field *)malloc(sizeof(t_field));
	newfield->row = bf_init(h);
	newfield->w = w;
	newfield->h = h;
	newfield->bw = 0;
	newfield->bh = 0;
	newfield->x = 0;
	newfield->y = 0;
	return (newfield);
}
