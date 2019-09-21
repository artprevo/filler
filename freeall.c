/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artprevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 21:24:07 by artprevo          #+#    #+#             */
/*   Updated: 2019/09/21 18:06:43 by artprevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "filler.h"

void	tafreetatoucompri(t_env *env)
{
	t_linetab	*tab;
	t_linepiece	*piece;
	t_result	*result;
	
	free(env->tab);
	free(env->piece);
	while (LINETAB)
	{
		free(LINETAB->line);
		tab = LINETAB->next;
		free(LINETAB);
		LINETAB = tab;
	}
	while (LINEPIECE)
	{
		free(LINEPIECE->line);
		piece = LINEPIECE->next;
		free(LINEPIECE);
		LINEPIECE = piece;
	}
	while (RESULT)
	{
		result = RESULT->next;
		free(RESULT);
		RESULT = result;
	}
	free(env);
}
