/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftopt.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <glafitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/02 21:33:13 by glafitte          #+#    #+#             */
/*   Updated: 2015/06/02 23:24:42 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTOPT_H
# define LIBFTOPT_H

# include <string.h>

# define RED			"\033[1;31m"
# define GREEN			"\033[1;32m"
# define CYAN			"\033[1;36m"
# define BLUE			"\033[1;34m"
# define YELLOW			"\033[1;33m"

# define ERR_LOC(str)	ft_err(__FILE__, __LINE__, str)

typedef struct			s_opt
{
	char				opt;
	int					val;
	char				*value;
	char				**arg;
	struct s_opt		*next;
	struct s_opt		*prev;
}						t_opt;

char					*ft_strdup(char *src);
int						ft_err(char *file, int line, char *msg);
int						ft_fprintf(int fd, char const *format, ...);
int						ft_print_tab(char **tab);
int						ft_count_tab(char **tab);
char					**ft_tabdup(char **src);
void					*ft_memalloc(size_t size);
void					ft_bzero(void *s, size_t n);
void					ft_freetab(char ***tab);
void					ft_memdel(void **ap);
int						ft_strlen(const char *str);
char					ft_strcmp(const char *s1, const char *s2, char equ);
void					ft_putstr_color(const char *str, char *color, int i);
char					*ft_strnew(size_t size);
int						ft_atoi(char *str);
char					*ft_itoa(int n);
int						ft_free_env(t_opt *list);
t_opt					*ft_create_list(char **arg);
void					ft_add_elem(t_opt **list, char *var);
int						ft_free_env(t_opt *list);
int						ft_option(int argc, char **argv, char const *opt,
									int *start);

#endif
