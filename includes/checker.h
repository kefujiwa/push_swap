/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 02:27:56 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/04/02 15:06:52 by kefujiwa         ###   ########.fr       */
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
void	display_process(t_stack *a, t_stack *b, char *line);
int		is_option(char *str);
void	output_result(t_stack *a, t_stack *b, int flag);
int		parse_option(int *flag, char **argv);
int		perform_instruction(t_stack *a, t_stack *b, int flag);

#endif
