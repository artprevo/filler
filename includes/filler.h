/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artprevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 18:27:52 by artprevo          #+#    #+#             */
/*   Updated: 2019/09/26 17:54:21 by artprevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/libft.h"
# define BUFFER_SIZE 1000000

# define LINETAB	(env->linetab)
# define LINEPIECE	(env->linepiece)
# define RESULT		(env->result)
# define POS		(env->pos)

typedef	struct			s_env
{
	char				**tab;
	char				**piece;
	int					truex;
	int					xtab;
	int					ytab;
	int					xpiece;
	int					ypiece;
	int					order;
	char				me;
	char				him;
	int					count;
	int					xhim;
	int					yhim;
	int					init;
	struct s_linetab	*linetab;
	struct s_linepiece	*linepiece;
	struct s_result		*result;
}						t_env;

typedef struct			s_linetab
{
	char				*line;
	int					x;
	int					empty;
	struct s_linetab	*next;
	struct s_linetab	*prev;
}						t_linetab;

typedef struct			s_linepiece
{
	char				*line;
	int					truey;
	int					x;
	int					empty;
	struct s_linepiece	*next;
	struct s_linepiece	*prev;
}						t_linepiece;

typedef struct			s_result
{
	int					x;
	int					y;
	int					distance;
}						t_result;

int	main();

/*
 * init.c
 */
t_result        	*ft_initresult();
t_linetab           *ft_initlinetab(char *str, int x, int empty);
t_linepiece         *ft_initlinepiece(char *str, int x, int empty);
t_env   			*ft_processinit();

/*
 * parsing.c
 */
int             create_tab(t_env *env, char *str, char c);
void            create_linepiece(t_env *env, char *str, int j);
void            create_linetab(t_env *env, char *str);

/*
 * utility.c
 */
int     ft_isempty(char *str);

/*
 * position.c
 */
void    findposition(t_env *env);

/*
 * freeall.c
 */
t_env   *tafreetatoucompri(t_env *env);

// int		testpos(t_env *env);

int    gatherresult(t_env *env);
t_result    *assignres(t_env *env);
void	truex(t_env *env);
void    printstr(char *str);
void    printnbr(int nbr);
int		findhim(t_env *env);
int		distance(t_env *env, int x, int y);
#endif
