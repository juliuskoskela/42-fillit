/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 23:09:31 by jkoskela          #+#    #+#             */
/*   Updated: 2020/09/24 01:58:04 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define BUFF_SIZE 4
# define MAX_FD 1024
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/uio.h>
# include <unistd.h>

typedef struct		s_list
{
	void			*content;
	int				content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_field
{
	uint64_t		*row;
	size_t			w;
	size_t			h;
	size_t			bw;
	size_t			bh;
	int				x;
	int				y;
}					t_field;

typedef struct		s_dlist
{
	void			*content;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}					t_dlist;

int					ft_atoi(const char *str);
int					ft_atoi_base(const char *str, int base);
double				ft_atof(const char *str);
char				*ft_itoa(int n);
void				ft_bzero(void *s, size_t n);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_isupper(int c);
int					ft_islower(int c);
int					ft_iswspace(char c);
int					ft_sign(int n);
int					ft_lentoc(char *s, char c);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memset(void *s, int c, size_t n);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strncat(char *dest, const char *src, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strrev(char *str);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dest, const char *src, size_t n);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
char				*ft_strdup(const char *s);
char				*ft_strndup(const char *s, size_t n);
char				*ft_strcdup(const char *s1, char c);
size_t				ft_strlen(const char *s);
char				*ft_strstr(const char *h, const char *n);
char				*ft_strnstr(const char *h, const char *n, size_t len);
int					ft_tolower(int c);
int					ft_toupper(int c);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strcsub(char *s, char c);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int					ft_sizeofint(int n);
void				*ft_calloc(size_t nmemb, size_t size);
int					ft_gnl(const int fd, char **line);
float				ft_sqrt(float x);
int					ft_log2_64(uint64_t value);
void				ERROR(char *message);

uint64_t			b(char *str);
uint64_t			readbits(char *str, char c, size_t size);
uint64_t			checkbit(uint64_t nb, int n);
size_t				highest_one(uint64_t nb, size_t size);
size_t				lowest_one(uint64_t nb, size_t size);
void				printbits(uint64_t nb, size_t size);
uint64_t			*bf_init(size_t size);
uint64_t			bf_column(uint64_t *field, size_t col, size_t size);
t_field				*bf_dup(t_field *src);
t_field				*bf_new(size_t w, size_t h);
int					bf_fill(uint64_t *field, char *file, char one, size_t size);
int					bf_overlap(t_field *board, t_field *field);
int					bf_cmp(t_field **f1, t_field **f2);
void				bf_print(t_field *field);
void				bf_moveleft(t_field *field, size_t steps);
void				bf_moveright(t_field *field, size_t steps);
void				bf_movedown(t_field *field, size_t steps);
void				bf_moveup(t_field *field, size_t steps);
void				bf_fieldsize(t_field *field);
void				bf_del(t_field *field);
void				bf_fieldplus(t_field *board, t_field *field);
void				bf_fieldminus(t_field *board, t_field *field);
void				bf_clear(t_field *field);
char				*bitoa(uint64_t nb, size_t len);

size_t				dl_len(t_dlist *node);
void				dl_putfirst(t_dlist **ref, void *new);
void				dl_putlast(t_dlist **ref, void *new);
void				dl_putbefore(t_dlist **ref, t_dlist *next, void *new);
void				dl_putafter(t_dlist **ref, t_dlist *prev, void *new);
void				dl_print(t_dlist *node);
void				dl_print_b(t_dlist *node);
void				dl_del_node(t_dlist **ref, t_dlist *del);
void				dl_del_node_at(t_dlist **ref, size_t pos);
void				dl_del_last(t_dlist **ref);
void				dl_rotate(t_dlist **head_ref, size_t N);
t_dlist				*dl_get_last(t_dlist **list);
void				dl_del_list(t_dlist **ref);

#endif
