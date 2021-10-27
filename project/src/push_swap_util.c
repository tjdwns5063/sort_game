/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjki <seongjk@student.42seoul.k>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 18:31:31 by seongjki          #+#    #+#             */
/*   Updated: 2021/10/27 20:11:28 by seongjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	show_stack(t_lst *lst, char *lst_name)
{
	t_lst	*ptr;
	char	*tmp;

	ptr = lst;
	write(1, lst_name, ft_strlen(lst_name));
	write(1, " : ", 4);
	while (ptr)
	{
		tmp = ft_itoa(ptr->value);
		write(1, tmp, ft_strlen(tmp));
		write(1, " ", 2);
		free(tmp);
		ptr = ptr->next;
	}
	write(1, "\n", 2);
}

void	show_stack_together(t_lst *a, t_lst *b)
{
	show_stack(a, "a");
	show_stack(b, "b");
}
