/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_result.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 23:33:53 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/03/28 17:37:59 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	put_ko(int flag)
{
	if (!(flag & CFLAG))
		return (ft_putendl_fd("KO", STDOUT_FILENO));
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

static void	put_ok(int flag)
{
	if (!(flag & CFLAG))
		return (ft_putendl_fd("OK", STDOUT_FILENO));
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

void	output_result(t_stack *a, t_stack *b, int flag)
{
	if (is_sorted(a, b))
		put_ok(flag);
	else
		put_ko(flag);
}
