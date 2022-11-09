/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esordone <esordone@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 11:12:31 by esordone          #+#    #+#             */
/*   Updated: 2022/11/09 18:58:10 by esordone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>


char	*get_next_line(int fd)
{
	int			i;
	//size_t		len;
	//char	*res;

	char *str;
	
	str = (char *)malloc(sizeof(char) * BUFFER_SIZE);

	//i = 0;
	//while (res[i])
	//{
	i =	read(fd, str, BUFFER_SIZE);
		// 1. de donde leo fd
		// 2. donde lo guardo str
		// 3. cuanto leo BUFFER
	//	i++;
	//}
	//res[i] = '\0';
	if (i == 0)
		return (NULL);
	return (str);
}


int main (int argc, char **argv)
{
	int fd;
	char *str;

	if (argc != 2)
		return (1);

	printf("File: %s\n",argv[1]);
	
	fd = open(argv[1], O_RDONLY);
	str = get_next_line(fd);
	while (str != NULL)
	{
		printf("Linea: %s",str);
		str = get_next_line(fd);
	}
	return (0);
}
