/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_safe_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclement <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 16:38:50 by pclement          #+#    #+#             */
/*   Updated: 2018/02/11 16:38:53 by pclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*ft_safe_free(char *str)
{
	if (str)
	{
		free(str);
		str = NULL;
	}
	return (str);
}

void	ft_free_lst_op(t_lst *op_lst)
{
	t_lst	*tmp;

	tmp = op_lst;
	while (op_lst)
	{
		tmp = op_lst->next;
		ft_safe_free(op_lst->op);
		free(op_lst);
		op_lst = tmp;
	}
}

void	ft_free_lst_nb(t_nb_lst *lst)
{
	t_nb_lst *tmp;

	tmp = lst;
	while (lst)
	{
		tmp = lst->next;
		free(lst);
		lst = tmp;
	}
}

void	ft_free_all(t_sort_info *info)
{
	ft_free_lst_op(info->op_lst);
	info->op_lst = 0;
	ft_free_lst_nb(LSTA);
	LSTA = 0;
	ft_free_lst_nb(LSTB);
	LSTB = 0;
	free(info);
	info = 0;
}

void	ft_safe_free_lst_op(t_lst *op_lst)
{
	ft_safe_free(op_lst->op);
	free(op_lst);
}
