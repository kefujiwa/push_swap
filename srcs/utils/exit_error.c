/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 01:56:00 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/04/06 15:57:03 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void	put_black_white_err(void)
{
	ft_putendl_fd("███████╗██████╗ ██████╗  ██████╗ ██████╗ ", STDERR_FILENO);
	ft_putendl_fd("██╔════╝██╔══██╗██╔══██╗██╔═══██╗██╔══██╗", STDERR_FILENO);
	ft_putendl_fd("█████╗  ██████╔╝██████╔╝██║   ██║██████╔╝", STDERR_FILENO);
	ft_putendl_fd("██╔══╝  ██╔══██╗██╔══██╗██║   ██║██╔══██╗", STDERR_FILENO);
	ft_putendl_fd("███████╗██║  ██║██║  ██║╚██████╔╝██║  ██║", STDERR_FILENO);
	ft_putendl_fd("╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝ ╚═════╝ ╚═╝  ╚═╝", STDERR_FILENO);
}

static void	put_colored_err(void)
{
	ft_putendl_fd(YELLOW"███████╗██████╗ ██████╗  ██████╗ ██████╗ "RESET,
			STDERR_FILENO);
	ft_putendl_fd(YELLOW"██╔════╝██╔══██╗██╔══██╗██╔═══██╗██╔══██╗"RESET,
			STDERR_FILENO);
	ft_putendl_fd(YELLOW"█████╗  ██████╔╝██████╔╝██║   ██║██████╔╝"RESET,
			STDERR_FILENO);
	ft_putendl_fd(YELLOW"██╔══╝  ██╔══██╗██╔══██╗██║   ██║██╔══██╗"RESET,
			STDERR_FILENO);
	ft_putendl_fd(YELLOW"███████╗██║  ██║██║  ██║╚██████╔╝██║  ██║"RESET,
			STDERR_FILENO);
	ft_putendl_fd(YELLOW"╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝ ╚═════╝ ╚═╝  ╚═╝"RESET,
			STDERR_FILENO);
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
