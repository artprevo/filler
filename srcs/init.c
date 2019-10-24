/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artprevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 19:02:43 by artprevo          #+#    #+#             */
/*   Updated: 2019/10/18 17:43:41 by artprevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_result			*ft_initresult(int x, int y)
{
	t_result		*new;

	if (!(new = (t_result *)malloc(sizeof(t_result))))
		return (NULL);
	new->x = x;
	new->y = y;
	new->distance = 0;
	new->coeff = -200;
	new->score = 0;
	return (new);
}

static t_env		*ft_initenv(void)
{
	t_env	*new;

	if (!(new = (t_env *)malloc(sizeof(t_env))))
		return (NULL);
	new->tab = NULL;
	new->piece = NULL;
	new->truex = 0;
	new->truey = -1;
	new->xtab = 0;
	new->ytab = 0;
	new->xpiece = 0;
	new->ypiece = 0;
	new->order = 0;
	new->me = 0;
	new->him = 0;
	new->xhim = 0;
	new->yhim = 0;
	new->linetab = NULL;
	new->linepiece = NULL;
	new->result = NULL;
	new->dominance = NULL;
	new->origin = NULL;
	return (new);
}

t_linetab			*ft_initlinetab(char *str, int x, int empty)
{
	t_linetab	*new;

	if (!(new = (t_linetab *)malloc(sizeof(t_linetab))))
		return (NULL);
	new->line = ft_strdup(str);
	new->x = x;
	new->empty = empty;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_linepiece			*ft_initlinepiece(t_env *env, char *str, int x, int empty)
{
	t_linepiece		*new;

	if (!(new = (t_linepiece *)malloc(sizeof(t_linepiece))))
		return (NULL);
	new->line = ft_strdup(str);
	if (env->truey == -1)
		env->truey = truey(str);
	if (truey(str) < env->truey)
		env->truey = truey(str);
	new->x = x;
	new->empty = empty;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_env				*ft_processinit(void)
{
	t_env	*new;

	new = ft_initenv();
	new->xme = 0;
	new->yme = 0;
	new->count = 0;
	new->init = 0;
	new->score = 0;
	new->distance = 0;
	new->coeff = 0;
	return (new);
}
