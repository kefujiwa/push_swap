/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition_solver_a.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 17:17:01 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/04/01 18:07:26 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	partition_solver_a(t_stack *a, t_stack *b)
{
	t_partition	p;
	t_dlist		*next;

	p.size = (int)a->partition->content;
	while (p.size > 2 && !is_sorted(a, get_partition_end(a), ASC))
	{
		p.median = get_median(a, p.size);
		p.total = p.size / 2;
		create_partition(a, b, &p, AFLAG);
	}
	if ((int)a->first->content > (int)a->first->next->content)
		swap(a, NULL, AFLAG);
	next = a->partition->next;
	ft_dlstdelone(a->partition, NULL);
	a->partition = next;
}
