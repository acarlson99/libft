/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 16:13:51 by acarlson          #+#    #+#             */
/*   Updated: 2018/10/20 12:46:59 by acarlson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <string.h>

# include <unistd.h>

# define RET_COND(cond,ret) if(cond) return (ret)
# define NULL_CHECK(x) if(x) return (NULL)
# define MIN(a,b) (a < b) ? a : b
# define MAX(a,b) (a > b) ? a : b
# define ABS(x) (x < 0) ? -x : x

# define ISALPHA(c) ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
# define ISDIGIT(c) (c >= '0' && c <= '9')
# define ISALNUM(c) (ISALPHA(c) || ISDIGIT(c))
# define ISASCII(c) (c >= 0 && c <= 0177)
# define ISPRINT(c) (c >= 040 && c <= 0176)
# define TOUPPER(c) ((c >= 'a' && c <= 'z') ? c & '_' : c)
# define TOLOWER(c) ((c >= 'A' && c <= 'Z') ? c | ' ' : c)

/*
** SET
*/

# define S_BOL		"\e[1m"
# define S_DIM		"\e[2m"
# define S_UND		"\e[4m"
# define S_BLN		"\e[5m"
# define S_HID		"\e[8m"
# define S_INV		"\e[7m"
# define S_RST_ALL	"\e[0m"
# define S_RST_BLD	"\e[21m"
# define S_RST_DIM	"\e[22m"
# define S_RST_UND	"\e[24m"
# define S_RST_BLN	"\e[25m"
# define S_RST_INV	"\e[27m"
# define S_RST_HID	"\e[28m"

/*
** FOREGROUND
*/

# define F_BLK		"\e[30m"
# define F_RED		"\e[31m"
# define F_GRN		"\e[32m"
# define F_YLW		"\e[33m"
# define F_BLU		"\e[34m"
# define F_MGN		"\e[35m"
# define F_CYN		"\e[36m"
# define F_GRY		"\e[37m"
# define F_WHT		"\e[97m"
# define F_LGRY		"\e[37m"
# define F_DGRY		"\e[90m"
# define F_LRED		"\e[91m"
# define F_LGRN		"\e[92m"
# define F_LYLW		"\e[93m"
# define F_LBLU		"\e[94m"
# define F_LMGN		"\e[95m"
# define F_LCYN		"\e[96m"
# define F_DFT		"\e[39m"

/*
** BACKGROUND
*/

# define B_BLK		"\e[40m"
# define B_RED		"\e[41m"
# define B_GRN		"\e[42m"
# define B_YLW		"\e[43m"
# define B_BLU		"\e[44m"
# define B_MGN		"\e[45m"
# define B_CYN		"\e[46m"
# define B_GRY		"\e[47m"
# define B_LGRY		"\e[47m"
# define B_DGRY		"\e[100m"
# define B_LRED		"\e[101m"
# define B_LGRN		"\e[102m"
# define B_LYLW		"\e[103m"
# define B_LBLU		"\e[104m"
# define B_LMGN		"\e[105m"
# define B_LCYN		"\e[106m"
# define B_WHT		"\e[107m"
# define B_DFT		"\e[49m"

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
void			ft_putstr(char *s);
void			ft_putendl(char const *s);
void			ft_putnbr(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);

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

typedef enum	e_bool
{
	false,
	true
}				t_bool;

int				ft_isprime(unsigned long n);
int				ft_atoibase(const char *str, int base);
int				ft_isin(char c, const char *str);
size_t			ft_wordlen(const char *s, char c);
size_t			ft_wordnum(const char *s, char c);
char			*ft_strndup(const char *s1, size_t n);
char			*ft_itoabase(int n, int base);
char			*ft_strrev(const char *s);

#endif
