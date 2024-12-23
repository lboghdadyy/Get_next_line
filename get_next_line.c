/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaghdad < sbaghdad@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 19:37:47 by sbaghdad          #+#    #+#             */
/*   Updated: 2024/12/23 12:22:11 by sbaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*cut_it(char *str)
{
	char	*cut;
	int		i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (str[i] == '\n')
		i++;
	cut = malloc(i + 1);
	if (!cut)
		return (free(str), NULL);
	i = 0;
	while (str[i] != '\n' && str[i])
	{
		cut[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		cut[i++] = '\n';
	cut[i] = '\0';
	return (cut);
}

char	*change_index(char	*rest)
{
	int		i;
	int		j;
	char	*str;

	if (!rest)
		return (NULL);
	(1) && (i = 0, j = 0);
	while (rest[i] != '\n' && rest[i])
		i++;
	if (rest[i] == '\n')
		i++;
	if (rest[i] == '\0')
		return (free(rest), NULL);
	str = malloc(ft_strlen(rest + i) + 1);
	if (!str)
		return (free(str), free(rest), NULL);
	while (rest[i])
	{
		str[j] = rest[i];
		j++;
		i++;
	}
	str[j] = '\0';
	free(rest);
	return (str);
}

char	*get_it(int fd, char *rest)
{
	char	*buffer;
	int		bytes;
	char	*tmp;

	bytes = 1;
	while (!ft_strchr(rest, '\n'))
	{
		buffer = malloc((size_t)BUFFER_SIZE + 1);
		if (!buffer)
			return (free(rest), free(buffer), NULL);
		bytes = read(fd, buffer, (size_t)BUFFER_SIZE);
		if (bytes == 0 && rest)
			return (free(buffer), rest);
		else if ((bytes == 0 && !rest) || bytes == -1)
			return (free(buffer), free(rest), NULL);
		buffer[bytes] = '\0';
		tmp = ft_strjoin(rest, buffer);
		free (rest);
		free (buffer);
		rest = tmp;
	}
	tmp = NULL;
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*after_new_line;
	char		*line;
	char		*tmp;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	after_new_line = get_it(fd, after_new_line);
	if (!after_new_line)
	{
		free(after_new_line);
		return (NULL);
	}
	line = cut_it(after_new_line);
	if (!line)
	{
		return (free (after_new_line), line);
	}
	tmp = change_index(after_new_line);
	after_new_line = tmp;
	return (line);
}
