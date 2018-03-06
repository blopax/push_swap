/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclement <pclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 14:54:45 by pclement          #+#    #+#             */
/*   Updated: 2018/03/06 15:35:20 by pclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_show_bonus_op_number(t_sort_info *info)
{
	if (ft_is_sorted(LSTA, LSTA) == 1 && LSTB == 0)
	{
		write(1, "OK\n", 3);
		if (info->count_op == 1)
		{
			ft_putstr("Cette liste a ete triee en :\t");
			ft_putnbr(ft_count_nb_lst_op(info->op_lst));
			ft_putstr(" coups\n");
		}
	}
	else
		write(1, "KO\n", 3);
}

void	ft_check_op_error(char *line)
{
	if (ft_strcmp(line, "pa") != 0 && ft_strcmp(line, "pb") != 0 &&
			ft_strcmp(line, "sa") != 0 && ft_strcmp(line, "sb") != 0 &&
			ft_strcmp(line, "ra") != 0 && ft_strcmp(line, "rb") != 0 &&
			ft_strcmp(line, "rra") != 0 && ft_strcmp(line, "rrb") != 0 &&
			ft_strcmp(line, "ss") != 0 && ft_strcmp(line, "rr") != 0 &&
			ft_strcmp(line, "rrr") != 0)
		ft_error();
}

void	ft_get_op(t_sort_info *info)
{
	char	*line;

	while (get_next_line(0, &line))
	{
		ft_check_op_error(line);
		ft_add_op_lst(info->op_lst, line);
		ft_safe_free(line);
	}
}

int		main(int argc, char **argv)
{
	t_sort_info *info;
	int			argc_limit;

	argc_limit = 1;
	info = ft_init_info_struct();
	ft_check_option_checker(argv, &argc_limit, info);
	if (argc - argc_limit == 0)
		ft_usage("checker");
	while (argc > argc_limit)
	{
		ft_get_arg(argv[argc - 1], info);
		argc--;
	}
	if (ft_check_double(LSTA) == 1)
		ft_error();
	ft_get_op(info);
	ft_do_op(info);
	ft_show_bonus_op_number(info);
	ft_free_all(info);
	return (0);
}
