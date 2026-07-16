/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianda <adrianda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 22:21:59 by adrianda          #+#    #+#             */
/*   Updated: 2026/07/16 17:11:40 by adrianda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>


typedef struct	s_node
{
	int				value;
	int				index;
	struct s_node	*next;
} t_node;

typedef struct	s_ps
{
	t_node	*stack_a;
	t_node	*stack_b;
	int	op_sa;
	int	total_ops;
} t_ps;

//Classificação e Conversão de Caracteres
int			ft_isdigit(int c);
//Manipulação e Busca em Memória
void		*ft_memset(void *s, int c, size_t n);
void		ft_bzero(void *s, size_t n);
//Manipulação e Busca em Strings
size_t		ft_strlen(const char *str);
char		*ft_strchr(const char *s, int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
long long			ft_atol(const char *nptr);
//Manipulação Avançada de Strings
char		*ft_substr(const char *s, unsigned int start, size_t len);
char		*ft_strjoin(const char *s1, const char *s2);
char		**ft_split(char const *s, char c);
//Escrita em File Descriptors
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
//Alocação Dinâmica Base
void		*ft_calloc(size_t nmemb, size_t size);
char		*ft_strdup(const char *s);
// Limpeza de matriz
void	free_vector(char **vector);
#endif