/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 22:24:37 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/03/25 22:48:29 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	swap(t_list **lst)
{
	t_list	*first;
	t_list	*second;

	first = *lst1;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*lst = second;
}

void		swap_s(t_list **lst1, t_list **lst2)
{
	if (lst1 && *lst1 && (*lst1)->next)
		swap(lst1);
	if (lst2 && *lst2 && (*lst2)->next)
		swap(lst2);
}
