/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   print_str.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/24 19:21:53 by alexis       #+#   ##    ##    #+#       */
/*   Updated: 2017/11/29 10:09:20 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdarg.h>
#include <libft.h>

int		print_str(char *p, va_list list)
{
	if ((*++p) == 's')
	{
		ft_putstr(va_arg(list, char *));
		return (1);
	}
	return (0);
}
