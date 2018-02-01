/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min_max.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclement <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 14:38:23 by pclement          #+#    #+#             */
/*   Updated: 2018/02/01 14:39:12 by pclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_set_max(t_nb_lst *lst)
{
	int max;

	max = lst->nb;
	while (lst)
	{
		if (lst->nb > max)
			max = lst->nb;
		lst = lst->next;
	}
	return (max);
}

int		ft_set_min(t_nb_lst *lst)
{
	int min;

	min = lst->nb;
	while (lst)
	{
		if (lst->nb < min)
			min = lst->nb;
		lst = lst->next;
	}
	return (min);
}

void	ft_define_min_max(t_nb_lst *lst)
{
	int max;
	int min;

	max = ft_set_max(lst);
	min = ft_set_min(lst);
	while (lst)
	{
		if (lst->nb == min)
			lst->min = 1;
		else
			lst->min = 0;
		if (lst->nb == max)
			lst->max = 1;
		else
			lst->max = 0;
		lst = lst->next;
	}
}
