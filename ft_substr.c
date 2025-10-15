/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmauley <cmauley@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 18:13:04 by cmauley           #+#    #+#             */
/*   Updated: 2025/10/15 23:46:16 by cmauley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Extrait une sous-chaîne de 's' à partir de l'index 'start' avec une longueur maximale de 'len'
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub; // Pointeur pour la sous-chaîne résultante
	size_t	s_len; // Longueur de la chaîne d'origine

	if (s == 0)
		return (NULL);
	s_len = ft_strlen(s); // Calcule la longueur de la chaîne d'origine
	if (start >= s_len) // Si 'start' est au-delà de la fin de la chaîne, retourne une chaîne vide
		return (ft_strdup("")); // Alloue une nouvelle chaîne vide
	if (start + len >= s_len) // Ajuste 'len' si nécessaire pour ne pas dépasser la fin de la chaîne
		len = s_len - start; // Nouvelle longueur
	sub = (char *)malloc(len + 1); // Alloue de la mémoire pour la sous-chaîne (+1 pour le caractère nul)
	if (sub == 0)
		return (NULL);
	ft_memcpy(sub, s + start, len); // Copie 'len' caractères à partir de 'start' dans la nouvelle chaîne
	sub[len] = '\0'; // Termine la sous-chaîne avec un caractère nul
	return (sub); // Retourne la sous-chaîne résultante
}
/*int	main()
{
	char	*s = "bonjour";
	char	*sub;

	sub = ft_substr(s, 2, 3);
	printf("%s\n", sub);
	free(sub);
	return (0);
}*/
