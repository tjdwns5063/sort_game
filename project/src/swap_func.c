/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_func1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjki <seongjk@student.42seoul.k>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 11:40:03 by seongjki          #+#    #+#             */
/*   Updated: 2021/10/28 15:58:31 by seongjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	swap_func(t_lst **lst)
{
	t_lst	*ptr;
	int		tmp_value;
	int		tmp_idx;
	char	*tmp_binary;

	ptr = *lst;
	if (!ptr || !ptr->next)
		return (0);
	tmp_value = ptr->value;
	tmp_idx = ptr->idx;
	tmp_binary = ptr->binary;
	ptr->value = ptr->next->value;
	ptr->idx = ptr->next->idx;
	ptr->binary = ptr->next->binary;
	ptr->next->value = tmp_value;
	ptr->next->idx = tmp_idx;
	ptr->next->binary = tmp_binary;
	return (1);
}

int	swap_a(t_lst **a)
{
	if (!swap_func(a))
		return (0);
	ft_putstr_fd("sa\n", 1);
	return (1);
}

int	swap_b(t_lst **b)
{
	if (!swap_func(b))
		return (0);
	ft_putstr_fd("sb\n", 1);
	return (1);
}

int	swap_together(t_lst **a, t_lst **b)
{
	swap_func(a);
	swap_func(b);
	ft_putstr_fd("ss\n", 1);
	return (1);
}
