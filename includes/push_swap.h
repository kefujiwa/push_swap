/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 02:24:15 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/03/30 20:56:58 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/*
** SELF-MADE HEADER FILES
*/
# include "utils.h"

/*
** PROTOTYPE DECLARATION
*/
int		get_median(t_stack *st, int size);
t_dlist	*get_partition_end(t_stack *st);
void	solve_a(t_stack *a, t_stack *b);
void	solve_b(t_stack *a, t_stack *b);
void	quick_sort (int *array, int left, int right);

#endif
