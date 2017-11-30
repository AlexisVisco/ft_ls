/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lst_sort.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/26 11:33:52 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/30 16:09:39 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	lst_sort(t_list **lst, int (*comparator)())
{
	int		changed;
	t_list	*current;

	if (!lst || !*lst || !comparator)
		return ;
	changed = 1;
	while (changed)
	{
		changed = 0;
		current = *lst;
		while (current->next)
		{
			if (comparator(current->content, current->next->content) > 0)
			{
				lst_swap(current, current->next);
				changed = 1;
			}
			current = current->next;
		}
	}
}

static void		heapify(t_list **lst, int n, int i, int (*cmp)())
{
	int largest;
	int l;
	int r;

	largest = i;
	l = 2 * i + 1;
	r = 2 * i + 2;
	if (l < n && cmp(lst_get(lst, l), lst_get(lst, largest)))
		largest = l;
	if (r < n && cmp(lst_get(lst, r), lst_get(lst, largest)))
		largest = r;
	if (largest != i)
	{
		lst_swap(lst_get(lst, i), lst_get(lst, largest));
		heapify(lst, n, largest, cmp);		
	}
}

void	lst_sort_heap(t_list **lst, int (*comparator)())
{
	int s;
	int i;
	
	s = lst_size(*lst);
	i = (s/2) - 1;
	while (i >= 0)
	{
		heapify(lst, s, i, comparator);
		i--;
	}
	i = s-1;
	while (i >= 0)
	{
		lst_swap(lst_get(lst, 0), lst_get(lst, i));
		heapify(lst, i, 0, comparator);
		i--;
	}
}