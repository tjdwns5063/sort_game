/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_func2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjki <seongjk@student.42seoul.k>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 12:21:31 by seongjki          #+#    #+#             */
/*   Updated: 2021/10/27 16:25:23 by seongjki         ###   ########.fr       */
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
	ft_putstr_fd("ra\n", 1);
	return (1);
}

int	rotate_b(t_lst **b)
{
	if (!rotate_func(b))
		return (1);
	ft_putstr_fd("rb\n", 1);
	return (1);
}

int	rotate_together(t_lst **a, t_lst **b)
{
	rotate_func(a);
	rotate_func(b);
	ft_putstr_fd("rr\n", 1);
	return (1);
}
