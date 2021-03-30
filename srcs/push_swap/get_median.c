/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_median.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 17:38:47 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/03/29 20:07:06 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_median(t_stack *st, int size)
{
	t_dlist	*tmp;
	int		array[size];
	int		i;

	tmp = st->first;
	i = 0;
	while (i < size)
	{
		array[i++] = (int)tmp->content;
		tmp = tmp->next;
	}
	quick_sort(array, 0, size - 1);
	return (array[size / 2]);
}
