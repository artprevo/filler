/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkerror.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artprevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 16:55:50 by artprevo          #+#    #+#             */
/*   Updated: 2019/10/26 17:10:48 by artprevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static	int		checktabzer(t_env *env, int i, int k)
{
	t_linetab	*tab;

	tab = LINETAB;
	if (env->init == 0 && env->order == 1)
	{
		while (tab && tab->line)
		{
			i = 0;
			while (tab->line[i])
			{
				if (tab->line[i] == 'X' || tab->line[i] == 'O')
					k++;
				if (i > 3 && (tab->line[i] != 'X' && tab->line[i] != 'O' &&
				tab->line[i] != '.'))
					return (FALSE);
				i++;
			}
			tab = tab->next;
		}
		if (k != 2)
			return (FALSE);
	}
	return (TRUE);
}

int				checktabintegrity(t_env *env, char *str, int flag)
{
	t_linetab	*tab;

	if (env->init == 1)
		return (TRUE);
	if (flag == 'y')
	{
		tab = 0;
		if (ft_strlen(str) != (size_t)env->ytab + 4)
			return (FALSE);
	}
	if (flag == 'x')
	{
		str = 0;
		tab = LINETAB;
		while (tab->next)
			tab = tab->next;
		if (tab->x != env->xtab - 1)
			return (FALSE);
		return (checktabzer(env, 0, 0));
	}
	return (TRUE);
}

int				checkpieceintegrity(t_env *env, char *str, int flag)
{
	t_linepiece	*piece;

	if (env->init == 1)
		return (TRUE);
	if (flag == 'y')
	{
		piece = 0;
		if (ft_strlen(str) != (size_t)env->ypiece)
			return (FALSE);
	}
	if (flag == 'x')
	{
		str = 0;
		piece = LINEPIECE;
		while (piece->next)
			piece = piece->next;
		if (piece->x != env->xpiece - 1)
			return (FALSE);
	}
	return (TRUE);
}

int				checkplayerintegrity(t_env *env, char *line)
{
	if (ft_strnequ(line, "$$$ exec p", 10) == FALSE)
		return (FALSE);
	if (env->order != 1 && env->order != 2)
		return (FALSE);
	return (TRUE);
}
