/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjki <seongjk@student.42seoul.k>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 18:46:25 by seongjki          #+#    #+#             */
/*   Updated: 2021/10/26 20:24:02 by seongjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_sort(t_lst *lst, int cnt)
{
	t_lst	*curr;
	t_lst	*next;
	int		size;

	if (!lst)
		return (0);
	size = ps_lstsize(lst);
	if (cnt != size)
		return (0);
	curr = lst;
	while (curr->next)
	{
		next = curr->next;
		if (curr->value > next->value)
			return (0);
		curr = next;
	}
	return (1);
}

int	find_min(t_lst *a)
{
	t_lst	*lst;
	int		min;

	lst = a;
	min = lst->value;
	while (lst)
	{
		if (min > lst->value)
			min = lst->value;
		lst = lst->next;
	}
	return (min);
}

int	get_head_cnt(t_lst *a)
{
	t_lst	*head;
	int		cnt;
	int		min;

	head = a;
	min = find_min(a);
	cnt = 0;
	while (head)
	{
		if (head->value == min)
			break ;
		cnt++;
		head = head->next;
	}
	return (cnt);
}

int	get_tail_cnt(t_lst *a)
{
	t_lst	*tail;
	int		cnt;
	int		min;

	tail = a;
	min = find_min(a);
	cnt = 0;
	while (tail->next)
		tail = tail->next;
	while (tail)
	{
		if (tail->value == min)
			break ;
		cnt++;
		tail = tail->prev;
	}
	return (cnt + 1);
}

void	move_number(t_lst **a, t_lst **b)
{
	int		head_cnt;
	int		tail_cnt;

	if (!*a)
		return ;
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
}

void	sort_lst(t_lst **a, t_lst **b, int cnt)
{
	int	iter;

	iter = cnt;
	if (is_sort(*a, cnt) != 1)
	{
		while (iter-- >= 0)
			move_number(a, b);
	}
	iter = cnt;;
	while (iter-- >= 0)
		push_a(b, a);
	//show_stack_together(*a, *b);
}
