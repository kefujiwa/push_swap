/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 22:51:45 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/03/27 16:13:08 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	push(t_stack **dst, t_stack **src)
{
	t_stack	*tmp;

	if (!src || !*src)
		return (VALID);
	tmp = *src;
	*src = tmp->next;
	if (*src)
		(*src)->prev = NULL;
	ft_dlstadd_front(dst, tmp);
	return (VALID);
}
