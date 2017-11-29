/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   printer.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/27 13:51:19 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/29 18:47:32 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_file_info(t_list *content)
{
	t_file_inf *inf;

	inf = (t_file_inf *)content->content;
	ft_printf(
		"\n\ninf {\nparent: %s\nfile_name: %s\npath: %s\nis_dir: %i\n}", 
		inf->parent, inf->file_name, inf->path, inf->is_directory
	);
}