/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putdouble_fd.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/26 21:53:19 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/29 10:02:42 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_putdouble_fd(int fd, double d)
{
	int		i;

	i = 0;
	ft_putnbr_fd(fd, (int)d);
	ft_putchar_fd(fd, '.');
	d -= (int)d;
	while (i++ < 6)
		d *= 10;
	ft_putnbr_fd(fd, d);
}
