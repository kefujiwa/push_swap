/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 17:06:37 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/03/29 01:13:37 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	is_sorted(t_stack *st)
{
	t_dlist	*head;

	head = st->first;
	while (head != st->last)
	{
		if ((int)head->content > (int)head->next->content)
			return (INVALID);
		head = head->next;
	}
	return (VALID);
}
