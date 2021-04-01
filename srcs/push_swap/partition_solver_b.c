/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition_solver_b.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 17:14:29 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/04/01 18:07:03 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	partition_solver_b(t_stack *a, t_stack *b)
{
	t_partition	p;
	t_dlist		*next;

	p.size = (int)b->partition->content;
	if (p.size > 2 && !is_sorted(b, get_partition_end(b), DESC))
	{
		p.median = get_median(b, p.size);
		if (p.size % 2 == 1)
			p.total = p.size / 2;
		else
			p.total = p.size / 2 - 1;
		create_partition(b, a, &p, BFLAG);
	}
	else
	{
		if ((int)b->first->content < (int)b->first->next->content)
			swap(b, NULL, BFLAG);
		while (p.size--)
			push(a, b, BFLAG);
		next = b->partition->next;
		ft_dlstdelone(b->partition, NULL);
		b->partition = next;
	}
}
