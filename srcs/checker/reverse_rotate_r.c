/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_r.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 23:17:24 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/03/27 15:53:59 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	reverse_rotate(t_stack **lst)
{
	t_stack	*last;

	last = ft_dlstlast(*lst);
	last->prev->next = NULL;
	last->prev = NULL;
	ft_dlstadd_front(lst, last);
}

int			reverse_rotate_r(t_stack **lst1, t_stack **lst2)
{
	if (lst1 && *lst1 && (*lst1)->next)
		reverse_rotate(lst1);
	if (lst2 && *lst2 && (*lst2)->next)
		reverse_rotate(lst2);
	return (VALID);
}
