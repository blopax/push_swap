/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_ps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclement <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 16:09:00 by pclement          #+#    #+#             */
/*   Updated: 2018/02/01 17:10:28 by pclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void		ft_init(int *i, long *result, int *sign)
{
	*i = 0;
	*result = 0;
	*sign = 1;
}

int				ft_atoi_ps(const char *str)
{
	int					i;
	int					start;
	long				result;
	int					sign;

	if (!str)
		return (0);
	ft_init(&i, &result, &sign);
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	start = i;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - 48;
		i++;
		if (result > 2147483648 || (result == 2147483648 && sign == 1))
			ft_error();
	}
	return (sign * result);
}
