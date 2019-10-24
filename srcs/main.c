/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artprevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 18:26:57 by artprevo          #+#    #+#             */
/*   Updated: 2019/10/18 17:55:04 by artprevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int					main(void)
{
	t_env	*env;

	env = ft_processinit();
	while (1)
	{
		processparsing(env);
		if (gatherresult(env) == 0)
			ft_putstr("0 0\n");
		else
			printresult(env);
		env = tafreetatoucompri(env);
	}
	env = tafreetatoucompri(env);
	free(env);
	return (0);
}
