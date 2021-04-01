/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 22:57:36 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/04/01 16:11:50 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void	rotate_st(t_stack *st)
{
	st->first = st->first->next;
	st->last = st->first->prev;
}

int			rotate(t_stack *st1, t_stack *st2, int flag)
{
	if (st1 && st1->size > 1)
		rotate_st(st1);
	if (st2 && st2->size > 1)
		rotate_st(st2);
	if (flag & AFLAG && flag & BFLAG)
		ft_putendl_fd("rr", STDOUT_FILENO);
	else if (flag & AFLAG)
		ft_putendl_fd("ra", STDOUT_FILENO);
	else if (flag & BFLAG)
		ft_putendl_fd("rb", STDOUT_FILENO);
	return (VALID);
}
