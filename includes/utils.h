/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 02:26:23 by kefujiwa          #+#    #+#             */
/*   Updated: 2021/03/25 23:47:49 by kefujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

/*
** SELF-MADE HEADER FILES
*/
# include "libft.h"

/*
** EXTERNAL LIBRARIES
*/
# include <limits.h>
# include <stdlib.h>

/*
** PROTOTYPE DECLARATION
*/
int	is_valid_args(char **argv);
int	put_error(void);

#endif
