/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 01:56:00 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/04/07 01:21:21 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void	put_black_white_err(void)
{
	ft_putendl_fd(" _______   ________  ________  ________  ________"
			, STDERR_FILENO);
	ft_putendl_fd("|\\  ___ \\ |\\   __  \\|\\   __  \\|\\   __  \\|\\   __  \\"
			, STDERR_FILENO);
	ft_putstr_fd("\\ \\   __/|\\ \\  \\|\\  \\ \\  \\|\\  \\ \\  \\|\\  \\ \\  "
			, STDERR_FILENO);
	ft_putendl_fd("\\|\\  \\", STDERR_FILENO);
	ft_putstr_fd(" \\ \\  \\_|/_\\ \\   _  _\\ \\   _  _\\ \\  \\\\\\  \\ \\   "
			, STDERR_FILENO);
	ft_putendl_fd("_  _\\", STDERR_FILENO);
	ft_putstr_fd("  \\ \\  \\_|\\ \\ \\  \\\\  \\\\ \\  \\\\  \\\\ \\  \\\\\\  "
			, STDERR_FILENO);
	ft_putendl_fd("\\ \\  \\\\  \\|", STDERR_FILENO);
	ft_putstr_fd("   \\ \\_______\\ \\__\\\\ _\\\\ \\__\\\\ _\\\\ \\_______\\ "
			, STDERR_FILENO);
	ft_putendl_fd("\\__\\\\ _\\", STDERR_FILENO);
	ft_putstr_fd("    \\|_______|\\|__|\\|__|\\|__|\\|__|\\|_______|"
			, STDERR_FILENO);
	ft_putendl_fd("\\|__|\\|__|", STDERR_FILENO);
}

static void	put_colored_err(void)
{
	ft_putendl_fd(YELLOW" _______   ________  ________  ________  ________"
			, STDERR_FILENO);
	ft_putendl_fd("|\\  ___ \\ |\\   __  \\|\\   __  \\|\\   __  \\|\\   __  \\"
			, STDERR_FILENO);
	ft_putstr_fd("\\ \\   __/|\\ \\  \\|\\  \\ \\  \\|\\  \\ \\  \\|\\  \\ \\  "
			, STDERR_FILENO);
	ft_putendl_fd("\\|\\  \\", STDERR_FILENO);
	ft_putstr_fd(" \\ \\  \\_|/_\\ \\   _  _\\ \\   _  _\\ \\  \\\\\\  \\ \\   "
			, STDERR_FILENO);
	ft_putendl_fd("_  _\\", STDERR_FILENO);
	ft_putstr_fd("  \\ \\  \\_|\\ \\ \\  \\\\  \\\\ \\  \\\\  \\\\ \\  \\\\\\  "
			, STDERR_FILENO);
	ft_putendl_fd("\\ \\  \\\\  \\|", STDERR_FILENO);
	ft_putstr_fd("   \\ \\_______\\ \\__\\\\ _\\\\ \\__\\\\ _\\\\ \\_______\\ "
			, STDERR_FILENO);
	ft_putendl_fd("\\__\\\\ _\\", STDERR_FILENO);
	ft_putstr_fd("    \\|_______|\\|__|\\|__|\\|__|\\|__|\\|_______|"
			, STDERR_FILENO);
	ft_putendl_fd("\\|__|\\|__|"RESET, STDERR_FILENO);
}

void		exit_error(t_stack *a, t_stack *b, int flag)
{
	if (flag & ART && flag & CFLAG)
		put_colored_err();
	else if (flag & ART)
		put_black_white_err();
	else if (flag & CFLAG)
		ft_putendl_fd(YELLOW"Error"RESET, STDERR_FILENO);
	else
		ft_putendl_fd("Error", STDERR_FILENO);
	stack_clear(a);
	stack_clear(b);
	exit(EXIT_FAILURE);
}
