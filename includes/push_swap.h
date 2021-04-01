/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 02:24:15 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/04/01 18:12:40 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/*
** SELF-MADE HEADER FILES
*/
# include "utils.h"

/*
** STRUCTURE
*/
typedef struct	s_partition
{
	int	size;
	int	median;
	int	total;
	int	i;
	int	j;
}				t_partition;

/*
** PROTOTYPE DECLARATION
*/
void			create_partition(t_stack *x, t_stack *y,
									t_partition *p, int flag);
int				get_median(t_stack *st, int size);
t_dlist			*get_partition_end(t_stack *st);
void			initial_solver(t_stack *a, t_stack *b);
void			partition_solver_a(t_stack *a, t_stack *b);
void			partition_solver_b(t_stack *a, t_stack *b);
void			sort_u3(t_stack *a);
void			quick_sort (int *array, int left, int right);

#endif
