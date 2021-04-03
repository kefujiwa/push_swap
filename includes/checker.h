/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 02:27:56 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/04/02 21:40:16 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

/*
** SELF-MADE HEADER FILES
*/
# include "utils.h"

/*
** PROTOTYPE DECLARATION
*/
void	output_result(t_stack *a, t_stack *b, int flag);
int		perform_instruction(t_stack *a, t_stack *b, int flag);

#endif
