/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmauley <cmauley@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 22:19:26 by cmauley           #+#    #+#             */
/*   Updated: 2025/10/15 23:40:15 by cmauley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Vérifie si le caractère 'c' est dans la chaîne 'set'
static int	inset(char c, const char *set)
{
	size_t	i; // Index pour parcourir la chaîne 'set'

	i = 0;
	while (set[i]) 	// Parcourt la chaîne 'set'
	{
		if (set[i] == c) // Si le caractère 'c' est trouvé dans 'set'
			return (1); // Retourne 1 (vrai)
		i++; // Passe au caractère suivant dans 'set'
	}
	return (0);
}

// Trim les caractères de 'set' au début et à la fin de 's1'
char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	i; // Index pour le début de la nouvelle chaîne
	size_t	j; // Index pour la fin de la nouvelle chaîne
	size_t	len; // Longueur de la nouvelle chaîne
	char	*s3; // Nouvelle chaîne résultante

	if (!s1 || !set) // Vérifie si les entrées sont valides
		return (NULL); // Retourne NULL si 's1' ou 'set' est NULL
	i = 0;
	while (s1[i] && inset(s1[i], set)) // Ignore les caractères de 'set' au début de 's1'
		i++;
	j = ft_strlen(s1); // Trouve la fin de 's1'
	while (j > i && inset(s1[j - 1], set)) // Ignore les caractères de 'set' à la fin de 's1'
		j--;
	len = j - i; // Calcule la longueur de la nouvelle chaîne
	s3 = (char *)malloc(len + 1); // Alloue de la mémoire pour la nouvelle chaîne
	if (!s3) //	 Vérifie si l'allocation a réussi
		return (NULL); // Retourne NULL en cas d'échec d'allocation
	ft_memcpy(s3, s1 + i, len); // Copie la partie utile de 's1' dans 's3'
	s3[len] = '\0'; // Termine la nouvelle chaîne avec un caractère nul
	return (s3); // Retourne la nouvelle chaîne trimée
}
