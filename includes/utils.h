/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 02:26:23 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/03/28 18:04:14 by kefujiwa         ###   ########.fr       */
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
** TYPEDEF
*/
typedef t_dlist t_stack;

/*
** PROTOTYPE DECLARATION
*/
int	is_sorted(t_stack *a, t_stack *b);
int	is_valid_args(char **argv);
int	push(t_stack **dst, t_stack **src);
int	put_error(void);
int	reverse_rotate(t_stack **lst1, t_stack **lst2);
int	rotate(t_stack **lst1, t_stack **lst2);
int	swap(t_stack **lst1, t_stack **lst2);


#endif
