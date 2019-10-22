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

t_result		*ft_initresult(int x, int y)
{
	t_result		*new;

	if (!(new = (t_result *)malloc(sizeof(t_result))))
		return (NULL);
	new->x = x;
	new->y = y;
	new->distance = -1;
	return (new);
}

static t_env	*ft_initenv()
{
	t_env	*new;

	if (!(new = (t_env *)malloc(sizeof(t_env))))
		return (NULL);
	new->tab = NULL;
	new->piece = NULL;
	new->truex = 0;
	new->xtab = 0;
	new->ytab = 0;
	new->xpiece = 0;
	new->order = 0;
	new->me = 0;
	new->him = 0;
	new->xhim = 0;
	new->yhim = 0;
	new->count = 0;
	new->ypiece = 0;
	new->init = 0;
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

static	int			truey(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '*')
			return (i);
		i++;
	}
	return (0);
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

t_linepiece			*ft_initlinepiece(char *str, int x, int empty)
{
	t_linepiece		*new;;

	if (!(new = (t_linepiece *)malloc(sizeof(t_linepiece))))
		return (NULL);
	new->line = ft_strdup(str);
	new->truey = truey(str);
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
