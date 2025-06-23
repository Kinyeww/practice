/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckin-yew <ckin-yew@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 00:00:00 by ckin-yew          #+#    #+#             */
/*   Updated: 2025/06/21 00:00:00 by ckin-yew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 6

#endif

char	*get_next_line(int fd);

// Your helper function prototypes (change names if yours are different)
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *s);
char	*ft_substr_all(char *s, unsigned int start);

#endif

		/*buffer[bytes_read] = '\0';
		saves = ft_strjoin(saves, buffer);
		if (ft_strchr(saves, '\n'))	
			break;
		bytes_read = read(fd, buffer, BUFFER_SIZE);*/