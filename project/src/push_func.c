/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjki <seongjk@student.42seoul.k>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 13:45:34 by seongjki          #+#    #+#             */
/*   Updated: 2021/10/27 16:18:31 by seongjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	push_func(t_lst **from, t_lst **to)
{
	t_lst	*from_lst;
	t_lst	*to_lst;
	int		top;

	if (!*from)
		return (0);
	from_lst = *from;
	to_lst = *to;
	top = ps_pop_left(from);
	ps_add_left(to, top);
	return (1);
}

int	push_a(t_lst **b, t_lst **a)
{
	if (!push_func(b, a))
		return (0);
	ft_putstr_fd("pa\n", 1);
	return (1);
}

int	push_b(t_lst **a, t_lst **b)
{
	if (!push_func(a, b))
		return (0);
	ft_putstr_fd("pb\n", 1);
	return (1);
}
