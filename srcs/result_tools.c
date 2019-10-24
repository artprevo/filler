/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artprevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 15:03:57 by artprevo          #+#    #+#             */
/*   Updated: 2019/10/24 15:03:58 by artprevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		add_result(t_env *env, int x, int y, int score)
{
	t_result	*new;

	if (RESULT == NULL)
	{
		new = ft_initresult(x, y);
		RESULT = new;
		new->distance = env->distance;
		new->score = score;
		new->coeff = env->coeff;
	}
	else
	{
		new = RESULT;
		new->x = x;
		new->y = y;
		new->score = score;
		new->distance = env->distance;
		new->coeff = env->coeff;
	}
}
