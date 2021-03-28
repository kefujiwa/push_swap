/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 02:08:30 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/03/28 23:58:27 by kefujiwa         ###   ########.fr       */
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
		return (put_error());
	if (!perform_instruction(&a, &b, flag))
		return (put_error());
	output_result(&a, &b, flag);
	ft_dlstclear(&(a.first), NULL);
	ft_dlstclear(&(b.first), NULL);
	return (EXIT_SUCCESS);
}
