/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjki <seongjk@student.42seoul.k>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 20:36:33 by seongjki          #+#    #+#             */
/*   Updated: 2021/10/20 18:25:58 by seongjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	show_stack(t_lst *a, t_lst *b)
{
	t_lst	*a_lst;
	t_lst	*b_lst;
	char	*tmp;

	a_lst = a;
	b_lst = b;
	write(1, "a: ", 4);
	while (a_lst)
	{
		tmp = ft_itoa(a_lst->value);
		write(1, tmp, ft_strlen(tmp));
		write(1, " ", 2);
		free(tmp);
		a_lst = a_lst->next;
	}
	write(1, "\nb: ", 5);
	while (b_lst)
	{
		tmp = ft_itoa(b_lst->value);
		write(1, tmp, ft_strlen(tmp));
		write(1, " ", 2);
		free(tmp);
		b_lst = b_lst->next;
	}
	write(1, "\n", 2);
}

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
	push_b(&a, &b);
	show_stack(a, b);
	//system("leaks push_swap");
}
