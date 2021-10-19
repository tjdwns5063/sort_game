/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjki <seongjk@student.42seoul.k>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 17:12:13 by seongjki          #+#    #+#             */
/*   Updated: 2021/10/19 20:49:34 by seongjki         ###   ########.fr       */
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

#endif
