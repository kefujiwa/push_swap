/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_solver.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 15:52:14 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/04/03 13:45:51 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	initial_partition(t_stack *a, t_stack *b, t_solver s, int flag)
{
	s.i = 0;
	while (s.i < s.total && (int)a->first->content < s.median)
	{
		display_instruction(a, b, "pb", flag);
		s.i++;
	}
	while (s.i < s.total && (int)a->last->content < s.median)
	{
		display_instruction(a, b, "rra", flag);
		display_instruction(a, b, "pb", flag);
		s.i++;
	}
	while (s.i < s.total)
	{
		s.j = 0;
		while ((int)a->first->content >= s.median && s.j++ < a->size)
			display_instruction(a, b, "ra", flag);
		display_instruction(a, b, "pb", flag);
		s.i++;
	}
	ft_dlstadd_front(&(b->partition), ft_dlstnew((void *)(intptr_t)s.i));
}

void		initial_solver(t_stack *a, t_stack *b, int flag)
{
	t_solver	s;

	while (a->size > 3 && !is_sorted(a, a->last, ASC))
	{
		s.median = get_median(a, a->size);
		s.total = a->size / 2;
		initial_partition(a, b, s, flag);
	}
	sort_u3(a, b, flag);
}
