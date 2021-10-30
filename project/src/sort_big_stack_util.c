/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack_util.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjki <seongjk@student.42seoul.k>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 11:42:46 by seongjki          #+#    #+#             */
/*   Updated: 2021/10/30 13:31:08 by seongjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_idx(t_lst *lst)
{
	t_lst	*ptr1;
	t_lst	*ptr2;
	int		cnt;

	ptr1 = lst;
	while (ptr1)
	{
		ptr2 = lst;
		cnt = ps_lstsize(lst) - 1;
		while (ptr2)
		{
			if (ptr1->value < ptr2->value)
				cnt--;
			ptr2 = ptr2->next;
		}
		ptr1->idx = cnt;
		ptr1 = ptr1->next;
	}
}

void	set_binary(t_lst *lst)
{
	t_lst	*ptr;

	ptr = lst;
	while (ptr)
	{
		ptr->binary = ft_convert_base(ptr->idx, "01");
		ptr = ptr->next;
	}
}

static int	check_last_bit_is_one(char *binary, unsigned int cnt)
{
	if (ft_strlen(binary) >= cnt && \
		 binary[ft_strlen(binary) - cnt] == '1')
		return (1);
	return (0);
}

void	check_top_and_move_iter(int size, unsigned int cnt, \
								t_lst **a, t_lst **b)
{
	char	*binary;

	while (size--)
	{
		binary = (*a)->binary;
		if (check_last_bit_is_one(binary, cnt))
			rotate_a(a);
		else
			push_b(a, b);
	}
	while (*b)
		push_a(b, a);
}
