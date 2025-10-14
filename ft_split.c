/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmauley <cmauley@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 20:32:37 by cmauley           #+#    #+#             */
/*   Updated: 2025/10/14 18:06:23 by cmauley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(const char *s, char c)
{
	int	y;
	int	z;

	y = 0;
	z = 0;
	while (s[y])
	{
		if ((s[y] == c) && (s[y + 1] != c))
			z++;
		y++;
	}
	if (z == 0)
		return (-1);
	return (z + 1);
}

/*static void	free_all(char **tab, int i)
{
	while (i > 0)
	{
		i--;
		free (tab[i]);
	}
	free (tab);
	return (NULL);
}*/

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		w;
	int		i;
	int		start;

	if (!s)
		return (NULL);
	str = malloc((word_count(s, c) + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	w = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (!s[i])
			break;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		str[w] = ft_substr(s, start, i - start);
		w++;
	}
	str[w] = NULL;
	return (str);
}
/*int	main()
{
	char	**tab;
	int		i;

	tab = ft_split("caca pipi caca  ", ' ');
	i = 0;
	while (tab[i])
	{
		printf("str = %d : %s\n", i, tab[i]);
		i++;
	}
	return (0);
}*/
