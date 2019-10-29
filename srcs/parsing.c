/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artprevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 16:03:46 by artprevo          #+#    #+#             */
/*   Updated: 2019/10/26 17:10:46 by artprevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static	void		initorder(t_env *env)
{
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
}

static	int			checkplayer(t_env *env, char *line)
{
	env->order = atoi(&line[10]);
	if (checkplayerintegrity(env, line) == FALSE)
		return (FALSE);
	return (TRUE);
}

static	int			parsing(t_env *env, char *line, int limit, int i)
{
	int	x;

	if (line[0] == '$' && env->init == 0 && checkplayer(env, line) == FALSE)
		return (FAILURE);
	if (line[0] == 'P' && line[1] == 'l')
	{
		if ((x = create_tab(env, line, 'M')) == FALSE)
			return (FAILURE);
		limit = x + 2 + i;
	}
	if (line[0] == 'P' && line[1] == 'i')
	{
		if ((x = create_tab(env, line, 'P')) == FALSE)
			return (FAILURE);
		limit = x + i;
	}
	if (line[0] == '0')
	{
		if (checktabintegrity(env, line, 'y') == FALSE)
			return (FAILURE);
		create_linetab(env, line);
	}
	return (limit);
}

static	int			variousperks(t_env *env)
{
	if (checktabintegrity(env, "", 'x') == FALSE)
		return (FAILURE);
	if (checkpieceintegrity(env, "", 'x') == FALSE)
		return (FAILURE);
	initorder(env);
	truex(env);
	if (env->init == 0)
		origin(env);
	bottompiece(env);
	dominance(env);
	findhim(env);
	return (SUCCESS);
}

int					processparsing(t_env *env, int i, int j, int limit)
{
	char	*line;

	while (i <= limit)
	{
		line = NULL;
		if (get_next_line(0, &line) <= 0)
			return (FAILURE);
		if (line[0] == '.' || line[0] == '*')
		{
			if (checkpieceintegrity(env, line, 'y') == FALSE)
				return (FAILURE);
			create_linepiece(env, line, j);
			j++;
		}
		else
			limit = parsing(env, line, limit, i);
		if (limit == FAILURE)
			return (FAILURE);
		i++;
		free(line);
	}
	if (variousperks(env) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
