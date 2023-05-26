/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgfern <jorgfern@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 19:59:31 by panesico          #+#    #+#             */
/*   Updated: 2023/05/11 15:44:44 by jorgfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_nlsplit(char *buffer)
{
	int		i;
	int		j;
	char	*temp;

	if (!buffer)
		return (0);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i++])
		return (free(buffer), NULL);
	temp = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	if (!temp)
		return (0);
	j = 0;
	while (buffer[i])
		temp[j++] = buffer[i++];
	return (free(buffer), temp);
}

char	*ft_next_line(char *buffer)
{
	int		i;
	char	*temp;

	if (!buffer[0])
		return (0);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	temp = ft_calloc((i + 2), sizeof(char));
	if (!temp)
		return (0);
	i = -1;
	while (buffer[++i] && buffer[i] != '\n')
		temp[i] = buffer[i];
	if (buffer[i] == '\n')
		temp[i] = buffer[i];
	return (temp);
}

char	*ft_read(char *buffer, int fd)
{
	char		*str;
	ssize_t		last_line_boole;

	str = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!str)
		return (0);
	last_line_boole = 1;
	while (!ft_strchr(buffer, '\n') && last_line_boole)
	{
		last_line_boole = read(fd, str, BUFFER_SIZE);
		if (last_line_boole == -1)
		{
			if (buffer)
				free(buffer);
			return (free(str), NULL);
		}
		str[last_line_boole] = 0;
		buffer = ft_strjoin(buffer, str);
	}
	free(str);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char		*buffer;
	char			*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer = ft_read(buffer, fd);
	if (!buffer)
		return (0);
	next_line = ft_next_line(buffer);
	buffer = ft_nlsplit(buffer);
	return (next_line);
}
