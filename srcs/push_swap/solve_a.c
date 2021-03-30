/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 17:05:35 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/03/31 02:38:14 by kefujiwa         ###   ########.fr       */
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

	size = (int)a->partition->content;
	while (size > 2 && !is_sorted(a, get_partition_end(a), ASC))
	{
		median = get_median(a, size);
		total = size / 2;
		i = 0;
		j = 0;
		while (i < total && (int)a->first->content < median)
		{
			push(b, a, BFLAG);
			size--;
			i++;
		}
		while (i < total)
		{
			while ((int)a->first->content >= median && j < size)
			{
				rotate(a, NULL, AFLAG);
				j++;
			}
			push(b, a, BFLAG);
			size--;
			i++;
		}
		while (j-- > 0)
			reverse_rotate(a, NULL, AFLAG);
		ft_dlstadd_front(&(b->partition), ft_dlstnew((void *)(intptr_t)i));
	}
	if (size == 1)
		return ;
	if ((int)a->first->content > (int)a->first->next->content)
		swap(a, NULL, AFLAG);
	a->partition = a->partition->next;
	if (a->partition)
		ft_dlstdelone(a->partition->prev, NULL);
}

static void	solver(t_stack *a, t_stack *b)
{
	int	median;
	int	total;
	int	i;
	int	j;

	while (a->size > 2 && !is_sorted(a, a->last, ASC))
	{
		median = get_median(a, a->size);
		total = a->size / 2;
		i = 0;
		while (i < total && (int)a->first->content <  median)
		{
			push(b, a, BFLAG);
			i++;
		}
		while (i < total && (int)a->last->content < median)
		{
			reverse_rotate(a, NULL, AFLAG);
			push(b, a, BFLAG);
			i++;
		}
		while (i < total)
		{
			j = 0;
			while ((int)a->first->content >= median && j++ < a->size)
				rotate(a, NULL, AFLAG);
			push(b, a, BFLAG);
			i++;
		}
		ft_dlstadd_front(&(b->partition), ft_dlstnew((void *)(intptr_t)i));
	}
	if (a->size == 1)
		return ;
	if ((int)a->first->content > (int)a->first->next->content)
		swap(a, NULL, AFLAG);
}

void		solve_a(t_stack *a, t_stack *b)
{
	if (!a->partition)
		solver(a, b);
	else
		partition_solver(a, b);
}
