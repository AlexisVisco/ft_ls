/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   print_int_pad.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/25 10:14:03 by alexis       #+#   ##    ##    #+#       */
/*   Updated: 2017/11/29 10:09:09 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdarg.h>
#include <libft.h>

int		print_int_pad(char *p, va_list list)
{
	int pad_size;
	int s;
	int diff;
	int i;

	if ((*++p) == '*' && (*p != '\0' && *++p == 'i'))
	{
		pad_size = va_arg(list, int);
		s = va_arg(list, int);
		diff = pad_size - ((int)math_intlen(s, 10) + (s < 0 ? 1 : 0));
		i = -1;
		while (++i < diff)
			ft_putchar(' ');
		ft_putnbr(s);
		return (2);
	}
	return (0);
}
