/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dl_del_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 05:24:38 by jkoskela          #+#    #+#             */
/*   Updated: 2020/09/24 01:59:23 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		dl_del_list(t_dlist **ref)
{
	t_dlist		*n;
	t_field		*tmp;
	t_dlist		*tmp2;

	tmp2 = (*ref);
	while (tmp2)
	{
		tmp = tmp2->content;
		bf_del(tmp);
		n = tmp2;
		tmp2 = tmp2->next;
		dl_del_node(&n, n);
	}
}
