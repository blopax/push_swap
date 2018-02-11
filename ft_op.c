#include "header.h"

t_nb_lst	*ft_last(t_nb_lst *first)
{
	t_nb_lst	*last;

	last = first;
	while (last && last->next)
		last = last->next;
	return (last);
}

void		ft_swap(t_nb_lst *lst, t_nb_lst *lst_a, int s, t_sort_info *info)
{
	t_nb_lst	tmp;
	t_nb_lst	*index;

	index = lst;
	if (ft_count_nb_lst(index) > 1)
	{
		while (index->next->next)
			index = index->next;
		tmp = *index;
		ft_swap_lst_content(index, tmp);
	}
	if (s == 1)
	{
		lst == lst_a ? ft_add_op_lst(info->op_lst, "sa\n") :
			ft_add_op_lst(info->op_lst, "sb\n");
	}
	ft_prev_def(lst);
}

void		ft_rotate_up(t_nb_lst *lst, t_nb_lst *lst_a,
		int s, t_sort_info *info)
{
	t_nb_lst	tmp1;
	t_nb_lst	tmp2;
	t_nb_lst	*index;

	index = lst;
	if (ft_count_nb_lst(lst) > 1)
	{
		tmp1 = *lst;
		index = index->next;
		while (index)
		{
			tmp2 = tmp1;
			tmp1 = *index;
			ft_rotate_lst_content(index, tmp2);
			index = index->next;
		}
		ft_rotate_lst_content(lst, tmp1);
	}
	index = 0;
	if (s == 1)
	{
		lst == lst_a ? ft_add_op_lst(info->op_lst, "ra\n") :
			ft_add_op_lst(info->op_lst, "rb\n");
	}
	ft_prev_def(lst);
}

void		ft_rotate_down(t_nb_lst *lst, t_nb_lst *lst_a,
		int s, t_sort_info *info)
{
	t_nb_lst	tmp1;
	t_nb_lst	tmp2;
	t_nb_lst	*index;

	index = ft_last(lst);
	if (ft_count_nb_lst(lst) > 1)
	{
		tmp1 = *index;
		index = index->prev;
		while (index)
		{
			tmp2 = tmp1;
			tmp1 = *index;
			ft_rotate_lst_content(index, tmp2);
			index = index->prev;
		}
		ft_rotate_lst_content(ft_last(lst), tmp1);
	}
	index = 0;
	if (s == 1)
	{
		lst == lst_a ? ft_add_op_lst(info->op_lst, "rra\n") :
			ft_add_op_lst(info->op_lst, "rrb\n");
	}
	ft_prev_def(lst);
}

void		ft_push_1_to_2(t_nb_lst **lst_1_ptr, t_nb_lst **lst_2_ptr,
		int s, t_sort_info *info)
{
	t_nb_lst	*lst_1;
	t_nb_lst	*lst_2;
	int			flag;

	lst_1 = *lst_1_ptr;
	lst_2 = *lst_2_ptr;
	flag = 0;
	if (lst_1)
	{
		if (lst_1->next)
			flag = 1;
		while (lst_1->next)
			lst_1 = lst_1->next;
		if (lst_2 == 0)
			*(lst_2_ptr) = lst_1;
		else
		{
			while (lst_2->next)
				lst_2 = lst_2->next;
			lst_2->next = lst_1;
		}
		ft_push_bis(flag, s, lst_2_ptr, info);
	}
}
