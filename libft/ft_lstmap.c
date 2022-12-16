/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 13:59:33 by mstrantz          #+#    #+#             */
/*   Updated: 2021/06/22 14:47:13 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*element;

	new_lst = 0;
	while (lst)
	{
		element = ft_lstnew(f(lst -> content));
		if (element == 0)
			ft_lstclear(&new_lst, del);
		else
			ft_lstadd_back(&new_lst, element);
		lst = lst -> next;
	}
	return (new_lst);
}
