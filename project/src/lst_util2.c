/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_util2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjki <seongjk@student.42seoul.k>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 18:47:40 by seongjki          #+#    #+#             */
/*   Updated: 2021/10/25 20:09:02 by seongjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_lstsize(t_lst *lst)
{
	t_lst	*ptr;
	int		size;

	ptr = lst;
	size = 0;
	while (ptr)
	{
		size++;
		ptr = ptr->next;
	}
	return (size);
}
