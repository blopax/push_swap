/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclement <pclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 15:27:07 by pclement          #+#    #+#             */
/*   Updated: 2018/03/06 15:35:21 by pclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_sort_process(t_sort_info *info)
{
	info->first_size_swap_lim = 10;
	ft_rec_sort(info);
	ft_opti_op_lst(info->op_lst);
	if (info->last_op_red >= 1)
		ft_show_lst_op_c(info->op_lst);
	else
		ft_show_lst_op(info->op_lst);
	ft_free_all(info);
}

int		main(int argc, char **argv)
{
	t_sort_info	*info;
	int			argc_limit;

	argc_limit = 1;
	if (argc == 1)
		ft_usage("push_swap");
	info = ft_init_info_struct();
	ft_check_option(argv, &argc_limit, info);
	while (argc > argc_limit)
	{
		ft_get_arg(argv[argc - 1], info);
		argc--;
	}
	if (ft_check_double(LSTA) == 1)
		ft_error();
	ft_sort_process(info);
	return (0);
}
