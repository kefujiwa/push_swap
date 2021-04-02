/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 02:08:30 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/04/02 15:15:39 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int			main(int argc, char **argv)
{
	int		flag;
	t_stack	a;
	t_stack	b;

	if (argc == 1)
		return (EXIT_SUCCESS);
	if (!parse_option(&flag, ++argv))
		return (EXIT_FAILURE);
	while (argv && is_option(*argv))
		argv++;
	if (!*argv)
		return (EXIT_SUCCESS);
	if (!build_stack(&a, &b, argv))
		exit_error(NULL, NULL);
	if (!perform_instruction(&a, &b, flag))
		exit_error(&a, &b);
	output_result(&a, &b, flag);
	stack_clear(&a);
	stack_clear(&b);
	return (EXIT_SUCCESS);
}
