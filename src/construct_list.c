/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   construct_list.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/27 10:20:50 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/30 11:26:32 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"
#include "f_colors.h"

static void	path_join(char *path, char *path_folder, char *file_path_folder)
{
	ft_strcpy(path, path_folder);
	ft_strcat(path, "/");
	ft_strcat(path, file_path_folder);
}

void		get_files_in_folder(t_args args, char *path_folder, t_list **l)
{
	DIR				*dir;
	struct dirent	*entry;
	t_file_inf		*file_info;
	char			path[4096];

	if (!(dir = opendir(path_folder)))
		return ;
	while ((entry = readdir(dir)) != NULL)
	{
		file_info = (t_file_inf *)malloc(sizeof(t_file_inf));
		path_join((char *)path, path_folder, entry->d_name);
		ft_strcpy(file_info->parent, path_folder);
		ft_strcpy(file_info->path, path);
		ft_strcpy(file_info->file_name, entry->d_name);
		file_info->is_directory = 0;
		file_info->type = entry->d_type;
		if (entry->d_type == DT_DIR)
			file_info->is_directory = file_info->file_name[0] == '.' ? 0 : 1;
		if ((args.a && file_info->file_name[0] == '.') ||
		(file_info->file_name[0] != '.'))
		{
			lst_add(l, lst_new(file_info, sizeof(t_file_inf)));
		}
	}
	closedir(dir);
}
