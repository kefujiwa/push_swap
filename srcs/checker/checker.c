/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 02:08:30 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/03/28 17:30:58 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int			main(int argc, char **argv)
{
	int		flag;
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (EXIT_SUCCESS);
	if(!parse_option(&flag, ++argv))
		return (EXIT_FAILURE);
	while (argv && *argv && **argv == '-')
		argv++;
	if (!*argv)
		return (EXIT_SUCCESS);
	if (!is_valid_args(argv))
		return (put_error());
	while (*argv)
		ft_dlstadd_back(&a, ft_dlstnew((void *)(intptr_t)ft_atoi(*argv++)));
	if (!perform_instruction(&a, &b, flag))
		return (put_error());
	output_result(a, b, flag);
	ft_dlstclear(&a, NULL);
	ft_dlstclear(&b, NULL);
	return (EXIT_SUCCESS);
}
