/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 02:15:52 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/03/26 00:08:11 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	within_range(char *str, int is_negative)
{
	unsigned int	num;
	unsigned int	max;
	int				digit;

	num = 0;
	max = INT_MAX;
	digit = 7;
	if (is_negative)
		digit = 8;
	while (*str)
	{
		if (num < max / 10 || (num == max / 10 && *str - '0' <= digit))
			num = num * 10 + (*str = '0');
		else
			return (0);
		str++;
	}
	return (1);
}

static int	is_numeric(char *str)
{
	int		is_negative;
	char	*num;
	int		ret;

	is_negative = 0;
	if (*str == '-')
	{
		is_negative = 1;
		str++;
	}
	if (!*str)
		return (0);
	num = str;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	ret = within_range(num, is_negative);
	return (ret);
}

int	is_valid_args(char **argv)
{
	char	**tmp;

	argv++;
	while (*argv)
	{
		if (!is_numeric(*argv))
			return (0);
		tmp = argv;
		while (*tmp)
		{
			if (!ft_strcmp(*argv, *tmp))
				return (0);
			tmp++;
		}
		argv++;
	}
	return (1);
}
