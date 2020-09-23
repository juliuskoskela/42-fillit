/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dl_get_last.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 01:11:40 by jkoskela          #+#    #+#             */
/*   Updated: 2020/09/24 01:51:17 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist			*dl_get_last(t_dlist **list)
{
	while((*list)->next)
		*list = (*list)->next;
	return (*list);
}
