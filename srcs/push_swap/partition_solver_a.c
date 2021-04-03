/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition_solver_a.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 17:17:01 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/04/03 13:49:52 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	partition_solver_a(t_stack *a, t_stack *b, int flag)
{
	t_solver	s;
	t_dlist		*next;

	s.size = (int)a->partition->content;
	while (s.size > 2 && !is_sorted(a, get_partition_end(a), ASC))
	{
		s.median = get_median(a, s.size);
		s.total = s.size / 2;
		create_partition(a, b, &s, flag | AFLAG);
	}
	if ((int)a->first->content > (int)a->first->next->content)
		display_instruction(a, b, "sa", flag);
	next = a->partition->next;
	ft_dlstdelone(a->partition, NULL);
	a->partition = next;
}
