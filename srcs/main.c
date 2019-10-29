/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artprevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 18:26:57 by artprevo          #+#    #+#             */
/*   Updated: 2019/10/26 16:57:44 by artprevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int					main(void)
{
	t_env	*env;

	env = ft_processinit();
	while (processparsing(env, 0, 0, 2) == SUCCESS)
	{
		if (gatherresult(env) == 0)
			ft_putstr("0 0\n");
		else
			printresult(env);
		env->origin->coups += 1;
		env = tafreetatoucompri(env);
	}
	env = tafreetatoucompri(env);
	if (ORIGIN)
		free(ORIGIN);
	free(env);
	return (EXIT_SUCCESS);
}
