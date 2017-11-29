/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   math_intlen.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/16 11:05:16 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/29 10:13:03 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		math_intlen(int n, int bse)
{
	unsigned int len;
	unsigned int x;

	len = 0;
	x = n > 0 ? n : -n;
	while (x /= bse)
		len++;
	return (len);
}
