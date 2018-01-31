/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_utilities.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvergnac <nvergnac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 17:39:56 by nvergnac          #+#    #+#             */
/*   Updated: 2018/01/31 15:50:45 by nvergnac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int			ft_count_nb_lst_op(t_lst *lst)
{
	int i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

void		ft_show_lst_op(t_lst *lst)
{
	while (lst)
	{
		write(0, "\033[0;m", 5);
		ft_putstr(lst->op);
		lst = lst->next;
	}
}

void		ft_show_lst_op_c(t_lst *lst)
{
	while (lst)
	{
		if (lst->next == NULL)
		{
			write(0, "\033[1;31m", 7);
			ft_putstr(lst->op);
		}
		else
		{
			write(0, "\033[0;m", 5);
			ft_putstr(lst->op);
		}
		lst = lst->next;
	}
	write(0, "\033[0;m", 5);
}

void		ft_show_lst_a(t_nb_lst *lst, int c)
{
	if (c == 1)
		write(2, "\033[1;32m", 7);
	else
		write(2, "\033[1;36m", 7);
	ft_putstr_fd("LIST A\n", 2);
	while (lst)
	{
		ft_putstr_fd("|", 2);
		ft_putnbr_fd(lst->nb, 2);
		ft_putstr_fd("| ", 2);
		lst = lst->next;
	}
	ft_putstr_fd("\n_______________________________________\n", 2);
	write(2, "\033[0;m", 5);
}

void		ft_show_lst_b(t_nb_lst *lst, int c)
{
	if (c == 1)
		write(2, "\033[1;35m", 7);
	else
		write(2, "\033[1;33m", 7);
	ft_putstr_fd("LIST B\n", 2);
	while (lst)
	{
		ft_putstr_fd("|", 2);
		ft_putnbr_fd(lst->nb, 2);
		ft_putstr_fd("| ", 2);
		lst = lst->next;
	}
	ft_putstr_fd("\n***************************************\n", 2);
	ft_putstr_fd("***************************************\n", 2);
	write(2, "\033[0;m", 5);
}
