/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_util2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjki <seongjk@student.42seoul.k>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 18:47:40 by seongjki          #+#    #+#             */
/*   Updated: 2021/10/30 15:11:35 by seongjki         ###   ########.fr       */
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

int	find_min(t_lst *lst)
{
	t_lst	*ptr;
	int		min;

	ptr = lst;
	min = ptr->value;
	while (ptr)
	{
		if (min > ptr->value)
			min = ptr->value;
		ptr = ptr->next;
	}
	return (min);
}

int	get_head_cnt(t_lst *lst)
{
	t_lst	*head;
	int		cnt;
	int		min;

	head = lst;
	min = find_min(lst);
	cnt = 0;
	while (head)
	{
		if (head->value == min)
			break ;
		cnt++;
		head = head->next;
	}
	return (cnt);
}

int	get_tail_cnt(t_lst *lst)
{
	t_lst	*tail;
	int		cnt;
	int		min;

	tail = lst;
	min = find_min(lst);
	cnt = 0;
	while (tail->next)
		tail = tail->next;
	while (tail)
	{
		if (tail->value == min)
			break ;
		cnt++;
		tail = tail->prev;
	}
	return (cnt + 1);
}

void	ps_lstclear(t_lst **lst)
{
	t_lst	*curr;
	t_lst	*next;

	if (!*lst)
		return ;
	curr = *lst;
	while (curr)
	{
		next = curr->next;
		free(curr->binary);
		free(curr);
		curr = next;
	}
}
