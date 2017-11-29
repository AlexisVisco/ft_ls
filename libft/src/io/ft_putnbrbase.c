/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putnbrbase.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/25 10:27:16 by alexis       #+#   ##    ##    #+#       */
/*   Updated: 2017/11/29 10:03:18 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbrbase_fd_inner(int nbr, char *base, size_t baselen,
				int fd)
{
	if (nbr >= (int)baselen)
	{
		ft_putnbrbase_fd_inner(nbr / baselen, base, baselen, fd);
		ft_putnbrbase_fd_inner(nbr % baselen, base, baselen, fd);
	}
	else
		ft_putchar_fd(base[nbr], fd);
}

void		ft_putnbrbase(int nbr, char *base)
{
	ft_putnbrbase_fd_inner(nbr, base, ft_strlen(base), 1);
}
