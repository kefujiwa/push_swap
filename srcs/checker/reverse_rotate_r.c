/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_r.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 23:17:24 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/03/26 13:33:26 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	reverse_rotate(t_list **lst)
{
	t_list	*last;
	t_list	*tmp;
	int		size;

	last = ft_lstlast(*lst);
	tmp = *lst;
	size = ft_lstsize(tmp) - 2;
	while (size--)
		tmp = tmp->next;
	tmp->next = NULL;
	ft_lstadd_front(lst, last);
}

void		reverse_rotate_r(t_list **lst1, t_list **lst2)
{
	if (lst1 && *lst1 && (*lst1)->next)
		reverse_rotate(lst1);
	if (lst2 && *lst2 && (*lst2)->next)
		reverse_rotate(lst2);
}
