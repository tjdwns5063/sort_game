/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjki <seongjk@student.42seoul.k>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 17:12:13 by seongjki          #+#    #+#             */
/*   Updated: 2021/10/20 15:02:39 by seongjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_lst
{
	int				value;
	struct s_lst	*prev;
	struct s_lst	*next;
}				t_lst;

void	ps_add_right(t_lst **lst, int value);
void	ps_add_left(t_lst **lst, int value);
int		ps_pop(t_lst **lst);
int		ps_pop_left(t_lst **lst);

int	swap_a(t_lst **a);
int	swap_b(t_lst **b);
int	swap_together(t_lst **a, t_lst **b);
int	push_a(t_lst **a, t_lst **b);
int	push_b(t_lst **a, t_lst **b);
int	rotate_a(t_lst **a);
int	rotate_b(t_lst **b);
int	rotate_together(t_lst **a, t_lst **b);
int	reverse_rotate_a(t_lst **a);
int	reverse_rotate_b(t_lst **b);
int	reverse_rotate_together(t_lst **a, t_lst **b);

#endif
