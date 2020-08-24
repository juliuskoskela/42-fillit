/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitlib.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esukava <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 14:34:55 by esukava           #+#    #+#             */
/*   Updated: 2020/08/24 15:24:17 by esukava          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITLIB_H
# define BITLIB_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

uint			readbits(char *str, char c, int size);
uint			checkbit(uint nb, int n);
void			printbits(uint nb, int n);
uint			*bf_init(size_t size);
void			bf_print(uint *field, size_t size);
int				bf_fill(uint *field, char *file, char one, size_t size);
void			bf_ynormal(uint *field, size_t size);
uint			bf_column(uint *field, size_t row, size_t size);
void			bf_moveleft(uint *field, size_t steps, size_t size);
void			bf_xnormal(uint *field, size_t size);
void			bf_normalize(uint *field, size_t size);
int				highest_one(uint nb, size_t size);
int				lowest_one(uint nb, size_t size);

#endif
