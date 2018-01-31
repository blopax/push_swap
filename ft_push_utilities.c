/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_utilities.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvergnac <nvergnac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 18:36:35 by nvergnac          #+#    #+#             */
/*   Updated: 2018/01/26 14:52:26 by pclement         ###   ########.fr       */
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
