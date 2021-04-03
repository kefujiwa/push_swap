/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 02:24:15 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/04/03 15:52:47 by kefujiwa         ###   ########.fr       */
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
typedef struct	s_solver
{
	int	size;
	int	median;
	int	total;
	int	i;
	int	j;
}				t_solver;

/*
** PROTOTYPE DECLARATION
*/
void			create_partition(t_stack *x, t_stack *y,
											t_solver *s, int flag);
void			display_instruction(t_stack *a, t_stack *b,
											char *line, int flag);
int				get_median(t_stack *st, int size);
t_dlist			*get_partition_end(t_stack *st);
void			initial_solver(t_stack *a, t_stack *b, int flag);
int				is_option(char *str);
int				parse_option(int *flag, char **argv);
void			partition_solver_a(t_stack *a, t_stack *b, int flag);
void			partition_solver_b(t_stack *a, t_stack *b, int flag);
void			sort_u3(t_stack *a, t_stack *b, int flag);
void			quick_sort (int *array, int left, int right);

#endif
