/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esordone <esordone@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 11:12:31 by esordone          #+#    #+#             */
/*   Updated: 2022/11/15 16:01:38 by esordone         ###   ########.fr       */
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
	{
		free(tmp);
		return (NULL);
	}
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
		str = ft_free(str, tmp);
	}
	free(tmp);
	return (str);
}

char	*line(char *str)
{
	int		i;
	char	*line;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	/*line = (char *)malloc(sizeof(char) * i + 1);
	if (!line)
	{
		free(line);
		return (NULL);
	}*/
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] && str[i] == '\n')
		line[i] = '\n';
	//line[i] = '\0';
	printf("Line contiene|%s\n", line);
	return (line);
}

char	*next(char *str)
{
	int		i;
	int		n;
	static char	*next;

	i = 0;
	n = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str)
	{
		free(str);
		return (NULL);
	}
	printf("Encuenta salto de linea en |%i|\n", i);
	/*next = (char *)malloc(sizeof(char) * (ft_strlen(str) - i)+ 1);
	if (!next)
	{
		free(next);
		return (NULL);
	}*/
	next = ft_calloc((ft_strlen(str) - i + 1), sizeof(char));
	/*if (!next)
	{
		free(next);
		return (NULL);
	}*/
	//i++;
	while (str[i])
		next[n++] = str[i++];
	printf("Next contiene |%s|\n", next);
	//next[n] = '\0';
	free(str);
	return (next);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*new_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	new_line = line(buffer);
	buffer = next(new_line);
	return (new_line);
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
