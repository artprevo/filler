/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixpiece.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artprevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 13:44:08 by artprevo          #+#    #+#             */
/*   Updated: 2019/10/21 13:44:17 by artprevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "filler.h"

void bottompiece(t_env *env)
{
    t_linepiece *piece;
    t_linepiece *tmp;

    piece = LINEPIECE;
    while (piece && piece->next)
      piece = piece->next;
    while (piece && ft_isempty(piece->line) == 1)
    {
      tmp = piece->prev;
      free(piece->line);
      free(piece);
      piece = tmp;
      piece->next = NULL;
    }
}
