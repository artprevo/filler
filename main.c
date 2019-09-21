/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artprevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 18:26:57 by artprevo          #+#    #+#             */
/*   Updated: 2019/09/21 18:17:16 by artprevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "filler.h"

// LE PROGRAMME DOIT TOURNER EN BOUCLE
// FAIRE EN SORTE D'IMPLEMENTER UN WHILE 1
// JETAIS EN TRIAN DE BOSSER SUR RESULT ET POSITION.C
// FAIRE UN DEBUT D'ALGO POUR VERIFIER LE PARSING QUI ENCHAINE

void    printstr(char *str)
{
	    fprintf(stderr,"\033[0;32m%s\033[0m\n", str);
}

int	main()
{
	t_env	*env;
	char	*str;
	FILE	*fptr;
	char	*line;
	int		x;
	int		limit;
	int		i;
	int		j;
	t_result	*res;

	env = ft_processinit();
	j = 0; //sert a mettre le bon x sur linepiece
	i = 0;
	limit = 2;
	fptr = fopen("../data.txt", "a");
	str = "2 3\n";
	while (i <= limit)
	{
		get_next_line(0, &line);
		if (line[0] == '$')
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
//	fprintf(fptr, "i = %d\n", i);
	findposition(env);
/*	findresults(env);
	fprintf(fptr, "xme = %d || yme = %d\nxhim = %d || yhim = %d\ntop = %d\norder = %d\n", POS->xme, POS->yme, POS->xhim, POS->yhim, POS->top, env->order);
	fprintf(fptr, "xpiece = %d || ypiece = %d\nxtab = %d || ytab = %d\n", env->xpiece, env->ypiece, env->xtab, env->ytab);
*/	while (LINETAB)
	{
		printstr(LINETAB->line);
		LINETAB = LINETAB->next;
	}
	res = assignres(env);
	while (LINEPIECE)
	{
		fprintf(fptr, "x = %d | %s\n", LINEPIECE->x, LINEPIECE->line);
		LINEPIECE = LINEPIECE->next;
	}
	fclose(fptr);
	ft_putnbr_fd(res->x, 1);
	ft_putchar_fd(' ', 1);
	ft_putnbr_fd(res->y, 1);
	ft_putchar_fd('\n', 1);
	tafreetatoucompri(env);
	return (0);
}
