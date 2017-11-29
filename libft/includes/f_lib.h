/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   f_lib.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/25 14:31:50 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/25 14:54:30 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef _F_LIB_H
# define _F_LIB_H
# include <string.h>
# include <stdlib.h>

int		ft_atoi(const char *str);
char	*ft_itoa_base(int value, int base);
char	*ft_itoa(int nbr);

#endif