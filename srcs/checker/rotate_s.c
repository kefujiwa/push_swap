/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 22:57:36 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/03/27 15:54:35 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	rotate(t_stack **lst)
{
	t_stack	*tmp;

	tmp = *lst;
	*lst = tmp->next;
	(*lst)->prev = NULL;
	tmp->next = NULL;
	ft_dlstadd_back(lst, tmp);
}

int			rotate_s(t_stack **lst1, t_stack **lst2)
{
	if (lst1 && *lst1)
		rotate(lst1);
	if (lst2 && *lst2)
		rotate(lst2);
	return (VALID);
}
