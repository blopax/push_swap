/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opti_op_lst_bis.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclement <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 14:40:08 by pclement          #+#    #+#             */
/*   Updated: 2018/02/01 14:40:10 by pclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_check_separate_sa_sb(t_lst *op_lst)
{
	t_lst	*tmp;
	t_lst	*rem;

	if (ft_strcmp(OP, "sa\n") == 0 && ft_strcmp(OPNN, "sb\n") == 0 &&
			(ft_strcmp(OPN, "ra\n") == 0 || ft_strcmp(OPN, "rb\n") == 0))
	{
		if (ft_strcmp(OPN, "ra\n") == 0)
		{
			rem = op_lst->next->next;
			tmp = op_lst;
		}
		if (ft_strcmp(OPN, "rb\n") == 0)
		{
			rem = op_lst;
			tmp = op_lst->next->next;
		}
		ft_replace(tmp, "ss\n");
		if (rem->next && rem->prev)
		{
			rem->next->prev = rem->prev;
			rem->prev->next = rem->next;
		}
		ft_safe_free_lst_op(rem);
	}
}

void	ft_check_separate_sb_sa(t_lst *op_lst)
{
	t_lst	*tmp;
	t_lst	*rem;

	if (ft_strcmp(OP, "sb\n") == 0 && ft_strcmp(OPNN, "sa\n") == 0 &&
			(ft_strcmp(OPN, "ra\n") == 0 || ft_strcmp(OPN, "rb\n") == 0))
	{
		if (ft_strcmp(OPN, "ra\n") == 0)
		{
			tmp = op_lst->next->next;
			rem = op_lst;
		}
		if (ft_strcmp(OPN, "rb\n") == 0)
		{
			tmp = op_lst;
			rem = op_lst->next->next;
		}
		ft_replace(tmp, "ss\n");
		if (rem->next && rem->prev)
		{
			rem->next->prev = rem->prev;
			rem->prev->next = rem->next;
		}
		ft_safe_free_lst_op(rem);
	}
}

void	ft_check_separate_ra_rb(t_lst *op_lst)
{
	t_lst	*tmp;
	t_lst	*rem;

	if (ft_strcmp(OP, "ra\n") == 0 && ft_strcmp(OPNN, "rb\n") == 0 &&
			(ft_strcmp(OPN, "sa\n") == 0 || ft_strcmp(OPN, "sb\n") == 0))
	{
		if (ft_strcmp(OPN, "sa\n") == 0)
		{
			rem = op_lst->next->next;
			tmp = op_lst;
		}
		if (ft_strcmp(OPN, "sb\n") == 0)
		{
			rem = op_lst;
			tmp = op_lst->next->next;
		}
		ft_replace(tmp, "rr\n");
		if (rem->next && rem->prev)
		{
			rem->next->prev = rem->prev;
			rem->prev->next = rem->next;
		}
		ft_safe_free_lst_op(rem);
	}
}

void	ft_check_separate_rb_ra(t_lst *op_lst)
{
	t_lst	*tmp;
	t_lst	*rem;

	if (ft_strcmp(OP, "rb\n") == 0 && ft_strcmp(OPNN, "ra\n") == 0 &&
			(ft_strcmp(OPN, "sa\n") == 0 || ft_strcmp(OPN, "sb\n") == 0))
	{
		if (ft_strcmp(OPN, "sa\n") == 0)
		{
			tmp = op_lst->next->next;
			rem = op_lst;
		}
		if (ft_strcmp(OPN, "sb\n") == 0)
		{
			tmp = op_lst;
			rem = op_lst->next->next;
		}
		ft_replace(tmp, "rr\n");
		if (rem->next && rem->prev)
		{
			rem->next->prev = rem->prev;
			rem->prev->next = rem->next;
		}
		ft_safe_free_lst_op(rem);
	}
}

void	ft_opti_op_lst_2(t_lst *op_lst)
{
	int count;

	count = 0;
	while (op_lst && op_lst->next && op_lst->next->next)
	{
		ft_check_separate_sa_sb(op_lst);
		ft_check_separate_sb_sa(op_lst);
		ft_check_separate_ra_rb(op_lst);
		ft_check_separate_rb_ra(op_lst);
		op_lst = op_lst->next;
		count++;
	}
}
