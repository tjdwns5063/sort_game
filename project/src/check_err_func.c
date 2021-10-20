/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_err_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjki <seongjk@student.42seoul.k>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 17:20:52 by seongjki          #+#    #+#             */
/*   Updated: 2021/10/20 18:46:00 by seongjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	occur_error(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

void	check_integer_range(long long nbr)
{
	if (nbr < INT_MIN || nbr > INT_MAX)
		occur_error();
}

void	check_equal(t_lst *lst)
{
	t_lst	*curr;
	t_lst	*next;

	curr = lst;
	while (curr)
	{
		next = curr->next;
		while (next)
		{
			if (curr->value == next->value)
				occur_error();
			next = next->next;
		}
		curr = curr->next;
	}
}

void	check_isdigit(char *str)
{
	int	idx;

	if (ft_strncmp("-", str, 2) == 0)
		occur_error();
	idx = 1;
	while (str[idx])
	{
		if (!ft_isdigit(str[idx++]))
			occur_error();
	}
}
