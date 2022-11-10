/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esordone <esordone@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 11:12:31 by esordone          #+#    #+#             */
/*   Updated: 2022/11/10 17:54:51 by esordone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_free(char **str)
{
	if (*str)
	{
		free(*str);
		*str = NULL;
	}
}

char	*read_file(int fd, char *str)
{
	static char	*tmp;
	int			i;

	i = 1;
	tmp = (char *)malloc (sizeof(char) * BUFFER_SIZE);
	if (!tmp)
		return (NULL);
	while (i > 0)
	{
		i = read(fd, str, BUFFER_SIZE);
		if (i == 0)
		{
			free(tmp);
			return (NULL);
		}
		//1. de donde leo (fd)
		//2. donde lo guardo (str)
		//3. cuanto quiero leer (BUFFER)
		tmp[i] = 0;
		str = ft_free(tmp);
		//para quan trobes un \n
		//if (ft_strchr(i, '\n')
	}
	free(i);
	return (tmp);
}
char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer;

	if (fd < 0)
		return (NULL);
	buffer = read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	if (buffer != NULL)
		free(buffer);
	return (buffer);
}

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
}
