/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_option.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 12:11:08 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/04/03 15:44:45 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	put_illegal(char c)
{
	ft_putstr_fd("checker: illegal option -- ", STDERR_FILENO);
	ft_putchar_fd(c, STDERR_FILENO);
	ft_putchar_fd('\n', STDERR_FILENO);
	ft_putendl_fd("usage: checker [-acv] [integer ...]", STDERR_FILENO);
	return (INVALID);
}

int			parse_option(int *flag, char **argv)
{
	char	*str;

	*flag = 0;
	while (argv && *argv && **argv == '-')
	{
		str = *argv + 1;
		if (ft_isdigit(*str))
			return (VALID);
		while (*str)
		{
			if (*str == 'v')
				*flag |= VFLAG;
			else if (*str == 'c')
				*flag |= CFLAG;
			else if (*str == 'a')
				*flag |= ART;
			else
				return (put_illegal(*str));
			str++;
		}
		argv++;
	}
	return (VALID);
}
