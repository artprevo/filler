/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artprevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 18:26:57 by artprevo          #+#    #+#             */
/*   Updated: 2019/09/19 21:38:32 by artprevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "filler.h"

int	main()
{
	t_env	*env;
	char	*str;
	FILE	*fptr;
	char	*line;
	int		x;
	int		limit;
	int		i;

	env = ft_processinit();
	i = 0;
	limit = 2;
	fptr = fopen("../data.txt", "a");
	str = "2 3\n";
	while (i <= limit)
	{
		get_next_line(0, &line);
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
			create_linepiece(env, line);
		i++;
		free(line);
	}
	i = 0;
	while (LINETAB)
	{
			fprintf(fptr, "x = %d | %s\n", LINETAB->x, LINETAB->line);
		LINETAB = LINETAB->next;
	}
	while (LINEPIECE)
	{
		fprintf(fptr, "x = %d | %s\n", LINEPIECE->x, LINEPIECE->line);
		LINEPIECE = LINEPIECE->next;
	}
	fclose(fptr);
	ft_putstr_fd(str, 1); 
	return (0);
}
