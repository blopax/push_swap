/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclement <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 14:40:52 by pclement          #+#    #+#             */
/*   Updated: 2018/02/01 14:40:53 by pclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_nb_lst	*ft_push_pivot_to_b_last(t_sort_info *info, int piv)
{
	t_nb_lst	*last;

	last = ft_last(info->first);
	if (info->first_size < info->first_size_swap_lim)
		ft_swap_check(info, piv);
	if (last->nb <= piv)
	{
		ft_push_1_to_2(&(info->lst_a), &(info->lst_b), 1, info);
		ft_redefine(info);
		if (last->nb == piv && ft_check_piv_val(info->lst_a, piv, 'a') == 1)
		{
			ft_rotate_up(info->lst_b, info->lst_a, 1, info);
			info->count_lst_b++;
		}
	}
	else if (last->nb > piv && ft_check_piv_val(info->lst_a, piv, 'a') == 1)
	{
		ft_rotate_up(info->lst_a, info->lst_a, 1, info);
		info->count_lst_a++;
	}
	return (last);
}

void		ft_push_pivot_to_b(t_sort_info *info, int piv)
{
	t_nb_lst	*last;
	int			flag;

	info->count_lst_a = 0;
	info->count_lst_b = 0;
	last = ft_last(info->first);
	ft_redefine(info);
	flag = 0;
	while (flag == 0 && ft_check_piv_val(info->lst_a, piv, 'a') == 1)
	{
		if (last == info->first)
			flag = 1;
		last = ft_push_pivot_to_b_last(info, piv);
	}
	ft_redefine_lst_0_1(info);
	ft_rotate_back(info, piv, info->count_lst_a, info->count_lst_b);
}

t_nb_lst	*ft_push_pivot_to_a_last(t_sort_info *info, int piv)
{
	t_nb_lst	*last;

	last = ft_last(info->first);
	if (info->first_size < info->first_size_swap_lim)
		ft_swap_check(info, piv);
	if (last->nb >= piv)
	{
		ft_push_1_to_2(&(info->lst_b), &(info->lst_a), 1, info);
		ft_redefine(info);
		if (last->nb == piv && ft_check_piv_val(info->lst_b, piv, 'b') == 1)
		{
			ft_rotate_up(info->lst_a, info->lst_a, 1, info);
			info->count_lst_a++;
		}
	}
	else if (last->nb < piv && ft_check_piv_val(info->lst_b, piv, 'b') == 1)
	{
		ft_rotate_up(info->lst_b, info->lst_a, 1, info);
		info->count_lst_b++;
	}
	return (last);
}

void		ft_push_pivot_to_a(t_sort_info *info, int piv)
{
	t_nb_lst	*last;
	int			flag;

	info->count_lst_a = 0;
	info->count_lst_b = 0;
	last = ft_last(info->first);
	ft_redefine(info);
	flag = 0;
	while (flag == 0 && ft_check_piv_val(info->lst_b, piv, 'b') == 1)
	{
		if (last == info->first)
			flag = 1;
		last = ft_push_pivot_to_a_last(info, piv);
	}
	ft_redefine_lst_0_1(info);
	ft_rotate_back(info, piv, info->count_lst_b, info->count_lst_a);
}

void		ft_quicksort(t_sort_info *info)
{
	int			pivot_val;

	pivot_val = ft_find_med(info->first);
	if (info->show_pivot == 1)
	{
		write(2, "\033[1;31m", 7);
		ft_putstr_fd("Valeur du pivot :\t", 2);
		ft_putnbr_fd(pivot_val, 2);
		ft_putstr_fd("\n", 2);
		write(2, "\033[1;31m", 7);
	}
	ft_fill_pivot_lst(info->first, pivot_val);
	info->flag = 0;
	if (info->first == info->lst_b || info->first == info->lst_a)
		info->flag = 1;
	if (info->lst_to_sort == 'a')
		ft_push_pivot_to_b(info, pivot_val);
	else if (info->lst_to_sort == 'b')
		ft_push_pivot_to_a(info, pivot_val);
}
