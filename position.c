/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artprevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 13:38:45 by artprevo          #+#    #+#             */
/*   Updated: 2019/09/21 18:02:56 by artprevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	findposition(t_env *env)
{
	int		i;
	FILE	*fptr;
	t_linetab	*newline;

	newline = LINETAB;
	fptr = fopen("../dataposition.txt", "w");
	if (env->order == 1)
	{
		POS->me = 'O';
		POS->him = 'X';
	}
	if (env->order == 2)
	{
		POS->me = 'X';
		POS->him = 'O';
	}
	while (newline)
	{
		i = 0;
		while (newline->line[i])
		{
			if (POS->xme != -1 && POS->xhim == -1)
				POS->top = 1;
			if (POS->xme == -1 && POS->xhim != -1)
				POS->top = 0;
			if (!(POS->top == 0 && POS->xme != -1))
			{
				if (newline->line[i] == POS->me || newline->line[i] == POS->me + 32)
				{
					POS->xme = newline->x;
					POS->yme = i - 4;
				}
			}
			if (!(POS->top == 1 && POS->xhim != -1))
			{
				if (newline->line[i] == POS->him || newline->line[i] == POS->him + 32)
				{
					POS->xhim = newline->x;
					POS->yhim = i - 4;
				}
			}
			i++;
		}
		fprintf(fptr, "line = %s\n", newline->line);
		newline = newline->next;
	}
	fclose(fptr);
}
