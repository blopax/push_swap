/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_doublons.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclement <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 15:13:15 by pclement          #+#    #+#             */
/*   Updated: 2018/02/01 16:29:10 by pclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_check_value(int *tab, int size)
{
	while (size - 1 > 0)
	{
		if (tab[size - 1] == tab[size - 2])
			return (1);
		size--;
	}
	return (0);
}

int		ft_check_double(t_nb_lst *lst)
{
	int			size;
	int			*tab;
	t_nb_lst	*tmp;
	int			error;

	error = 0;
	tmp = lst;
	size = ft_count_nb_lst(lst);
	if (size == 1)
		return (0);
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
	error = ft_check_value(tab, ft_count_nb_lst(lst));
	free(tab);
	return (error);
}

void	ft_error(void)
{
	ft_putstr("Error\n");
	exit(0);
}
