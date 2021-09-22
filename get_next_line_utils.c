/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmendes- <cmendes-@students.42sp.org.br>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 16:56:21 by cmendes-          #+#    #+#             */
/*   Updated: 2021/09/09 16:56:21 by cmendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	contador(char const *b, char const *c)
{
	int		i;
	int		ii;
	int		t;

	i = 0;
	ii = 0;
	t = 0;
	while (b && b[i] != '\0')
		i++;
	while (c && c[ii] != '\0')
		ii++;
	t = i + ii + 1;
	return (t);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		ii;
	int		j;
	char	*a;

	i = 0;
	ii = 0;
	j = 0;
	a = (char *) malloc(contador(s1, s2));
	if (a == NULL)
		return (NULL);
	while (s1 && s1[i] != '\0')
		a[j++] = s1[i++];
	while (s2 && s2[ii] != '\0')
		a[j++] = s2[ii++];
	a[j] = '\0';
	return (a);
}

char	*read_line(char *s, int c)
{
	char		*strg;
	int			i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != c && s[i] != '\0')
		i++;
	strg = (char *) malloc(i + 2 * sizeof(char));
	if (!strg)
		return (NULL);
	i = 0;
	while (s[i] != c && s[i] != '\0')
	{
		strg[i] = s[i];
		i++;
	}
	strg[i++] = c;
	strg[i] = '\0';
	free(s);
	return (strg);
}

int	ft_strchr(const char *s, int c)
{
	int				i;
	char			*a;
	unsigned char	b;

	a = (char *) s;
	b = c;
	i = 0;
	if (!a)
		return (0);
	while (a[i] != '\0')
	{
		if (a[i] == b)
			return (i + 1);
		i++;
	}
	if (b == '\0')
		return (i + 1);
	return (0);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t			i;
	unsigned char	*a;
	unsigned char	*b;

	a = (unsigned char *) src;
	b = (unsigned char *) dst;
	i = 0;
	if ((a == NULL) && (dstsize == '\0'))
		return (0);
	while ((i + 1 < dstsize) && (a[i] != '\0'))
	{
		b[i] = a[i];
		i++;
	}
	if ((dstsize != 0) && (b != NULL) && ((i + 1 == dstsize) || (a[i] == '\0')))
		b[i] = '\0';
	while (a[i] != '\0')
		i++;
	return (0);
}
