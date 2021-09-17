/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmendes- <cmendes-@students.42sp.org.br>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 16:56:42 by cmendes-          #+#    #+#             */
/*   Updated: 2021/09/09 16:56:42 by cmendes-         ###   ########.fr       */
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
	while (b[i] != '\0')
		i++;
	while (c[ii] != '\0')
		ii++;
	t = i + ii + 1;
	return (t);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*a;

	i = 0;
	j = 0;
	if ((!s1) || (!s2))
		return (NULL);
	a = (char *) malloc(contador(s1, s2));
	if (a == NULL)
		return (NULL);
	while (s1[i] != '\0')
		a[j++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		a[j++] = s2[i++];
	if (s2[i] == '\0')
		a[j] = '\0';
	return (a);
}

char	*ft_strchr(const char *s, int c)
{
	int				i;
	char			*a;
	unsigned char	b;

	a = (char *) s;
	b = c;
	i = 0;
	while (a[i] != '\0')
	{
		if (a[i] == b)
			return (&a[i]);
		i++;
	}
	if (b == '\0')
		return (&a[i]);
	return (0);
}

char *read_line(char *s, int c)
{

}

char *line(int fd, char *s)
{
	while(s != '\n')
	{
		read (
	}

}

static char	*read_line(int fd)
{
	char		*font;
	char		*dest;
	char		*final;
	static int	i;

	dest = "";
	font = (char *) malloc(1 * sizeof(char));
	while (*font != '\n')
	{
		read(fd, font, 5);

		final = ft_strjoin(dest, font);
		//free(dest);
	}
	if (dest == NULL)
		return (NULL);
	return (dest);
}

char	*get_next_line(int fd)
{
	//static int	i;
	//int			last_position;

	//last_position = 0;
	//if (last_position < i)
	//{	
	//	while (last_position < i)
	//	{
	//		read_line (fd);
	//		last_position++;
	//	}
	//}
	//i++;
	//printf("I: %i LP: %i\n", i, last_position);
	return (read_line(fd));
}
int main ()
{
	int a = open("teste.txt", O_RDONLY | O_EXCL);
	printf("RESULTADO1:%s\n", get_next_line(a));
	printf("RESULTADO2:%s\n", get_next_line(a));
	printf("RESULTADO3:%s\n", get_next_line(a));
	printf("RESULTADO4:%s\n", get_next_line(a));
	printf("RESULTADO5:%s\n", get_next_line(a));
	printf("RESULTADO6:%s\n", get_next_line(a));
	printf("RESULTADO7:%s\n", get_next_line(a));
	printf("RESULTADO8:%s\n", get_next_line(a));
	printf("RESULTADO9:%s\n", get_next_line(a));
	printf("RESULTADO10:%s\n", get_next_line(a));
	printf("RESULTADO11:%s\n", get_next_line(a));
	printf("RESULTADO12:%s\n", get_next_line(a));
	printf("RESULTADO13:%s\n", get_next_line(a));
	printf("RESULTADO14:%s\n", get_next_line(a));
	printf("RESULTADO15:%s\n", get_next_line(a));
	return (0);
}
