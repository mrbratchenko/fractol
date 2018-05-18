/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbratche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 20:56:41 by sbratche          #+#    #+#             */
/*   Updated: 2017/11/15 20:56:43 by sbratche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *fresh;
	t_list *head;

	if (lst == NULL || f == NULL)
		return (NULL);
	fresh = f(lst);
	head = fresh;
	while (lst->next != NULL)
	{
		lst = lst->next;
		if (!(fresh->next = (t_list *)malloc(sizeof(t_list))))
			free(fresh->next);
		fresh->next = f(lst);
		fresh = fresh->next;
	}
	return (head);
}
