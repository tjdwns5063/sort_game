/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_func_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjki <seongjk@student.42seoul.k>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 15:42:05 by seongjki          #+#    #+#             */
/*   Updated: 2021/10/27 20:41:18 by seongjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two_item(t_lst **lst)
{
	t_lst	*curr;
	t_lst	*next;

	if (!*lst || !(*lst)->next)
		return ;
	curr = *lst;
	next = curr->next;
	if (curr->value > next->value)
		swap_a(lst);
}

void	sort_three_item(t_lst **lst)
{
	t_lst	*head;
	t_lst	*mid;
	t_lst	*tail;

	if (!*lst)
		return ;
	head = *lst;
	mid = head->next;
	tail = mid->next;
	if (head->value > mid->value)
		swap_a(lst);
	if (tail->value < head->value)
		reverse_rotate_a(lst);
	if (mid->value > tail->value)
	{
		reverse_rotate_a(lst);
		swap_a(lst);
	}
}

void	sort_four_item(t_lst **a, t_lst **b)
{
	t_lst	*head;
	int		min;
	int		head_cnt;
	int		tail_cnt;

	if (!*a)
		return ;
	head = *a;
	min = find_min(*a);
	head_cnt = get_head_cnt(*a);
	tail_cnt = get_tail_cnt(*a);
	if (head_cnt <= tail_cnt)
	{
		while (head_cnt--)
			rotate_a(a);
		push_b(a, b);
	}
	else
	{
		while (tail_cnt--)
			reverse_rotate_a(a);
		push_b(a, b);
	}
	sort_three_item(a);
	push_a(b, a);
}

void	sort_five_item(t_lst **a, t_lst **b)
{
	t_lst	*head;
	int		min;
	int		head_cnt;
	int		tail_cnt;

	if (!*a)
		return ;
	head = *a;
	min = find_min(*a);
	head_cnt = get_head_cnt(*a);
	tail_cnt = get_tail_cnt(*a);
	if (head_cnt <= tail_cnt)
	{
		while (head_cnt--)
			rotate_a(a);
		push_b(a, b);
	}
	else
	{
		while (tail_cnt--)
			reverse_rotate_a(a);
		push_b(a, b);
	}
	sort_four_item(a, b);
	push_a(b, a);
}
