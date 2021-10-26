/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_func_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjki <seongjk@student.42seoul.k>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 15:42:05 by seongjki          #+#    #+#             */
/*   Updated: 2021/10/26 17:01:47 by seongjki         ###   ########.fr       */
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

	if (!*lst || !(*lst)->next || !(*lst)->next->next)
		return ;
	head = *lst;
	mid = head->next;
	tail = mid->next;
	if (head->value > mid->value)
		sort_two_item(lst);
	if (tail->value < head->value)
		reverse_rotate_a(lst);
	if (mid->value > tail->value)
	{
		reverse_rotate_a(lst);
		swap_a(lst);
	}
}
