// char	*get_next_line(int fd)
// {
// 	char	*str;
// 	char	*neo;
// 	char	c;
// 	int		byte;
// 	int		i;
// 	int		j;

// 	if (BUFFER_SIZE < 1 || fd < 0)
// 		return (NULL);
// 	i = 0;
// 	str = (char *)malloc(BUFFER_SIZE + 1);
// 	if (!str)
// 		return (NULL);
// 	byte = read(fd, &c, 1);
// 	while (byte > 0)
// 	{
// 		if (i >= BUFFER_SIZE)
// 		{
// 			neo = (char *)malloc(i + BUFFER_SIZE + 1);
// 			if (!neo)
// 				return (free(str), NULL);
// 			j = -1;
// 			while (++j < i)
// 				neo[j] = str[j];
// 			free(str);
// 			str = neo;
// 		}
// 		str[i] = c;
// 		i++;
// 		if (c == '\n')
// 			break ;
// 		byte = read(fd, &c, 1);
// 	}
// 	if (i == 0 || byte < 0)
// 		return (free(str), NULL);
// 	return (str[i] = '\0', str);
// }
