/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artprevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 15:57:56 by artprevo          #+#    #+#             */
/*   Updated: 2019/09/21 17:43:58 by artprevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "filler.h"

int	emptyline(char *line)
{
	int			i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '*')
			return (0);
		i++;
	}
	return (1);
}

/*
static int		checkpostab(t_linetab *tab, int i)
{
	if (tab->line[i] == '.')
		return (1);
	return (0);
}

void		testpos(t_env *env)
{
	t_pos		*pos;
	t_linepiece	*piece;
	t_linetab	*tab;
	t_result	*res;
	int			i;
	int			j;
	int			omega;
	int			omega2;

	res = RESULT;
	pos = POS;
	piece = LINEPIECE;
	tab = LINETAB;
	j = 0;
	while (tab->x != pos->xme)
		tab = tab->next;
	i = pos->yme;
	res->x = pos->xme;
	res->y = pos->yme;
	while (piece->line[j] != '*')
		j++;
	omega = j - 1;
	while (piece)
	{
		while (piece->line[j])
		{
			if (j < omega)
				omega2 = omega - j;
			if (j > omega)
				omega2 = omega + j;
			if (j == omega)
				omega2 = omega;
			if (piece->line[j] == '*' && checkpostab(tab, i + omega2) == 0)
				break ;
			j++;
		}
		piece = piece->next;
		tab = tab->next;
	}
}
*/
