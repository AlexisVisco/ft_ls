/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strjoin_multiple.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/26 21:41:12 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/26 21:43:02 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_multiple(char *str, ...)
{
	va_list	ap;
	char	*tmp;
	char	*cpy;
	int		i;

	i = 0;
	va_start(ap, str);
	while (42)
	{
		tmp = va_arg(ap, char *);
		if (!tmp)
			break ;
		cpy = ft_strdup(str);
		if (i++ > 0)
			free(str);
		str = ft_strjoin(cpy, tmp);
		free(cpy);
	}
	va_end(ap);
	return (str);
}
