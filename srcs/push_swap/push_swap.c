/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 23:57:28 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/03/31 01:29:36 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_swap(t_stack *a, t_stack *b)
{
	if (!is_sorted(a, a->last, ASC))
	{
		solve_a(a, b);
		solve_b(a, b);
	}
	while (!is_sorted(a, a->last, ASC) || b->first)
	{
		solve_a(a, b);
		solve_b(a, b);
	}
}

int			main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc == 1)
		return (EXIT_SUCCESS);
	if (!build_stack(&a, &b, ++argv))
		return (put_error());
	push_swap(&a, &b);
	ft_dlstclear(&(a.first), NULL);
	ft_dlstclear(&(b.first), NULL);
	return (EXIT_SUCCESS);
}
