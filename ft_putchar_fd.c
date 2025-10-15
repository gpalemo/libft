/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmauley <cmauley@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 23:25:59 by cmauley           #+#    #+#             */
/*   Updated: 2025/10/16 00:07:03 by cmauley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Écrit le caractère 'c' sur le descripteur de fichier 'fd'
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1); // Utilise la fonction write pour écrire le caractère
}
/*int	main()
{
	ft_putchar_fd('a', 1); // Écrit 'a' sur la sortie standard (fd = 1)
	return (0);
}*/
