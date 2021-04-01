/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 23:57:28 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/04/01 18:03:02 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_swap(t_stack *a, t_stack *b)
{
	if (is_sorted(a, a->last, ASC))
		return ;
	if (a->size <= 3)
		sort_u3(a);
	else
	{
		if (!is_sorted(a, a->last, ASC))
			initial_solver(a, b);
		while (!is_sorted(a, a->last, ASC) || b->first)
		{
			if (a->size > 3 && a->partition)
				partition_solver_a(a, b);
			else
				sort_u3(a);
			if (b->partition)
				partition_solver_b(a, b);
		}
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
