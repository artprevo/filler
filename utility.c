/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artprevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 20:46:15 by artprevo          #+#    #+#             */
/*   Updated: 2019/09/21 18:02:54 by artprevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_isempty(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'X' || str[i] == 'x' || str[i] == 'o' || str[i] == 'O')
			return (0);
		i++;
	}
	return (1);
}
/*
char	*resultis(t_result *res)
{
	char	*tmp;
	int		len;
	
	len = 5;
	if (res->x > 9)
		len++;
	if (res->y > 9)
		len++;
	if (len == 5)
	{
		tmp = ft_strnew(5);
		tmp[0] = res->x % + 48;
		tmp[1] = ' ';
		tmp[2] = res->y % + 48;
		tmp[3] = '\n';
		tmp[4] = '\0';
	}
	if (len == 6)
	{
		tmp = ft_strnew(6);
		if (res->x > 9)
		{
			tmp[0] = ((res->x/10) % 10) + 48;
			tmp[1] = res->x % 10 + 48;
			tmp[2] = ' ';
			tmp[3] = res->y 0 + 48;
			tmp[4] = '\n';
			tmp[5] = '\0';
		}
		if (res->y > 9)
		{
			tmp[0] = res->x % 10 + 48;
			tmp[1] = ' ';
			tmp[2] = ((res->y/10) % 10) + 48;
			tmp[3] = res->y % 10 + 48;
			tmp[4] = '\n';
			tmp[5] = '\0';
		}
	}
	if (len == 7)
	{
		tmp = ft_strnew(7);
			tmp[0] = ((res->x/10) % 10) + 48;
			tmp[1] = res->x % 10 + 48;
			tmp[2] = ' ';
			tmp[3] = ((res->y/10) % 10) + 48;
			tmp[4] = res->y % 10 + 48;
			tmp[5] = '\n';
			tmp[6] = '\0';
	}
	return (tmp);
}
*/
t_result	*assignres(t_env *env)
{
	t_result *res;
	t_pos	*pos;
	t_linepiece	*line;
	int			i;

	i = 0;
	line = LINEPIECE;
	while (LINEPIECE->line[i] != '*')
		i++;
	pos = POS;
	res = (t_result *)malloc(sizeof(t_result));
	res->x = pos->xme;
	res->y = pos->yme - i;
	return (res);
}
