/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   max_fn.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/29 13:53:10 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/30 13:33:37 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

int		max_link_user(int ref, t_file_inf *i, struct stat fs)
{
	(void)i;
	return (ref < math_intlen(fs.st_nlink, 10)
	? math_intlen(fs.st_nlink, 10) : -1);
}

int		max_file_size(int ref, t_file_inf *i, struct stat fs)
{
	int b;
	int s;

	b = (i->type == DT_CHR || i->type == DT_BLK);
	s = b ? fs.st_rdev : fs.st_size;
	return (ref < math_intlen(s, 10) ? math_intlen(s, 10) : -1);
}

int		max_user(int ref, t_file_inf *i, struct stat fs)
{
	struct passwd *pw;

	(void)i;
	pw = getpwuid(fs.st_uid);
	if (!pw)
		return (-1);
	return (ref < (int)ft_strlen(pw->pw_name)
	? (int)ft_strlen(pw->pw_name) : -1);
}

int		max_group(int ref, t_file_inf *i, struct stat fs)
{
	struct group *gr;

	(void)i;
	gr = getgrgid(fs.st_gid);
	return (ref < (int)ft_strlen(gr->gr_name)
	? (int)ft_strlen(gr->gr_name) : -1);
}
