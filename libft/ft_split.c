/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzeck <tzeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 17:01:43 by tzeck             #+#    #+#             */
/*   Updated: 2021/07/23 17:14:41 by tzeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	delimiter(const char *s, char c, int i)
{
	while (s[i] != c && s[i])
		i++;
	return (i);
}

static int	string_count(const char *s, char c)
{
	int	str_nbr;
	int	i;

	if (!s[0])
		return (0);
	str_nbr = 0;
	i = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			str_nbr++;
			while (s[i] && s[i] == c)
				i++;
			continue ;
		}
		i++;
	}
	if (s[i - 1] != c)
		str_nbr++;
	return (str_nbr);
}

static void	write_words(const char *s, char c, char **mainstr, unsigned int b)
{
	unsigned int	a;
	unsigned int	i;
	size_t			z;

	i = 0;
	a = 0;
	z = 0;
	while (a < b)
	{
		i = z + i;
		while (s[i] && s[i] == c)
			i++;
		z = delimiter(s, c, i) - i;
		mainstr[a] = (char *)ft_substr(s, i, z);
		a++;
	}
	mainstr[a] = NULL;
}

char	**ft_split(const char *s, char c)
{
	char			**mainstr;
	unsigned int	b;

	if (!s)
		return (0);
	b = string_count(s, c);
	mainstr = (char **)malloc(b * sizeof(char *) + 1 * sizeof(char *));
	if (mainstr == '\0')
		return (0);
	write_words(s, c, mainstr, b);
	return (mainstr);
}
