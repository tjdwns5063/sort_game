/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjki <seongjk@student.42seoul.k>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 18:46:25 by seongjki          #+#    #+#             */
/*   Updated: 2021/10/28 15:58:49 by seongjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sort(t_lst *lst, int cnt)
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

void	sort_small_stack(t_lst **a, t_lst **b)
{
	int	cnt;

	cnt = ps_lstsize(*a);
	if (cnt == 2)
		sort_two_item(a);
	else if (cnt == 3)
		sort_three_item(a);
	else if (cnt == 4)
		sort_four_item(a, b);
	else if (cnt == 5)
		sort_five_item(a, b);
}

void	sort_lst(t_lst **a, t_lst **b)
{
	int	cnt;

	cnt = ps_lstsize(*a);
	while (is_sort(*a, cnt) != 1)
	{
		if (cnt <= 5)
			sort_small_stack(a, b);
		else
			sort_big_stack(a, b);
	}
	show_together(*a, *b);
}
