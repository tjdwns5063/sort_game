/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjki <seongjk@student.42seoul.k>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 17:12:13 by seongjki          #+#    #+#             */
/*   Updated: 2021/10/28 15:50:48 by seongjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define INT_MAX 2147483647
# define INT_MIN -2147483648
# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_lst
{
	int				value;
	int				idx;
	char			*binary;
	struct s_lst	*prev;
	struct s_lst	*next;
}				t_lst;

/* this func in lst_util.c*/
void	ps_add_right(t_lst **lst, int value);
void	ps_add_left(t_lst **lst, int value);
int		ps_pop(t_lst **lst);
int		ps_pop_left(t_lst **lst);
/* this func in lst_util2.c*/
int		ps_lstsize(t_lst *lst);
int		find_min(t_lst *lst);
int		find_max(t_lst *lst);
int		get_head_cnt(t_lst *lst);
int		get_tail_cnt(t_lst *lst);
/* this func in swap_func.c*/
int		swap_a(t_lst **a);
int		swap_b(t_lst **b);
int		swap_together(t_lst **a, t_lst **b);
/* this func in push_func.c*/
int		push_a(t_lst **b, t_lst **a);
int		push_b(t_lst **a, t_lst **b);
/*this func in rotate_func.c*/
int		rotate_a(t_lst **a);
int		rotate_b(t_lst **b);
int		rotate_together(t_lst **a, t_lst **b);
/*this func in reverse_rotate.c*/
int		reverse_rotate_a(t_lst **a);
int		reverse_rotate_b(t_lst **b);
int		reverse_rotate_together(t_lst **a, t_lst **b);
/*this func in check_err_func.c*/
void	check_integer_range(long long nbr);
void	check_equal(char **arr);
void	check_isdigit(char *str);
void	check_strlen(char *str);
/*this func in push_swap_util.c*/
void	show_stack(t_lst *lst, char *lst_name);
void	show_together(t_lst *a, t_lst *b);
void	show_idx(t_lst *lst, char *lst_name);
void	show_binary(t_lst *lst, char *lst_name);
/*this func in sort_func.c*/
void	sort_lst(t_lst **a, t_lst **b);
/*this func in sort_small_stack_util.c*/
void	sort_two_item(t_lst **lst);
void	sort_three_item(t_lst **lst);
void	sort_four_item(t_lst **a, t_lst **b);
void	sort_five_item(t_lst **a, t_lst **b);
/*this func in sort_big_stack_util.c*/
void	set_idx(t_lst *lst);
void	set_binary(t_lst *lst);
void	sort_big_stack(t_lst **a, t_lst **b);

#endif
