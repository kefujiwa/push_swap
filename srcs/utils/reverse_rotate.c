/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 23:17:24 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/03/28 23:32:34 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void	reverse_rotate_st(t_stack *st)
{
	t_dlist	*head;

	head = st->first;
	st->first = head->prev;
	st->last = head;
}

int			reverse_rotate(t_stack *st1, t_stack *st2)
{
	if (st1 && st1->size > 1)
		reverse_rotate_st(st1);
	if (st2 && st2->size > 1)
		reverse_rotate_st(st2);
	return (VALID);
}
