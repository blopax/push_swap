/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvergnac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 19:05:05 by nvergnac          #+#    #+#             */
/*   Updated: 2018/01/30 20:54:55 by nvergnac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <limits.h>
# include "libft/libft.h"
# define BUFF_SIZE 32

typedef struct	s_gnl
{
	char	*tmp;
	char	buf[BUFF_SIZE + 1];
	int		ret;
}				t_gnl;

int				get_next_line(const int fd, char **line);
#endif
