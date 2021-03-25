/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 02:08:30 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/03/26 00:04:42 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	is_instruction(char *str)
{
	int			i;
	const char	*instructions[] = {
		"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr", "rra", "rrb", "rrr"};

	i = 0;
	while (instructions[i])
	{
		if (str && !ft_strcmp(instructions[i], str))
			return (1);
		i++;
	}
	return (0);
}

static int	init_list(t_list **a, t_list **b, t_list **inst, char **argv)
{
	char		*line;
	int			ret;

	*a = NULL;
	*b = NULL;
	*inst = NULL;
	while (*argv)
		ft_lstadd_back(a, ft_lstnew((void *)(intptr_t)ft_atoi(*argv++)));
	while ((ret = get_next_line(0, &line)) > 0)
	{
		if (!is_instruction(line))
			return (EXIT_FAILURE);
		ft_lstadd_back(inst, ft_lstnew(line));
	}
	if (ret == -1)
		return (EXIT_FAILURE);
	return (0);
}

int			main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	t_list	*inst;

	if (argc == 1)
		return (EXIT_SUCCESS);
	if (!is_valid_args(argv))
		return (put_error());
	if (init_list(&a, &b, &inst, argv) == EXIT_FAILURE)
		return (put_error());
	perform_instruction(&a, &b, inst);
	check_result(&a, &b);
	ft_lstclear(&a, NULL);
	ft_lstclear(&b, NULL);
	ft_lstclear(&inst, free);
	return (EXIT_SUCCESS);
}
