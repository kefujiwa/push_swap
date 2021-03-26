/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 14:26:27 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/03/27 00:53:12 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	draw_instructions(void)
{
	ft_putstr_fd(ESC"[2;26H""---instructions---", 1);
	ft_putstr_fd(ESC"[3;26H""> sa : swap a", 1);
	ft_putstr_fd(ESC"[4;26H""> sb : swap b", 1);
	ft_putstr_fd(ESC"[5;26H""> ss : sa + sb", 1);
	ft_putstr_fd(ESC"[6;26H""> pa : push a", 1);
	ft_putstr_fd(ESC"[7;26H""> pb : push b", 1);
	ft_putstr_fd(ESC"[8;26H""> ra : rotate a", 1);
	ft_putstr_fd(ESC"[9;26H""> rb : rotate b", 1);
	ft_putstr_fd(ESC"[10;26H""> rb : ra + rb", 1);
	ft_putstr_fd(ESC"[11;26H""> rra: reverse rotate a", 1);
	ft_putstr_fd(ESC"[12;26H""> rrb: reverse rotate b", 1);
	ft_putstr_fd(ESC"[13;26H""> rrr: rra + rrb", 1);
	ft_putstr_fd(ESC"[15;26H""> EOF => Ctrl + D\n", 1);
}

static void	draw_header(int cnt, char *line)
{
	ft_putstr_fd(ESC"[1;1H", STDERR_FILENO);
	if (line)
	{
		ft_putstr_fd(line, STDERR_FILENO);
		ft_putstr_fd("  ", STDERR_FILENO);
	}
	ft_putnbr_fd(cnt, STDERR_FILENO);
	ft_putstr_fd(ESC"[2;1H-----A-----o-----B-----", STDERR_FILENO);
}

static void	draw_lst(t_list *a, t_list *b)
{
	int	len;

	ft_putstr_fd(ESC"[3;1H", STDERR_FILENO);
	while (a && a->content)
	{
		len = ft_strlen((char *)a->content);
		while (10 - len++)
			ft_putstr_fd(RIGHT, STDERR_FILENO);
		ft_putstr_fd(RIGHT, STDERR_FILENO);
		ft_putstr_fd((char *)a->content, STDERR_FILENO);
		ft_putchar_fd('|', STDERR_FILENO);
		ft_putstr_fd(CRLF, STDERR_FILENO);
		a = a->next;
	}
	ft_putstr_fd(ESC"[3;1H", STDERR_FILENO);
	while (b && b->content)
	{
		ft_putstr_fd(ESC"[11C", STDERR_FILENO);
		ft_putchar_fd('|', STDERR_FILENO);
		ft_putstr_fd((char *)b->content, STDERR_FILENO);
		ft_putstr_fd(CRLF, STDERR_FILENO);
		b = b->next;
	}
}

static void	draw_footer(t_list *a, t_list *b)
{
	int	row;
	int	i;

	if (ft_lstsize(a) > ft_lstsize(b))
		row = ft_lstsize(a);
	else
		row = ft_lstsize(b);
	ft_putstr_fd(ESC"[3;1H", STDERR_FILENO);
	i = 0;
	while (i++ < row)
		ft_putstr_fd(DOWN, STDERR_FILENO);
	ft_putstr_fd("-----------o-----------\n\n", STDERR_FILENO);
	if (row + 3 <= 15)
		ft_putstr_fd(ESC"[17;1H", STDERR_FILENO);
}

void		draw_process(t_list *a, t_list *b, char *line)
{
	static int	cnt = -1;

	cnt++;
	ft_putstr_fd(CLEAR, STDERR_FILENO);
	draw_instructions();
	draw_header(cnt, line);
	draw_lst(a, b);
	draw_footer(a, b);
}
