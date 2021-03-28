/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 22:57:36 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/03/29 04:06:01 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void	rotate_st(t_stack *st)
{
	t_dlist	*head;

	head = st->first;
	st->first = head->next;
	st->last = head;
}

int			rotate(t_stack *st1, t_stack *st2, int flag)
{
	if (st1 && st1->size > 1)
		rotate_st(st1);
	if (st2 && st2->size > 1)
		rotate_st(st2);
	if (flag == AFLAG)
		ft_putendl_fd("ra", STDOUT_FILENO);
	else if (flag == BFLAG)
		ft_putendl_fd("rb", STDOUT_FILENO);
	else if (flag == (AFLAG | BFLAG))
		ft_putendl_fd("rr", STDOUT_FILENO);
	return (VALID);
}
