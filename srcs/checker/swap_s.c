/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 22:24:37 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/03/27 15:51:43 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	swap(t_stack **lst)
{
	t_stack	*first;
	t_stack	*second;

	first = *lst;
	second = first->next;
	first->prev = second;
	first->next = second->next;
	second->prev = NULL;
	second->next = first;
	*lst = second;
}

int			swap_s(t_stack **lst1, t_stack **lst2)
{
	if (lst1 && *lst1 && (*lst1)->next)
		swap(lst1);
	if (lst2 && *lst2 && (*lst2)->next)
		swap(lst2);
	return (VALID);
}
