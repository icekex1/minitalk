/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzeck <tzeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 17:56:12 by tzeck             #+#    #+#             */
/*   Updated: 2021/07/15 17:31:04 by tzeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	struct s_list	*ft_list;

	ft_list = malloc(sizeof(struct s_list));
	if (ft_list == NULL)
		return (NULL);
	ft_list->content = content;
	ft_list->next = NULL;
	return (ft_list);
}
