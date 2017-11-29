/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   free_debug.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/25 21:41:11 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/29 10:12:49 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "f_printf.h"
#include <stdlib.h>

void	free_debug(void *ptr)
{
	void **real_ptr;

	real_ptr = (void **)ptr;
	free(*real_ptr);
	*real_ptr = NULL;
	ft_printf("Pointer is now free.\n");
}
