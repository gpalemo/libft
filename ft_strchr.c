/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmauley <cmauley@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 00:31:14 by cmauley           #+#    #+#             */
/*   Updated: 2025/10/15 23:58:04 by cmauley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Recherche la première occurrence du caractère 'c' dans la chaîne 's'
char	*ft_strchr(const char *s, int c)
{
	char	ch; // Caractère à rechercher

	ch = (char) c; // Conversion de 'c' en char pour la comparaison
	while (*s)
	{
		if (*s == ch) // Si le caractère courant correspond à 'ch'
			return ((char *)s); // Retourne un pointeur vers cette position dans la chaîne
		s++;
	}
	if (*s == ch) // Vérifie le caractère nul à la fin de la chaîne
		return ((char *)s); // Retourne un pointeur vers le caractère nul si 'ch' est le caractère nul
	return (NULL); // Si 'ch' n'est pas trouvé,
}
/*int main()
{
    char *str = "salut";

    printf("Emplacement de l = %s\n", ft_strchr(str, 'l'));

    return (0);
}*/
