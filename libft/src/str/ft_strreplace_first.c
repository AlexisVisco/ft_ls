/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strreplace_first.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/13 14:34:40 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/25 10:52:07 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int		is_query_i(const char *query, const char *str, int index)
{
	int i;
	int ok;

	ok = 1;
	i = 0;
	while (query[i])
	{
		if (query[i] != str[i + index])
		{
			ok = 0;
			break ;
		}
		i++;
	}
	if (ok)
		return (1);
	return (0);
}

static int		strstr_i(const char *str, const char *query)
{
	int i;

	i = 0;
	if (ft_strlen(query) == 0)
		return (-1);
	while (str[i])
	{
		if (str[i] == query[0])
		{
			if (is_query_i(query, str, i))
				return (i);
		}
		i++;
	}
	return (-1);
}

static char		*build_str(char *first, char *mid, char *last)
{
	return (ft_strjoin(ft_strjoin(first, mid), last));
}

char			*ft_strreplace_first(char *search, char *replace, char *subject)
{
	int		index;
	char	*str;

	if (!search || !replace || !subject)
		return (NULL);
	if (ft_strstr(subject, search) != NULL)
	{
		index = strstr_i(subject, search);
		if (index == 0)
		{
			str = ft_strsub(subject, ft_strlen(search),
			ft_strlen(subject) - ft_strlen(search));
			return (build_str("", replace, str));
		}
		else
			return (build_str(ft_strsub(subject, 0, index), replace,
			ft_strsub(subject, index + ft_strlen(search),
			ft_strlen(subject) - (index + ft_strlen(search)))));
	}
	return (subject);
}
