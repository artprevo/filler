/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artprevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 15:57:56 by artprevo          #+#    #+#             */
/*   Updated: 2019/10/18 17:36:25 by artprevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static	void	initperks(t_env *env)
{
	env->count = 0;
	env->score = 0;
	env->coeff = 0;
}

static	void	putres(t_env *env, int x, int i)
{
	if (env->count == 1 && ((x + env->xpiece - env->truex <= env->xtab)))
	{
		if (!RESULT || (env->coeff >= RESULT->coeff && env->order == 1))
			add_result(env, x, i, env->score);
	}
}

static int		checkpostab(t_env *env, t_linetab *tab, int i, char c)
{
	char	me;

	me = env->me;
	if (c == '.')
		return (1);
	if (c == '*' && i < 4)
		return (0);
	if (c == '*' && i - 4 >= env->ytab)
		return (0);
	if (c == '*' && (tab->line[i] == env->him || tab->line[i] == env->him + 32))
		return (0);
	if (c == '*' && (tab->line[i] == me || tab->line[i] == me + 32))
	{
		env->count += 1;
		if (env->count > 1)
			return (0);
		algo(env, tab->x, i);
	}
	return (1);
}

static int		testpos(t_env *env, int x, int i)
{
	t_linepiece	*piece;
	t_linetab	*tab;
	int			j;
	int			k;

	piece = LINEPIECE;
	tab = LINETAB;
	initperks(env);
	while (tab->x != x)
		tab = tab->next;
	while (piece->x != env->truex)
		piece = piece->next;
	while (tab && piece)
	{
		j = env->truey;
		k = i;
		while (piece->line[j])
			if (checkpostab(env, tab, k++, piece->line[j++]) == 0)
				return (0);
		tab = tab->next;
		piece = piece->next;
	}
	putres(env, x, i);
	return (1);
}

int				gatherresult(t_env *env)
{
	int			i;
	t_linetab	*tab;

	tab = LINETAB;
	while (tab)
	{
		i = 4;
		while (i <= env->ytab + 4)
		{
			testpos(env, tab->x, i);
			i++;
		}
		if (RESULT && env->order == 2)
			break ;
		tab = tab->next;
	}
	if (!RESULT)
		return (0);
	return (1);
}
