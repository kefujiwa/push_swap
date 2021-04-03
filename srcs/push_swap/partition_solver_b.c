/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition_solver_b.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 17:14:29 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/04/03 14:33:14 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	partition_solver_b(t_stack *a, t_stack *b, int flag)
{
	t_solver	s;
	t_dlist		*next;

	s.size = (int)b->partition->content;
	if (s.size > 2 && !is_sorted(b, get_partition_end(b), DESC))
	{
		s.median = get_median(b, s.size);
		if (s.size % 2 == 1)
			s.total = s.size / 2;
		else
			s.total = s.size / 2 - 1;
		create_partition(b, a, &s, flag | BFLAG);
	}
	else
	{
		if ((int)b->first->content < (int)b->first->next->content)
			display_instruction(a, b, "sb", flag);
		while (s.size--)
			display_instruction(a, b, "pa", flag);
		next = b->partition->next;
		ft_dlstdelone(b->partition, NULL);
		b->partition = next;
	}
}
