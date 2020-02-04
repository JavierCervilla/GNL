/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcervill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 16:13:01 by jcervill          #+#    #+#             */
/*   Updated: 2019/12/23 16:14:06 by jcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_copy_line(char **aux, char **line)
{
	char	*temp;
	int		len;

	len = 0;
	while ((*aux)[len] != '\n' && (*aux)[len] != '\0')
		len++;
	if ((*aux)[len] == '\n')
	{
		*line = ft_substr(*aux, 0, len);
		temp = ft_strdup(&((*aux)[len + 1]));
		free(*aux);
		*aux = temp;
	}
	else
	{
		*line = ft_strdup(*aux);
		free(*aux);
		*aux = NULL;
		return (0);
	}
	return (1);
}

static int	ft_ret(t_line *x, char **line, int fd)
{
	if (x->bits < 0)
		return (-1);
	else if (!x->aux[fd] && x->bits == 0)
	{
		*line = ft_strdup("");
		return (0);
	}
	return (ft_copy_line(&x->aux[fd], line));
}

int			get_next_line(int fd, char **line)
{
	static t_line x;

	if (!line || fd < 0 || BUFFER_SIZE < 1)
		return (-1);
	while ((x.bits = read(fd, x.buff, BUFFER_SIZE)) > 0)
	{
		x.buff[x.bits] = '\0';
		if (x.aux[fd] == NULL)
			x.aux[fd] = ft_strdup(x.buff);
		else
		{
			x.temp = ft_strjoin(x.aux[fd], x.buff);
			free(x.aux[fd]);
			x.aux[fd] = x.temp;
		}
		if (ft_strchr(x.aux[fd], '\n'))
			break ;
	}
	return (ft_ret(&x, line, fd));
}
