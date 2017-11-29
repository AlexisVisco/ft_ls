/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/27 09:47:15 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/29 21:21:49 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

void	set_default_args(t_args *args)
{
	args->l = 0;
	args->a = 0;
	args->r = 0;
	args->t = 0;
	args->rec = 0;
}

void	debug_args(t_args arguments)
{
	ft_printf("-l: %i\n-a: %i\n-r: %i\n-t: %i\n-R: %i\n", arguments.l,
	arguments.a, arguments.r, arguments.t, arguments.rec);
}

void	set_arg_from_letter(char c, t_args *arguments)
{
	if (c == 'l')
		arguments->l = 1;
	else if (c == 'a')
		arguments->a = 1;
	else if (c == 'r')
		arguments->r = 1;
	else if (c == 't')
		arguments->t = 1;
	else if (c == 'R')
		arguments->rec = 1;
}

void	parse_args(t_args *arguments, int n, char **args)
{
	int i;

	if (n > 2) /** parse arg like ls -a -r -t **/
	{
		i = 0;
		while (++i < n)
			if (args[i][0] == '-')
				set_arg_from_letter(args[i][1], arguments);
	}
	else /** parse arg like ls -lar */
	{
		i = -1;
		while (args[1][++i])
		{
			if (i == 0 && args[1][i] == '-')
				continue ;
			else if (i == 0 && args[1][i] != '-')
				break ;
			else
				set_arg_from_letter(args[1][i], arguments);
		}
	}
}

int		main(int n, char **args)
{
	t_args	arguments;
	t_list	*only_folders;
	
	only_folders = NULL;
	set_default_args(&arguments);
	if (n >= 2)
		parse_args(&arguments, n, args);
	ft_ls_rec(arguments, ".");
	
}
