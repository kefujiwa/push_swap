/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 22:51:45 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/03/25 22:55:34 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	push(t_list **dst, t_list **src)
{
	t_list	*tmp;

	if (!src || !*src)
		return ;
	tmp = *src;
	*src = tmp->next;
	tmp->next = *dst;
	*dst = tmp;
}
