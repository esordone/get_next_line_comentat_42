/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esordone <esordone@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 11:12:31 by esordone          #+#    #+#             */
/*   Updated: 2022/11/15 12:52:06 by esordone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char *s1, char *s2)
{
	char	*tmp;
	
	tmp = ft_strjoin(s1, s2);
	free(s1);
	return (tmp);
}

char	*read_file(int fd, char *str)
{
	char	*tmp;
	int		i;

	i = 1;
	tmp = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!tmp)
		return (NULL);
	while (!ft_strchr(str, '\n') && i != 0)
	{
		i = read(fd, tmp, BUFFER_SIZE);
		if (i == -1)
		{
			free(tmp);
			return (NULL);
		}
		//1. de donde leo (fd)
		//2. donde lo guardo (str)
		//3. cuanto quiero leer (BUFFER)
		tmp[i] = '\0';
		printf("Entra en el joinfree: |\n|");
		str = ft_free(str, tmp);
		printf("|%s\n|", str);
	}
	free(tmp);
	return (str);
}

char	*read_line(char *str)
{
	int		i;
	char	*line;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (str[i])
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] && str[i] == '\n')
		line[i++] = '\n';
	printf("Line contiene|%s\n", line);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	line = read_line(buffer);
	return (line);
}

int	main(void)
{
	int	fd;

    fd = open("/Users/esordone/get_next_line/text.txt", O_RDONLY);
	printf("fd == %i\n", fd);
	printf("La primera linea contiene: %s\n", get_next_line(fd));
	printf("La segunda linea contiene: %s\n", get_next_line(fd));
	close(fd);
	return (0);
}
/*
int main (int argc, char **argv)
{
	int		fd;
	char	*str;

	if (argc != 2)
		return (1);

	printf("File: %s\n",argv[1]);
	
	fd = open(argv[1], O_RDONLY);
	str = get_next_line(fd);
	while (str != NULL)
	{
		printf("Linea: %s",str);
		str = get_next_line(fd);
		if (str != NULL)
			free(str);
	}
	return (0);
}*/
