/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 00:01:32 by nuferron          #+#    #+#             */
/*   Updated: 2023/05/14 00:01:34 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include "libft/libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_printf
{
	char	padd_type;
	char	sign;
	char	hex;
	int		width;
	char	precision;
	int		prec_width;
}	t_flags;

int		ft_printf(char const *format, ...);
int		print_char(int c);
int		print_string(char *str);
int		print_num(int n);
int		print_pointer(unsigned long long num);
int		print_unsigned_num(unsigned int num);
int		print_hex_min(unsigned int dec_num);
int		print_hex_cap(unsigned int dec_num);
int		ft_printf_bonus(char const *format, ...);
int		eval_flags(char *format, int i, t_flags *flags);
void	default_flags(t_flags *flags);
int		capturing_flags(char *format, int i, t_flags *flags);
int		capturing_flags_char(char *format, int i, t_flags *flags);
int		is_specifier(char c);
int		char_bonus(int c, t_flags *flags);
int		string_bonus(char *str, t_flags *flags);
int		num_bonus(int num, t_flags *flags);
int		pointer_bonus(unsigned long long num, t_flags *flags);
int		unsigned_bonus(unsigned int num, t_flags *flags);
int		hex_min_bonus(unsigned int dec_num, t_flags *flags);
int		hex_cap_bonus(unsigned int dec_num, t_flags *flags);
int		percentage_bonus(t_flags *flags);
int		hex_len(unsigned int num);
int		precision_len(char type, int len, t_flags *flags);
int		precision_padding(char *str, int len, int len_precision);
char	*add_padding(char *str, t_flags *flags);
char	*add_sign(char *str, t_flags *flags);
void	sign_to_front(char *str);
char	*add_ox(char *str, t_flags *flags);
void	ox_to_front(char *str, t_flags *flags);
int		unsigned_len(unsigned int num);
int		pointer_len(unsigned long long num);
int		hex_len(unsigned int num);
#endif
