/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artprevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 16:11:08 by artprevo          #+#    #+#             */
/*   Updated: 2019/10/26 16:27:46 by artprevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int				closedoor(t_env *env, int x, int y, int i)
{
	t_linetab	*tab;
	int			sum;

	sum = 0;
	tab = LINETAB;
	while (tab->x != x)
		tab = tab->next;
	while (env->xtab > 20 && tab->line[i] && i < y && tab->line[i] == '.')
	{
		if (tab->line[i] == HIM || tab->line[i] == HIM + SHIFT_MIN)
			return (FALSE);
		sum++;
		if (tab->line[i] == ME || tab->line[i] == ME + SHIFT_MIN)
			break ;
		i++;
	}
	if (env->xtab < 50 && sum < 4 && sum != 0)
		return (TRUE);
	if (env->xtab > 50 && sum < 17 && sum != 0 && COUPS > 200)
		return (TRUE);
	return (FALSE);
}

static int				pointab(t_env *env, int x, int y)
{
	t_linetab	*tab;
	int			i;
	int			sum;

	sum = 0;
	tab = LINETAB;
	while (tab)
	{
		i = 4;
		while (tab->line[i])
		{
			if (tab->line[i] == env->him)
				sum += (absolute(tab->x - x) + absolute(i - y));
			i++;
		}
		tab = tab->next;
	}
	return (sum);
}

void					algo(t_env *env, int x, int y)
{
	t_dominance *dom;
	int			sum;

	dom = DOM;
	sum = pointab(env, x, y);
	if (env->order == 1 && env->xtab < 20 && (y == 3 && x < 8) && COUPS < 7)
		sum = 0;
	if (env->order == 1 && env->xtab < 20 && (y != 3 && x > 8) && COUPS < 7)
		sum = 1000;
	if (env->order == 1 && env->xtab < 20 && (x == 3) && COUPS > 7)
		sum = 0;
	if (env->order == 2 && env->xtab < 20 && (y > 17) && (x < 13) && COUPS < 30)
		sum = 0;
	if (x >= ORIGIN->xme && y < 8 && closedoor(env, x, y, 4) == TRUE)
		sum = 0;
	if (env->order == 1 && env->xtab > 50 && (x == 30 || x == 70) &&
		y <= ORIGIN->yme && COUPS < 80)
		sum = 0;
	if (env->order == 1 && env->xtab > 50 && (x == 30 || x == 70) &&
		y >= ORIGIN->yme && COUPS > 80)
		sum = 0;
	if (env->order == 2 && env->xtab > 50 && (x == 70 || y == 60 || x == 30) &&
		COUPS < 300)
		sum = 0;
	env->coeff += sum;
}
