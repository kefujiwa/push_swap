/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 20:59:41 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/03/29 17:37:03 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	build_stack(t_stack *a, t_stack *b, char **argv)
{
	intptr_t	content;

	if (!is_valid_args(argv))
		return (INVALID);
	a->first = NULL;
	while (*argv)
	{
		content = (intptr_t)ft_atoi(*argv);
		ft_dlstadd_back(&(a->first), ft_dlstnew((void *)content));
		argv++;
	}
	a->last = ft_dlstlast(a->first);
	a->size = ft_dlstsize(a->first);
	a->first->prev = a->last;
	a->last->next = a->first;
	a->partition = NULL;
	b->first = NULL;
	b->last = NULL;
	b->size = 0;
	b->partition = NULL;
	return (VALID);
}
