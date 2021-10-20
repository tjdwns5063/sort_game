/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_func2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjki <seongjk@student.42seoul.k>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 12:21:31 by seongjki          #+#    #+#             */
/*   Updated: 2021/10/20 15:02:43 by seongjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	rotate_func(t_lst **lst)
{
	t_lst	*ptr;
	int		tmp;

	ptr = *lst;
	if (!ptr)
		return (0);
	while (ptr->next)
	{
		tmp = ptr->value;
		ptr->value = ptr->next->value;
		ptr->next->value = tmp;
		ptr = ptr->next;
	}
	return (1);
}

int	rotate_a(t_lst **a)
{
	if (!rotate_func(a))
		return (1);
	write(1, "ra\n", 4);
	return (1);
}

int	rotate_b(t_lst **b)
{
	if (!rotate_func(b))
		return (1);
	write(1, "rb\n", 4);
	return (1);
}

int	rotate_together(t_lst **a, t_lst **b)
{
	rotate_func(a);
	rotate_func(b);
	write(1, "rr\n", 4);
	return (1);
}
