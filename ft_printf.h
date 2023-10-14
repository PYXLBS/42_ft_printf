/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabertha <pabertha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 12:03:04 by pabertha          #+#    #+#             */
/*   Updated: 2023/09/20 12:03:05 by pabertha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <ctype.h>
# include <string.h>
# include <strings.h>
# include <stdio.h>
# include <stdint.h>
# include <limits.h>
# include <stdarg.h>

int					ft_printf(const char *content, ...);
int					ft_putchar(char c);
int					ft_strlen(const char *s);
int					ft_putstr(char *s);
int					ft_putnbr(int n);
int					ft_putuint(unsigned int n);
int					ft_puthex(unsigned long n, char c);
int					ft_putptr_hex(void *ptr);
int					ft_convert(char flag, va_list arg);
char				*ft_strchr(const char *s, int c);
int					ft_handle_content(const char **content);

#endif
