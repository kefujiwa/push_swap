/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 23:57:28 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/04/03 19:30:31 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_swap(t_stack *a, t_stack *b, int flag)
{
	if (is_sorted(a, a->last, ASC))
		return ;
	if (a->size <= 3)
		sort_u3(a, b, flag);
	else
	{
		if (!is_sorted(a, a->last, ASC))
			initial_solver(a, b, flag);
		while (!is_sorted(a, a->last, ASC) || b->first)
		{
			if (a->partition)
				partition_solver_a(a, b, flag);
			if (b->partition)
				partition_solver_b(a, b, flag);
		}
	}
}

int			main(int argc, char **argv)
{
	int		flag;
	t_stack	a;
	t_stack	b;

	if (argc == 1)
		return (EXIT_SUCCESS);
	if (!parse_option(&flag, ++argv))
		return (EXIT_FAILURE);
	while (argv && is_option(*argv))
		argv++;
	if (!*argv)
		return (EXIT_SUCCESS);
	if (!build_stack(&a, &b, argv))
		exit_error(NULL, NULL, flag);
	push_swap(&a, &b, flag);
	stack_clear(&a);
	stack_clear(&b);
	return (EXIT_SUCCESS);
}
