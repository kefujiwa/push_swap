/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 17:06:37 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/03/28 17:14:25 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	is_sorted(t_stack *a, t_stack *b)
{
	while (a && a->next)
	{
		if ((int)a->content > (int)a->next->content)
			return (INVALID);
		a = a->next;
	}
	if (b)
		return (INVALID);
	return (VALID);
}
