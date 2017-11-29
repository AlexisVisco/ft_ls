/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putubase.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/26 21:58:48 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/29 10:05:33 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_putubase(unsigned long n, unsigned int base)
{
	ft_putubase_fd(1, n, base);
}
