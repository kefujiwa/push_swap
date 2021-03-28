/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 22:24:37 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/03/28 23:33:00 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void	swap_st(t_stack *st)
{
	t_dlist	*first;
	t_dlist	*second;

	first = st->first;
	second = st->first->next;
	second->next->prev = first;
	first->next = second->next;
	first->prev = second;
	second->next = first;
	second->prev = st->last;
	st->last->next = second;
	st->first = second;
}

int			swap(t_stack *st1, t_stack *st2)
{
	if (st1 && st1->size > 1)
		swap_st(st1);
	if (st2 && st2->size > 1)
		swap_st(st2);
	return (VALID);
}
