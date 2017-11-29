/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lst_remove_at.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/26 10:26:05 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/29 10:20:13 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	lst_remove_at(t_list **lst, int where)
{
	t_list	*node;
	t_list	*prev;
	int		i;

	if ((node = *lst) == NULL)
		return ;
	prev = NULL;
	i = 0;
	while (node)
	{
		if (i == where)
		{
			if (prev)
				prev->next = node->next;
			else
				*lst = node->next;
			free(node);
			return ;
		}
		prev = node;
		node = node->next;
		i++;
	}
}
