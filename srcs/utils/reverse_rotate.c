/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 23:17:24 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/03/29 18:10:13 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void	reverse_rotate_st(t_stack *st)
{
	st->first = st->first->prev;
	st->last = st->first->prev;
}

int			reverse_rotate(t_stack *st1, t_stack *st2, int flag)
{
	if (st1 && st1->size > 1)
		reverse_rotate_st(st1);
	if (st2 && st2->size > 1)
		reverse_rotate_st(st2);
	if (flag == AFLAG)
		ft_putendl_fd("rra", STDOUT_FILENO);
	else if (flag == BFLAG)
		ft_putendl_fd("rrb", STDOUT_FILENO);
	else if (flag == (AFLAG | BFLAG))
		ft_putendl_fd("rrr", STDOUT_FILENO);
	return (VALID);
}
