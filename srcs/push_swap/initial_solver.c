/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_solver.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 15:52:14 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/04/01 18:05:57 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	initial_partitions(t_stack *a, t_stack *b, int median, int total)
{
	int	i;
	int	j;

	i = 0;
	while (i < total && (int)a->first->content < median)
	{
		push(b, a, AFLAG);
		i++;
	}
	while (i < total && (int)a->last->content < median)
	{
		reverse_rotate(a, NULL, AFLAG);
		push(b, a, AFLAG);
		i++;
	}
	while (i < total)
	{
		j = 0;
		while ((int)a->first->content >= median && j++ < a->size)
			rotate(a, NULL, AFLAG);
		push(b, a, AFLAG);
		i++;
	}
	ft_dlstadd_front(&(b->partition), ft_dlstnew((void *)(intptr_t)i));
}

void		initial_solver(t_stack *a, t_stack *b)
{
	t_partition	p;

	while (a->size > 3 && !is_sorted(a, a->last, ASC))
	{
		p.median = get_median(a, a->size);
		p.total = a->size / 2;
		initial_partitions(a, b, p.median, p.total);
	}
	sort_u3(a);
}
