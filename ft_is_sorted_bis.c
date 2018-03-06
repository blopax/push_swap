/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sorted_bis.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclement <pclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 17:55:06 by pclement          #+#    #+#             */
/*   Updated: 2018/03/06 15:35:20 by pclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_swap_if_b_first_piv(t_nb_lst *lst, t_nb_lst *lsta, t_sort_info *info)
{
	t_nb_lst *tmp;

	tmp = lst;
	if (lst && ft_nb_lst(lst) > 1)
	{
		while (lst && lst->next)
			lst = lst->next;
		if (lst->min == 1 && ft_nb_lst(tmp) > 2)
		{
			ft_rotate_up(tmp, lsta, 1, info);
			ft_swap_if_b_first_piv(tmp, lsta, info);
		}
		if (lst->nb < lst->prev->nb)
		{
			ft_swap(tmp, lsta, 1, info);
			ft_swap_if_b_first_piv(tmp, lsta, info);
		}
	}
}

void	ft_swap_if_a_first_piv(t_nb_lst *lst, t_nb_lst *lsta, t_sort_info *info)
{
	t_nb_lst *tmp;

	tmp = lst;
	{
		if (lst->min == 1 && ft_nb_lst(lst) > 2)
		{
			ft_rotate_down(tmp, lsta, 1, info);
			ft_swap_if_a_first_piv(tmp, lsta, info);
		}
		while (lst && lst->next)
			lst = lst->next;
		if (lst->max == 1 && ft_count_nb_lst(tmp) > 2)
		{
			ft_rotate_up(tmp, lsta, 1, info);
			ft_swap_if_a(tmp, lsta, info);
		}
		if (lst->nb > lst->prev->nb)
			ft_swap(tmp, lsta, 1, info);
	}
}

void	ft_reset_sort_status(t_nb_lst *lst)
{
	t_nb_lst *tmp;

	tmp = lst;
	while (tmp && tmp->next)
	{
		lst->sort = -1;
		tmp = tmp->next;
	}
	tmp->sort = -1;
}

int		ft_is_sorted_bis(t_nb_lst *lst, char ref, t_sort_info *info)
{
	if (lst == info->lst_a)
		ft_swap_if_a_first_piv(lst, info->lst_a, info);
	if (lst == info->lst_b)
		ft_swap_if_b_first_piv(lst, info->lst_a, info);
	if (ft_nb_lst(lst) == 1)
		return (1);
	ft_reset_sort_status(lst);
	ref == 'a' ? ft_define_sort_a(lst) : ft_define_sort_b(lst);
	while (lst && lst->next)
	{
		if (lst->sort == 1)
			lst = lst->next;
		else
			return (0);
	}
	return (1);
}
