/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmauley <cmauley@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 20:32:37 by cmauley           #+#    #+#             */
/*   Updated: 2025/10/15 23:29:15 by cmauley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Compte le nombre de mots séparés par le caractère 'c' dans la chaîne 's'
static size_t	word_count(const char *s, char c)
{
	size_t	i; // Index pour parcourir la chaîne
	size_t	word_count; // Compteur de mots

	i = 0;
	word_count = 0;
	while (s[i]) // Parcourt la chaîne jusqu'à la fin
	{
		while (s[i] && s[i] == c) // Ignore les séparateur
			i++;
		if (s[i] && s[i] != c) // Si on trouve un caractère non séparateur
			word_count++; // On a trouvé un mot, on incrémente le compteur
		while (s[i] && s[i] != c) // Avance jusqu'au prochain séparateur
			i++;
	}
	return (word_count); // Retourne le nombre de mots trouvés
}

// Libère toute la mémoire allouée en cas d'erreur
static void	*free_all(char **tab, int i)
{
	while (i >= 0) // Parcourt le tableau à l'envers
	{
		free (tab[i]); // Libère chaque chaîne
		i--;
	}
	free (tab); // Libère le tableau principal
	return (NULL);  // Retourne NULL pour signaler l'erreur
}

// Remplit le tableau 'str' avec les mots extraits de la chaîne 's'
static int	fill_words(char const *s, char c, char **str)
{
	size_t	i; // Index pour parcourir la chaîne
	size_t	w;	// Index pour le tableau de mots
	size_t	start; // Position de début d'un mot

	i = 0;
	w = 0;
	while (s[i]) // Parcourt la chaîne jusqu'à la fin
	{
		while (s[i] && s[i] == c) // Ignore les séparateurs
			i++;
		if (!s[i]) // Si on est à la fin de la chaîne, on arrête
			break ;
		start = i; // Marque le début du mot
		while (s[i] && s[i] != c) // Avance jusqu'au prochain séparateur (fin du mot)
			i++;
		str[w] = ft_substr(s, start, i - start); // Extrait le mot et le stocke dans le tableau
		if (!str[w]) // Si l'allocation échoue, on libère tout et retourne NULL
		{
			free_all(str, w); // Libère la mémoire déjà allouée
			return (0); // Retourne 0 pour signaler l'erreur
		}
		w++; // Passe au mot suivant dans le tableau
	}
	return (1); // Retourne 1 si tout s'est bien passé
}

// Fonction principale pour diviser la chaîne 's' en un tableau de mots séparés par 'c'
char	**ft_split(char const *s, char c)
{
	char	**str; // Tableau de chaînes pour stocker les mots

	if (!s) // Vérifie si la chaîne d'entrée est NULL
		return (NULL); // Retourne NULL si l'entrée est invalide
	str = malloc((word_count(s, c) + 1) * sizeof(char *)); // Alloue de la mémoire pour le tableau de mots (+1 pour le NULL final)
	if (!str) // Vérifie si l'allocation a réussi
		return (NULL); // Retourne NULL en cas d'échec d'allocation
	str[word_count(s, c)] = NULL; // Met le dernier élément du tableau à NULL pour marquer la fin
	if (!fill_words(s, c, str))
		return (NULL); // Remplit le tableau avec les mots, retourne NULL en cas d'erreur
	return (str); // Retourne le tableau de mots
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
