/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbratche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 19:34:39 by sbratche          #+#    #+#             */
/*   Updated: 2017/12/25 19:34:50 by sbratche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/get_next_line.h"

t_list					*ft_new_lstnew(void const *content, size_t content_size)
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
			if (!(copy = (void *)malloc(sizeof(*copy))))
				free(copy);
			fresh->content = copy;
			bzero(copy, ft_strlen(copy));
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

static t_list			*ft_get_correct_fd(t_list **stalst, int fd)
{
	t_list *newlst;

	newlst = *stalst;
	while (newlst)
	{
		if (newlst->content_size == (size_t)fd)
			return (newlst);
		newlst = newlst->next;
	}
	newlst = ft_new_lstnew("\0", fd);
	ft_lstadd(stalst, newlst);
	return (newlst);
}

static int				ft_if_ret_zero(t_list *temp, char **line)
{
	if (ft_strlen(temp->content) == 0 && ft_strlen(*line) == 0)
		return (0);
	temp->content = "\0";
	return (1);
}

static void				ft_write_leftover(char *str, t_list *temp, char **line)
{
	int i;

	str = temp->content;
	temp->content = ft_strdup(*line);
	free(str);
	str = *line;
	i = ft_strchr(str, '\n') - str;
	*line = ft_strsub(str, 0, i);
	free(str);
	str = temp->content;
	temp->content = ft_strsub(str, i + 1, ft_strlen(str) - i);
	free(str);
}

int						get_next_line(const int fd, char **line)
{
	int				ret;
	char			buff[BUFF_SIZE + 1];
	char			*str;
	static t_list	*stalst = NULL;
	t_list			*temp;

	if (fd < 0 || !line || BUFF_SIZE <= 0 ||
		(!(temp = ft_get_correct_fd(&stalst, fd))))
		return (-1);
	str = ft_strnew(0);
	*line = ft_strjoin(temp->content, str);
	free(str);
	while (!(ft_strchr(*line, '\n')))
	{
		if ((ret = read(fd, buff, BUFF_SIZE)) == -1)
			return (-1);
		if (ret == 0)
			return (ft_if_ret_zero(temp, line));
		buff[ret] = '\0';
		str = *line;
		*line = ft_strjoin(str, buff);
		free(str);
	}
	ft_write_leftover(str, temp, line);
	return (1);
}
