/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmauley <cmauley@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 22:33:17 by cmauley           #+#    #+#             */
/*   Updated: 2025/10/14 22:44:56 by cmauley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	inset(char c, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*s3;
	int		i;
	int		k;
	int		len;
	int		j;

	i = 0;
	k = 0;
	len = ft_strlen(s1);
	j = len - 1;
	while (inset(s1[i], set) == 1)
		i++;
	while (inset(s1[j], set) == 1)
		j--;
	len = len - (j - i);
	if (len == 0)
		return (NULL);
	s3 = malloc(len - 1);
	while (i <= j)
	{
		s3[k++] = s1[i++];
	}
	s3[k] = '\0';
	return (s3);
}
/*int	main()
{
	char	*s1 = "abababjabajababa";
	char	*set = "ab";

	char *str = ft_strtrim(s1, set);
	printf("%s\n", str);
	free(str);
	return (0);
}*/
