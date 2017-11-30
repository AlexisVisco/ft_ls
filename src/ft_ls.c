/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ls.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/29 09:28:35 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/30 14:16:17 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

static unsigned long	get_total(t_list *files)
{
	t_file_inf		*inf;
	unsigned long	total;
	struct stat		fs;

	total = 0;
	while (files)
	{
		inf = (t_file_inf *)files->content;
		if (stat(inf->path, &fs) < 0)
			continue ;
		total += (unsigned long)fs.st_blocks;
		files = files->next;
	}
	return (total);
}

static void				files_a(t_list **files, t_list **folders, t_args args)
{
	t_file_inf	*inf;
	t_max_inf	*maxi;
	t_list		**head;

	maxi = fill_max(*files);
	head = files;
	while (*files)
	{
		inf = (t_file_inf *)(*files)->content;
		if (inf->is_directory && args.rec)
		{
			lst_push(folders, lst_new(inf->path, sizeof(char) *
			ft_strlen(inf->path)));
		}
		print_file(args, inf, maxi);
		free((*files)->content);
		files = &(*files)->next;
	}
	lst_clear(head);
	free(maxi);
}

static void				folders_a(t_list **folders, t_args args)
{
	t_list	**head;

	head = folders;
	while (*folders)
	{
		ft_ls(args, (char *)(*folders)->content);
		free((*folders)->content);
		folders = &(*folders)->next;
	}
	lst_clear(head);
}

void					ft_ls(t_args args, char *file_path)
{
	t_list			*folders;
	t_list			*files;
	int				total;
	static char		first = 1;

	files = NULL;
	folders = NULL;
	if (args.rec && !first)
		ft_putchar('\n');
	first = 0;
	get_files_in_folder(args, file_path, &files);
	total = get_total(files);
	sort_files(args, &files);
	if (args.rec && !ft_strequ(".", file_path))
		ft_printf("%s:\n", file_path);
	if (args.l && total)
		ft_printf("total %i\n", total);
	files_a(&files, &folders, args);
	if (args.rec)
		folders_a(&folders, args);
}
