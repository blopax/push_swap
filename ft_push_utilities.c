/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_utilities.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclement <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 16:38:25 by pclement          #+#    #+#             */
/*   Updated: 2018/02/11 16:38:27 by pclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_middle(int a, int b, int c)
{
	if ((a <= b && b <= c) || (c <= b && b <= a))
		return (b);
	else if ((b <= a && a <= c) || (c <= a && a <= b))
		return (a);
	else
		return (c);
}

int		ft_nb_lst(t_nb_lst *lst)
{
	int i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

int		ft_max(int a, int b)
{
	if (a <= b)
		return (b);
	else
		return (a);
}

int		ft_min(int a, int b)
{
	if (a >= b)
		return (b);
	else
		return (a);
}
