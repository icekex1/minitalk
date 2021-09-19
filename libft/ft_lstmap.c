/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzeck <tzeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 13:02:42 by tzeck             #+#    #+#             */
/*   Updated: 2021/07/21 18:38:46 by tzeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*cur;

	if (lst && f)
	{
		new_lst = ft_lstnew(f(lst->content));
		cur = new_lst;
		while (lst->next)
		{
			lst = lst->next;
			cur->next = ft_lstnew(f(lst->content));
			if (cur->next == NULL)
			{
				ft_lstclear(&new_lst, del);
				return (NULL);
			}
			cur = cur->next;
		}
		return (new_lst);
	}
	return (NULL);
}
