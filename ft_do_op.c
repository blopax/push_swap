/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvergnac <nvergnac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 17:25:26 by nvergnac          #+#    #+#             */
/*   Updated: 2018/01/31 15:40:38 by nvergnac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_do_op_2(t_sort_info *info)
{
	if (ft_strcmp("pa", info->OP) == 0 && LSTB)
		ft_push_1_to_2(&LSTB, &LSTA, 0, info);
	if (ft_strcmp("pb", info->OP) == 0 && LSTA)
		ft_push_1_to_2(&LSTA, &LSTB, 0, info);
	if (ft_strcmp("ra", info->OP) == 0)
		ft_rotate_up(LSTA, LSTA, 0, info);
	if (ft_strcmp("rb", info->OP) == 0)
		ft_rotate_up(LSTB, LSTA, 0, info);
	if (ft_strcmp("rr", info->OP) == 0)
	{
		ft_rotate_up(LSTA, LSTA, 0, info);
		ft_rotate_up(LSTB, LSTA, 0, info);
	}
	if (ft_strcmp("rra", info->OP) == 0)
		ft_rotate_down(LSTA, LSTA, 0, info);
	if (ft_strcmp("rrb", info->OP) == 0)
		ft_rotate_down(LSTB, LSTA, 0, info);
	if (ft_strcmp("rrr", info->OP) == 0)
	{
		ft_rotate_down(LSTA, LSTA, 0, info);
		ft_rotate_down(LSTB, LSTA, 0, info);
	}
}

void	ft_do_op(t_sort_info *info)
{
	t_lst	*tmp;

	tmp = info->op_lst;
	while (info->op_lst)
	{
		if (ft_strcmp("sa", info->OP) == 0)
			ft_swap(LSTA, LSTA, 0, info);
		if (ft_strcmp("sb", info->OP) == 0)
			ft_swap(LSTB, LSTA, 0, info);
		if (ft_strcmp("ss", info->OP) == 0)
		{
			ft_swap(LSTA, LSTA, 0, info);
			ft_swap(LSTB, LSTA, 0, info);
		}
		ft_do_op_2(info);
		ft_prev_def(LSTA);
		ft_prev_def(LSTB);
		info->op_lst = info->op_lst->next;
		if (info->show_list == 1)
		{
			ft_show_lst_a(LSTA, 2);
			ft_show_lst_b(LSTB, 2);
		}
	}
	info->op_lst = tmp;
}
