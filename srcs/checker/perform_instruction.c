/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_instruction.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 21:40:18 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/03/26 00:05:18 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	check_instruction(t_list **a, t_list **b, t_list *inst)
{
	if (!ft_strcmp((char *)inst->content, "sa"))
		swap_s(a, NULL);
	else if (!ft_strcmp((char *)inst->content, "sb"))
		swap_s(b, NULL);
	else if (!ft_strcmp((char *)inst->content, "ss"))
		swap_s(a, b);
	else if (!ft_strcmp((char *)inst->content, "pa"))
		push(a, b);
	else if (!ft_strcmp((char *)inst->content, "pb"))
		push(b, a);
	else if (!ft_strcmp((char *)inst->content, "ra"))
		rotate_s(a, NULL);
	else if (!ft_strcmp((char *)inst->content, "rb"))
		rotate_s(a, NULL);
	else if (!ft_strcmp((char *)inst->content, "rr"))
		rotate_s(a, b);
	else if (!ft_strcmp((char *)inst->content, "rra"))
		reverse_rotate_r(a, NULL);
	else if (!ft_strcmp((char *)inst->content, "rrb"))
		reverse_rotate_r(b, NULL);
	else if (!ft_strcmp((char *)inst->content, "rrr"))
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
