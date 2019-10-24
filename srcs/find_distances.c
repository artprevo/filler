/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artprevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 19:07:52 by artprevo          #+#    #+#             */
/*   Updated: 2019/10/21 13:43:55 by artprevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		findhim(t_env *env)
{
	t_linetab		*tab;
	int				i;

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

int		findme(t_env *env)
{
	t_linetab		*tab;
	int				i;

	tab = LINETAB;
	while (tab)
	{
		i = 4;
		while (tab->line[i])
		{
			if (tab->line[i] == env->me || tab->line[i] == env->me + 32)
			{
				env->xme = tab->x;
				env->yme = i;
				return (0);
			}
			i++;
		}
		tab = tab->next;
	}
	return (0);
}

int		absolute(int i)
{
	if (i < 0)
		i = -i;
	return (i);
}

int		distance(t_env *env, int x, int y)
{
	int		difx;
	int		dify;

	difx = absolute(env->xhim - x);
	dify = absolute(env->yhim + 4 - y);
	return (difx + dify);
}
