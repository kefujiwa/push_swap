/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_result.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 23:33:53 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/04/03 15:48:25 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	put_black_white_ko(void)
{
	ft_putstr_fd(BWHITE"  "RESET"     "BWHITE"  "RESET" ", STDOUT_FILENO);
	ft_putendl_fd("  "BWHITE"    "RESET, STDOUT_FILENO);
	ft_putstr_fd(BWHITE"  "RESET"    "BWHITE"  "RESET"  ", STDOUT_FILENO);
	ft_putendl_fd(" "BWHITE"  "RESET"   "BWHITE"  "RESET, STDOUT_FILENO);
	ft_putstr_fd(BWHITE"  "RESET"   "BWHITE"  "RESET"   ", STDOUT_FILENO);
	ft_putendl_fd(BWHITE"  "RESET"     "BWHITE" "RESET, STDOUT_FILENO);
	ft_putstr_fd(BWHITE"  "RESET"  "BWHITE"  "RESET"    ", STDOUT_FILENO);
	ft_putendl_fd(BWHITE"  "RESET"     "BWHITE"  "RESET, STDOUT_FILENO);
	ft_putstr_fd(BWHITE"     "RESET"     ", STDOUT_FILENO);
	ft_putendl_fd(BWHITE"  "RESET"     "BWHITE"  "RESET, STDOUT_FILENO);
	ft_putstr_fd(BWHITE"   "RESET" "BWHITE"  "RESET"    ", STDOUT_FILENO);
	ft_putendl_fd(BWHITE"  "RESET"     "BWHITE"  "RESET, STDOUT_FILENO);
	ft_putstr_fd(BWHITE"  "RESET"   "BWHITE"  "RESET"   ", STDOUT_FILENO);
	ft_putendl_fd(BWHITE"  "RESET"     "BWHITE" "RESET, STDOUT_FILENO);
	ft_putstr_fd(BWHITE"  "RESET"    "BWHITE"  "RESET"  ", STDOUT_FILENO);
	ft_putendl_fd(" "BWHITE"  "RESET"   "BWHITE"  "RESET, STDOUT_FILENO);
	ft_putstr_fd(BWHITE"  "RESET"     "BWHITE"  "RESET" ", STDOUT_FILENO);
	ft_putendl_fd("  "BWHITE"    "RESET, STDOUT_FILENO);
}

static void	put_colored_ko(void)
{
	ft_putstr_fd(BRED"  "RESET"     "BRED"  "RESET" ", STDOUT_FILENO);
	ft_putendl_fd("  "BRED"    "RESET, STDOUT_FILENO);
	ft_putstr_fd(BRED"  "RESET"    "BRED"  "RESET"  ", STDOUT_FILENO);
	ft_putendl_fd(" "BRED"  "RESET"   "BRED"  "RESET, STDOUT_FILENO);
	ft_putstr_fd(BRED"  "RESET"   "BRED"  "RESET"   ", STDOUT_FILENO);
	ft_putendl_fd(BRED"  "RESET"     "BRED" "RESET, STDOUT_FILENO);
	ft_putstr_fd(BRED"  "RESET"  "BRED"  "RESET"    ", STDOUT_FILENO);
	ft_putendl_fd(BRED"  "RESET"     "BRED"  "RESET, STDOUT_FILENO);
	ft_putstr_fd(BRED"     "RESET"     ", STDOUT_FILENO);
	ft_putendl_fd(BRED"  "RESET"     "BRED"  "RESET, STDOUT_FILENO);
	ft_putstr_fd(BRED"   "RESET" "BRED"  "RESET"    ", STDOUT_FILENO);
	ft_putendl_fd(BRED"  "RESET"     "BRED"  "RESET, STDOUT_FILENO);
	ft_putstr_fd(BRED"  "RESET"   "BRED"  "RESET"   ", STDOUT_FILENO);
	ft_putendl_fd(BRED"  "RESET"     "BRED" "RESET, STDOUT_FILENO);
	ft_putstr_fd(BRED"  "RESET"    "BRED"  "RESET"  ", STDOUT_FILENO);
	ft_putendl_fd(" "BRED"  "RESET"   "BRED"  "RESET, STDOUT_FILENO);
	ft_putstr_fd(BRED"  "RESET"     "BRED"  "RESET" ", STDOUT_FILENO);
	ft_putendl_fd("  "BRED"    "RESET, STDOUT_FILENO);
}

static void	put_black_white_ok(void)
{
	ft_putstr_fd("  "BWHITE"    "RESET"    ", STDOUT_FILENO);
	ft_putendl_fd(BWHITE"  "RESET"     "BWHITE"  "RESET, STDOUT_FILENO);
	ft_putstr_fd(" "BWHITE"  "RESET"   "BWHITE"  "RESET"  ", STDOUT_FILENO);
	ft_putendl_fd(BWHITE"  "RESET"    "BWHITE"  "RESET, STDOUT_FILENO);
	ft_putstr_fd(BWHITE"  "RESET"     "BWHITE" "RESET"  ", STDOUT_FILENO);
	ft_putendl_fd(BWHITE"  "RESET"   "BWHITE"  "RESET, STDOUT_FILENO);
	ft_putstr_fd(BWHITE"  "RESET"     "BWHITE"  "RESET" ", STDOUT_FILENO);
	ft_putendl_fd(BWHITE"  "RESET"  "BWHITE"  "RESET, STDOUT_FILENO);
	ft_putstr_fd(BWHITE"  "RESET"     "BWHITE"  "RESET" ", STDOUT_FILENO);
	ft_putendl_fd(BWHITE"     "RESET, STDOUT_FILENO);
	ft_putstr_fd(BWHITE"  "RESET"     "BWHITE"  "RESET" ", STDOUT_FILENO);
	ft_putendl_fd(BWHITE"   "RESET" "BWHITE"  "RESET, STDOUT_FILENO);
	ft_putstr_fd(BWHITE"  "RESET"     "BWHITE" "RESET"  ", STDOUT_FILENO);
	ft_putendl_fd(BWHITE"  "RESET"   "BWHITE"  "RESET, STDOUT_FILENO);
	ft_putstr_fd(" "BWHITE"  "RESET"   "BWHITE"  "RESET"  ", STDOUT_FILENO);
	ft_putendl_fd(BWHITE"  "RESET"    "BWHITE"  "RESET, STDOUT_FILENO);
	ft_putstr_fd("  "BWHITE"    "RESET"    ", STDOUT_FILENO);
	ft_putendl_fd(BWHITE"  "RESET"     "BWHITE"  "RESET, STDOUT_FILENO);
}

static void	put_colored_ok(void)
{
	ft_putstr_fd("  "BGREEN"    "RESET"    ", STDOUT_FILENO);
	ft_putendl_fd(BGREEN"  "RESET"     "BGREEN"  "RESET, STDOUT_FILENO);
	ft_putstr_fd(" "BGREEN"  "RESET"   "BGREEN"  "RESET"  ", STDOUT_FILENO);
	ft_putendl_fd(BGREEN"  "RESET"    "BGREEN"  "RESET, STDOUT_FILENO);
	ft_putstr_fd(BGREEN"  "RESET"     "BGREEN" "RESET"  ", STDOUT_FILENO);
	ft_putendl_fd(BGREEN"  "RESET"   "BGREEN"  "RESET, STDOUT_FILENO);
	ft_putstr_fd(BGREEN"  "RESET"     "BGREEN"  "RESET" ", STDOUT_FILENO);
	ft_putendl_fd(BGREEN"  "RESET"  "BGREEN"  "RESET, STDOUT_FILENO);
	ft_putstr_fd(BGREEN"  "RESET"     "BGREEN"  "RESET" ", STDOUT_FILENO);
	ft_putendl_fd(BGREEN"     "RESET, STDOUT_FILENO);
	ft_putstr_fd(BGREEN"  "RESET"     "BGREEN"  "RESET" ", STDOUT_FILENO);
	ft_putendl_fd(BGREEN"   "RESET" "BGREEN"  "RESET, STDOUT_FILENO);
	ft_putstr_fd(BGREEN"  "RESET"     "BGREEN" "RESET"  ", STDOUT_FILENO);
	ft_putendl_fd(BGREEN"  "RESET"   "BGREEN"  "RESET, STDOUT_FILENO);
	ft_putstr_fd(" "BGREEN"  "RESET"   "BGREEN"  "RESET"  ", STDOUT_FILENO);
	ft_putendl_fd(BGREEN"  "RESET"    "BGREEN"  "RESET, STDOUT_FILENO);
	ft_putstr_fd("  "BGREEN"    "RESET"    ", STDOUT_FILENO);
	ft_putendl_fd(BGREEN"  "RESET"     "BGREEN"  "RESET, STDOUT_FILENO);
}

void		output_result(t_stack *a, t_stack *b, int flag)
{
	if (is_sorted(a, a->last, ASC) && !b->first)
	{
		if (flag & CFLAG && flag & ART)
			return (put_colored_ok());
		else if (flag & ART)
			return (put_black_white_ok());
		else if (flag & CFLAG)
			return (ft_putendl_fd(GREEN"OK"RESET, STDOUT_FILENO));
		else
			return (ft_putendl_fd("OK", STDOUT_FILENO));
	}
	else
	{
		if (flag & CFLAG && flag & ART)
			return (put_colored_ko());
		else if (flag & ART)
			return (put_black_white_ko());
		else if (flag & CFLAG)
			return (ft_putendl_fd(RED"KO"RESET, STDOUT_FILENO));
		else
			return (ft_putendl_fd("KO", STDOUT_FILENO));
	}
}
