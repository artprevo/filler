/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artprevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 16:03:46 by artprevo          #+#    #+#             */
/*   Updated: 2019/10/23 16:03:47 by artprevo         ###   ########.fr       */
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

static	int			parsing(t_env *env, char *line, int limit, int i)
{
	int	x;

	if (line[0] == '$' && env->init == 0)
		env->order = atoi(&line[10]);
	if (line[0] == 'P' && line[1] == 'l')
	{
		if ((x = create_tab(env, line, 'M')) == 0)
			return (0);
		limit = x + 2 + i;
	}
	if (line[0] == 'P' && line[1] == 'i')
	{
		if ((x = create_tab(env, line, 'P')) == 0)
			return (0);
		limit = x + i;
	}
	if (line[0] == '0')
		create_linetab(env, line);
	return (limit);
}

static	void		variousperks(t_env *env)
{
	initorder(env);
	truex(env);
	if (env->init == 0)
		origin(env);
	bottompiece(env);
	dominance(env);
	findhim(env);
}

void				processparsing(t_env *env)
{
	char	*line;
	int		limit;
	int		i;
	int		j;

	j = 0;
	i = 0;
	limit = 2;
	while (i <= limit)
	{
		line = 0;
		if (get_next_line(0, &line) == -1)
			break ;
		if (line[0] == '.' || line[0] == '*')
		{
			create_linepiece(env, line, j);
			j++;
		}
		else
			limit = parsing(env, line, limit, i);
		i++;
		free(line);
	}
	variousperks(env);
}
