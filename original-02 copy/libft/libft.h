/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:21:17 by hmaciel-          #+#    #+#             */
/*   Updated: 2023/05/25 21:09:50 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/**********************
	LIBS
**********************/

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

/**********************
	BONUS TYPEDEF
**********************/
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct s_printf
{
	va_list	args;
	int		f_hash;
	int		f_align;
	char	f_stype;
	int		f_zpad;
	int		w_num;
	int		p_dot;
	int		p_num;
	char	e_sign;
	int		e_val;
	char	e_symb;
	char	e_radix;
	char	at;
	char	arg_len1;
	char	arg_len2;
	int		arg_zero;
	int		res_len;
	int		pf_len;
}	t_printf;

/**********************
 FUNCTIONS PROTOTYPES
**********************/

int				ft_atoi(const char *nptr);
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t nmemb, size_t size);
char			*ft_charjoin(char const *s1, char const c);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
char			*ft_itoa(int n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memset(void *s, int c, size_t n);
void			ft_putchar_fd(char c, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
char			**ft_split(char const *s, char c);
char			*ft_strchr(const char *s, int c);
char			*ft_strdup(const char *s);
char			*ft_strjoin(char const *s1, char const *s2);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
size_t			ft_strlen(const char *s);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strnstr(const char *big, const char *little, size_t len);
char			*ft_strrchr(const char *s, int c);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
int				ft_tolower(int c);
int				ft_toupper(int c);
t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **lst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *), \
				void (*del)(void *));
/**********ft_pf_all2s_1.c**********/
int				ft_pf_tools_d2s(t_printf *f, unsigned int n, char *str);
int				ft_pf_tools_i2s(char arg_type, unsigned int n, char *str);
int				ft_pf_tools_f2s(t_printf *f, char *str);
int				ft_pf_tools_f2s_power(t_printf *f, char *arg_arr, \
				char *str, void *arg);
void			ft_pf_tools_f2s_exp(t_printf *f, long double *arg);
/**********ft_pf_all2s_2.c**********/
int				ft_pf_tools_f2s_fill_arr(char base, char *arg_arr, void *arg);
int				ft_pf_tools_f2s_round(t_printf *f, int k, char *arg_arr);
int				ft_pf_tools_f2s_round_offset(t_printf *f);
int				ft_pf_tools_f2s_mantissa(t_printf *f, char dot, \
				char *arg_arr, char *str);
/* ft_pf_fwp2f.c - prepare t_printf for each new arg */
const char		*ft_pf_all2f(t_printf *flgs, const char *s);
const char		*ft_pf_f2f(t_printf *flgs, const char *s);
const char		*ft_pf_w2f(t_printf *flgs, const char *s);
const char		*ft_pf_p2f(t_printf *f, const char *s);
const char		*ft_pf_l2f(t_printf *flgs, const char *s);
/*	ft_pf_fwp2s.c */
int				ft_pf_fwp_p2s(t_printf *f, char *digit, int i);
int				ft_pf_fwp_war2s(t_printf *f, char *ds, int i);
int				ft_pf_fwp_wal2s(t_printf *f, char *ds, int i);
int				ft_pf_fwp_hash2s(t_printf *f, char *digit, int i);
void			ft_pf_write(t_printf *f, char *res);
/* ft_pf_tools1.c */
void			ft_pf_fwp_u(t_printf *f, void *arg);
char			ft_pf_tools_d2c(const int n, char radix);
char			*ft_pf_tools_strrev(char *str, int j);
char			ft_pf_tools_radix(char base);
int				ft_isdigit(int c);
/* ft_pf_type_numbers.c*/
void			ft_pf_type_fega(t_printf *f);
void			ft_pf_type_fega_flags(t_printf *f);
void			ft_pf_type_g(t_printf *f);
void			ft_pf_type_iduox(t_printf *f);
void			ft_pf_type_n(t_printf *f);
/* ft_pf_type_scp.c*/
void			ft_pf_type_s(t_printf *f);
int				ft_pf_type_s2s(t_printf *f, char *res, char *ds, int ds_len);
void			ft_pf_type_c(t_printf *f);
void			ft_pf_type_p(t_printf *f);
int				ft_pf_type_p2s(t_printf *f, char *res, unsigned long long arg);
/*	ft_printf.c -  where the printf and most directly functions reside */
int				ft_printf(const char *format, ...);
const char		*ft_pf_type(t_printf *flgs, const char *s);
void			ft_pf_f_init(t_printf *f);
#endif
