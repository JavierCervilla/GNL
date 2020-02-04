/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcervill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 16:14:31 by jcervill          #+#    #+#             */
/*   Updated: 2019/12/23 16:15:21 by jcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# ifndef FD_SIZE
#  define FD_SIZE 4096
# endif
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

typedef struct	s_line
{
	char	*aux[FD_SIZE];
	char	buff[BUFFER_SIZE + 1];
	char	*temp;
	int		bits;
}				t_line;

char			*ft_strjoin(char *s1, char *s2);
size_t			ft_strlen(char *str);
char			*ft_strdup(char *s);
char			*ft_strchr(char *s, int c);
char			*ft_substr(char *s, size_t start, size_t len);
int				get_next_line(int fd, char **line);
#endif
