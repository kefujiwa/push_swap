/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_result.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 23:33:53 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/04/07 01:10:10 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	put_black_white_ko(void)
{
	ft_putendl_fd(" ___  __    ________", STDOUT_FILENO);
	ft_putendl_fd("|\\  \\|\\  \\ |\\   __  \\", STDOUT_FILENO);
	ft_putendl_fd("\\ \\  \\/  /|\\ \\  \\|\\  \\", STDOUT_FILENO);
	ft_putendl_fd(" \\ \\   ___  \\ \\  \\\\\\  \\", STDOUT_FILENO);
	ft_putendl_fd("  \\ \\  \\\\ \\  \\ \\  \\\\\\  \\", STDOUT_FILENO);
	ft_putendl_fd("   \\ \\__\\\\ \\__\\ \\_______\\", STDOUT_FILENO);
	ft_putendl_fd("    \\|__| \\|__|\\|_______|", STDOUT_FILENO);
}

static void	put_colored_ko(void)
{
	ft_putendl_fd(RED" ___  __    ________", STDOUT_FILENO);
	ft_putendl_fd("|\\  \\|\\  \\ |\\   __  \\", STDOUT_FILENO);
	ft_putendl_fd("\\ \\  \\/  /|\\ \\  \\|\\  \\", STDOUT_FILENO);
	ft_putendl_fd(" \\ \\   ___  \\ \\  \\\\\\  \\", STDOUT_FILENO);
	ft_putendl_fd("  \\ \\  \\\\ \\  \\ \\  \\\\\\  \\", STDOUT_FILENO);
	ft_putendl_fd("   \\ \\__\\\\ \\__\\ \\_______\\", STDOUT_FILENO);
	ft_putendl_fd("    \\|__| \\|__|\\|_______|"RESET, STDOUT_FILENO);
}

static void	put_black_white_ok(void)
{
	ft_putendl_fd(" ________  ___  __", STDOUT_FILENO);
	ft_putendl_fd("|\\   __  \\|\\  \\|\\  \\", STDOUT_FILENO);
	ft_putendl_fd("\\ \\  \\|\\  \\ \\  \\/  /|_", STDOUT_FILENO);
	ft_putendl_fd(" \\ \\  \\\\\\  \\ \\   ___  \\", STDOUT_FILENO);
	ft_putendl_fd("  \\ \\  \\\\\\  \\ \\  \\\\ \\  \\", STDOUT_FILENO);
	ft_putendl_fd("   \\ \\_______\\ \\__\\\\ \\__\\", STDOUT_FILENO);
	ft_putendl_fd("    \\|_______|\\|__| \\|__|", STDOUT_FILENO);
}

static void	put_colored_ok(void)
{
	ft_putendl_fd(GREEN" ________  ___  __", STDOUT_FILENO);
	ft_putendl_fd("|\\   __  \\|\\  \\|\\  \\", STDOUT_FILENO);
	ft_putendl_fd("\\ \\  \\|\\  \\ \\  \\/  /|_", STDOUT_FILENO);
	ft_putendl_fd(" \\ \\  \\\\\\  \\ \\   ___  \\", STDOUT_FILENO);
	ft_putendl_fd("  \\ \\  \\\\\\  \\ \\  \\\\ \\  \\", STDOUT_FILENO);
	ft_putendl_fd("   \\ \\_______\\ \\__\\\\ \\__\\", STDOUT_FILENO);
	ft_putendl_fd("    \\|_______|\\|__| \\|__|"RESET, STDOUT_FILENO);
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
