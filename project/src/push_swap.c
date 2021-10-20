/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjki <seongjk@student.42seoul.k>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 20:36:33 by seongjki          #+#    #+#             */
/*   Updated: 2021/10/20 15:02:41 by seongjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	show_stack(t_lst *a, t_lst *b)
{
	t_lst	*a_lst;
	t_lst	*b_lst;

	a_lst = a;
	b_lst = b;
	printf("a: ");
	while (a_lst)
	{
		printf("%d ", a_lst->value);
		a_lst = a_lst->next;
	}
	printf("\nb: ");
	while (b_lst)
	{
		printf("%d ", b_lst->value);
		b_lst = b_lst->next;
	}
	printf("\n");
}

static void	add_split_nbr(t_lst **a, char *str)
{
	char	**arr;
	int		nbr;
	char	**tmp;

	nbr = 0;
	arr = ft_split(str, ' ');
	tmp = arr;
	while (*tmp)
	{
		nbr = ft_atoi(*tmp);
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
	rotate_a(&a);
	push_b(&a, &b);
	show_stack(a, b);
	//system("leaks push_swap");
}
