/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmauley <cmauley@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 23:13:43 by cmauley           #+#    #+#             */
/*   Updated: 2025/10/15 23:52:24 by cmauley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Duplique la chaîne de caractères 'src' en allouant de la mémoire pour la nouvelle chaîne
char	*ft_strdup(const char *src)
{
	char	*dest; // Pointeur pour la chaîne dupliquée

	dest = (char *) malloc(ft_strlen(src) + 1); // Alloue de la mémoire pour la nouvelle chaîne (+1 pour le caractère nul)
	if (!dest) // Vérifie si l'allocation a réussi
		return (NULL);
	ft_memcpy(dest, src, ft_strlen(src) + 1); // Copie la chaîne source dans la nouvelle chaîne, y compris le caractère nul
	return (dest); // Retourne le pointeur vers la chaîne dupliquée
}

/*int	main(void)
{
	char	*src = "Hello World";
	char	*copy;

	copy = ft_strdup(src);
	printf("Source = %s\n", src);
	printf("Copie = %s\n", copy);

	free(copy);
	return (0);
}*/
