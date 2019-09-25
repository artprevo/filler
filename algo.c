/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artprevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 19:07:52 by artprevo          #+#    #+#             */
/*   Updated: 2019/09/25 20:12:35 by artprevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "filler.h"

int		findhim(t_env *env)
{
	int		i;
	t_linetab	*tab;

	tab = LINETAB;
	while (tab)
	{
		i = 4;
		while (tab->line[i])
		{
			if (tab->line[i] == env->him || tab->line[i] == env->him + 32)
			{
				env->xhim = tab->x;
				env->yhim = i;
				return (0);
			}
			i++;
		}
		tab = tab->next;
	}
	return (0);
}

int		distance(t_env *env, int x, int y)
{
	int		difx;
	int		dify;

	difx = env->xhim - x;
	dify = env->yhim - y;
	if (env->order == 2)
	{
		difx = -difx;
		dify = -dify;
	}
	return (difx + dify);
}
