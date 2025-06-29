/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckin-yew <ckin-yew@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 13:31:53 by ckin-yew          #+#    #+#             */
/*   Updated: 2025/06/14 21:54:13 by ckin-yew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*save_leftovers(char *saves, char *leftovers)
{
	int	i;

	i = 0;
	while (saves[i] != '\n')
		i++;
	leftovers = ft_substr_all(saves, i + 1);
	return (leftovers);
}

char	*ft_one_line(char *saves)
{
	int	i;
	int	k;
	char *one_line;

	i = 0;
	while (saves[i] != '\n')
		i++;
	one_line = malloc(sizeof(char) * (i + 2));
	k = 0;
	while (k <= i)
	{
		one_line[k] = saves[k];
		k++;
	}
	one_line[k] = '\0';
	free (saves);
	return (one_line);
}

char	*ft_write_bytes(int fd, int *bytes_read, char *buffer, char *saves)
{
	*bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (*bytes_read < 0)
		return (NULL);
	while (*bytes_read > 0)
	{
		buffer[*bytes_read] = '\0';
		saves = ft_strjoin(saves, buffer);
		if (ft_strchr(saves, '\n'))	
			break;
		*bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	return (saves);
}

char	*get_next_line(int fd)
{
	char buffer[BUFFER_SIZE + 1];
	int bytes_read;
	char *saves;
	static char *leftovers;
	char	*newline;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	saves = NULL;
	if (leftovers)
		saves = ft_strdup(leftovers);
	if (!(saves = ft_write_bytes(fd, &bytes_read, buffer, saves)))
		return (NULL);
	newline = ft_strchr(saves, '\n');
	free (leftovers);
	if (newline && *(newline + 1) != '\0')
		leftovers = save_leftovers(saves, leftovers);
	else
		leftovers = NULL;
	if (!newline && saves && *saves != '\0')
		return (saves);
	return (ft_one_line(saves));
}

#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*newline;

	fd = 42; //open("abclyrics.txt", O_RDONLY);
	if (fd < 0)
		return (1);
	newline = "";
	//while ((newline = get_next_line(fd)))
	//{
		printf("%s", newline);
		free(newline);
	//}
	close(fd);
	return (0);
}
