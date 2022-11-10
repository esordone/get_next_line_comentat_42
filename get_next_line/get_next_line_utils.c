/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esordone <esordone@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:13:35 by esordone          #+#    #+#             */
/*   Updated: 2022/11/10 16:29:20 by esordone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	char	*n;
	char	i;

	n = (char *)s;
	i = (char)c;
	while (*n != i)
	{
		if (*n == 0)
		{
			return (NULL);
		}
		if (*n == '\0')
			return (n);
		n++;
	}
	return (n);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	i;
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	s3 = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!s1 || !s2 || !s3)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		s3[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		s3[len1] = s2[i];
		len1++;
		i++;
	}
	s3[len1] = '\0';
	return (s3);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	n;
	char			*s2;

	if (!*s || start > ft_strlen(s))
	{
		s2 = (char *)malloc(sizeof(char) * (1));
		if (!s2)
			return (NULL);
		s2[0] = '\0';
		return (s2);
	}
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	s2 = (char *)malloc(sizeof(char) * (len + 1));
	if (!s2)
		return (NULL);
	n = 0;
	while (s[start] && n < len)
	{
		s2[n] = s[start];
		start++;
		n++;
	}
	s2[n] = '\0';
	return (s2);
}

char	*ft_strdup(const char *s1)
{
	char	*p;
	int		i;
	int		len;
	char	*s;

	s = (char *)s1;
	len = ft_strlen(s1);
	p = (char *)malloc(sizeof(char) * (len + 1));
	if (!p)
		return (NULL);
	i = 0;
	while (i < len && s[i] != '\0')
	{
		p[i] = s[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
