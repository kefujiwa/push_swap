/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 02:27:56 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/04/03 19:23:50 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

/*
** SELF-MADE HEADER FILES
*/
# include "utils.h"

/*
** MACRO DECLARATION - GNI FLAG
*/
# define NORMAL 0
# define FREE 1

/*
** PROTOTYPE DECLARATION
*/
int		get_next_instruction(char **line, int flag);
int		is_option(char *str);
void	output_result(t_stack *a, t_stack *b, int flag);
int		parse_option(int *flag, char **argv);
int		perform_instruction(t_stack *a, t_stack *b, int flag);

#endif
