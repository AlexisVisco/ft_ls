/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ls.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/27 09:46:07 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/30 11:34:57 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef _FT_LS_H
# define _FT_LS_H

# include "libft.h"
# include <unistd.h>
# include <sys/types.h>
# include <dirent.h>
# include <sys/stat.h>
# include <sys/time.h>
# include <pwd.h>
# include <time.h>
# include <grp.h>
# include <sys/types.h>
# include <stdlib.h>

# include <stdio.h>

# define MINOR(x) ((x) & 0xffffff)
# define MAJOR(x) (((x) >> 24) & 0xff)

typedef struct	s_args
{
	int			l;
	int			a;
	int			r;
	int			t;
	int			rec;
}				t_args;

typedef struct	s_file_inf
{
	char		parent[4096];
	char		path[4096];
	char		file_name[4096];
	int			is_directory;
	int			type;
}				t_file_inf;

typedef struct	s_max_inf
{
	size_t 		link_user;
	size_t 		user;
	size_t 		group;
	size_t 		file_size;
}				t_max_inf;


void			ft_ls(t_args args, char *file_path);

void			get_files_in_folder(t_args args, char *path_folder, t_list **l);
void			sort_files(t_args args, t_list **files);
void			print_file_info(t_list *content);
void			print_file(t_args args, t_file_inf *inf, t_max_inf *mi);
void			sort_files(t_args args, t_list **l);

t_max_inf		*fill_max(t_list *lst);
int				max_link_user(int ref, t_file_inf *i, struct stat fs);
int				max_file_size(int ref, t_file_inf *i, struct stat fs);
int				max_user(int ref, t_file_inf *i, struct stat fs);
int				max_group(int ref, t_file_inf *i, struct stat fs);

#endif
