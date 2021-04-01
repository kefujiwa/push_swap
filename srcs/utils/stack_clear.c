/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_clear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 21:28:57 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/04/01 21:32:02 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	stack_clear(t_stack *st)
{
	if (!st || !st->first)
		return ;
	while (st->size--)
	{
		free(st->first);
		st->first = st->first->next;
	}
}
