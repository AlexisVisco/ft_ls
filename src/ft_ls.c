/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ls.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/29 09:28:35 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/04 10:06:00 by aviscogl    ###    #+. /#+    ###.fr     */
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
		if (get_stat(inf, &fs) < 0)
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

int						ft_ls_file(t_args args, char *file_path)
{
	struct stat	fs;
	t_file_inf	*i;
	t_max_inf	*m;

	i = (t_file_inf *)malloc(sizeof(t_file_inf));
	m = get_default_max();
	ft_strcpy(i->path, file_path);
	ft_strcpy(i->file_name, ft_strbasename((const char*)file_path));
	i->type = DT_REG;
	if (get_stat(i, &fs) < 0)
		return (0);
	print_file(args, i, m);
	free(i);
	free(m);
	ft_putchar('\n');
	return (1);
}

int						ft_ls(t_args args, char *path)
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
	if (!get_files_in_folder(args, path, &files))
		return (0);
	total = get_total(files);
	sort_files(args, &files);
	if (args.r)
		lst_reverse(&files);
	if (args.rec && !first)
		ft_printf("%s:\n", path);
	if (args.l && total)
		ft_printf("total %i\n", total);
	files_a(&files, &folders, args);
	if (args.rec)
		folders_a(&folders, args);
	return (1);
}
