/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaghdad < sbaghdad@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 19:38:03 by sbaghdad          #+#    #+#             */
/*   Updated: 2024/12/23 10:43:13 by sbaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen( char *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}

int	ft_strchr(char *s, int c)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] == (char) c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strdup(char *s1)
{
	char	*str;
	size_t	i;

	if (!s1)
		return (NULL);
	str = malloc(sizeof(*s1) * (ft_strlen(s1) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

char	*check_it(char	*str1, char	*str2)
{
	if (!str1 && str2)
		return (ft_strdup(str2));
	else if (str1 && !str2)
		return (ft_strdup(str1));
	else
		return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*string;
	size_t	len;
	int		j;
	int		i;

	if (!s1 || !s2)
	{
		s1 = check_it(s1, s2);
		return (s1);
	}
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	string = (char *)malloc(len);
	if (!string)
		return (NULL);
	(1) && (i = 0, j = 0);
	while (s1[i])
	{
		string[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		string[i] = s2[j];
		(1) && (i++, j++);
	}
	free(s1);
	s1 = NULL;
	string[i] = '\0';
	return (string);
}
