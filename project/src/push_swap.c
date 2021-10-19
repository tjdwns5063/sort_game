/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjki <seongjk@student.42seoul.k>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 20:36:33 by seongjki          #+#    #+#             */
/*   Updated: 2021/10/19 20:49:35 by seongjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_lst	*a;
	t_lst	*b;

	if (ac < 2)
		exit(0);
	a = 0;
	b = 0;
	int idx = 1;
	while (idx < ac)
		ps_add_right(&a, ft_atoi(av[idx++]));
	t_lst	*tmp;
	tmp = a;
	while (tmp)
	{
		printf("%d\n", tmp->value);
		tmp = tmp->next;
	}
	ps_pop_left(&a);
}
