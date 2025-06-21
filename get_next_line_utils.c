#include <get_next_line.h>

char	*ft_strjoin(char *s1, char *s2)
{
    int i;
    int k;
    char *result;

    result = NULL;
    i = 0;
    while (s1[i])
        i++;
    k = 0;
    while (s2[i])
        k++;
    result = malloc(sizeof(char) * i + k + 2); //one for \n and one for \0
    while (s2[k])
    {
        str[i + k] = s2[k];
        k++;
    }
    str[i + k] = '\0';
    return (str);
}

int ft_strlen(const char *str)
{
    int i;

    i = 0;
    while (str[i])
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