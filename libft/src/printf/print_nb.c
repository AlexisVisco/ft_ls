/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   print_nb.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/24 20:16:41 by alexis       #+#   ##    ##    #+#       */
/*   Updated: 2017/11/29 10:09:45 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdarg.h>
#include <libft.h>

int		print_nb(char *p, va_list list)
{
	if ((*++p) == 'd' || (*p) == 'i')
	{
		ft_putnbr(va_arg(list, int));
		return (1);
	}
	return (0);
}
