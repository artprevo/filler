/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artprevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 19:02:43 by artprevo          #+#    #+#             */
/*   Updated: 2019/09/19 21:38:20 by artprevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static t_env	*ft_initenv()
{
	t_env	*new;

	if (!(new = (t_env *)malloc(sizeof(t_env))))
		return (NULL);
	new->tab = NULL;
	new->piece = NULL;
	new->xtab = 0;
	new->ytab = 0;
	new->xpiece = 0;
	new->ypiece = 0;
	new->linetab = NULL;
	new->linepiece = NULL;
	new->result = NULL;
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

t_linepiece			*ft_initlinepiece(char *str, int x, int empty)
{
	t_linepiece		*new;;

	if (!(new = (t_linepiece *)malloc(sizeof(t_linepiece))))
		return (NULL);
	new->line = ft_strdup(str);
	new->x = x;
	new->empty = empty;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_env	*ft_processinit()
{
	t_env	*env;

	env = ft_initenv();
	return (env);
}
