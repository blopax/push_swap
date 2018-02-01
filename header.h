/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclement <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 14:42:45 by pclement          #+#    #+#             */
/*   Updated: 2018/02/01 19:53:24 by pclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include <stdlib.h>
# include <unistd.h>
# include "get_next_line.h"
# include "libft/libft.h"
# define LSTA info->lst_a
# define LSTB info->lst_b
# define OP op_lst->op
# define OPN op_lst->next->op
# define OPNN op_lst->next->next->op

typedef struct		s_lst
{
	char			*op;
	struct s_lst	*next;
	struct s_lst	*prev;
}					t_lst;

typedef struct		s_nb_lst
{
	int				nb;
	int				index;
	int				pivot;
	int				max;
	int				min;
	int				sort;
	struct s_nb_lst	*next;
	struct s_nb_lst	*prev;
}					t_nb_lst;

typedef struct		s_sort_info
{
	t_lst			*op_lst;
	t_nb_lst		*lst_a;
	t_nb_lst		*lst_b;
	t_nb_lst		*first;
	int				first_size;
	int				first_size_swap_lim;
	t_nb_lst		*lst_0;
	t_nb_lst		*lst_1;
	t_nb_lst		*inf_a;
	t_nb_lst		*inf_b;
	t_nb_lst		*sup_a;
	t_nb_lst		*sup_b;
	int				count_lst_a;
	int				count_lst_b;
	int				show_list;
	int				count_op;
	int				show_pivot;
	int				last_op_red;
	int				pivot_count;
	char			lst_to_sort;
	int				flag;
}					t_sort_info;

void				ft_get_arg(char *arg, t_sort_info *info);
int					ft_check_option(char **argv, int *lim, t_sort_info *info);
int					ft_check_option_checker(char **argv, int *lim,
					t_sort_info *info);
t_sort_info			*ft_init_info_struct(void);
void				ft_free_all(t_sort_info *info);
void				ft_safe_free_lst_op(t_lst *op_lst);
void				ft_add_op_lst(t_lst *lst, char *op);
void				ft_opti_op_lst(t_lst *op_lst);
void				ft_opti_op_lst_2(t_lst *op_lst);
void				ft_replace(t_lst *op_lst, char *op);
void				ft_push_bis(int flag, int s, t_nb_lst **lst,
					t_sort_info *info);
void				ft_push_1_to_2(t_nb_lst **lst_1_ptr,
					t_nb_lst **lst_2_ptr, int write_flag, t_sort_info *info);
void				ft_rotate_down(t_nb_lst *lst, t_nb_lst *lst_a,
					int write_flag, t_sort_info *info);
void				ft_rotate_up(t_nb_lst *lst, t_nb_lst *lst_a,
					int write_flag, t_sort_info *info);
void				ft_swap(t_nb_lst *lst, t_nb_lst *lst_a,
					int write_flag, t_sort_info *info);
void				ft_rotate_lst_content(t_nb_lst *lst, t_nb_lst tmp);
void				ft_swap_lst_content(t_nb_lst *lst, t_nb_lst tmp);
void				ft_do_op(t_sort_info *info);
void				ft_do_op2(t_sort_info *info);
int					ft_sort(t_nb_lst *lst_a, t_nb_lst *lst_b,
					t_sort_info *info);
char				*ft_safe_free(char *str);
void				ft_reset_sort_status(t_nb_lst *lst);
void				ft_define_sort_a(t_nb_lst *lst);
void				ft_define_sort_b(t_nb_lst *lst);
void				ft_define_min_max(t_nb_lst *lst);
int					ft_is_sorted(t_nb_lst *lst, t_nb_lst *lst_a);
int					ft_nb_lst(t_nb_lst *lst);
void				ft_prev_def(t_nb_lst *lst);
int					ft_middle(int a, int b, int c);
t_nb_lst			*ft_last(t_nb_lst *first);
void				ft_rotate_up_i(t_nb_lst *lst,
					t_nb_lst *lst_a, int rotate_nb);
void				ft_rotate_down_i(t_nb_lst *lst,
					t_nb_lst *lst_a, int rotate_nb);
int					ft_count_nb_lst(t_nb_lst *lst);
int					ft_max(int a, int b);
int					ft_min(int a, int b);
void				ft_quicksort(t_sort_info *info);
void				ft_swap_if_a(t_nb_lst *lst, t_nb_lst *lst_a,
					t_sort_info *info);
void				ft_swap_if_b(t_nb_lst *lst, t_nb_lst *lst_a,
					t_sort_info *info);
void				ft_swap_if_b_first_piv(t_nb_lst *lst,
					t_nb_lst *lst_a, t_sort_info *info);
int					*ft_sort_tab(int *tab, int size);
void				ft_set_index(t_nb_lst *lst);
int					ft_get_med_pos(t_nb_lst *lst);
int					ft_find_med(t_nb_lst *lst);
void				ft_redefine(t_sort_info *info);
void				ft_show_lst_a(t_nb_lst *lst, int c);
void				ft_show_lst_b(t_nb_lst *lst, int c);
void				ft_show_lst_op(t_lst *lst);
void				ft_show_lst_op_c(t_lst *lst);
void				ft_sort_index(t_sort_info *info);
int					ft_sort_small(t_sort_info *info);
int					ft_check_true_sort(t_nb_lst *tmp,
					t_nb_lst *lst, t_nb_lst *lst_a);
t_nb_lst			*get_last_sorted_elem(t_nb_lst *lst, t_nb_lst *lst_a);
int					ft_check_true_sort_b(t_nb_lst *lst);
int					ft_check_true_sort_a(t_nb_lst *lst);
void				ft_push_pivot_bis_b(t_sort_info *info,
					int piv_val, int rotate);
void				ft_push_pivot_bis_a(t_sort_info *info,
					int piv_val, int rotate);
int					ft_check_piv_val_b(t_nb_lst *lst, int piv_val);
int					ft_check_piv_val_a(t_nb_lst *lst, int piv_val);
int					ft_is_sorted_bis(t_nb_lst *lst, char ref,
					t_sort_info *info);
void				ft_set_sort_status_bis(t_nb_lst *lst, char ref);
void				ft_push_pivot(t_sort_info *info, int pivot_val);
void				ft_put_pivot_flag_on_list(t_nb_lst *lst, int pivot_val);
int					ft_rec_sort(t_sort_info *info);
void				ft_add_nb_lst(t_nb_lst *lst, int nb);
int					ft_count_nb_lst_op(t_lst *lst);
t_lst				*ft_init_lst_op();
t_nb_lst			*ft_init_lst_nb();
void				ft_swap_check(t_sort_info *info, int piv_val);
void				ft_redefine_lst_0_1(t_sort_info *info);
void				ft_fill_pivot_lst(t_nb_lst *lst, int piv_val);
int					ft_check_piv_val(t_nb_lst *lst, int piv_val, char c);
void				ft_rotate_back(t_sort_info *info, int piv,
					int count_0, int count_1);
void				ft_usage(char *str);
void				ft_error(void);
int					ft_check_double(t_nb_lst *lst);
int					ft_check_value(int *tab, int size);
int					ft_atoi_ps(const char *str);

#endif
