/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmauley <cmauley@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 01:09:37 by cmauley           #+#    #+#             */
/*   Updated: 2025/10/15 23:51:25 by cmauley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Recherche la dernière occurrence du caractère 'c' dans la chaîne 's'
char	*ft_strrchr(const char *s, int c)
{
	char	ch; // Caractère à rechercher
	char	*res; // Pointeur pour la dernière occurrence trouvée

	ch = (char) c; // Conversion de 'c' en char
	res = NULL; // Initialisation du pointeur résultat à NULL
	while (*s) // Parcourt la chaîne jusqu'à la fin
	{
		if (*s == ch) // Si le caractère courant correspond à 'ch'
			res = ((char *)s); // Met à jour le pointeur résultat
		s++; // Passe au caractère suivant
	}
	if (*s == ch) // Vérifie le caractère nul à la fin de la chaîne
		res = ((char *)s); // Met à jour le pointeur résultat si 'ch' est le caractère nul
	return (res); // Retourne le pointeur vers la dernière occurrence ou NULL si non trouvé
}
/*int main()
{
    char *str = "quoikoubeh";

    printf("Recherche de 'q'  -> %s\n", ft_strrchr(str, 'q'));
    printf("Recherche de 'u'  -> %s\n", ft_strrchr(str, 'u'));
    printf("Recherche de 'h'  -> %s\n", ft_strrchr(str, 'h'));

    return (0);
}*/
