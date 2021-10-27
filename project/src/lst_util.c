/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjki <seongjk@student.42seoul.k>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 17:46:05 by seongjki          #+#    #+#             */
/*   Updated: 2021/10/27 14:25:10 by seongjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_lst	*ps_lstnew(int value)
{
	t_lst	*ptr;

	ptr = (t_lst *)malloc(sizeof(t_lst));
	if (!ptr)
		return (0);
	ptr->value = value;
	ptr->next = 0;
	ptr->prev = 0;
	return (ptr);
}

void	ps_add_right(t_lst **lst, int value)
{
	t_lst	*head;
	t_lst	*new;

	head = *lst;
	new = ps_lstnew(value);
	if (!new)
		return ;
	if (!head)
	{
		*lst = new;
		return ;
	}
	while (head->next)
		head = head->next;
	head->next = new;
	new->prev = head;
}

void	ps_add_left(t_lst **lst, int value)
{
	t_lst	*head;
	t_lst	*new;

	head = *lst;
	new = ps_lstnew(value);
	if (!new)
		return ;
	if (!head)
	{
		*lst = new;
		return ;
	}
	new->next = head;
	head->prev = new;
	*lst = new;
}

int	ps_pop(t_lst **lst)
{
	t_lst	*curr;
	t_lst	*prev;
	int		ret;

	curr = *lst;
	if (!curr)
		return (0);
	while (curr->next)
		curr = curr->next;
	prev = curr->prev;
	prev->next = 0;
	ret = curr->value;
	free(curr);
	return (ret);
}

int	ps_pop_left(t_lst **lst)
{
	t_lst	*curr;
	t_lst	*next;
	int		ret;

	curr = *lst;
	if (!curr->next)
	{
		ret = curr->value;
		free(curr);
		*lst = 0;
		return (ret);
	}
	next = curr->next;
	ret = curr->value;
	next->prev = 0;
	free(curr);
	*lst = next;
	return (ret);
}
