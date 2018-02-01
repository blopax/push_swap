/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclement <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 14:37:21 by pclement          #+#    #+#             */
/*   Updated: 2018/02/01 14:37:24 by pclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_swap_if_b(t_nb_lst *lst, t_nb_lst *lst_a, t_sort_info *info)
{
	t_nb_lst *tmp;

	tmp = lst;
	if (lst && ft_count_nb_lst(lst) > 1)
	{
		while (lst && lst->next)
			lst = lst->next;
		if (lst->nb < lst->prev->nb)
			ft_swap(tmp, lst_a, 1, info);
	}
}

void	ft_swap_if_a(t_nb_lst *lst, t_nb_lst *lst_a, t_sort_info *info)
{
	t_nb_lst *tmp;

	tmp = lst;
	{
		while (lst && lst->next)
			lst = lst->next;
		if (lst->nb > lst->prev->nb)
			ft_swap(tmp, lst_a, 1, info);
	}
}

void	ft_define_sort_a(t_nb_lst *lst)
{
	while (lst && lst->next)
	{
		if (lst->nb >= lst->next->nb)
			lst->sort = 1;
		else
			lst->sort = 0;
		lst = lst->next;
	}
	if (lst->nb <= lst->prev->nb)
		lst->sort = 1;
	else
		lst->sort = 0;
}

void	ft_define_sort_b(t_nb_lst *lst)
{
	while (lst && lst->next)
	{
		if (lst->nb <= lst->next->nb)
			lst->sort = 1;
		else
			lst->sort = 0;
		lst = lst->next;
	}
	if (lst->nb >= lst->prev->nb)
		lst->sort = 1;
	else
		lst->sort = 0;
}

int		ft_is_sorted(t_nb_lst *lst, t_nb_lst *lst_a)
{
	if (ft_count_nb_lst(lst) == 1)
		return (1);
	ft_reset_sort_status(lst);
	lst == lst_a ? ft_define_sort_a(lst) : ft_define_sort_b(lst);
	while (lst && lst->next)
	{
		if (lst->sort == 1)
			lst = lst->next;
		else
			return (0);
	}
	return (1);
}
