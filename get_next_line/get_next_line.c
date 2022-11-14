/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esordone <esordone@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 11:12:31 by esordone          #+#    #+#             */
/*   Updated: 2022/11/14 18:10:37 by esordone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
		str = ft_strjoin(str, tmp);
	}
	free(tmp);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	//char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	return (buffer);
}
/*
int	main(void)
{
	int	fd;

    fd = open("/Users/esordone/get_next_line/text.txt", O_RDONLY);
	printf("fd == %i\n", fd);
	printf("La primera linea contiene: %s\n", get_next_line(fd));
	printf("La segunda linea contiene: %s\n", get_next_line(fd));
	close(fd);
	return (0);
}*/
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
