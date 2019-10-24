/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proxdomi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artprevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 18:26:39 by artprevo          #+#    #+#             */
/*   Updated: 2019/10/24 18:26:40 by artprevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		findzone(t_env *env, int x, int y)
{
	if (x <= env->xtab / 2 && y <= env->ytab / 2 + 4)
		return (1);
	if (x <= env->xtab / 2 && y >= env->ytab / 2 + 4)
		return (2);
	if (x >= env->xtab / 2 && y <= env->ytab / 2 + 4)
		return (3);
	if (x >= env->xtab / 2 && y >= env->ytab / 2 + 4)
		return (4);
	return (0);
}
