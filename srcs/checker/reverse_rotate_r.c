/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_r.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 23:17:24 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/03/25 23:29:12 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	reverse_rotate(t_list **lst)
{
	t_list	tmp;

	tmp = ft_lstlast(*lst);
	ft_lstadd_front(lst, tmp);
}

void		reverse_rotate_r(t_list **lst1, t_list **lst2)
{
	if (lst1 && *lst1)
		reverse_rotate(lst1);
	if (lst2 && *lst2)
		reverse_rotate(lst2);
}
