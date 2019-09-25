/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artprevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 18:26:57 by artprevo          #+#    #+#             */
/*   Updated: 2019/09/25 21:55:28 by artprevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "filler.h"

// COMPRENDRE POURQUOI LES MAPS PLANTENT

void    printnbr(int nbr)
{
	fprintf(stderr,"\033[0;32m%d\033[0m\n", nbr);
}

void    printstr(char *str)
{
	fprintf(stderr,"\033[0;32m%s\033[0m\n", str);
}

int	main()
{
	t_env	*env;
	char	*line;
	int		x;
	int		limit;
	int		i;
	int		j;
	t_result	*res;

	env = ft_processinit();
	while (1)
	{
		j = 0; //sert a mettre le bon x sur linepiece
		i = 0;
		limit = 2;
		while (i <= limit)
		{
			get_next_line(0, &line);
			if (line[0] == '$' && env->init == 0)
			{
				env->order = atoi(&line[10]);
				env->init = 1;
			}
			if (line[0] == 'P' && line[1] == 'l')
			{
				if ((x = create_tab(env, line, 'M')) == 0)
					return (0);
				limit = x + 2 + i;
			}
			if (line[0] == 'P' && line[1] == 'i')
			{
				if ((x = create_tab(env, line, 'P')) == 0)
					return (0);
				limit = x + i;
			}
			if (line[0] == '0')
				create_linetab(env, line);
			if (line[0] == '.' || line[0] == '*')
			{
				create_linepiece(env, line, j);
				j++;
			}
			i++;
			free(line);
		}
		if (gatherresult(env) == 0)
			break ;
		t_linetab	*linet;

		linet = LINETAB;
/*		while (linet)
		{
			printstr(linet->line);
			linet = linet->next;
		}*/
		res = RESULT;
		ft_putnbr_fd(res->x, 1);
		ft_putchar_fd(' ', 1);
		ft_putnbr_fd(res->y - 4, 1);
		ft_putchar_fd('\n', 1);
		env = tafreetatoucompri(env);
	}
	env = tafreetatoucompri(env);
	free(env);
	return (0);
}
