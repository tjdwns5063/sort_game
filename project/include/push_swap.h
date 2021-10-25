/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjki <seongjk@student.42seoul.k>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 17:12:13 by seongjki          #+#    #+#             */
/*   Updated: 2021/10/25 18:49:28 by seongjki         ###   ########.fr       */
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
void	check_equal(t_lst *lst);
void	check_isdigit(char *str);
/*this func in push_swap_util.c*/
void	show_stack(t_lst *lst, char *lst_name);
void	show_stack_together(t_lst *a, t_lst *b);
/*this func in sort_func.c*/
void	sort_lst(t_lst **a, t_lst **b, int cnt);
void	swap_and_push(t_lst **from, t_lst **to);
void	compare_head_with_tail(t_lst **from, t_lst **to);
/*this func in sort_func_util.c*/
void	sort_two_item(t_lst **lst);
void	sort_three_item(t_lst **lst);

#endif
