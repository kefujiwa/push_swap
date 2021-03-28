/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 02:27:56 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/03/28 23:26:25 by kefujiwa         ###   ########.fr       */
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
void	display_process(t_stack *a, t_stack *b, char *line);
int		is_option(char *str);
void	output_result(t_stack *a, t_stack *b, int flag);
int		parse_option(int *flag, char **argv);
int		perform_instruction(t_stack *a, t_stack *b, int flag);

#endif
