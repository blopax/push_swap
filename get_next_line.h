/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclement <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 16:40:12 by pclement          #+#    #+#             */
/*   Updated: 2018/02/11 16:40:14 by pclement         ###   ########.fr       */
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
