/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   print_hex.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/25 10:32:07 by alexis       #+#   ##    ##    #+#       */
/*   Updated: 2017/11/29 10:09:51 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdarg.h>
#include <libft.h>

int		print_hex(char *p, va_list list)
{
	if ((*++p) == 'X')
	{
		ft_putnbrbase(va_arg(list, int), "0123456789ABCDEF");
		return (1);
	}
	else if ((*p) == 'x')
	{
		ft_putnbrbase(va_arg(list, int), "0123456789abcdef");
		return (1);
	}
	return (0);
}
