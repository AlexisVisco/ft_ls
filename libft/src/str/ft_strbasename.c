/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strbasename.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/01 10:33:21 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/01 11:12:05 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strbasename(const char *filename)
{
	char *p;

	p = ft_strrchr(filename, '/');
	return (p ? p + 1 : (char *)filename);
}
