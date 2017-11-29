/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   print_str_pad.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/25 10:14:03 by alexis       #+#   ##    ##    #+#       */
/*   Updated: 2017/11/29 10:07:20 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdarg.h>
#include <libft.h>

int		print_str_pad(char *p, va_list list)
{
	int		pad_size;
	char	*s;
	int		diff;
	int		i;

	if ((*++p) == '*' && (*p != '\0' && *++p == 's'))
	{
		pad_size = va_arg(list, int);
		s = va_arg(list, char *);
		diff = pad_size - (int)ft_strlen(s);
		i = -1;
		while (++i < diff)
			ft_putchar(' ');
		ft_putstr(s);
		return (2);
	}
	return (0);
}
