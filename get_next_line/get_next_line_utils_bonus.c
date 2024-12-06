/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-moh <aben-moh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 10:34:59 by aben-moh          #+#    #+#             */
/*   Updated: 2024/12/06 12:23:46 by aben-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

static char	*ft_strdup(char *s1)
{
	char	*p;
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(s1);
	p = malloc(sizeof(char) * (len + 1));
	if (!p)
		return (NULL);
	while (s1[i] != '\0')
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_strjoin(char *str, char *buff)
{
	size_t	i;
	size_t	j;
	char	*res;

	if (!str && !buff)
		return (NULL);
	if (!str)
		return (ft_strdup(buff));
	if (!buff)
		return (ft_strdup(str));
	res = malloc(sizeof(char) * ((ft_strlen(str) + ft_strlen(buff)) + 1));
	if (!res)
		return (free(str), str = NULL, NULL);
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		res[i] = str[i];
		i++;
	}
	while (buff[j] != '\0')
		res[i++] = buff[j++];
	res[i] = '\0';
	free(str);
	return (res);
}
