/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 17:06:37 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/03/28 23:27:17 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	is_sorted(t_stack *a, t_stack *b)
{
	t_dlist	*head;

	head = a->first;
	while (head != a->last)
	{
		if ((int)head->content > (int)head->next->content)
			return (INVALID);
		head = head->next;
	}
	if (b->first)
		return (INVALID);
	return (VALID);
}
