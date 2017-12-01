/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   errors.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/01 09:25:19 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/01 11:10:57 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"
#include "f_colors.h"

void	display_error(t_error_type err, char *arg)
{
	if (err == NO_FILE_OR_FOLDER)
		ft_printf("%sls: %s: No such file or directory.\n%s",
				L_RED, arg, RESET_ALL);
	else if (err == INVALID_ARG)
		ft_printf("%sls: %s: Argument is invalid.\n%s",
				L_RED, arg, RESET_ALL);
}
