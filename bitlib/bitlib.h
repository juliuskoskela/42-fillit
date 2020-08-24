/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitlib.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esukava <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 14:34:55 by esukava           #+#    #+#             */
/*   Updated: 2020/08/24 16:59:21 by esukava          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITLIB_H
# define BITLIB_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>


unsigned int			readbits(char *str, char c, size_t size);
unsigned int			checkbit(unsigned int nb, int n);
void			printbits(unsigned int nb, size_t size);
unsigned int			*bf_init(size_t size);
void			bf_print(unsigned int *field, size_t size);
int				bf_fill(unsigned int *field, char *file, char one, size_t size);
void			bf_ynormal(unsigned int *field, size_t size);
unsigned int			bf_column(unsigned int *field, size_t col, size_t size);
void			bf_moveleft(unsigned int *field, size_t steps, size_t size);
void			bf_xnormal(unsigned int *field, size_t size);
void			bf_normalize(unsigned int *field, size_t size);
int				highest_one(unsigned int nb, size_t size);
int				lowest_one(unsigned int nb, size_t size);

#endif
