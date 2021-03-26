/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 02:27:56 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/03/26 13:06:15 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

/*
** SELF-MADE HEADER FILES
*/
# include "utils.h"
# include "stdint.h"

/*
** MACRO DECLARATION - BIT MASK FLAG
*/
# define VFLAG 0x01
# define CFLAG 0x02

/*
** PROTOTYPE DECLARATION
*/
void	check_result(t_list **a, t_list **b);
int		parse_option(int *flag, char **argv);
void	perform_instruction(t_list **a, t_list **b, t_list *inst);
void	push(t_list **dst, t_list **src);
void	reverse_rotate_r(t_list **lst1, t_list **lst2);
void	rotate_s(t_list **lst1, t_list **lst2);
void	swap_s(t_list **lst1, t_list **lst2);

#endif
