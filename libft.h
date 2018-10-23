/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 16:13:51 by acarlson          #+#    #+#             */
/*   Updated: 2018/10/23 15:26:04 by acarlson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <string.h>

# include <unistd.h>

/*
** Handy macros
*/

# define RET_IF(cond,ret) if(cond) return (ret)
# define RET_NONE(cond) if(cond) return ;
# define NULL_CHECK(x) if(x) return (NULL)
# define MIN(a,b) (a < b) ? a : b
# define MAX(a,b) (a > b) ? a : b
# define ABS(x) (x < 0) ? -x : x

/*
** Stupid macros
*/

# define ISALPHA(c) ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
# define ISDIGIT(c) (c >= '0' && c <= '9')
# define ISALNUM(c) (ISALPHA(c) || ISDIGIT(c))
# define ISASCII(c) (c >= 0 && c <= 0177)
# define ISPRINT(c) (c >= 040 && c <= 0176)
# define TOUPPER(c) ((c >= 'a' && c <= 'z') ? c & '_' : c)
# define TOLOWER(c) ((c >= 'A' && c <= 'Z') ? c | ' ' : c)

/*
** limits stuff because we can't use limits.h for whatever reason
*/

# define FT_UCHAR_MAX 255
# define FT_SCHAR_MAX 127
# define FT_SCHAR_MIN -128

# define FT_UINT_MAX (((unsigned int)0) - 1)
# define FT_INT_MAX (FT_UINT_MAX / 2)
# define FT_INT_MIN (FT_INT_MAX + 1)

# define FT_ULONG_MAX (((unsigned long)0) - 1)
# define FT_LONG_MAX (FT_ULONG_MAX / 2)
# define FT_LONG_MIN (FT_LONG_MAX + 1)

/*
** Colors
*/

/*
** SET
*/

# define S_BOL		"\033[1m"
# define S_DIM		"\033[2m"
# define S_UND		"\033[4m"
# define S_BLN		"\033[5m"
# define S_HID		"\033[8m"
# define S_INV		"\033[7m"
# define S_RST_ALL	"\033[0m"
# define S_RST_BLD	"\033[21m"
# define S_RST_DIM	"\033[22m"
# define S_RST_UND	"\033[24m"
# define S_RST_BLN	"\033[25m"
# define S_RST_INV	"\033[27m"
# define S_RST_HID	"\033[28m"

/*
** FOREGROUND
*/

# define F_BLK		"\033[30m"
# define F_RED		"\033[31m"
# define F_GRN		"\033[32m"
# define F_YLW		"\033[33m"
# define F_BLU		"\033[34m"
# define F_MGN		"\033[35m"
# define F_CYN		"\033[36m"
# define F_GRY		"\033[37m"
# define F_WHT		"\033[97m"
# define F_LGRY		"\033[37m"
# define F_DGRY		"\033[90m"
# define F_LRED		"\033[91m"
# define F_LGRN		"\033[92m"
# define F_LYLW		"\033[93m"
# define F_LBLU		"\033[94m"
# define F_LMGN		"\033[95m"
# define F_LCYN		"\033[96m"
# define F_DFT		"\033[39m"

/*
** BACKGROUND
*/

# define B_BLK		"\033[40m"
# define B_RED		"\033[41m"
# define B_GRN		"\033[42m"
# define B_YLW		"\033[43m"
# define B_BLU		"\033[44m"
# define B_MGN		"\033[45m"
# define B_CYN		"\033[46m"
# define B_GRY		"\033[47m"
# define B_LGRY		"\033[47m"
# define B_DGRY		"\033[100m"
# define B_LRED		"\033[101m"
# define B_LGRN		"\033[102m"
# define B_LYLW		"\033[103m"
# define B_LBLU		"\033[104m"
# define B_LMGN		"\033[105m"
# define B_LCYN		"\033[106m"
# define B_WHT		"\033[107m"
# define B_DFT		"\033[49m"

/*
** Part one
*/

void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *dst, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *s1);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *s1, const char *s2, size_t n);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strnstr(const char *haystack,\
const char *needle, size_t len);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_atoi(const char *str);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);

/*
** Part two
*/

void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s1, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);
char			*ft_itoa(int n);
void			ft_putchar(char c);
void			ft_putstr(char const *s);
void			ft_putendl(char const *s);
void			ft_putnbr(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);

/*
** Bonus part
*/

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

t_list			*ft_lstnew(void const *content, size_t constent_size);
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

/*
** My functions
*/

int				ft_isprime(unsigned long n);
int				ft_atoibase(const char *str, int base);
int				ft_isin(char c, const char *str);
int				ft_reduce(int *arr, size_t size, int (*f)(int a, int b));
int				ft_floor(float n);
int				ft_ceil(float n);
double			ft_sqrt(double n);
size_t			ft_wordlen(const char *s, char c);
size_t			ft_wordnum(const char *s, char c);
char			*ft_strndup(const char *s1, size_t n);
char			*ft_itoabase(int n, int base);
char			*ft_strrev(const char *s);
void			ft_putflt(float n, size_t precision);
void			*ft_memrealloc(void *ptr, size_t size);


#endif
