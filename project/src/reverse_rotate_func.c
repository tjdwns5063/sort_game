/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_func.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjki <seongjk@student.42seoul.k>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 13:56:17 by seongjki          #+#    #+#             */
/*   Updated: 2021/10/28 13:24:46 by seongjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	reverse_rotate_func(t_lst **lst)
{
	t_lst	*ptr;
	int		tmp_value;
	int		tmp_idx;
	char	*tmp_binary;

	ptr = *lst;
	if (!ptr)
		return (0);
	while (ptr->next)
		ptr = ptr->next;
	while (ptr->prev)
	{
		tmp_value = ptr->value;
		tmp_idx = ptr->idx;
		tmp_binary = ptr->binary;
		ptr->value = ptr->prev->value;
		ptr->idx = ptr->prev->idx;
		ptr->binary = ptr->prev->binary;
		ptr->prev->value = tmp_value;
		ptr->prev->idx = tmp_idx;
		ptr->prev->binary = tmp_binary;
		ptr = ptr->prev;
	}
	return (1);
}

int	reverse_rotate_a(t_lst **a)
{
	if (!reverse_rotate_func(a))
		return (1);
	ft_putstr_fd("rra\n", 1);
	return (1);
}

int	reverse_rotate_b(t_lst **b)
{
	if (!reverse_rotate_func(b))
		return (1);
	ft_putstr_fd("rrb\n", 1);
	return (1);
}

int	reverse_rotate_together(t_lst **a, t_lst **b)
{
	reverse_rotate_func(a);
	reverse_rotate_func(b);
	ft_putstr_fd("rrr\n", 1);
	return (1);
}
