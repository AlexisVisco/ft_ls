/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   f_io.h                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/25 14:27:35 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/26 22:00:45 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef _F_IO_H
# define _F_IO_H

void	ft_putchar_fd(char c, int fd);
void	ft_putchar(char c);
void	ft_putendl_fd(char const *s, int fd);
void	ft_putendl(char const *s);
void	ft_putnbr_fd(int n, int fd);
void	ft_putnbr(int n);
void	ft_putnbrbase(int nbr, char *base);
void	ft_putstr_classic(char *str);
void	ft_putstr_fd(char const *s, int fd);
void	ft_putstr(const char *str);
void	ft_putdouble_fd(int fd, double d);
void	ft_putdouble(double d);
void	ft_putubase_fd(int fd, unsigned long n, unsigned int base);
void	ft_putubase(unsigned long n, unsigned int base);

#endif
