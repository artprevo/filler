/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artprevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 20:46:15 by artprevo          #+#    #+#             */
/*   Updated: 2019/09/19 20:59:56 by artprevo         ###   ########.fr       */
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
