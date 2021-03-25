/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 23:33:53 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/03/25 23:41:01 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	check_result(t_list **a, t_list **b)
{
	t_list	*lst;

	lst = *a;
	while (lst)
	{
		if ((int)lst->data > (int)lst->next->data)
			return (ft_putendl_fd("KO", 1);
		lst = lst->next;
	}
	if (*b)
		return (ft_putendl_fd("KO", 1));
	ft_putendl_fd("OK", 1);
}
