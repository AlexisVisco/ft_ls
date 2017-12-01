/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/27 09:47:15 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/01 12:12:23 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

void		set_default_args(t_args *args)
{
	args->l = 0;
	args->a = 0;
	args->r = 0;
	args->t = 0;
	args->rec = 0;
}

static void	set_arg_from_letter(char c, t_args *a)
{
	a->l = (c == 'l') ? 1 : a->l;
	a->a = (c == 'a') ? 1 : a->a;
	a->r = (c == 'r') ? 1 : a->r;
	a->t = (c == 't') ? 1 : a->t;
	a->rec = (c == 'R') ? 1 : a->rec;
}

static int	parse_args(t_args *argts, int n, char **args, t_list **f)
{
	int i;

	if (n >= 2)
	{
		i = 0;
		while (++i < n)
		{
			if (args[i][0] == '-')
			{
				while (*args[i]++)
				{
					if (ft_strrchr("-lartR", *args[i]) == NULL)
					{
						display_error(INVALID_ARG, &(args[i][0]));
						return (0);
					}
					set_arg_from_letter(*args[i], argts);
				}
			}
			else
				lst_push(f, lst_new(args[i], sizeof(char) *
				ft_strlen(args[i])));
		}
	}
	return (1);
}

int			main(int n, char **args)
{
	t_args	params;
	t_list	*only_folders;

	only_folders = NULL;
	set_default_args(&params);
	if (n >= 2)
		if (!parse_args(&params, n, args, &only_folders))
			return (0);
	if (lst_size(only_folders) != 0)
	{
		while (only_folders)
		{
			if (!ft_ls(params, (char *)only_folders->content))
				if (!ft_ls_file(params, (char *)only_folders->content))
					display_error(NO_FILE_OR_FOLDER,
					(char *)only_folders->content);
			free(only_folders->content);
			only_folders = only_folders->next;
		}
		free(only_folders);
	}
	else
		ft_ls(params, ".");
	return (1);
}
