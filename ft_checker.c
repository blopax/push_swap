/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvergnac <nvergnac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 14:54:45 by nvergnac          #+#    #+#             */
/*   Updated: 2018/01/31 16:01:26 by nvergnac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_show_bonus_op_number(t_sort_info *info)
{
	if (info->count_op == 1)
	{
		ft_putstr("Cette liste a ete triee en :\t");
		ft_putnbr(ft_count_nb_lst_op(info->op_lst));
		ft_putstr(" coups\n");
	}
}

void	ft_add_op_lst_checker(t_lst *lst_op, char *line)
{
	t_lst	*tmp;
	t_lst	*new;

	tmp = lst_op;
	if (lst_op->op == 0)
		lst_op->op = ft_strdup(line);
	else
	{
		new = ft_init_lst_op();
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		new->op = ft_strdup(line);
	}
}

void	ft_get_op(t_sort_info *info)
{
	char	*line;

	while (get_next_line(0, &line))
	{
		if (ft_strcmp(line, "") == 0)
			break ;
		if (ft_strcmp(line, "Error") == 0)
		{
			ft_putstr("Error\n");
			exit(0);
		}
		ft_add_op_lst(info->op_lst, line);
		ft_safe_free(line);
	}
}

int		main(int argc, char **argv)
{
	t_sort_info *info;
	int			argc_limit;

	if (argc == 1)
		ft_usage("checker");
	argc_limit = 1;
	info = ft_init_info_struct();
	ft_check_option_checker(argv, &argc_limit, info);
	while (argc > argc_limit)
	{
		ft_get_arg(argv[argc - 1], info);
		argc--;
	}
	ft_get_op(info);
	ft_do_op(info);
	if (ft_is_sorted(LSTA, LSTA) == 1)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_show_bonus_op_number(info);
	ft_free_all(info);
	return (0);
}
