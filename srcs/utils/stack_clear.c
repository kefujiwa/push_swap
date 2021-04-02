/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_clear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 21:28:57 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/04/02 15:52:06 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	stack_clear(t_stack *st)
{
	t_dlist	*tmp;

	if (!st || !st->first)
		return ;
	while (st->size--)
	{
		tmp = st->first->next;
		free(st->first);
		st->first = tmp;
	}
}
