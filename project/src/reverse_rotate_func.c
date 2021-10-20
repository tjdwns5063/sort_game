/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_func.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjki <seongjk@student.42seoul.k>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 13:56:17 by seongjki          #+#    #+#             */
/*   Updated: 2021/10/20 14:15:31 by seongjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	reverse_rotate_func(t_lst **lst)
{
	t_lst	*ptr;
	int		tmp;

	ptr = *lst;
	if (!ptr)
		return (0);
	while (ptr->next)
		ptr = ptr->next;
	while (ptr->prev)
	{
		tmp = ptr->value;
		ptr->value = ptr->prev->value;
		ptr->prev->value = tmp;
		ptr = ptr->prev;
	}
	return (1);
}

int	reverse_rotate_a(t_lst **a)
{
	if (!reverse_rotate_func(a))
		return (1);
	write(1, "rra\n", 5);
	return (1);
}

int	reverse_rotate_b(t_lst **b)
{
	if (!reverse_rotate_func(b))
		return (1);
	write(1, "rrb\n", 5);
	return (1);
}

int reverse_rotate_together(t_lst **a, t_lst **b)
{
	reverse_rotate_func(a);
	reverse_rotate_func(b);
	write(1, "rrr\n", 5);
	return (1);
}
