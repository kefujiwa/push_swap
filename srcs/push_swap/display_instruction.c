/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_instruction.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 13:45:02 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/04/03 18:42:59 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	display_instruction(t_stack *a, t_stack *b, char *line, int flag)
{
	if (!ft_strcmp(line, "sa"))
		swap(a, NULL, AFLAG);
	else if (!ft_strcmp(line, "sb"))
		swap(b, NULL, BFLAG);
	else if (!ft_strcmp(line, "pa"))
		push(a, b, BFLAG);
	else if (!ft_strcmp(line, "pb"))
		push(b, a, AFLAG);
	else if (!ft_strcmp(line, "ra"))
		rotate(a, NULL, AFLAG);
	else if (!ft_strcmp(line, "rb"))
		rotate(b, NULL, BFLAG);
	else if (!ft_strcmp(line, "rra"))
		reverse_rotate(a, NULL, AFLAG);
	else if (!ft_strcmp(line, "rrb"))
		reverse_rotate(b, NULL, BFLAG);
	if (flag & AFLAG)
		flag ^= AFLAG;
	if (flag & BFLAG)
		flag ^= BFLAG;
	if (flag & VFLAG)
		display_process(a, b, line, flag);
}
