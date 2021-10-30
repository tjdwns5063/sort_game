/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_err_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjki <seongjk@student.42seoul.k>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 17:20:52 by seongjki          #+#    #+#             */
/*   Updated: 2021/10/30 14:38:59 by seongjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	occur_error(t_lst **lst)
{
	ft_putstr_fd("Error\n", 2);
	ps_lstclear(lst);
	exit(0);
}

void	check_integer_range(long long nbr, t_lst **a)
{
	if (nbr < INT_MIN || nbr > INT_MAX)
		occur_error(a);
}

void	check_equal(t_lst **a)
{
	t_lst	*curr;
	t_lst	*next;

	curr = *a;
	while (curr)
	{
		next = curr->next;
		while (next)
		{
			if (curr->value == next->value)
				occur_error(a);
			next = next->next;
		}
		curr = curr->next;
	}
}

void	check_isdigit(char *str, t_lst **a)
{
	int	idx;

	idx = 0;
	if (ft_strncmp("-", str, 2) == 0)
		occur_error(a);
	if (str[idx] == '-')
		idx++;
	while (str[idx])
	{
		if (!ft_isdigit(str[idx++]))
			occur_error(a);
	}
}
