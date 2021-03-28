/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 22:24:37 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/03/28 18:15:26 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void	swap_st(t_stack **st)
{
	t_stack	*first;
	t_stack	*second;

	first = *st;
	second = first->next;
	first->prev = second;
	first->next = second->next;
	second->prev = NULL;
	second->next = first;
	*st = second;
}

int			swap(t_stack **st1, t_stack **st2)
{
	if (st1 && *st1 && (*st1)->next)
		swap_st(st1);
	if (st2 && *st2 && (*st2)->next)
		swap_st(st2);
	return (VALID);
}
