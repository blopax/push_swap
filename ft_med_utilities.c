/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_med_utilities.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclement <pclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 17:23:05 by pclement          #+#    #+#             */
/*   Updated: 2018/03/06 15:35:20 by pclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		*ft_sort_tab(int *tab, int size)
{
	int min;
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		j = i;
		min = tab[i];
		while (j < size)
		{
			if (tab[j] < min)
			{
				tab[i] = tab[j];
				tab[j] = min;
				min = tab[i];
			}
			j++;
		}
		i++;
	}
	return (tab);
}

int		ft_get_med_value(int *tab, int pos)
{
	return (tab[pos - 1]);
}

int		ft_get_med_pos(t_nb_lst *lst)
{
	return ((ft_count_nb_lst(lst) + 1) / 2);
}

int		ft_find_med(t_nb_lst *lst)
{
	int			size;
	int			*tab;
	int			pos_med;
	int			med;
	t_nb_lst	*tmp;

	tmp = lst;
	size = ft_count_nb_lst(lst);
	if (size == 1)
		return (lst->nb);
	if (!(tab = (int *)malloc(sizeof(int) * size)))
		exit(0);
	while (size > 0)
	{
		tab[size - 1] = tmp->nb;
		if (tmp->next)
			tmp = tmp->next;
		size--;
	}
	tab = ft_sort_tab(tab, ft_count_nb_lst(lst));
	pos_med = ft_get_med_pos(lst);
	med = ft_get_med_value(tab, pos_med);
	free(tab);
	return (med);
}
