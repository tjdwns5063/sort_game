/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjki <seongjk@student.42seoul.k>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 20:36:33 by seongjki          #+#    #+#             */
/*   Updated: 2021/10/26 17:11:12 by seongjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	add_split_nbr(t_lst **a, char *str)
{
	char		**arr;
	long long	nbr;
	char		**tmp;
	int			cnt;

	nbr = 0;
	arr = ft_split(str, ' ');
	tmp = arr;
	cnt = 0;
	while (*tmp)
	{
		check_isdigit(*tmp);
		nbr = ft_atol(*tmp);
		check_integer_range(nbr);
		ps_add_right(a, nbr);
		cnt++;
		free(*tmp);
		tmp++;
	}
	free(arr);
	return (cnt);
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
	int		cnt;

	if (ac < 2)
		exit(0);
	init_lst(&a, &b);
	idx = 1;
	cnt = 0;
	while (idx < ac)
		cnt += add_split_nbr(&a, av[idx++]);
	check_equal(a);
	sort_lst(&a, &b, cnt);
	//system("leaks push_swap | grep 'leaked'");
}
