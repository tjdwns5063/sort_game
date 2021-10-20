/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjki <seongjk@student.42seoul.k>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 20:36:33 by seongjki          #+#    #+#             */
/*   Updated: 2021/10/20 18:38:30 by seongjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	add_split_nbr(t_lst **a, char *str)
{
	char		**arr;
	long long	nbr;
	char		**tmp;

	nbr = 0;
	arr = ft_split(str, ' ');
	tmp = arr;
	while (*tmp)
	{
		check_isdigit(*tmp);
		nbr = ft_atol(*tmp);
		check_integer_range(nbr);
		ps_add_right(a, nbr);
		free(*tmp);
		tmp++;
	}
	free(arr);
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
	check_equal(a);
	show_stack_together(a, b);
	//system("leaks push_swap");
}
