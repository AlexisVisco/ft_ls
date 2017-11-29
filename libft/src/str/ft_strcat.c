/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strcat.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/08 16:08:52 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/25 10:48:34 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	int index;
	int from;

	from = ft_strlen_classic(dest);
	index = 0;
	while (src[index] != '\0')
	{
		dest[index + from] = src[index];
		index++;
	}
	dest[index + from] = '\0';
	return (dest);
}
