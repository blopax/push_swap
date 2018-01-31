/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclement <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 15:32:59 by pclement          #+#    #+#             */
/*   Updated: 2018/01/26 14:56:41 by pclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_rotate_b_1(t_sort_info *info, int *count_lst_1_ptr, char c)
{
	if (c == 'd')
	{
		ft_rotate_down(info->lst_1, info->lst_a, 1, info);
		(*count_lst_1_ptr)--;
	}
	if (c == 'u')
	{
		ft_rotate_up(info->lst_1, info->lst_a, 1, info);
		(*count_lst_1_ptr)++;
	}
}

void		ft_rotate_b_0(t_sort_info *info, int *count_0_ptr, char c, int piv)
{
	if (c == 'd')
	{
		ft_rotate_down(info->lst_0, info->lst_a, 1, info);
		(*count_0_ptr)--;
		if (info->first_size < info->first_size_swap_lim)
			ft_swap_check(info, piv);
	}
	if (c == 'u')
	{
		ft_rotate_up(info->lst_0, info->lst_a, 1, info);
		(*count_0_ptr)++;
		if (info->first_size < info->first_size_swap_lim)
			ft_swap_check(info, piv);
	}
}

void		ft_rotate_back(t_sort_info *inf, int piv, int count0, int count_1)
{
	if (inf->first_size < inf->first_size_swap_lim)
		ft_swap_check(inf, piv);
	if (count_1 <= ft_count_nb_lst(inf->lst_1) / 2)
	{
		while (count_1 > 0 && ft_count_nb_lst(inf->lst_1) > 1)
			ft_rotate_b_1(inf, &count_1, 'd');
	}
	else
	{
		while (count_1 <= ft_nb_lst(inf->lst_1) && ft_nb_lst(inf->lst_1) > 1)
			ft_rotate_b_1(inf, &count_1, 'u');
	}
	if (inf->flag != 1)
	{
		if (count0 <= ft_count_nb_lst(inf->lst_0) / 2 && inf->pivot_count > 0)
		{
			while (count0 > 0 && ft_count_nb_lst(inf->lst_0) > 2)
				ft_rotate_b_0(inf, &count0, 'd', piv);
		}
		else if (count0 > ft_nb_lst(inf->lst_0) / 2 && inf->pivot_count > 0)
		{
			while (count0 <= ft_nb_lst(inf->lst_0) && ft_nb_lst(inf->lst_0) > 1)
				ft_rotate_b_0(inf, &count0, 'u', piv);
		}
	}
}
