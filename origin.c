/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoabove.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artprevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 17:31:52 by artprevo          #+#    #+#             */
/*   Updated: 2019/10/22 17:31:54 by artprevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "filler.h"

int             origindistance(t_env *env, int x)
{
  int		difx;

  difx = 2 * absolute(ORIGIN->xme - x);
  return (difx);
}

static t_origin *initorigin(t_env *env)
{
  t_origin		*new;

  env = 0;
  if (!(new = (t_origin *)malloc(sizeof(t_origin))))
    return (NULL);
  new->xme = 0;
  new->yme = 0;
  new->xhim = 0;
  new->yhim = 0;
  return (new);
}

void origin(t_env *env)
{
    t_origin *origin;

    origin = initorigin(env);
    env->origin = origin;
    findhim(env);
    findme(env);
    origin->xme = env->xme;
    origin->yme = env->yme;
    origin->xhim = env->xhim;
    origin->yhim = env->yhim;
}
