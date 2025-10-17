/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmauley <cmauley@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 22:57:10 by cmauley           #+#    #+#             */
/*   Updated: 2025/10/16 23:39:15 by cmauley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	last = ft_lstlast(*lst);

	if (!last)
		*lst = new;
	last->next = new;
}
/*int	main()
{
	t_list	*a = ft_lstnew("hello");
	t_list	*b = ft_lstnew("world");
	t_list	*c = ft_lstnew("42");

	a->next = b;
	ft_lstadd_back(&a, c);
	printf("%s\n",(char *)a->next->next->content);
	return(0);
}*/
