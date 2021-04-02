/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_colored.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 16:26:05 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/04/02 20:31:23 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	check_if_a(int row, char *line)
{
	if ((row == 1 || row == 2) && !ft_strcmp(line, "sa"))
		return (VALID);
	else if ((row == 1 || row == 2) && !ft_strcmp(line, "ss"))
		return (VALID);
	else if (row == 1 && !ft_strcmp(line, "pa"))
		return (VALID);
	else if (!ft_strcmp(line, "ra"))
		return (VALID);
	else if (!ft_strcmp(line, "rr"))
		return (VALID);
	else if (!ft_strcmp(line, "rra"))
		return (VALID);
	else if (!ft_strcmp(line, "rrr"))
		return (VALID);
	return (NONE);
}

static int	check_if_b(int row, char *line)
{
	if ((row == 1 || row == 2) && !ft_strcmp(line, "sb"))
		return (VALID);
	else if ((row == 1 || row == 2) && !ft_strcmp(line, "ss"))
		return (VALID);
	else if (row == 1 && !ft_strcmp(line, "pb"))
		return (VALID);
	else if (!ft_strcmp(line, "rb"))
		return (VALID);
	else if (!ft_strcmp(line, "rr"))
		return (VALID);
	else if (!ft_strcmp(line, "rrb"))
		return (VALID);
	else if (!ft_strcmp(line, "rrr"))
		return (VALID);
	return (NONE);
}

int			is_colored(int row, char *line, int flag)
{
	if (!(flag & CFLAG) || !line)
		return (INVALID);
	if (flag & AFLAG)
		return (check_if_a(row, line));
	else if (flag &BFLAG)
		return (check_if_b(row, line));
	return (INVALID);
}
