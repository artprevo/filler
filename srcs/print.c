/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artprevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 16:00:10 by artprevo          #+#    #+#             */
/*   Updated: 2019/10/23 16:00:10 by artprevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	printresult(t_env *env)
{
	t_result	*res;

	res = RESULT;
	ft_putnbr_fd(res->x - env->truex, 1);
	ft_putchar_fd(' ', 1);
	ft_putnbr_fd(res->y - 4 - env->truey, 1);
	ft_putchar_fd('\n', 1);
}
