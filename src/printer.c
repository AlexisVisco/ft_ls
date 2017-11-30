/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   printer.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/29 11:32:42 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/30 11:52:37 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

static void		print_permissions(mode_t mode)
{
	ft_putchar((S_ISDIR(mode)) ? 'd' : '-');
	ft_putchar((mode & S_IRUSR) ? 'r' : '-');
	ft_putchar((mode & S_IWUSR) ? 'w' : '-');
	ft_putchar((mode & S_IXUSR) ? 'x' : '-');
	ft_putchar((mode & S_IRGRP) ? 'r' : '-');
	ft_putchar((mode & S_IWGRP) ? 'w' : '-');
	ft_putchar((mode & S_IXGRP) ? 'x' : '-');
	ft_putchar((mode & S_IROTH) ? 'r' : '-');
	ft_putchar((mode & S_IWOTH) ? 'w' : '-');
	ft_putchar((mode & S_IXOTH) ? 'x' : '-');
}

static void		print_date(time_t *t)
{
	char	buf[50];
	char	*date;
	int		i;
	int		len;

	date = ctime_r(t, buf);
	i = 3;
	len = ft_strlen(date) - 10;
	while (++i <= len)
		ft_putchar(date[i]);
}

void			print_link(char *path)
{
	int		path_size;
	char	*path_save;

	if (!(path_save = ft_strdup(path)))
		return ;
	path_size = readlink(path, path, 1024);
	if (path_size > 0)
	{
		path[path_size] = '\0';
		ft_putstr(" -> ");
		ft_putstr(path);
	}
	ft_strcpy(path, path_save);
	free(path_save);
}

void			print_file_size(t_file_inf *inf, struct stat fs, t_max_inf *mi)
{
	int b;

	b = (inf->type == DT_CHR || inf->type == DT_BLK);
	ft_printf(" %*i ", mi->file_size, b ? fs.st_rdev : fs.st_size);
}

void			print_file(t_args args, t_file_inf *inf, t_max_inf *mi)
{
	struct stat		fs;
	struct passwd	*pw;
	struct group	*gr;

	if (!args.l)
	{
		ft_printf("%s\n", inf->file_name);
		return ;
	}
	if (stat(inf->path, &fs) < 0)
		return ;
	pw = getpwuid(fs.st_uid);
	gr = getgrgid(fs.st_gid);
	print_permissions(fs.st_mode);
	ft_printf("  %*i %*s  %*s",
		mi->link_user, fs.st_nlink,
		mi->user, !pw ? "" : pw->pw_name,
		mi->group, gr->gr_name);
	print_file_size(inf, fs, mi);
	print_date(&fs.st_mtime);
	ft_printf(" %s", inf->file_name);
	if (inf->type == DT_LNK)
		print_link(inf->path);
	ft_putchar('\n');
}
