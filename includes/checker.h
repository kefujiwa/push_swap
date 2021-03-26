/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 02:27:56 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/03/27 00:54:45 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

/*
** SELF-MADE HEADER FILES
*/
# include "utils.h"

/*
** MACRO DECLARATION - BIT MASK FLAG
*/
# define VFLAG 0x01
# define CFLAG 0x02

/*
** MACRO DECLARATION - ESCAPE SEQUENCE
*/
# define ESC     "\x1b"
# define CLEAR   "\x1b[2J"
# define UP      "\x1b[1A"
# define DOWN    "\x1b[1B"
# define RIGHT   "\x1b[1C"
# define LEFT    "\x1b[1D"
# define CRLF    "\x1b[1E"
# define RESET   "\x1b[0m"
# define BOLD    "\x1b[1m"
# define RED     "\x1b[31m"
# define GREEN   "\x1b[32m"
# define YELLOW  "\x1b[33m"
# define BRED    "\x1b[41m"
# define BGREEN  "\x1b[42m"
# define BYELLOW "\x1b[43m"

/*
** PROTOTYPE DECLARATION
*/
void	check_result(t_list **a, t_list **b, int flag);
void	draw_process(t_list *a, t_list *b, char *line);
int		parse_option(int *flag, char **argv);
int		perform_instruction(t_list **a, t_list **b, int flag);
int		push(t_list **dst, t_list **src);
int		reverse_rotate_r(t_list **lst1, t_list **lst2);
int		rotate_s(t_list **lst1, t_list **lst2);
int		swap_s(t_list **lst1, t_list **lst2);

#endif
