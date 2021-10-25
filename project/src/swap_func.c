/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_func1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjki <seongjk@student.42seoul.k>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 11:40:03 by seongjki          #+#    #+#             */
/*   Updated: 2021/10/25 17:37:54 by seongjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	swap_func(t_lst **lst)
{
	t_lst	*ptr;
	int		tmp;

	ptr = *lst;
	if (!ptr || !ptr->next)
		return (0);
	tmp = ptr->value;
	ptr->value = ptr->next->value;
	ptr->next->value = tmp;
	return (1);
}

int	swap_a(t_lst **a)
{
	if (!swap_func(a))
		return (0);
	write(1, "sa\n", 4);
	return (1);
}

int	swap_b(t_lst **b)
{
	if (!swap_func(b))
		return (0);
	write(1, "sb\n", 4);
	return (1);
}


int	swap_together(t_lst **a, t_lst **b)
{
	swap_func(a);
	swap_func(b);
	write(1, "ss\n", 4);
	return (1);
}
