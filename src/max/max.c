/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   max.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/29 13:38:58 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/01 11:11:12 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

int			get_max(t_list *lst, int (*cmp)(int, t_file_inf *, struct stat))
{
	t_file_inf		*i;
	int				max;
	struct stat		fs;
	int				cmp_res;

	max = 0;
	while (lst && lst->content)
	{
		i = (t_file_inf *)lst->content;
		if (stat(i->path, &fs) < 0)
			return (0);
		cmp_res = cmp(max, i, fs);
		if (cmp_res != -1)
			max = cmp_res;
		lst = lst->next;
	}
	return (max);
}

t_max_inf	*fill_max(t_list *lst)
{
	t_max_inf *inf;

	inf = (t_max_inf *)malloc(sizeof(t_max_inf));
	inf->link_user = get_max(lst, max_link_user);
	inf->user = get_max(lst, max_user);
	inf->file_size = get_max(lst, max_file_size);
	inf->group = get_max(lst, max_group);
	return (inf);
}

t_max_inf	*get_default_max(void)
{
	t_max_inf *inf;

	inf = (t_max_inf *)malloc(sizeof(t_max_inf));
	inf->file_size = 0;
	inf->user = 0;
	inf->link_user = 0;
	inf->group = 0;
	return (inf);
}
