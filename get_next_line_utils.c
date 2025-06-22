#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int i;
	int k;
	char *str;

	str = NULL;
	i = 0;
	while (s1[i])
		i++;
	k = 0;
	while (s2[i])
		k++;
	str = malloc(sizeof(char) * i + k + 2); //one for \n and one for \0
	while (s2[k])
	{
		str[i + k] = s2[k];
		k++;
	}
	str[i + k] = '\0';
	return (str);
}

size_t ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char    *ft_substr_all(char *s, unsigned int start)
{
	int i;
	int j;
	char *substr;
	
	i = start;
	j = 0;
	substr = malloc(sizeof(char) * ft_strlen(s + start) + 1);
	while (s[i])
	{
		substr[j] = s[i];
		i++;
		j++;
	}
	substr[j] = '\0';
	return (substr);
}

char	*ft_strdup(const char *s1)
{
	int	i;
	char	*s1cpy;

	i = 0;
	while (s1[i] != '\0')
		i++;
	s1cpy = malloc(sizeof(char) * (i + 1));
	if (!s1cpy)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		s1cpy[i] = s1[i];
		i++;
	}
	s1cpy[i] = '\0';
	return (s1cpy);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if ((unsigned char)s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}