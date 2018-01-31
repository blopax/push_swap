/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort_swap_utilities.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclement <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 15:34:33 by pclement          #+#    #+#             */
/*   Updated: 2018/01/24 16:23:03 by pclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_swap_check(t_sort_info *info, int piv_val)
{
	t_nb_lst	*last_a;
	t_nb_lst	*last_b;

	last_a = ft_last(info->lst_a);
	last_b = ft_last(info->lst_b);
	if (info->lst_to_sort == 'a')
		last_a = ft_last(info->first);
	else
		last_b = ft_last(info->first);
	if (last_a && last_a->prev &&
			last_a != info->first && last_a->prev != info->first &&
			!(ft_count_nb_lst(info->lst_a) == 2 && info->lst_a->nb == piv_val))
	{
		if (last_a->nb > last_a->prev->nb && last_a->prev->nb > piv_val)
			ft_swap(info->lst_a, info->lst_a, 1, info);
	}
	if (last_b && last_b->prev &&
			last_b != info->first && last_b->prev != info->first &&
			!(ft_count_nb_lst(info->lst_b) == 2 && info->lst_b->nb == piv_val))
	{
		if (last_b->nb < last_b->prev->nb && last_b->prev->nb <= piv_val)
			ft_swap(info->lst_b, info->lst_a, 1, info);
	}
}

void		ft_fill_pivot_lst(t_nb_lst *lst, int piv_val)
{
	while (lst)
	{
		if (lst->nb == piv_val)
			lst->pivot = 1;
		lst = lst->next;
	}
}

int			ft_check_piv_val(t_nb_lst *lst, int piv_val, char c)
{
	if (c == 'a')
	{
		while (lst)
		{
			if (lst->nb <= piv_val)
				return (1);
			lst = lst->next;
		}
	}
	else if (c == 'b')
	{
		while (lst)
		{
			if (lst->nb >= piv_val)
				return (1);
			lst = lst->next;
		}
	}
	return (0);
}

void		ft_redefine_lst_0_1(t_sort_info *info)
{
	if (info->lst_to_sort == 'a')
	{
		info->lst_0 = info->lst_a;
		info->lst_1 = info->lst_b;
	}
	else
	{
		info->lst_0 = info->lst_b;
		info->lst_1 = info->lst_a;
	}
}
