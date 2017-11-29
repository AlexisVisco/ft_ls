/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   print_binary.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/25 10:32:07 by alexis       #+#   ##    ##    #+#       */
/*   Updated: 2017/11/29 10:10:02 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdarg.h>
#include <libft.h>

int		print_binary(char *p, va_list list)
{
	if ((*++p) == 'b')
	{
		ft_putnbrbase(va_arg(list, int), "01");
		return (1);
	}
	return (0);
}
