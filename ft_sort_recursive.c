#include "header.h"

void	ft_define_inf_sup(t_sort_info *info)
{
	t_nb_lst	*lst;

	info->inf_a = info->lst_a;
	info->sup_a = info->lst_a;
	info->inf_b = info->lst_b;
	info->sup_b = info->lst_b;
	lst = info->lst_a;
	while (lst)
	{
		if (lst->pivot == 1 && !(lst->next == 0))
			info->sup_a = lst->next;
		lst = lst->next;
	}
	lst = info->lst_b;
	while (lst)
	{
		if (lst->pivot == 1
				&& !(lst->next == 0 && ft_is_sorted(info->lst_a, info->lst_a)))
			info->sup_b = lst->next;
		lst = lst->next;
	}
}

void	ft_define_first(t_sort_info *info)
{
	if (ft_is_sorted(info->lst_a, info->lst_a) == 1)
	{
		info->first = info->sup_b;
		info->lst_to_sort = 'b';
	}
	else
	{
		info->first = info->sup_a;
		info->lst_to_sort = 'a';
	}
}

void	ft_fill_info(t_sort_info *info)
{
	ft_define_inf_sup(info);
	ft_define_first(info);
	info->first_size = ft_count_nb_lst(info->first);
}

int		ft_rec_sort(t_sort_info *info)
{
	if (ft_is_sorted(info->lst_a, info->lst_a) && info->lst_b == 0)
		return (1);
	ft_fill_info(info);
	if (info->first_size <= 8 && info->pivot_count == 0)
		ft_sort_small_list(info);
	else
	{
		ft_quicksort(info);
		info->pivot_count++;
	}
	if (info->show_list == 1)
	{
		ft_show_lst_a(info->lst_a, 1);
		ft_show_lst_b(info->lst_b, 1);
	}
	return (ft_rec_sort(info));
}
