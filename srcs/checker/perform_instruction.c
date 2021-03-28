/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_instruction.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 21:40:18 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/03/28 23:59:00 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	check_instruction(t_stack *a, t_stack *b, char *line)
{
	if (!ft_strcmp(line, "sa"))
		return (swap(a, NULL));
	else if (!ft_strcmp(line, "sb"))
		return (swap(b, NULL));
	else if (!ft_strcmp(line, "ss"))
		return (swap(a, b));
	else if (!ft_strcmp(line, "pa"))
		return (push(a, b));
	else if (!ft_strcmp(line, "pb"))
		return (push(b, a));
	else if (!ft_strcmp(line, "ra"))
		return (rotate(a, NULL));
	else if (!ft_strcmp(line, "rb"))
		return (rotate(b, NULL));
	else if (!ft_strcmp(line, "rr"))
		return (rotate(a, b));
	else if (!ft_strcmp(line, "rra"))
		return (reverse_rotate(a, NULL));
	else if (!ft_strcmp(line, "rrb"))
		return (reverse_rotate(b, NULL));
	else if (!ft_strcmp(line, "rrr"))
		return (reverse_rotate(a, b));
	else
		return (INVALID);
}

int			perform_instruction(t_stack *a, t_stack *b, int flag)
{
	char	*line;
	int		ret;

	if (flag & VFLAG)
		display_process(a, b, NULL);
	while ((ret = get_next_line(0, &line)) > 0)
	{
		if (!check_instruction(a, b, line))
			return (INVALID);
		if (flag & VFLAG)
			display_process(a, b, line);
	}
	free(line);
	if (ret == -1)
		return (INVALID);
	return (VALID);
}
