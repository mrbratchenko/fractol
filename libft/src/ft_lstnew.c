/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbratche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 19:06:33 by sbratche          #+#    #+#             */
/*   Updated: 2017/11/14 19:06:34 by sbratche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*fresh;
	void	*copy;

	copy = NULL;
	if (!(fresh = (t_list *)malloc(sizeof(t_list))))
		free(fresh);
	if (fresh != NULL)
	{
		fresh->next = NULL;
		if (content != NULL)
		{
			if (!(copy = (void *)malloc(sizeof(*copy) * content_size)))
				free(copy);
			fresh->content = copy;
			copy = ft_memcpy(copy, content, content_size);
			fresh->content_size = content_size;
		}
		else
		{
			fresh->content = NULL;
			fresh->content_size = 0;
		}
		return (fresh);
	}
	return (NULL);
}
