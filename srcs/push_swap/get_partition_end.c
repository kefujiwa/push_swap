/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_partition_end.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 15:52:40 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/03/30 15:53:06 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dlist	*get_partition_end(t_stack *st)
{
	t_dlist	*end;
	int		size;

	end = st->first;
	size = (int)st->partition->content - 1;
	while (size-- > 0)
		end = end->next;
	return (end);
}
