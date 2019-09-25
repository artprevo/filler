/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artprevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 15:57:56 by artprevo          #+#    #+#             */
/*   Updated: 2019/09/25 21:55:30 by artprevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "filler.h"

static void		add_result(t_env *env, int x, int y, int distance)
{
	t_result	*new;

	if (RESULT == NULL)
	{
		new = ft_initresult(x, y);
		RESULT = new;
		new->distance = distance;
	}
	else
	{
		new = RESULT;
		new->x = x;
		new->y = y;
		new->distance = distance;
	}
}

static int		checkpostab(t_env *env, t_linetab *tab, int i, char c)
{
	char	me;

	me = env->me;
	if (c == '*' && (i < 4 || i + 4 > env->xtab))
			return (0);
	if (c == '.')
		return (1);
	if (c == '*' && (tab->line[i] == me || tab->line[i] == me + 32))
	{
		env->count += 1;
		if (env->count > 1)
			return (0);
	}
	if (c == env->him || c == env->him + 32)
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
//	if (i + env->ypiece < env->ytab + piece->truey)
//	{
		i = i - piece->truey;
		while (tab->x != x)
			tab = tab->next;
		while (piece)
		{
			j = 0;
			k = i;
			while (piece->line[j])
			{
			//	if (tab->empty == 1)
			//		break ;
				if (checkpostab(env, tab, k, piece->line[j]) == 0)
					return (0);
				k++;
				j++;
			}
			if (tab->next)
				tab = tab->next;
			else
				return (0);
			piece = piece->next;
		}
		if (env->count == 1)
		{
		//	if (!RESULT)
				add_result(env, x, i, distance(env, x, i));
		//	else
		//	{
			//	if (distance(env, x, i) < RESULT->distance)
		//			add_result(env, x, i, distance(env, x, i));
		//	}
		}
//	}
	return (1);
}

int		gatherresult(t_env *env)
{
	int		i;
	t_linetab	*tab;

	findhim(env);
	tab = LINETAB;
	if (env->order == 1)
	{
		env->me = 'O';
		env->him = 'X';
	}
	else
	{
		env->me = 'X';
		env->him = '0';
	}
	while (tab)
	{
		i = 4;
		while (tab->line[i])
		{
			testpos(env, tab->x, i);
			i++;
			if (RESULT)
				break ;
		}
		tab = tab->next;
	}
	if (!RESULT)
		return (0);
	return (1);
}
