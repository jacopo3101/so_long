/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javellis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 12:46:47 by javellis          #+#    #+#             */
/*   Updated: 2022/10/11 12:46:52 by javellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include<stddef.h>

static t_list	*ft_first(t_list *lst, void (*del)(void *), void *(*f)(void *))
{
	t_list	*res;

	res = ft_lstnew(f(lst->content));
	if (!res)
	{
		ft_lstclear(&res, del);
		return (NULL);
	}
	return (res);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res_begin;
	t_list	*res;

	res_begin = ft_first(lst, del, f);
	res = res_begin;
	if (!res)
		return (NULL);
	else
		lst = lst->next;
	while (lst)
	{
		res->next = ft_lstnew(f(lst->content));
		if (res)
		{
			lst = lst->next;
			res = res->next;
		}
		else
		{
			ft_lstclear(&res_begin, del);
			return (NULL);
		}
	}
	return (res_begin);
}
