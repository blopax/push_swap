/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_lst_push_swap.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclement <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 16:35:18 by pclement          #+#    #+#             */
/*   Updated: 2018/02/11 16:35:20 by pclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_lst			*ft_init_lst_op(void)
{
	t_lst	*new_lst_op;

	if (!(new_lst_op = (t_lst*)malloc(sizeof(t_lst))))
		exit(0);
	new_lst_op->op = 0;
	new_lst_op->next = NULL;
	new_lst_op->prev = NULL;
	return (new_lst_op);
}

void			ft_add_op_lst(t_lst *lst_op, char *line)
{
	t_lst	*new;

	if (lst_op->op == 0)
		lst_op->op = ft_strdup(line);
	else
	{
		new = ft_init_lst_op();
		while (lst_op->next)
			lst_op = lst_op->next;
		lst_op->next = new;
		new->prev = lst_op;
		new->op = ft_strdup(line);
	}
}

t_nb_lst		*ft_init_lst_nb(void)
{
	t_nb_lst	*new_lst_nb;

	if (!(new_lst_nb = (t_nb_lst*)malloc(sizeof(t_nb_lst))))
		exit(0);
	new_lst_nb->nb = 0;
	new_lst_nb->pivot = 0;
	new_lst_nb->index = 0;
	new_lst_nb->sort = -1;
	new_lst_nb->min = 0;
	new_lst_nb->max = 0;
	new_lst_nb->next = NULL;
	new_lst_nb->prev = NULL;
	return (new_lst_nb);
}

void			ft_add_nb_lst(t_nb_lst *lst, int nb)
{
	t_nb_lst	*tmp;
	t_nb_lst	*new;

	tmp = lst;
	if (lst->index == 0)
	{
		lst->nb = nb;
		lst->index = 1;
	}
	else
	{
		new = ft_init_lst_nb();
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		while (lst->next != new)
			lst = lst->next;
		lst->next = new;
		new->prev = lst;
		new->nb = nb;
	}
}

t_sort_info		*ft_init_info_struct(void)
{
	t_sort_info	*info;

	if (!(info = (t_sort_info *)malloc(sizeof(t_sort_info))))
		exit(0);
	info->lst_a = ft_init_lst_nb();
	info->lst_b = 0;
	info->op_lst = ft_init_lst_op();
	info->pivot_count = 0;
	info->show_list = 0;
	info->show_pivot = 0;
	info->last_op_red = 0;
	info->count_op = 0;
	return (info);
}
