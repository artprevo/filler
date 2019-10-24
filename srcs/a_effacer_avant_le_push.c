/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_effacer_avant_le_push.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artprevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 20:45:57 by artprevo          #+#    #+#             */
/*   Updated: 2019/10/24 20:46:10 by artprevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void    printnbr(int nbr)
{
	fprintf(stderr,"\033[0;32m%d\033[0m\n", nbr);
}

void    printstr(char *str)
{
	fprintf(stderr,"\033[0;32m%s\033[0m\n", str);
}

