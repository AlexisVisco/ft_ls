/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ls.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/29 09:28:35 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/29 21:19:17 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

static unsigned long	get_total(t_list *files)
{
	t_file_inf		*inf;
	unsigned long	total;
	
	total = 0;
	while (files)
	{
		inf = (t_file_inf *)files->content;
		struct stat		fs;
		if(stat(inf->path, &fs) < 0 )
			continue ;
		total += (unsigned long)fs.st_blocks;
		files = files->next;
	}
	return total;
}

void					ft_ls_rec(t_args args, char *file_path)
{
	t_list		*folders;
	t_list		*files;
	t_file_inf	*inf;
	t_max_inf	*maxi;
	
	files = NULL;
	get_files_in_folder(args, file_path, &files);
	sort_files(args, &files);
	if (args.rec && !ft_strequ(".", file_path))
		ft_printf("%s:\n", file_path);
	if (args.l)
		printf("total %lu\n", get_total(files));
	maxi = fill_max(files);
	folders = NULL;
	while (files)
	{
		inf = (t_file_inf *)files->content;
		if (inf->is_directory && args.rec)
		{
			lst_push(&folders, lst_new(inf->path, sizeof(char) *
			ft_strlen(inf->path)));
		}
		print_file(args, inf, maxi);
		free(files->content);
		files = files->next;
	}
	if (args.rec)
		ft_putchar('\n');
	//lst_clear(&files);
	if (args.rec)
		while (folders)
		{
			ft_ls_rec(args, (char *)folders->content);
			free(folders->content);
			folders = folders->next;
		}
	//lst_clear(&folders);
}