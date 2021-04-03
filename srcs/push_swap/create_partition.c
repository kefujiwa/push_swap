/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_partition.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 16:17:16 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/04/03 14:38:09 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	display_inst(t_stack *x, t_stack *y, char *line, int flag)
{
	if (flag & AFLAG && !ft_strcmp(line, "p"))
		display_instruction(x, y, "pb", flag);
	else if (flag & BFLAG && !ft_strcmp(line, "p"))
		display_instruction(y, x, "pa", flag);
	else if (flag & AFLAG && !ft_strcmp(line, "r"))
		display_instruction(x, y, "ra", flag);
	else if (flag & BFLAG && !ft_strcmp(line, "r"))
		display_instruction(y, x, "rb", flag);
	else if (flag & AFLAG && !ft_strcmp(line, "rr"))
		display_instruction(x, y, "rra", flag);
	else if (flag & BFLAG && !ft_strcmp(line, "rr"))
		display_instruction(y, x, "rrb", flag);
}

static int	is_target(t_stack *x, t_solver *s, int flag)
{
	if (flag & AFLAG)
		return ((int)x->first->content < s->median);
	else if (flag & BFLAG)
		return ((int)x->first->content > s->median);
	return (INVALID);
}

void		create_partition(t_stack *x, t_stack *y, t_solver *s, int flag)
{
	s->i = 0;
	while (s->i < s->total && is_target(x, s, flag))
	{
		display_inst(x, y, "p", flag);
		s->size--;
		s->i++;
	}
	s->j = 0;
	while (s->i < s->total)
	{
		while (!is_target(x, s, flag) && s->j < s->size)
		{
			display_inst(x, y, "r", flag);
			s->j++;
		}
		display_inst(x, y, "p", flag);
		s->size--;
		s->i++;
	}
	while (s->size != x->size && s->j--)
		display_inst(x, y, "rr", flag);
	x->partition->content = (void *)(intptr_t)s->size;
	ft_dlstadd_front(&(y->partition), ft_dlstnew((void *)(intptr_t)s->i));
}
