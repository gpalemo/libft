/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmauley <cmauley@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 22:39:12 by cmauley           #+#    #+#             */
/*   Updated: 2025/10/15 23:44:26 by cmauley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Calcule la longueur nécessaire pour représenter l'entier 'n' en chaîne de caractères
static int	nblen(int n)
{
	size_t	len; // Compteur de chiffres

	len = 0;
	if (n <= 0) // Si 'n' est négatif ou zéro, on a besoin d'un caractère supplémentaire pour le signe ou le zéro
		len++;
	while (n != 0) // Compte le nombre de chiffres en divisant 'n' par 10 jusqu'à ce qu'il soit zéro
	{
		n /= 10;
		len++;
	}
	return (len); // Retourne la longueur totale nécessaire
}
// Convertit un entier 'n' en une chaîne de caractères
char	*ft_itoa(int n)
{
	int		len; // Longueur de la chaîne résultante
	long	num; // Valeur de 'n' convertie en long pour gérer les cas négatifs
	char	*res; // Chaîne résultante

	num = n; // Conversion de 'n' en long pour éviter les débordements
	len = nblen(n); // Calcule la longueur nécessaire pour la chaîne
	res = malloc((len + 1) * sizeof(char)); // Alloue de la mémoire pour la chaîne (+1 pour le caractère nul)
	if (!res)
		return (NULL);
	res[len--] = '\0'; // Termine la chaîne avec un caractère nul
	if (num < 0) // Si 'n' est négatif, on gère le signe
	{
		num = -num; // Rend 'num' positif
		res[0] = '-'; // Place le signe négatif au début de la chaîne
	}
	else if (n == 0) // Si 'n' est zéro, on place '0' dans la chaîne
		res[0] = '0';
	while (num > 0) // Remplit la chaîne avec les chiffres de 'num' en partant de la fin
	{
		res[len] = (num % 10) + 48; // Convertit le chiffre en caractère
		num /= 10; // Passe au chiffre suivant
		len -= 1; // Décrémente l'index pour la prochaine position
	}
	return (res); // Retourne la chaîne résultante
}
// int	main()
// {
// 	printf("%s\n", ft_itoa(123));
// 	return (0);
// }
