/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 02:15:52 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/03/28 17:33:24 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	is_integer(char *str)
{
	char	*tmp;
	long	num;

	tmp = str;
	if (*tmp == '-')
		tmp++;
	if (!*tmp)
		return (INVALID);
	while (*tmp)
	{
		if (!ft_isdigit(*tmp))
			return (INVALID);
		tmp++;
	}
	num = ft_atol(str);
	if (num < INT_MIN || num > INT_MAX)
		return (INVALID);
	return (VALID);
}

int	is_valid_args(char **argv)
{
	char	**tmp;

	while (*argv)
	{
		if (!is_integer(*argv))
			return (INVALID);
		tmp = argv + 1;
		while (*tmp)
		{
			if (!ft_strcmp(*argv, *tmp))
				return (INVALID);
			tmp++;
		}
		argv++;
	}
	return (VALID);
}
