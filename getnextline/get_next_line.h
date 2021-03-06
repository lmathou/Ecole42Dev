/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 18:44:00 by jblancha          #+#    #+#             */
/*   Updated: 2017/01/28 16:50:14 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>

typedef struct		s_file
{
	int				fd;
	char			*buf;
}					t_file;
int					get_next_line(const int fd, char **line);
# define BUFF_SIZE 10
# define NEG(x) (((x) < 0) ? 1 : 0)
# define ABS(x) (((x) < 0) ? -(x) : x)

#endif
