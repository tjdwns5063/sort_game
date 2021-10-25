/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjki <seongjk@student.42seoul.k>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 18:46:25 by seongjki          #+#    #+#             */
/*   Updated: 2021/10/25 20:09:07 by seongjki         ###   ########.fr       */
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

void	swap_and_push(t_lst **from, t_lst **to)
{
	if (!*from || !(*from)->next)
		return ;
	while (*from)
	{
		if ((*from)->next && (*from)->value < (*from)->next->value)
			swap_a(from);
		push_b(from, to);
		push_b(from, to);
	}
}

void	compare_head_with_tail(t_lst **from, t_lst **to)
{
	t_lst	*head;
	t_lst	*tail;

	if (!*from)
		return ;
	swap_b(from);
	for (int i = 0; i < 2; i++)
	{
		if (!*from)
			return ;
		head = *from;
		tail = head;
		while (tail->next)
			tail = tail->next;
		if (head->value < tail->value)
			reverse_rotate_b(from);
		push_a(from, to);
	}
}

void	sort_lst(t_lst **a, t_lst **b, int cnt)
{
	if (is_sort(*a, cnt) != 1)
	{
		swap_and_push(a, b);
		while (is_sort(*a, cnt) == 0)
		{
			compare_head_with_tail(b, a);
		}
	}
	show_stack_together(*a, *b);
}
