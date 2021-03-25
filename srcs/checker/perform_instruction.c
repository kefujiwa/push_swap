/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_instruction.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 21:40:18 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/03/25 22:55:49 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	check_instruction(t_list **a, t_list **b, t_list *inst)
{
	if (!ft_strcmp((char *)inst->data, "sa"))
		swap_s(a, NULL);
	else if (!ft_strcmp((char *)inst->data, "sb"))
		swap_s(b, NULL);
	else if (!ft_strcmp((char *)inst->data, "ss"))
		swap_s(a, b);
	else if (!ft_strcmp((char *)inst->data, "pa"))
		push(a, b);
	else if (!ft_strcmp((char *)inst->data, "pb"))
		push(b, a);
	else if (!ft_strcmp((char *)inst->data, "ra"))
		rotate_s(a, NULL);
	else if (!ft_strcmp((char *)inst->data, "rb"))
		rotate_s(a, NULL);
	else if (!ft_strcmp((char *)inst->data, "rr"))
		rotate_s(a, b);
	else if (!ft_strcmp((char *)inst->data, "rra"))
		reverse_rotate_r(a, NULL);
	else if (!ft_strcmp((char *)inst->data, "rrb"))
		reverse_rotate_r(b, NULL);
	else if (!ft_strcmp((char *)inst->data, "rrr"))
		reverse_rotate_r(a, b);
}

void		perform_instruction(t_list **a, t_list **b, t_list *inst)
{
	while (inst)
	{
		check_instruction(a, b, inst);
		inst = inst->next;
	}
}
