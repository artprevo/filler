/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artprevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 20:46:15 by artprevo          #+#    #+#             */
/*   Updated: 2019/10/18 17:55:14 by artprevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			ft_isempty(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'X' || str[i] == 'x' || str[i] == 'o' || str[i] == 'O')
			return (0);
		if (str[i] == '*')
			return (0);
		i++;
	}
	return (1);
}

int			truey(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '*')
			return (i);
		i++;
	}
	return (i);
}

void		truex(t_env *env)
{
	int			i;
	int			x;
	t_linepiece	*piece;

	x = 0;
	piece = LINEPIECE;
	while (piece)
	{
		i = 0;
		while (piece->line[i])
		{
			if (piece->line[i] != '.')
				break ;
			i++;
		}
		if (i == env->ypiece && piece)
		{
			x++;
			piece = piece->next;
		}
		else
			break ;
	}
	env->truex = x;
}

void		bottompiece(t_env *env)
{
	t_linepiece *piece;
	t_linepiece *tmp;
	int			k;

	k = 0;
	piece = LINEPIECE;
	while (piece && piece->next)
		piece = piece->next;
	while (piece && ft_isempty(piece->line) == 1)
	{
		tmp = piece;
		piece = piece->prev;
		piece->next = NULL;
		free(tmp->line);
		free(tmp);
		k++;
	}
}
