/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_u3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 15:24:15 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/04/03 13:51:13 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_u3(t_stack *a, t_stack *b, int flag)
{
	while (a->size == 3 && !((int)a->first->content < (int)a->last->content
	&& (int)a->first->next->content < (int)a->last->content))
	{
		if ((int)a->first->next->content < (int)a->first->content
		&& (int)a->last->content < (int)a->first->content)
			display_instruction(a, b, "ra", flag);
		if ((int)a->first->content < (int)a->first->next->content
		&& (int)a->last->content < (int)a->first->next->content)
			display_instruction(a, b, "rra", flag);
	}
	if ((int)a->first->content > (int)a->first->next->content)
		display_instruction(a, b, "sa", flag);
}
