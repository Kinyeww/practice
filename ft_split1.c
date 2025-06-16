int wordcounts(char *str, char deli)
{
	int i;
	int word;

	i = 0;
	word = 0;
	while (str[i])
	{
		while (str[i] == deli)
			i++;
		word++;
		while (str[i] && str[i] != deli)
			i++;
	}
	return (word);
}

int	main(char *str, char deli)
{
	
}