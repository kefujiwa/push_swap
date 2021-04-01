/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 17:06:37 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/04/01 16:08:03 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	is_sorted(t_stack *st, t_dlist *last, int flag)
{
	t_dlist	*head;

	head = st->first;
	if (!last)
		last = st->last;
	while (head != last)
	{
		if (flag & ASC && (int)head->content > (int)head->next->content)
			return (INVALID);
		if (flag & DESC && (int)head->content < (int)head->next->content)
			return (INVALID);
		head = head->next;
	}
	return (VALID);
}
