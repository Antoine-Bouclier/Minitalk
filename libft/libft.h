/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 08:43:53 by abouclie          #+#    #+#             */
/*   Updated: 2025/02/26 15:47:32 by abouclie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdint.h>
# include <stdarg.h>

void		ft_bzero(void *s, size_t n);
char		*ft_strdup(const char *s1);
char		*ft_strjoin(char *s1, char *s2, ssize_t b_read);
char		*ft_strnstr(const char *big, const char *little, size_t len);
size_t		ft_strlen(const char *s);
long int	ft_atoi(const char *nptr);
void		ft_putnbr(unsigned int pid);
void		ft_putstr_fd(char *s, int fd);
void		*ft_memcpy(void *dest, const void *src, size_t n);

/* GNL */
char		*ft_strccpy(char *line);
char		*get_next_line(int fd);

/* Printf */
char		*ft_itoa_base(long int n, char *base);
char		*ft_itoa_ptr(uintptr_t n, char *base);
int			ft_intlen(long n, int bsize);
int			ft_print_ptr(unsigned long long n);
int			ft_printnbr(long int n, char *base);
int			ft_printstr(char *str);
int			ft_ptrlen(uintptr_t n);
int			ft_printf(const char *str, ...);
void		ft_putstr(char *str);

#endif