/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bf_normalize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esukava <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 15:10:33 by esukava           #+#    #+#             */
/*   Updated: 2020/08/24 15:13:34 by esukava          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bitlib.h"

void			bf_normalize(uint *field, size_t size)
{
	bf_ynormal(field, size);
	bf_xnormal(field, size);
}
