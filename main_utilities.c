/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utilities.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclement <pclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 14:58:13 by pclement          #+#    #+#             */
/*   Updated: 2018/03/06 15:35:21 by pclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_check_option(char **argv, int *argc_limit, t_sort_info *info)
{
	int	i;

	i = 1;
	while (i <= 3)
	{
		if (ft_strcmp(argv[i], "-r") == 0)
		{
			info->last_op_red = 1;
			(*argc_limit)++;
		}
		else if (ft_strcmp(argv[i], "-p") == 0)
		{
			info->show_pivot = 1;
			(*argc_limit)++;
		}
		else if (ft_strcmp(argv[i], "-s") == 0)
		{
			info->show_list = 1;
			(*argc_limit)++;
		}
		else
			return (0);
		i++;
	}
	return (0);
}

int		ft_check_option_checker(char **argv, int *argc_limit, t_sort_info *info)
{
	int	i;

	i = 1;
	while (i <= 2)
	{
		if (ft_strcmp(argv[i], "-n") == 0)
		{
			info->count_op = 1;
			(*argc_limit)++;
		}
		else if (ft_strcmp(argv[i], "-s") == 0)
		{
			info->show_list = 1;
			(*argc_limit)++;
		}
		else
			return (0);
		i++;
	}
	return (0);
}

void	ft_check_error(char *data)
{
	int	i;

	i = 0;
	if (data[i] == '-' || data[i] == '+')
		i++;
	if (data[i] == 0)
	{
		ft_putstr("Error\n");
		exit(0);
	}
	while (data[i])
	{
		if (data[i] >= '0' && data[i] <= '9')
			i++;
		else
		{
			ft_putstr("Error\n");
			exit(0);
		}
	}
}

void	ft_get_arg(char *arg, t_sort_info *info)
{
	char	**argv;
	int		size;

	argv = ft_strsplit(arg, ' ');
	size = 0;
	while (argv[size])
		size++;
	size--;
	while (size >= 0)
	{
		ft_check_error(argv[size]);
		ft_add_nb_lst(LSTA, ft_atoi_ps(argv[size]));
		size--;
	}
	size = 0;
	while (argv[size])
	{
		ft_safe_free(argv[size]);
		argv[size] = 0;
		size++;
	}
	free(argv);
	argv = 0;
}

void	ft_usage(char *str)
{
	if (ft_strcmp(str, "push_swap") == 0)
	{
		write(1, "usage:\tpush_swap [-r -s -p] integers\
				\n\t-r shows last operation in red\
				\n\t-s shows lists after each pivot (for argc > 9)\
				\n\t-p shows each pivot value\n", 156);
	}
	if (ft_strcmp(str, "checker") == 0)
	{
		write(1, "usage:\tchecker [-n -s] integers\
				\n\t-n shows number of operation\
				\n\t-s shows lists before each operation\n", 108);
	}
	exit(0);
}
