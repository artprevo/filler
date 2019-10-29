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

int				findhim(t_env *env)
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

int				findme(t_env *env)
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

int				absolute(int i)
{
	if (i < 0)
		i = -i;
	return (i);
}

static int		scoreptwo(t_env *env, int x, int y)
{
	t_linetab	*tab;
	int			xhim;
	int			yhim;
	int			i;

	tab = LINETAB;
	while (tab)
	{
		i = 4;
		while (tab->line[i])
		{
			if (tab->line[i] == env->him || tab->line[i] == env->him + 32)
			{
				yhim = i;
				xhim = tab->x;
			}
			i++;
		}
		tab = tab->next;
	}
	return (absolute(xhim - x) + 4 * absolute(yhim - y));
}

int				distance(t_env *env, int x, int y)
{
	int			score;
	t_origin	*origin;

	origin = ORIGIN;
	score = 0;
	if (origin->xhim > origin->xme)
		score += absolute(env->xhim - x) + absolute(env->yhim + 4 - y);
	else if (origin->xhim < origin->xme)
		score = scoreptwo(env, x, y);
	if (env->xtab < 20 && env->order == 2 && x > 3)
		score = 0 - (env->xtab - x);
	else if (env->xtab < 40 && env->order == 2)
	{
		if (x < 7 || score == 17)
			score -= 0 - (env->xtab - x);
	}
	return (score);
}
