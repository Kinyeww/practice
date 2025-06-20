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

//int	open(const char *path, int flags [, int mode ])

char	*save_leftovers(char *saves, char *leftovers)
{
	int	i;

	i = 0;
	while (saves[i] != '\n')
		i++;
	leftovers = ft_substr(saves, i + 1);
	return (leftovers);
}

char	*ft_one_line(char *saves)
{
	int	i;
	int	k;
	int	l;
	char *one_line;

	i = 0;
	while (saves[i] != '\n')
		i++;
	one_line = malloc(sizeof(char) * i + 1);
	k = 0;
	while (i <= k)
	{
		one_line[k] = saves[k];
		k++;
	}
	one_line[k] = '\0';
	free (saves);
	return (one_line);
}

char	*get_next_line(int fd)
{
	char buffer[BUFFER_SIZE + 1]; //scoop
	int bytes_read;
	char *saves; //eating bowl
	static char *leftovers;

	saves = NULL;
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (leftovers)
		//put leftover inside the array
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		saves = ft_strjoin(saves, buffer);
		if (ft_strchr(saves, '\n'))	
			break;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	if ((ft_strchr(saves, '\n')) + 1 != '\0')
	{
		save_leftovers(saves, leftovers);
		return (ft_one_line(saves));
	}
	return (saves);
}

int main(void)
{
	int fd;

	fd = open("abclyrics.txt", O_RDONLY);
	write(1, get_next_line(fd), 999);
	return (0);
}