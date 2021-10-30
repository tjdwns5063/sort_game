/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjki <seongjk@student.42seoul.k>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 20:36:33 by seongjki          #+#    #+#             */
/*   Updated: 2021/10/30 14:38:54 by seongjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	add_split_nbr(t_lst **a, char *str)
{
	char		**arr;
	long long	nbr;
	int			idx;

	nbr = 0;
	arr = ft_split(str, ' ');
	idx = 0;
	while (arr[idx])
	{
		check_isdigit(arr[idx], a);
		nbr = ft_atol(arr[idx]);
		check_integer_range(nbr, a);
		ps_add_right(a, nbr);
		free(arr[idx]);
		idx++;
	}
	check_equal(a);
	free(arr);
	return (0);
}

static void	init_lst(t_lst **a, t_lst **b)
{
	*a = 0;
	*b = 0;
}

int	main(int ac, char **av)
{
	t_lst	*a;
	t_lst	*b;
	int		idx;

	if (ac < 2)
		exit(0);
	init_lst(&a, &b);
	idx = 1;
	while (idx < ac)
		add_split_nbr(&a, av[idx++]);
	set_idx(a);
	set_binary(a);
	sort_lst(&a, &b);
}
