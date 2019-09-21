/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artprevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 18:27:52 by artprevo          #+#    #+#             */
/*   Updated: 2019/09/21 17:41:50 by artprevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/libft.h"
# define BUFFER_SIZE 1000

# define LINETAB	(env->linetab)
# define LINEPIECE	(env->linepiece)
# define RESULT		(env->result)
# define POS		(env->pos)

typedef	struct			s_env
{
	char				**tab;
	char				**piece;
	int					xtab;
	int					ytab;
	int					xpiece;
	int					ypiece;
	int					order;
	struct s_linetab	*linetab;
	struct s_linepiece	*linepiece;
	struct s_result		*result;
	struct s_pos		*pos;
}						t_env;

typedef	struct			s_pos
{
	int					xme;
	int					yme;
	int					xhim;
	int					yhim;
	int					top;
	char				me;
	char				him;
	struct s_pos		*next;
	struct s_pos		*prev;
}						t_pos;

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
	struct s_result		*next;
	struct s_result		*prev;
	int					best;
}						t_result;

int	main();

/*
 * init.c
 */
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
void    tafreetatoucompri(t_env *env);
// int		testpos(t_env *env);
int		emptyline(char *line);
char	*resultis(t_result *result);
t_result    *assignres(t_env *env);
#endif
