/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmauley <cmauley@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 20:32:37 by cmauley           #+#    #+#             */
/*   Updated: 2025/10/08 21:26:26 by cmauley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_split(char const *s, char c)
{

}

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
	return (z + 1);
}

static char	*word_dup(const char *s, int start, int end)
{
	truc dans le genre : return (ft_substr(s, start, end - start));
}


