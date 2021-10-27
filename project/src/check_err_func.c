/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_err_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjki <seongjk@student.42seoul.k>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 17:20:52 by seongjki          #+#    #+#             */
/*   Updated: 2021/10/27 21:11:33 by seongjki         ###   ########.fr       */
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

void	check_equal(char **arr)
{
	int	left;
	int	right;

	left = 0;
	while (*(arr + left))
	{
		right = left + 1;
		while (*(arr + right))
		{
			if (ft_strcmp(*(arr + left), *(arr + right)) == 0)
				occur_error();
			right++;
		}
		left++;
	}
}

void	check_strlen(char *str)
{
	if (ft_strlen(str) > 11)
		occur_error();
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
