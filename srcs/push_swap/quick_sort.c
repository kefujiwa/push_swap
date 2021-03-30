/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 15:40:51 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/03/29 16:58:01 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void quick_sort (int *array, int left, int right)
{
    int	i;
	int	j;
    int	pivot;
	int	tmp;

    i = left;
    j = right;
    pivot = array[(left + right) / 2];
    while (1) {
        while (array[i] < pivot)
            i++;
        while (pivot < array[j])
            j--;
        if (i >= j)
            break;
		tmp = array[i];
		array[i] = array[j];
		array[j] = tmp;
    }
    if (left < i - 1)
        quick_sort(array, left, i - 1);
    if (j + 1 <  right)
        quick_sort(array, j + 1, right);
}
