/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artprevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 18:39:36 by artprevo          #+#    #+#             */
/*   Updated: 2019/09/26 16:18:17 by artprevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int		findxtab(char *str)
{
	int		i;
	int		j;
	int		k;
	char	tmp[4];

	i = 0;
	j = 0;
	k = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 1)
		{
			tmp[j] = str[i];
			j++;
		}
		if (str[i] == ' ')
			k++;
		i++;
		if (k == 2)
			break ;
	}
	return (ft_atoi(tmp));
}

static int		findytab(char *str)
{
	int		i;
	int		j;
	int		k;
	char	tmp[4];

	i = 0;
	j = 0;
	k = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 1 && k == 2)
			tmp[j++] = str[i];
		if (str[i] == ' ')
			k++;
		i++;
	}
	return (ft_atoi(tmp));
}

void			create_linetab(t_env *env, char *str)
{
	t_linetab	*new;
	t_linetab	*tmp;

	if (LINETAB == NULL)
	{
		new = ft_initlinetab(str, findxtab(str), ft_isempty(str));
		LINETAB = new;
	}
	else
	{
		new = ft_initlinetab(str, findxtab(str), ft_isempty(str));
		tmp = LINETAB;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		new->prev = tmp;
		new->next = NULL;
	}
}

void			create_linepiece(t_env *env, char *str, int j)
{
	t_linepiece	*new;
	t_linepiece	*tmp;

	if (LINEPIECE == NULL)
	{
		new = ft_initlinepiece(str, j, ft_isempty(str));
		LINEPIECE = new;
	}
	else
	{
		new = ft_initlinepiece(str, j, ft_isempty(str));
		tmp = LINEPIECE;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		new->prev = tmp;
		new->next = NULL;
	}
}

int				create_tab(t_env *env, char *str, char c)
{
	int		x;
	int 	y;
	char	**tab;

	x = findxtab(str);
	y = findytab(str);
	if (!(tab = (char **)malloc(sizeof(char *) * x)))
		return (0);
	if (c == 'M')
	{
		env->tab = tab;
		env->xtab = x;
		env->ytab = y;
	}
	if (c == 'P')
	{
		env->piece = tab;
		env->xpiece = x;
		env->ypiece = y;
	}
	return (x);
}
