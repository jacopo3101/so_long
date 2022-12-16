/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javellis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 11:46:57 by javellis          #+#    #+#             */
/*   Updated: 2022/10/11 11:47:01 by javellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include<stddef.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*next;

	tmp = *lst;
	next = tmp->next;
	while (next)
	{
		ft_lstdelone(tmp, del);
		tmp = next;
		next = next->next;
	}
	ft_lstdelone(tmp, del);
	*lst = NULL;
}
