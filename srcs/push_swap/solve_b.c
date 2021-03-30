/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 15:53:59 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/03/31 02:23:06 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	partition_solver(t_stack *a, t_stack *b)
{
	int	median;
	int	total;
	int	i;
	int	j;
	int	size;

	size = (int)b->partition->content;
	if (size > 2 && !is_sorted(b, get_partition_end(b), DESC))
	{
		median = get_median(b, size);
		if (size % 2 == 1)
			total = size / 2;
		else
			total = size / 2 - 1;
		i = 0;
		j = 0;
		while (i < total && (int)b->first->content > median)
		{
			push(a, b, AFLAG);
			size--;
			i++;
		}
		while (i < total)
		{
			while ((int)b->first->content <= median && j < size)
			{
				rotate(b, NULL, BFLAG);
				j++;
			}
			push(a, b, AFLAG);
			size--;
			i++;
		}
		while (j--)
			reverse_rotate(b, NULL, BFLAG);
		b->partition->content = (void *)(intptr_t)size;
		ft_dlstadd_front(&(a->partition), ft_dlstnew((void *)(intptr_t)i));
	}
	else
	{
		if (size == 2 && (int)b->first->content < (int)b->first->next->content)
			swap(b, NULL, BFLAG);
		while (size--)
			push(a, b, AFLAG);
		b->partition = b->partition->next;
		if (b->partition)
			ft_dlstdelone(b->partition->prev, NULL);
	}
}

void		solve_b(t_stack *a, t_stack *b)
{
	if (b->partition)
		partition_solver(a, b);
}
