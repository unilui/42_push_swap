/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 15:38:38 by lufelip2          #+#    #+#             */
/*   Updated: 2022/09/10 03:57:52 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

# define BUFFER_SIZE 4096

typedef struct s_file {
	int				fd;
	int				rdd;
	char			*line;
	char			*buffer;
	char			*tmp;
	struct s_file	*next;
}	t_file;

typedef struct s_str {
	char	chr;
	int		written;
	va_list	args;
}	t_str;

typedef void	(*t_replace)(t_str *str);

void		ft_sort_int_tab(int *tab, int size);
void		ft_swap(int *a, int *b);
long		ft_atoi(const char *nptr);
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_tolower(int c);
int			ft_toupper(int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strdup(const char *s);
char		**ft_split(char const *s, char c);
char		*ft_itoa(int n);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char		*ft_strnstr(const char *big, const char *little, size_t len);
size_t		ft_strlen(const char *s);
void		ft_putnbr_fd(int n, int fd);
void		*ft_calloc(size_t nmemb, size_t size);
void		*ft_memset(void *s, int c, size_t n);
void		ft_bzero(void *s, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
void		*ft_memchr(const void *s, int c, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t n);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
char		*get_next_line(int fd);
int			ft_chrpst(char const *s, int c);
t_replace	placeholder(char placeholder);
void		replace_handler(t_str *str);
void		replace_uint(t_str *str);
void		replace_hexa(t_str *str);
void		replace_chr(t_str *str);
void		replace_int(t_str *str);
void		replace_str(t_str *str);
void		replace_ptr(t_str *str);
void		skip_replace(t_str *str);
int			ft_printf(const char *str, ...);
int			ft_putnbr(int nbr);
int			ft_putchar(const char c);
int			ft_putstr(char *s);
int			ft_put_ptr(size_t nbr, char chr);
int			ft_put_u_nbr(unsigned int nbr);
int			ft_put_x_nbr(unsigned int nbr, char chr);

#endif
