/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnolan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 14:37:25 by lnolan            #+#    #+#             */
/*   Updated: 2018/12/13 20:19:25 by lnolan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *prev;
	t_list *list;
	t_list *new;

	if (!lst || !f)
		return (NULL);
	list = f(lst);
	if (!(new = ft_lstnew(list->content, list->content_size)))
		return (NULL);
	prev = new;
	lst = lst->next;
	while (lst)
	{
		list = f(lst);
		if (!(new->next = ft_lstnew(list->content, list->content_size)))
		{
			free(list->next);
			return (NULL);
		}
		new = new->next;
		lst = lst->next;
	}
	return (prev);
}
