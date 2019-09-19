/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artprevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 18:26:57 by artprevo          #+#    #+#             */
/*   Updated: 2019/09/19 18:03:13 by artprevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "filler.h"


static int		findytab(char *str)
{
	int		i;
	int		j;
	int		k;
	char	tmp[4];

	i = 0;
	j = 0;
	k = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 1 && k == 2)
			tmp[j++] = str[i];
		if (str[i] == ' ')
			k++;
		i++;
	}
	return(ft_atoi(tmp));
}

static int		findxtab(char *str)
{
	int		i;
	int		j;
	int		k;
	char	tmp[4];

	i = 0;
	j = 0;
	k = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 1)
			tmp[j++] = str[i];
		if (str[i] == ' ')
			k++;
		i++;
		if (k == 2)
			break ;
	}
	return(ft_atoi(tmp));
}

int	main(int ac, char **av)
{
	char	*str;
	FILE	*fptr;
	char	*line;
	char	**tab;
	int		x;
	int		y;
	int		limit;
	int		j;
	char	**piece;
	int		k;

	k = 0;
	av = 0;
	j = 0;
	limit = 2;
	if (ac == 1)
	{
		fptr = fopen("../data.txt", "w");
		str = "2 3\n";
		int i = 0;
		while (i <= limit)
		{
			get_next_line(0, &line);
			if (line[0] == 'P')
			{
				x = findxtab(line);
				y = findytab(line);
				if (line[1] == 'i')
				{
					if (!(piece = (char **)malloc(sizeof(char *) * x)))
						return (0);
				limit = x + i;
				}
				else
				{
					if (!(tab = (char **)malloc(sizeof(char *) * x)))
						return (0);
				limit = x + 2 + i;
				}
				fprintf(fptr, "x = %d\ny = %d\n", x, y);
			}
			if (line[0] == '0')
			{
				tab[j] = ft_strdup(line);
				fprintf(fptr, "%s\n", tab[j]);
				j++;
			}
			if (line[0] == '.' || line[0] == '*')
			{
				piece[k] = ft_strdup(line);
				fprintf(fptr, "%s\n", piece[k]);
				k++;
			}
			i++;
			free(line);
		}
		i = 0;
		ft_putstr_fd(str, 1); 
		fclose(fptr);
	}
	printf("%d\n", atoi("24"));
	return (0);
}
