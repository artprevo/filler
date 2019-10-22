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

# include "filler.h"

static void score(t_env *env, int x, int y)
{
	int scorex;
	int scorey;

	scorex = absolute((x - (env->xtab/2)));
	scorey = absolute((y - (env->ytab/2)));
	env->score = env->score + (scorex + scorey);
}

static int adjacent(t_env *env, int x, int y)
{
	t_linetab *tab;
	int 			sum;

	sum = 0;
	tab = LINETAB;
	while (tab->x != x)
		tab = tab->next;
	if (x != 0)
	{
		tab = tab->prev;
	if (tab->line[y] == HIM || tab->line[x + 1] == HIM + 32)
		sum++;
		tab = tab->next;
	}
	if (tab->line[y + 1] == HIM || tab->line[x + 1] == HIM + 32)
		sum++;
	if (tab->line[y - 1] == HIM || tab->line[x + 1] == HIM + 32)
		sum++;
	if (tab)
	{
		tab = tab->next;
		if (tab->line[y] == HIM || tab->line[x + 1] == HIM + 32)
			sum++;
	}
	return (sum);
}

static void domiscore(t_env *env, int x, int y)
{
	t_dominance *dom;

	dom = DOM;
	if (dom->result == 1 && (x <= env->xtab/2 && y <= env->ytab/2 + 4))
		env->coeff = 40;
	if (dom->result == 2 && (x <= env->xtab/2 && y >= env->ytab/2 + 4))
		env->coeff = 40;
	if (dom->result == 3 && (x >= env->xtab/2 && y <= env->ytab/2 + 4))
		env->coeff = 40;
	if (dom->result == 4 && (x >= env->xtab/2 && y >= env->ytab/2 + 4))
		env->coeff = 40;
	if (y == env->ytab/2 + 4)
		env->coeff += 90;
	if (x == env->xtab/2)
		env->coeff += 50;
	env->distance = distance(env, x, y);
	score(env, x, y);
	if (RESULT)
	{
	if (env->score < RESULT->score)
		env->coeff += 10;
	if (env->distance <= RESULT->distance)
		env->coeff += 80;
	}
	env->coeff += 20 * adjacent(env, x, y);
	env->coeff += 3 * origindistance(env, x);
}

static void		add_result(t_env *env, int x, int y, int score)
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

static int		checkpostab(t_env *env, t_linetab *tab, int i, char c)
{
	char	me;

	me = env->me;
	// if (c == '*' && !tab->line[i])
	// 	return (0);
	if (c == '.')
		return (1);
	if (c == '*' && i < 4)
		return (0);
	if (c == '*' && i - 4 >= env->ytab)
		return (0);
	if (c == '*' && (tab->line[i] == me || tab->line[i] == me + 32))
	{
		env->count += 1;
		if (env->count > 1)
			return (0);
		domiscore(env, tab->x, i);
	}
	if (c == '*' && (tab->line[i] == env->him || tab->line[i] == env->him + 32))
		return (0);
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
	env->count = 0;
	env->score = 0;
	env->coeff = 0;
	i = i - piece->truey;
	while (tab->x != x)
		tab = tab->next;
	while (piece->x != env->truex)
		piece = piece->next;
	while (tab && piece)
	{
		j = 0;
		k = i;
		while (piece->line[j])
		{
			if (checkpostab(env, tab, k, piece->line[j]) == 0)
				return (0);
			k++;
			j++;
		}
		piece = piece->next;
		if (!tab->next)
			return (0) ;
		tab = tab->next;
	}
	if (env->count == 1)
	{
		if (!RESULT)
			add_result(env, x, i, env->score);
		else
		{
			if (env->coeff >= RESULT->coeff)
				add_result(env, x, i, env->score);
		}
	}
	return (1);
}

int		gatherresult(t_env *env)
{
	int		i;
	t_linetab	*tab;

	tab = LINETAB;
	if (env->order == 1)
	{
		env->me = 'O';
		env->him = 'X';
	}
	if (env->order == 2)
	{
		env->me = 'X';
		env->him = 'O';
	}
	if (env->init == 0)
		origin(env);
	dominance(env);
	findhim(env);
	while (tab && tab->next)
	{
		i = 4;
		while (i <= env->ytab + 4)
		{
			testpos(env, tab->x , i);
			i++;
		}
		tab = tab->next;
	}
	if (!RESULT)
		return (0);
	return (1);
}
