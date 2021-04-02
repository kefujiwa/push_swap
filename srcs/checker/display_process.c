/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 14:26:27 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/04/02 19:48:09 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	display_header(int cnt, char *line, int flag)
{
	ft_putstr_fd(ESC"[1;1H", STDERR_FILENO);
	if (line)
	{
		ft_putstr_fd("Exec ", STDERR_FILENO);
		if (flag & CFLAG)
			ft_putstr_fd(YELLOW, STDERR_FILENO);
		ft_putstr_fd(line, STDERR_FILENO);
		ft_putstr_fd(RESET": \n", STDERR_FILENO);
	}
	else
		ft_putendl_fd("Init a and b: ", STDERR_FILENO);
	ft_putnbr_fd(cnt, STDERR_FILENO);
	ft_putstr_fd(ESC"[3;1H-----A-----o-----B-----", STDERR_FILENO);
}

static void	display_stack_a(t_stack *a, char *line, int flag)
{
	t_dlist	*head;
	int		len;
	int		i;
	int		ret;

	ft_putstr_fd(ESC"[4;1H", STDERR_FILENO);
	head = a->first;
	i = 0;
	while (i++ < a->size)
	{
		len = ft_cnt_digits((int)head->content);
		while (11 - len++ > 0)
			ft_putstr_fd(RIGHT, STDERR_FILENO);
		if ((ret = is_colored(a, i, line, flag | AFLAG)) == BEFORE)
			ft_putstr_fd(YELLOW, STDERR_FILENO);
		else if (ret == AFTER)
			ft_putstr_fd(BBLUE""YELLOW, STDERR_FILENO);
		ft_putnbr_fd((int)head->content, STDERR_FILENO);
		ft_putstr_fd(RESET"|", STDERR_FILENO);
		ft_putstr_fd(CRLF, STDERR_FILENO);
		head = head->next;
	}
}

static void	display_stack_b(t_stack *b, char *line, int flag)
{
	t_dlist	*head;
	int		i;
	int		ret;

	ft_putstr_fd(ESC"[4;1H", STDERR_FILENO);
	head = b->first;
	i = 0;
	while (i++ < b->size)
	{
		ft_putstr_fd(ESC"[11C", STDERR_FILENO);
		ft_putstr_fd("|", STDERR_FILENO);
		if ((ret = is_colored(b, i, line, flag | BFLAG)) == BEFORE)
			ft_putstr_fd(YELLOW, STDERR_FILENO);
		else if (ret == AFTER)
			ft_putstr_fd(BBLUE""YELLOW, STDERR_FILENO);
		ft_putnbr_fd((int)head->content, STDERR_FILENO);
		ft_putstr_fd(RESET, STDERR_FILENO);
		ft_putstr_fd(CRLF, STDERR_FILENO);
		head = head->next;
	}
}

static void	display_footer(t_stack *a, t_stack *b)
{
	int	row;
	int	i;

	row = 0;
	if (a->size > b->size)
		row += a->size;
	else
		row += b->size;
	ft_putstr_fd(ESC"[4;1H", STDERR_FILENO);
	i = 0;
	while (i++ < row)
		ft_putstr_fd(DOWN, STDERR_FILENO);
	ft_putstr_fd("-----------o-----------\n\n", STDERR_FILENO);
	if (row + 4 <= 16)
		ft_putstr_fd(ESC"[18;1H", STDERR_FILENO);
}

void		display_process(t_stack *a, t_stack *b, char *line, int flag)
{
	static int	cnt = -1;

	cnt++;
	ft_putstr_fd(CLEAR, STDERR_FILENO);
	ft_putstr_fd(ESC"[3;26H""---Instructions---", STDERR_FILENO);
	ft_putstr_fd(ESC"[4;26H""> sa : swap a", STDERR_FILENO);
	ft_putstr_fd(ESC"[5;26H""> sb : swap b", STDERR_FILENO);
	ft_putstr_fd(ESC"[6;26H""> ss : sa + sb", STDERR_FILENO);
	ft_putstr_fd(ESC"[7;26H""> pa : push a", STDERR_FILENO);
	ft_putstr_fd(ESC"[8;26H""> pb : push b", STDERR_FILENO);
	ft_putstr_fd(ESC"[9;26H""> ra : rotate a", STDERR_FILENO);
	ft_putstr_fd(ESC"[10;26H""> rb : rotate b", STDERR_FILENO);
	ft_putstr_fd(ESC"[11;26H""> rb : ra + rb", STDERR_FILENO);
	ft_putstr_fd(ESC"[12;26H""> rra: reverse rotate a", STDERR_FILENO);
	ft_putstr_fd(ESC"[13;26H""> rrb: reverse rotate b", STDERR_FILENO);
	ft_putstr_fd(ESC"[14;26H""> rrr: rra + rrb", STDERR_FILENO);
	ft_putstr_fd(ESC"[16;26H""> EOF => Ctrl + D\n", STDERR_FILENO);
	display_header(cnt, line, flag);
	display_stack_a(a, line, flag);
	display_stack_b(b, line, flag);
	display_footer(a, b);
	usleep(150000);
}
