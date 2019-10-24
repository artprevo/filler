/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artprevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 18:27:52 by artprevo          #+#    #+#             */
/*   Updated: 2019/10/18 17:38:51 by artprevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/libft.h"
# define BUFFER_SIZE 1000000

# define LINETAB		(env->linetab)
# define LINEPIECE		(env->linepiece)
# define RESULT			(env->result)
# define POS			(env->pos)
# define HIM			(env->him)
# define ME				(env->me)
# define DOM			(env->dominance)
# define ORIGIN			(env->origin)

typedef	struct			s_env
{
	char				**tab;
	char				**piece;
	int					truex;
	int					truey;
	int					xtab;
	int					ytab;
	int					xpiece;
	int					ypiece;
	int					order;
	char				me;
	char				him;
	int					count;
	int					score;
	int					distance;
	int					xhim;
	int					yhim;
	int					xme;
	int					yme;
	int					init;
	int					coeff;
	struct s_linetab	*linetab;
	struct s_linepiece	*linepiece;
	struct s_result		*result;
	struct s_dominance	*dominance;
	struct s_origin		*origin;
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
	int					score;
	int					coeff;
}						t_result;

typedef struct			s_dominance
{
	int					z1;
	int					z2;
	int					z3;
	int					z4;
	int					xstart;
	int					ystart;
	int					result;
}						t_dominance;

typedef struct			s_origin
{
	int					xme;
	int					yme;
	int					xhim;
	int					yhim;
}						t_origin;

int						main(void);

void					processparsing(t_env *env);

t_result        		*ft_initresult(int x, int y);
t_linetab           	*ft_initlinetab(char *str, int x, int empty);
t_linepiece         	*ft_initlinepiece(t_env *env, char *str, int x, int empty);
t_env   				*ft_processinit(void);

int						create_tab(t_env *env, char *str, char c);
void					create_linepiece(t_env *env, char *str, int j);
void					create_linetab(t_env *env, char *str);

void					findposition(t_env *env);

t_env					*tafreetatoucompri(t_env *env);

void					origin(t_env *env);
int						origindistance(t_env *env, int x, int y);

void					domiscore(t_env *env, int x, int y);
int						gatherresult(t_env *env);
t_result				*assignres(t_env *env);

void					truex(t_env *env);
int						truey(char *str);
void					bottompiece(t_env *env);
int						ft_isempty(char *str);

void					printstr(char *str);
void					printnbr(int nbr);
void					printresult(t_env *env);

int						findhim(t_env *env);
int						findme(t_env *env);
int						distance(t_env *env, int x, int y);

void					algo(t_env *env, int x, int y);

void					add_result(t_env *env, int x, int y, int score);

int						findzone(t_env *env, int x, int y);

void					dominance (t_env *env);
int						absolute(int i);

#endif
