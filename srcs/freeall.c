/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artprevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 21:24:07 by artprevo          #+#    #+#             */
/*   Updated: 2019/10/18 16:17:21 by artprevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static	void	freelinepiece(t_env *env)
{
	t_linepiece	*piece;
	t_linepiece	*tmpp;

	if (LINEPIECE)
	{
		piece = LINEPIECE;
		while (piece)
		{
			free(piece->line);
			tmpp = piece->next;
			free(piece);
			piece = tmpp;
		}
	}
}

static	void	freelinetab(t_env *env)
{
	t_linetab	*tab;
	t_linetab	*tmpt;

	if (LINETAB)
	{
		tab = LINETAB;
		while (tab)
		{
			free(tab->line);
			tmpt = tab->next;
			free(tab);
			tab = tmpt;
		}
	}
}

t_env			*tafreetatoucompri(t_env *env)
{
	t_origin	*tmp;
	int			order;
	t_env		*new;

	tmp = env->origin;
	order = env->order;
	free(env->tab);
	free(env->piece);
	freelinetab(env);
	freelinepiece(env);
	free(DOM);
	free(RESULT);
	free(env);
	new = ft_processinit();
	new->order = order;
	new->init = 1;
	new->origin = tmp;
	return (new);
}
