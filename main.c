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

# include "filler.h"

// jui perds contre abanlin et hcao

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
	FILE	*fptr;

	fptr = fopen("../data.txt", "a");
	env = ft_processinit();
	while (1)
	{
		j = 0; //sert a mettre le bon x sur linepiece
		i = 0;
		limit = 2;
		while (i <= limit)
		{
			line = 0;
			if (get_next_line(0, &line) == -1)
				break ;
			if (line[0] == '$' && env->init == 0)
				env->order = atoi(&line[10]);
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
		truex(env);
		bottompiece(env);
		if (gatherresult(env) == 0)
			ft_putstr("0 0\n");
		else
		{
			res = RESULT;
			ft_putnbr_fd(res->x - env->truex, 1);
			ft_putchar_fd(' ', 1);
			ft_putnbr_fd(res->y - 4, 1);
			ft_putchar_fd('\n', 1);
		}
		env = tafreetatoucompri(env);
	}
	env = tafreetatoucompri(env);
	free(env);
	return (0);
}
