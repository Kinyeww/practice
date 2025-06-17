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

int	open(const char *path, int flags [, int mode ])

char	*get_next_line(int fd)
{
	char buffer[BUFFER_SIZE + 1];
	int bytes_read;
	char *saves;
	
	*saves = NULL;
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0);
	{
		buffer[bytes_read] = '\0';
		saves = ft_strjoin(stash, buffer);
		if (ft_strchr(saves, '\n'))
			break;
	}
}

int main(void)
{
	int fd;

	fd = open("abclyrics.txt", O_RDONLY);
}