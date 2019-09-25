/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artprevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 21:24:07 by artprevo          #+#    #+#             */
/*   Updated: 2019/09/25 21:39:40 by artprevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "filler.h"

t_env	*tafreetatoucompri(t_env *env)
{
	t_linetab	*tab;
	t_linetab	*tmpt;
	t_linepiece	*piece;
	t_linepiece	*tmpp;
	int			order;
	t_env		*new;

	order = env->order;
	free(env->tab);
	free(env->piece);
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
	if (RESULT)
		free(RESULT);
	free(env);
	new = ft_processinit();
	new->order = order;
	new->init = 1;
	return (new);
}
