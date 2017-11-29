/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putubase_fd.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/26 21:56:21 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/29 10:02:56 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_putubase_fd(int fd, unsigned long n, unsigned int base)
{
	char	res[42];
	int		i;

	i = 0;
	ft_bzero(&res, sizeof(res));
	while (1)
	{
		res[i] = n % base >= 10 ? 'a' - 10 + n % base : '0' + n % base;
		n /= base;
		if (!n)
			break ;
		i++;
	}
	while (i >= 0)
		ft_putchar_fd(fd, res[i--]);
}
