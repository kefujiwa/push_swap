/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 22:51:45 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/03/29 03:55:03 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void	pop_from(t_stack *src)
{
	if (src->size == 1)
	{
		src->first = NULL;
		src->last = NULL;
	}
	else
	{
		src->first = src->first->next;
		src->first->prev = src->last;
		src->last->next = src->first;
	}
	src->size--;
}

static void	push_to(t_stack *dst, t_dlist *element)
{
	ft_dlstadd_front(&(dst->first), element);
	if (dst->size == 0)
		dst->last = dst->first;
	else
	{
		dst->first->prev = dst->last;
		dst->last->next = dst->first;
	}
	dst->size++;
}

int			push(t_stack *dst, t_stack *src, int flag)
{
	t_dlist	*tmp;

	if (!dst || !src || !src->first)
		return (VALID);
	tmp = src->first;
	pop_from(src);
	push_to(dst, tmp);
	if (flag == AFLAG)
		ft_putendl_fd("pa", STDOUT_FILENO);
	else if (flag == BFLAG)
		ft_putendl_fd("pb", STDOUT_FILENO);
	return (VALID);
}
