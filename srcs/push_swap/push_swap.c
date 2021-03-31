/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 23:57:28 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/03/31 17:26:59 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_u3(t_stack *a)
{
	while (a->size == 3 && !((int)a->first->content < (int)a->last->content
	&& (int)a->first->next->content < (int)a->last->content))
	{
		if ((int)a->first->next->content < (int)a->first->content
		&& (int)a->last->content < (int)a->first->content)
			rotate(a, NULL, AFLAG);
		if ((int)a->first->content < (int)a->first->next->content
		&& (int)a->last->content < (int)a->first->next->content)
			reverse_rotate(a, NULL, AFLAG);
	}
	if ((int)a->first->content > (int)a->first->next->content)
		swap(a, NULL, AFLAG);
}

static void	push_swap(t_stack *a, t_stack *b)
{
	if (is_sorted(a, a->last, ASC))
		return ;
	if (a->size <= 3)
		sort_u3(a);
	else
	{
		if (!is_sorted(a, a->last, ASC))
		{
			solve_a(a, b);
			solve_b(a, b);
		}
		while (!is_sorted(a, a->last, ASC) || b->first)
		{
			if (a->size > 3)
				solve_a(a, b);
			else
				sort_u3(a);
			solve_b(a, b);
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
