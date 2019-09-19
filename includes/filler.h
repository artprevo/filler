/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artprevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 18:27:52 by artprevo          #+#    #+#             */
/*   Updated: 2019/09/19 18:31:15 by artprevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/libft.h"
# define BUFFER_SIZE 1000

typedef	struct			s_tab
{
	char				**tab;
	struct s_line		*line;
	struct s_piece		*piece;
	struct s_result		*result;
}						t_tab;

typedef struct			s_line
{
	char				*line;
	int					x;
	int					empty;
}						t_line;

typedef struct			s_piece
{
	char				**piece;
	struct s_linepiece	linepiece;
}						t_piece;

typedef struct			s_linepiece
{
	char				*line;
	int					x;
}						t_linepiece;

typedef struct			s_result
{
	int					x;
	int					y;
	int					distance;
}						t_result;

int	main();

#endif
