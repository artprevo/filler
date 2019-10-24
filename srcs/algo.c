/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artprevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 16:11:08 by artprevo          #+#    #+#             */
/*   Updated: 2019/10/23 16:17:42 by artprevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static	int				score(t_env *env, int x, int y)
{
	int score;

	score = 100;
	score -= absolute(env->xtab / 2 - x);
	score -= absolute(env->ytab / 2 - y);
	return (score);
}

static	int				adjacent(t_env *env, int x, int y, int sum)
{
	t_linetab		*tab;

	tab = LINETAB;
	while (tab->x != x)
		tab = tab->next;
	if (tab->prev && tab->next)
	{
		if (x != 0)
		{
			tab = tab->prev;
			if (tab->line[y] == ME || tab->line[x + 1] == ME + 32)
				sum++;
			tab = tab->next;
		}
		if (tab->line[y + 1] == ME || tab->line[x + 1] == ME + 32)
			sum++;
		if (tab->line[y - 1] == ME || tab->line[x + 1] == ME + 32)
			sum++;
		tab = tab->next;
		if (tab->line[y] == ME || tab->line[x + 1] == ME + 32)
			sum++;
	}
	return (sum);
}

void					algo(t_env *env, int x, int y)
{
	t_dominance *dom;

	dom = DOM;
	if (dom->result == 1 && (x <= env->xtab / 2 && y <= env->ytab / 2 + 4))
		env->coeff += 200;
	if (dom->result == 2 && (x <= env->xtab / 2 && y >= env->ytab / 2 + 4))
		env->coeff += 200;
	if (dom->result == 3 && (x >= env->xtab / 2 && y <= env->ytab / 2 + 4))
		env->coeff += 200;
	if (dom->result == 4 && (x >= env->xtab / 2 && y >= env->ytab / 2 + 4))
		env->coeff += 200;
	if (findzone(env, x, y) != dom->result)
		env->coeff -= 400;
	if (y >= env->ytab / 2 + 2)
		env->coeff += 200;
	if (absolute(findzone(env, x, y) - dom->result) == 1)
		env->coeff += 100;
	env->coeff += 20 * score(env, x, y);
	env->coeff += 200 - (50 * adjacent(env, x, y, 0));
	env->coeff += origindistance(env, x, y) + distance(env, x, y);
}
