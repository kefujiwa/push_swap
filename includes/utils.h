/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 02:26:23 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/03/29 04:02:59 by kefujiwa         ###   ########.fr       */
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
# define VALID 1
# define INVALID 0

/*
** MACRO DECLARATION - INSTRUCTION TYPE
*/
# define NONE 0x0
# define AFLAG 0x1
# define BFLAG 0x2

/*
** STRUCTURE
*/
typedef struct	s_stack
{
	t_dlist	*first;
	t_dlist	*last;
	int		size;
}				t_stack;

/*
** PROTOTYPE DECLARATION
*/
int	build_stack(t_stack *a, t_stack *b, char **argv);
int	is_sorted(t_stack *st);
int	is_valid_args(char **argv);
int	push(t_stack *dst, t_stack *src, int flag);
int	put_error(void);
int	reverse_rotate(t_stack *st1, t_stack *st2, int flag);
int	rotate(t_stack *st1, t_stack *st2, int flag);
int	swap(t_stack *st1, t_stack *st2, int flag);


#endif
