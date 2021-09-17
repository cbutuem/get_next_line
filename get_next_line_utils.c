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

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

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
	{
		//printf("Con c %c\n", c[ii]);
		ii++;
	}
	t = i + ii;
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
	//a[j] = '\0';
	return (a);
}

char	*read_line(char *s, int c)
{
	char				*strg;
	int			i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != c)
		i++;
	strg = (char *) malloc(i * sizeof(char));
	i = 0;
	while (s[i] != c)
	{
		strg[i] = s[i];
		i++;
	}
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
		return(0);
	while (a[i] != '\0')
	{
		if (a[i] == b)
			return (i);
		i++;
	}
	if (b == '\0')
		return (i);
	return (0);
}

char *line(int fd, char *s)
{
	static char 	c[6];
	char	*aux;

	//c[5] = '\0';
	while(!ft_strchr(s, '\n'))
	{
		read(fd, c, 5);
		aux = s;
		s = ft_strjoin(aux, c);
		free(aux);
		//printf("S:%s Tes: %zu C: %s\n", s, tes, c);
	}
	return (read_line(s, '\n'));
}

char	*get_next_line(int fd)
{
	//printf("I: %i LP: %i\n", i, last_position);
	return (line(fd, NULL));
}
int main ()
{
	int a = open("teste.txt", O_RDONLY | O_EXCL);
	printf("RESULTADO1:%s\n", get_next_line(a));
	printf("RESULTADO2:%s\n", get_next_line(a));
	printf("RESULTADO3:%s\n", get_next_line(a));
	//printf("RESULTADO4:%s\n", get_next_line(a));
	//printf("RESULTADO5:%s\n", get_next_line(a));
	//printf("RESULTADO6:%s\n", get_next_line(a));
	//printf("RESULTADO7:%s\n", get_next_line(a));
	//printf("RESULTADO8:%s\n", get_next_line(a));
	//printf("RESULTADO9:%s\n", get_next_line(a));
	//printf("RESULTADO10:%s\n", get_next_line(a));
	//printf("RESULTADO11:%s\n", get_next_line(a));
	//printf("RESULTADO12:%s\n", get_next_line(a));
	//printf("RESULTADO13:%s\n", get_next_line(a));
	//printf("RESULTADO14:%s\n", get_next_line(a));
	//printf("RESULTADO15:%s\n", get_next_line(a));
	return (0);
}
