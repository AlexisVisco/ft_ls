/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   f_lst.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/25 14:15:22 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/30 16:04:15 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef _F_LST_H
# define _F_LST_H
# include <string.h>
# include <stdlib.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

t_list				*lst_new(void const *content, size_t content_size);
void				lst_add(t_list **list, t_list *n);
t_list				*lst_get(t_list **list, int x);
t_list				*lst_shift(t_list **list);
t_list				*lst_pop(t_list **list);
t_list				*lst_find(t_list *list, void *data_ref, int (*c)());
void				lst_reverse(t_list **list);
void				lst_swap(t_list *a, t_list *b);
void				lst_sort(t_list **lst, int (*c)());
void				lst_sort_heap(t_list **lst, int (*comparator)());
void				ft_list_reverse(t_list **list);
void				lst_remove_at(t_list **list, int x);
void				lst_remove_if(t_list **lst, void *data_ref, int (*c)());
void				lst_clear(t_list **lst);
void				lst_foreach(t_list *lst, void (*f)(t_list *elem));
void				lst_foreach_i(t_list *lst, void (*f)(t_list *elem, int));
t_list				*lst_map(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*lst_collect_if(t_list *lst, void *data_ref, int (*c)());
void				lst_print(t_list *list, void (*print_function)(t_list*));
void				lst_push(t_list **list, t_list *value);
int					lst_size(t_list *list);

#endif
