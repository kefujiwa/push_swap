/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 01:56:00 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/04/02 15:16:16 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	exit_error(t_stack *a, t_stack *b)
{
	ft_putendl_fd("Error", 2);
	stack_clear(a);
	stack_clear(b);
	exit(EXIT_FAILURE);
}
