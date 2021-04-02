/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_colored.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 16:26:05 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/04/02 20:01:41 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	check_if_first(char *line, int flag)
{
	if (flag & AFLAG && !ft_strcmp(line, "sa"))
		return (BEFORE);
	else if (flag & BFLAG && !ft_strcmp(line, "sb"))
		return (BEFORE);
	else if (flag & (AFLAG | BFLAG) && !ft_strcmp(line, "ss"))
		return (BEFORE);
	else if ((flag & AFLAG && !ft_strcmp(line, "pb"))
			|| (flag & BFLAG && !ft_strcmp(line, "pa")))
		return (BEFORE);
	else if ((flag & AFLAG && !ft_strcmp(line, "pa"))
			|| (flag & BFLAG && !ft_strcmp(line, "pb")))
		return (AFTER);
	else if (flag & AFLAG && !ft_strcmp(line, "ra"))
		return (BEFORE);
	else if (flag & BFLAG && !ft_strcmp(line, "rb"))
		return (BEFORE);
	else if (flag & (AFLAG | BFLAG) && !ft_strcmp(line, "rr"))
		return (BEFORE);
	else if (flag & AFLAG && !ft_strcmp(line, "rra"))
		return (BEFORE);
	else if (flag & BFLAG && !ft_strcmp(line, "rrb"))
		return (BEFORE);
	else if (flag & (AFLAG | BFLAG) && !ft_strcmp(line, "rrr"))
		return (BEFORE);
	return (NONE);
}

static int	check_if_second(char *line, int flag)
{
	if (flag & AFLAG && !ft_strcmp(line, "sa"))
		return (AFTER);
	else if (flag & BFLAG && !ft_strcmp(line, "sb"))
		return (AFTER);
	else if (flag & (AFLAG | BFLAG) && !ft_strcmp(line, "ss"))
		return (AFTER);
	else if (flag & AFLAG && !ft_strcmp(line, "rra"))
		return (AFTER);
	else if (flag & BFLAG && !ft_strcmp(line, "rrb"))
		return (AFTER);
	else if (flag & (AFLAG | BFLAG) && !ft_strcmp(line, "rrr"))
		return (AFTER);
	return (NONE);
}

static int	check_if_last(char *line, int flag)
{
	if (flag & AFLAG && !ft_strcmp(line, "ra"))
		return (AFTER);
	else if (flag & BFLAG && !ft_strcmp(line, "rb"))
		return (AFTER);
	else if (flag & (AFLAG | BFLAG) && !ft_strcmp(line, "rr"))
		return (AFTER);
	return (NONE);
}

int			is_colored(t_stack *st, int row, char *line, int flag)
{
	if (!(flag & CFLAG))
		return (NONE);
	if (!line && flag & AFLAG && row == 1)
		return (BEFORE);
	else if (!line)
		return (NONE);
	if (row == 1)
		return (check_if_first(line, flag));
	else if (row == 2)
		return (check_if_second(line, flag));
	else if (row == st->size)
		return (check_if_last(line, flag));
	return (NONE);
}
