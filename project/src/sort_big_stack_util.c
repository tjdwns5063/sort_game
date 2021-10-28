/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack_util.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjki <seongjk@student.42seoul.k>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 11:42:46 by seongjki          #+#    #+#             */
/*   Updated: 2021/10/28 15:58:22 by seongjki         ###   ########.fr       */
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

void	sort_big_stack(t_lst **a, t_lst **b)
{
	int				size;
	char			*max_bits;
	int				max_bits_len;
	unsigned int	cnt;
	char			*binary;

	max_bits = ft_convert_base(ps_lstsize(*a) - 1, "01");
	max_bits_len = ft_strlen(max_bits);
	cnt = 1;
	while (max_bits_len--)
	{
		size = ps_lstsize(*a);
		while (size--)
		{
			binary = (*a)->binary;
			if (ft_strlen(binary) >= cnt && \
			 binary[ft_strlen(binary) - cnt] == '1')
				rotate_a(a);
			else
				push_b(a, b);
		}
		while (*b)
			push_a(b, a);
		cnt++;
	}
	free(max_bits);
}
