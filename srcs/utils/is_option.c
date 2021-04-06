/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_option.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 18:13:48 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/04/03 15:43:28 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	is_option(char *str)
{
	if (!str)
		return (INVALID);
	if (*str == '-' &&
			(*(str + 1) == 'v' || *(str + 1) == 'c' || *(str + 1) == 'a'))
		return (VALID);
	return (INVALID);
}
