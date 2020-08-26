/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitlib.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 14:34:55 by esukava           #+#    #+#             */
/*   Updated: 2020/08/26 12:55:48 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITLIB_H
# define BITLIB_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdint.h>

uint64_t		b(char *str);
uint64_t		readbits(char *str, char c, size_t size);
uint64_t		checkbit(uint64_t nb, int n);
void			printbits(uint64_t nb, size_t size);
uint64_t		*bf_init(size_t size);
void			bf_print(uint64_t *field, size_t size);
int				bf_fill(uint64_t *field, char *file, char one, size_t size);
void			bf_ynormal(uint64_t *field, size_t size);
uint64_t		bf_column(uint64_t *field, size_t col, size_t size);
void			bf_moveleft(uint64_t *field, size_t steps, size_t size);
void			bf_xnormal(uint64_t *field, size_t size);
void			bf_normalize(uint64_t *field, size_t size);
size_t			highest_one(uint64_t nb, size_t size);
size_t			lowest_one(uint64_t nb, size_t size);

#endif
