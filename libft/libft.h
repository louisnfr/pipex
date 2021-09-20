/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 01:39:18 by lraffin           #+#    #+#             */
/*   Updated: 2021/09/17 17:48:45 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# define BUFFER_SIZE	32
# define INT_MAX		2147483647
# define INT_MIN		-214783648

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int			ft_abs(int n);
int			ft_min(int a, int b);
int			ft_max(int a, int b);
int			ft_atoi_base(char *str, const char *base);
long long	ft_atol(const char *str);
int			ft_atoi(const char *str);
int			ft_bzero(void *s);
void		*ft_calloc(size_t count, size_t size);
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isflag(int c);
int			ft_isprint(int c);
char		*ft_itoa(int n);
void		ft_lstadd_back(t_list **alst, t_list *new);
void		ft_lstadd_front(t_list **alst, t_list *new);
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list		*ft_lstnew(void *content);
size_t		ft_lstsize(t_list *lst);
void		*ft_memccpy(void *dst, const void *src, int c, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t len);
void		*ft_memset(void *b, int c, size_t len);
int			ft_nbrlen_u(unsigned int n, int base_size);
int			ft_nbrlen_ul(unsigned long n, int base_size);
int			ft_nbrlen(long n, int base_size);
int			ft_put0xhexa_ret(unsigned long n, const char *base);
void		ft_putchar_fd(char c, int fd);
int			ft_putchar_ret(char c);
void		ft_putchar(char c);
void		ft_putendl_fd(char *s, int fd);
int			ft_puthexa_ret(unsigned int n, const char *base);
void		ft_putnbr_fd(int n, int fd);
int			ft_putnbr_u_ret(unsigned int n);
void		ft_putnbr_u(unsigned int n);
int			ft_putnbr_ret(int n);
void		ft_putnbr(int n);
void		ft_putstr_fd(char *s, int fd);
int			ft_putstr_n_ret(char *s, int n);
int			ft_putstr_ret(char *s);
void		ft_putstr(const char *s);
char		**ft_split(const char *s, char c);
int			ft_str_digit(char *s);
char		*ft_strchr(const char *s, int c);
int			ft_strcmp(char *s1, char *s2);
char		*ft_strdup(const char *s1);
char		*ft_strjoin(char *s1, char *s2);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t		ft_strlen(const char *s);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
char		*ft_strrchr(const char *s, int c);
char		*ft_strtrim(const char *s1, const char *set);
char		*ft_substr(const char *s, unsigned int start, size_t len);
void		ft_swap(int *a, int *b);
int			ft_tolower(int c);
int			ft_toupper(int c);
int			get_next_line(int fd, char **line);

#endif
