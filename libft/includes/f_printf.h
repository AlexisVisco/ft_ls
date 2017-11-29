/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   f_printf.h                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/25 14:33:19 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/26 12:22:04 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef _F_PRINTF_H
# define _F_PRINTF_H
# include <stdarg.h>

int		print_binary(char *p, va_list list);
int		print_char(char *p, va_list list);
int 	print_hex(char *p, va_list list);
int		print_nb(char *p, va_list list);
int		print_str_pad(char *p, va_list list);
int		print_int_pad(char *p, va_list list);
int		print_str(char *p, va_list list);
void	ft_printf(char *fmt, ...);

#endif