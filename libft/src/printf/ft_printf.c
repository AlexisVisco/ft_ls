/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/24 19:15:58 by alexis       #+#   ##    ##    #+#       */
/*   Updated: 2017/11/29 10:08:54 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include "f_printf.h"
#define NB_FUNCS 25

static void		fill_functions(int (**functions)(char *, va_list))
{
	functions[0] = print_char;
	functions[1] = print_nb;
	functions[2] = print_str;
	functions[3] = print_str_pad;
	functions[4] = print_hex;
	functions[5] = print_binary;
	functions[6] = print_int_pad;
}

void			ft_printf(char *fmt, ...)
{
	va_list		argp;
	int			(*functions[NB_FUNCS])(char *, va_list);
	int			i;
	int			custom_format;

	fill_functions(functions);
	va_start(argp, fmt);
	while (*fmt)
	{
		i = -1;
		custom_format = 0;
		while (*fmt == '%' && ++i < NB_FUNCS)
		{
			custom_format = functions[i](fmt, argp);
			if (custom_format)
			{
				fmt += custom_format;
				break ;
			}
		}
		if (!custom_format)
			ft_putchar(*fmt);
		fmt++;
	}
	va_end(argp);
}
