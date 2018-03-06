/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opti_op_lst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclement <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 14:47:19 by pclement          #+#    #+#             */
/*   Updated: 2018/03/06 15:35:21 by pclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_check_consecutive_s(t_lst *op_lst)
{
	t_lst	*tmp;

	tmp = op_lst->next;
	if (ft_strcmp(OP, "sa\n") == 0 && ft_strcmp(tmp->op, "sb\n") == 0)
	{
		ft_replace(op_lst, "ss\n");
		op_lst->next = tmp->next;
		if (tmp->next)
			tmp->next->prev = op_lst;
		ft_safe_free_lst_op(tmp);
	}
	else if (ft_strcmp(OP, "sb\n") == 0 && ft_strcmp(tmp->op, "sa\n") == 0)
	{
		ft_replace(op_lst, "ss\n");
		op_lst->next = tmp->next;
		if (tmp->next)
			tmp->next->prev = op_lst;
		ft_safe_free_lst_op(tmp);
	}
}

void	ft_check_consecutive_r(t_lst *op_lst)
{
	t_lst	*tmp;

	tmp = op_lst->next;
	if (ft_strcmp(OP, "ra\n") == 0 && ft_strcmp(tmp->op, "rb\n") == 0)
	{
		ft_replace(op_lst, "rr\n");
		op_lst->next = tmp->next;
		if (tmp->next)
			tmp->next->prev = op_lst;
		ft_safe_free_lst_op(tmp);
	}
	else if (ft_strcmp(OP, "rb\n") == 0 && ft_strcmp(tmp->op, "ra\n") == 0)
	{
		ft_replace(op_lst, "rr\n");
		op_lst->next = tmp->next;
		if (tmp->next)
			tmp->next->prev = op_lst;
		ft_safe_free_lst_op(tmp);
	}
}

void	ft_check_consecutive_rr(t_lst *op_lst)
{
	t_lst	*tmp;

	tmp = op_lst->next;
	if (ft_strcmp(OP, "rra\n") == 0 && ft_strcmp(tmp->op, "rrb\n") == 0)
	{
		ft_replace(op_lst, "rrr\n");
		op_lst->next = tmp->next;
		if (tmp->next)
			tmp->next->prev = op_lst;
		ft_safe_free_lst_op(tmp);
	}
	else if (ft_strcmp(OP, "rrb\n") == 0 && ft_strcmp(tmp->op, "rra\n") == 0)
	{
		ft_replace(op_lst, "rrr\n");
		op_lst->next = tmp->next;
		if (tmp->next)
			tmp->next->prev = op_lst;
		ft_safe_free_lst_op(tmp);
	}
}

void	ft_opti_op_lst(t_lst *op_lst)
{
	while (op_lst && op_lst->next)
	{
		ft_check_consecutive_s(op_lst);
		ft_check_consecutive_r(op_lst);
		ft_check_consecutive_rr(op_lst);
		op_lst = op_lst->next;
	}
}
