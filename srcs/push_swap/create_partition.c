/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_partition.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 16:17:16 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/04/01 18:02:07 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_target(t_stack *x, t_partition *p, int flag)
{
	if (flag & AFLAG)
		return ((int)x->first->content < p->median);
	else if (flag & BFLAG)
		return ((int)x->first->content > p->median);
	return (INVALID);
}

void		create_partition(t_stack *x, t_stack *y, t_partition *p, int flag)
{
	p->i = 0;
	while (p->i < p->total && is_target(x, p, flag))
	{
		push(y, x, flag);
		p->size--;
		p->i++;
	}
	p->j = 0;
	while (p->i < p->total)
	{
		while (!is_target(x, p, flag) && p->j < p->size)
		{
			rotate(x, NULL, flag);
			p->j++;
		}
		push(y, x, flag);
		p->size--;
		p->i++;
	}
	while (p->size != x->size && p->j--)
		reverse_rotate(x, NULL, flag);
	x->partition->content = (void *)(intptr_t)p->size;
	ft_dlstadd_front(&(y->partition), ft_dlstnew((void *)(intptr_t)p->i));
}
