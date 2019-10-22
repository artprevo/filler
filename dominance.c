/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artprevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 15:54:07 by artprevo          #+#    #+#             */
/*   Updated: 2019/10/21 15:54:08 by artprevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "filler.h"

static t_dominance *initdominance(t_env *env)
{
  t_dominance		*new;

  env = 0;
  if (!(new = (t_dominance *)malloc(sizeof(t_dominance))))
    return (NULL);
  new->z1 = 0;
  new->z2 = 0;
  new->z3 = 0;
  new->z4 = 0;
  new->result = 0;
  new->xstart = 0;
  new->ystart = 4;
  return (new);
}

static int zonedominance(t_env *env, t_dominance *dom, int xdest, int ydest)
{
  t_linetab *tab;
  int       i;
  int       sum;

  sum = 0;
  tab = LINETAB;
  i = dom->ystart;
  while (tab && tab->x != dom->xstart)
    tab = tab->next;
  while (tab && tab->x <= xdest)
  {
    i = dom->ystart;
    while (tab->line[i] && i <= ydest)
    {
      if (tab->line[i] == ME || tab->line[i] == ME + 32)
          sum++;
      if (tab->line[i] == HIM || tab->line[i] == HIM + 32)
        sum--;
      i++;
    }
    tab = tab->next;
  }
  return (sum);
}

static void processzonedominance(t_env *env, t_dominance *dom)
{
  dom->z1 = zonedominance(env, dom, env->xtab/2, (env->ytab/2) + 4);
  dom->ystart = (env->ytab/2) + 4;
  dom->z2 = zonedominance(env, dom, env->xtab/2, env->ytab + 4);
  dom->ystart = 4;
  dom->xstart = env->xtab/2;
  dom->z3 = zonedominance(env, dom, env->xtab, (env->ytab/2) + 4);
  dom->ystart = (env->ytab/2) + 4;
  dom->z4 = zonedominance(env, dom, env->xtab, env->ytab + 4);
}

void dominance (t_env *env)
{
  t_dominance *dom;

  dom = initdominance(env);
  env->dominance = dom;
  processzonedominance(env, dom);
  if (dom->z1 < dom->z2)
  {
    if (dom->z1 < dom->z3)
    {
      if (dom->z1 < dom->z4)
        dom->result = 1;
      else
        dom->result = 4;
    }
    else
    {
      if (dom->z3 < dom->z4)
        dom->result = 3;
      else
        dom->result = 4;
    }
  }
  else
  {
    if (dom->z2 < dom->z3)
    {
      if (dom->z2 < dom->z4)
        dom->result = 2;
      else
        dom->result = 4;
    }
    else
    {
      if (dom->z3 < dom->z4)
        dom->result = 3;
      else
        dom->result = 4;
    }
  }
}
