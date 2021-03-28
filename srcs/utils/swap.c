/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 22:24:37 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/03/29 04:06:16 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void	swap_multi(t_stack *st)
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

static void	swap_pair(t_stack *st)
{
	t_dlist	*tmp;

	tmp = st->first;
	st->first = st->last;
	st->last = tmp;
}

int			swap(t_stack *st1, t_stack *st2, int flag)
{
	if (st1 && st1->size == 2)
		swap_pair(st1);
	else if (st1 && st1->size > 2)
		swap_multi(st1);
	if (st2 && st2->size == 2)
		swap_pair(st2);
	else if (st2 && st2->size > 2)
		swap_multi(st2);
	if (flag == AFLAG)
		ft_putendl_fd("sa", STDOUT_FILENO);
	else if (flag == BFLAG)
		ft_putendl_fd("sb", STDOUT_FILENO);
	else if (flag == (AFLAG | BFLAG))
		ft_putendl_fd("ss", STDOUT_FILENO);
	return (VALID);
}
