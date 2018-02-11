#include "header.h"

void	ft_push_bis(int flag, int s, t_nb_lst **lst_2_ptr, t_sort_info *info)
{
	if (flag == 1)
	{
		if (*lst_2_ptr == LSTA)
			ft_last(LSTB)->prev->next = NULL;
		else
			ft_last(LSTA)->prev->next = NULL;
	}
	else
	{
		if (*lst_2_ptr == LSTA)
			LSTB = NULL;
		else
			LSTA = NULL;
	}
	if (s == 1)
	{
		*lst_2_ptr == LSTA ? ft_add_op_lst(info->op_lst, "pa\n") :
			ft_add_op_lst(info->op_lst, "pb\n");
	}
}

void	ft_rotate_lst_content(t_nb_lst *lst, t_nb_lst tmp)
{
	lst->nb = tmp.nb;
	lst->index = tmp.index;
	lst->max = tmp.max;
	lst->min = tmp.min;
	lst->pivot = tmp.pivot;
	lst->sort = tmp.sort;
}

void	ft_swap_lst_content(t_nb_lst *lst, t_nb_lst tmp)
{
	lst->nb = lst->next->nb;
	lst->index = lst->next->index;
	lst->pivot = lst->next->pivot;
	lst->max = lst->next->max;
	lst->min = lst->next->min;
	lst->sort = lst->next->sort;
	lst->next->nb = tmp.nb;
	lst->index = tmp.next->index;
	lst->pivot = tmp.next->pivot;
	lst->next->max = tmp.max;
	lst->next->min = tmp.min;
	lst->sort = tmp.next->sort;
}

void	ft_prev_def(t_nb_lst *lst)
{
	t_nb_lst	*tmp;

	tmp = NULL;
	while (lst)
	{
		lst->prev = tmp;
		tmp = lst;
		if (!(lst = lst->next))
			break ;
	}
}

int		ft_count_nb_lst(t_nb_lst *lst)
{
	int			i;
	t_nb_lst	*tmp;

	i = 0;
	tmp = lst;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}
