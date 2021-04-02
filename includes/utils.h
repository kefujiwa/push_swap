/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 02:26:23 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/04/02 19:44:34 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

/*
** SELF-MADE HEADER FILES
*/
# include "libft.h"

/*
** EXTERNAL LIBRARIES
*/
# include <limits.h>
# include <stdint.h>
# include <stdlib.h>

/*
** MACRO DECLARATION - RETURN VALUE
*/
# define INVALID 0x0
# define VALID 0x1

/*
** MACRO DECLARATION - INSTRUCTION TYPE
*/
# define NONE 0x0
# define AFLAG 0x2
# define BFLAG 0x4

/*
** MACRO DECLARATION - SORT ORDER
*/
# define ASC 0x8
# define DESC 0x10

/*
** MACRO DECLARATION - OPTION
*/
# define VFLAG 0x20
# define CFLAG 0x40

/*
** MACRO DECLARATION - DISPLAY PROCESS
*/
# define BEFORE 0x80
# define AFTER 0x100

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
# define BLUE    "\x1b[34m"
# define BRED    "\x1b[41m"
# define BGREEN  "\x1b[42m"
# define BYELLOW "\x1b[43m"
# define BBLUE   "\x1b[44m"

/*
** STRUCTURE
*/
typedef struct	s_stack
{
	t_dlist	*first;
	t_dlist	*last;
	int		size;
	t_dlist	*partition;
}				t_stack;

/*
** PROTOTYPE DECLARATION
*/
int				build_stack(t_stack *a, t_stack *b, char **argv);
void			exit_error(t_stack *a, t_stack *b);
int				is_colored(t_stack *st, int row, char *line, int flag);
int				is_sorted(t_stack *st, t_dlist *last, int flag);
int				is_valid_args(char **argv);
int				push(t_stack *dst, t_stack *src, int flag);
int				reverse_rotate(t_stack *st1, t_stack *st2, int flag);
int				rotate(t_stack *st1, t_stack *st2, int flag);
void			stack_clear(t_stack *st);
int				swap(t_stack *st1, t_stack *st2, int flag);

#endif
