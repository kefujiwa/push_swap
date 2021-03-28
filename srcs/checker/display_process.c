/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 14:26:27 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/03/28 23:50:36 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	display_header(int cnt, char *line)
{
	ft_putstr_fd(ESC"[1;1H", STDERR_FILENO);
	if (line)
	{
		ft_putstr_fd("Exec ", STDERR_FILENO);
		ft_putstr_fd(line, STDERR_FILENO);
		ft_putstr_fd(": \n", STDERR_FILENO);
	}
	else
		ft_putstr_fd("Init a and b: \n", STDERR_FILENO);
	ft_putnbr_fd(cnt, STDERR_FILENO);
	ft_putstr_fd(ESC"[3;1H-----A-----o-----B-----", STDERR_FILENO);
}

static void	display_stack_a(t_stack *a)
{
	t_dlist	*head;
	int		len;
	int		i;

	ft_putstr_fd(ESC"[4;1H", STDERR_FILENO);
	head = a->first;
	i = 0;
	while (i++ < a->size)
	{
		len = ft_cnt_digits((int)head->content);
		while (10 - len++)
			ft_putstr_fd(RIGHT, STDERR_FILENO);
		ft_putstr_fd(RIGHT, STDERR_FILENO);
		ft_putnbr_fd((int)head->content, STDERR_FILENO);
		ft_putchar_fd('|', STDERR_FILENO);
		ft_putstr_fd(CRLF, STDERR_FILENO);
		head = head->next;
	}
}

static void	display_stack_b(t_stack *b)
{
	t_dlist	*head;
	int		i;

	ft_putstr_fd(ESC"[4;1H", STDERR_FILENO);
	head = b->first;
	i = 0;
	while (i++ < b->size)
	{
		ft_putstr_fd(ESC"[11C", STDERR_FILENO);
		ft_putchar_fd('|', STDERR_FILENO);
		ft_putnbr_fd((int)head->content, STDERR_FILENO);
		ft_putstr_fd(CRLF, STDERR_FILENO);
		head = head->next;
	}
}

static void	display_footer(t_stack *a, t_stack *b)
{
	int	row;
	int	i;

	row = 4;
	if (a->size > b->size)
		row += a->size;
	else
		row += b->size;
	ft_putstr_fd(ESC"[4;1H", STDERR_FILENO);
	i = 0;
	while (i++ < row)
		ft_putstr_fd(DOWN, STDERR_FILENO);
	ft_putstr_fd("-----------o-----------\n\n", STDERR_FILENO);
	if (row <= 15)
		ft_putstr_fd(ESC"[18;1H", STDERR_FILENO);
}

void		display_process(t_stack *a, t_stack *b, char *line)
{
	static int	cnt = -1;

	cnt++;
	ft_putstr_fd(CLEAR, STDERR_FILENO);
	ft_putstr_fd(ESC"[3;26H""---instructions---", 1);
	ft_putstr_fd(ESC"[4;26H""> sa : swap a", 1);
	ft_putstr_fd(ESC"[5;26H""> sb : swap b", 1);
	ft_putstr_fd(ESC"[6;26H""> ss : sa + sb", 1);
	ft_putstr_fd(ESC"[7;26H""> pa : push a", 1);
	ft_putstr_fd(ESC"[8;26H""> pb : push b", 1);
	ft_putstr_fd(ESC"[9;26H""> ra : rotate a", 1);
	ft_putstr_fd(ESC"[10;26H""> rb : rotate b", 1);
	ft_putstr_fd(ESC"[11;26H""> rb : ra + rb", 1);
	ft_putstr_fd(ESC"[12;26H""> rra: reverse rotate a", 1);
	ft_putstr_fd(ESC"[13;26H""> rrb: reverse rotate b", 1);
	ft_putstr_fd(ESC"[14;26H""> rrr: rra + rrb", 1);
	ft_putstr_fd(ESC"[16;26H""> EOF => Ctrl + D\n", 1);
	display_header(cnt, line);
	display_stack_a(a);
	display_stack_b(b);
	display_footer(a, b);
}
