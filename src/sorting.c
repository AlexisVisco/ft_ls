/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sorting.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/29 10:39:37 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/04 10:02:12 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

static int	sort_alpha(void *f, void *s)
{
	t_file_inf *infa;
	t_file_inf *infb;

	infa = (t_file_inf *)f;
	infb = (t_file_inf *)s;
	return (ft_strcmp(infa->file_name, infb->file_name) > 0);
}

static int	sort_time(void *f, void *s)
{
	t_file_inf		*infa;
	t_file_inf		*infb;
	struct stat		fsa;
	struct stat		fsb;

	infa = (t_file_inf *)f;
	infb = (t_file_inf *)s;
	if (get_stat(infa, &fsa) < 0 || get_stat(infb, &fsb) < 0)
		return (0);
	return (fsa.st_mtime < fsb.st_mtime);
}

void		sort_files(t_args args, t_list **files)
{
	lst_sort(files, args.t ? sort_time : sort_alpha);
}
