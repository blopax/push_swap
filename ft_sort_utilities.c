/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utilities.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvergnac <nvergnac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 17:26:19 by nvergnac          #+#    #+#             */
/*   Updated: 2018/01/26 20:40:13 by nvergnac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_replace(t_lst *op_lst, char *op)
{
	ft_safe_free(op_lst->op);
	op_lst->op = ft_strdup(op);
}

void	ft_redefine(t_sort_info *info)
{
	ft_prev_def(info->lst_a);
	ft_prev_def(info->lst_b);
	if (info->lst_a)
		ft_define_min_max(info->lst_a);
	if (info->lst_b)
		ft_define_min_max(info->lst_b);
}

void	ft_sort_classic(t_sort_info *info)
{
	if (ft_last(LSTA)->prev->max == 1 && ft_nb_lst(LSTA) > 2)
	{
		ft_swap(LSTA, LSTA, 1, info);
		ft_rotate_up(LSTA, LSTA, 1, info);
	}
	ft_is_sorted_bis(info->lst_a, 'a', info);
	ft_push_1_to_2(&info->lst_a, &info->lst_b, 1, info);
	ft_redefine(info);
	ft_is_sorted_bis(info->lst_b, 'b', info);
}

int		ft_sort_nico_for_a_pc_0(t_sort_info *info)
{
	int	flag;

	flag = 0;
	ft_define_min_max(LSTA);
	ft_find_med(info->lst_a);
	if (ft_is_sorted_bis(info->lst_a, 'a', info) == 1 && !info->lst_b)
		flag = 1;
	while (flag == 0)
	{
		ft_sort_classic(info);
		if (ft_is_sorted_bis(info->lst_a, 'a', info) == 1)
		{
			while (LSTB != 0 && ft_is_sorted_bis(LSTA, 'a', info) == 1)
			{
				ft_is_sorted_bis(info->lst_b, 'b', info);
				ft_push_1_to_2(&info->lst_b, &info->lst_a, 1, info);
				ft_redefine(info);
			}
		}
		if (ft_is_sorted_bis(info->lst_a, 'a', info) == 1 && !info->lst_b)
			flag = 1;
	}
	return (1);
}
