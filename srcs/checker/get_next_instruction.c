/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_instruction.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 18:52:16 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/04/03 19:20:40 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	init(char **buf, char **str)
{
	*buf = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!(*buf))
		return (0);
	if (!(*str))
	{
		*str = ft_strdup("");
		if (!(*str))
			return (0);
	}
	return (1);
}

static void	clear(char **p)
{
	free(*p);
	*p = NULL;
}

static int	output(char **line, int ret, char **str)
{
	char	*tmp;

	if (ret == -1)
	{
		clear(str);
		return (-1);
	}
	tmp = *str;
	while (*tmp != '\n' && *tmp != '\0')
		tmp++;
	if (!(*line = ft_substr(*str, 0, tmp - *str)))
		return (-1);
	if (*tmp == '\0')
	{
		clear(str);
		return (0);
	}
	if (!(tmp = ft_strdup(tmp + 1)))
		return (-1);
	free(*str);
	*str = tmp;
	return (1);
}

static int	read_file(char **buf, char **str)
{
	int		ret;
	char	*tmp;

	while ((ret = read(STDIN_FILENO, *buf, BUFFER_SIZE)) > 0)
	{
		(*buf)[ret] = '\0';
		tmp = ft_strjoin(*str, *buf);
		if (!tmp)
		{
			clear(buf);
			clear(str);
			return (-1);
		}
		free(*str);
		*str = tmp;
		if (ft_strchr(*str, '\n'))
			break ;
	}
	return (ret);
}

int			get_next_instruction(char **line, int flag)
{
	int			ret;
	static char	*str;
	char		*buf;

	ret = 1;
	if (flag == FREE)
	{
		clear(&str);
		return (0);
	}
	if (BUFFER_SIZE <= 0 || !line || !(init(&buf, &str)))
		return (-1);
	if (!ft_strchr(str, '\n'))
		ret = read_file(&buf, &str);
	clear(&buf);
	return (output(line, ret, &str));
}
