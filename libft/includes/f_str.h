/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   f_str.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/25 14:38:52 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/01 10:34:32 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef _F_STR_H
# define _F_STR_H
# include <string.h>
# include <stdlib.h>

char	*ft_strcat(char *dest, const char *src);
char	*ft_strchr(const char *s, int c);
void	ft_strclr(char *s);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strcpy(char *d, const char *s);
void	ft_strdel(char **as);
char	*ft_strdup(const char *src);
int		ft_strequ(char const *s1, char const *s2);
void	ft_striter(char *s, void (*f)(char *));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strjoinch(char const *s1, char c);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
int		ft_strlen_classic(char *str);
size_t	ft_strlen(const char *str);
char	*ft_strmap(char const *s, char (*f)(char));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strncat(char *dest, const char *src, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strncpy(char *s1, const char *s2, size_t n);
int		ft_strnequ(char const *s1, char const *s2, size_t n);
char	*ft_strnew(size_t size);
char	*ft_strnstr(const char *s, const char *find, size_t slen);
char	*ft_strrchr(const char *s, int c);
char	*ft_strreplace_first(char *search, char *replace, char *subject);
char	*ft_strreplace(char *search, char *replace, char *subject);
char	**ft_strsplit(char *s, char delimiter);
char	*ft_strstr(const char *str, const char *query);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char	*ft_strtrim(char const *s);
int		ft_strmatch(const char *str, const char *match);
char	*ft_strjoin_multiple(char *str, ...);
int		ft_strisdigit(const char *s);
char	*ft_strbasename(const char *filename);

int		ft_tolower(int c);
int		ft_toupper(int c);

#endif
