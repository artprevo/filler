/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artprevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 19:02:43 by artprevo          #+#    #+#             */
/*   Updated: 2019/09/19 18:31:14 by artprevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static t_env	*ft_initenv(char *str)
{
	t_env	*new;

	if (!(new = (t_env *)malloc(sizeof(t_env))))
		return (NULL);
	new->str = str;
	new->form = NULL;
	return (new);
}

static t_opt	*ft_initopt(char *str)
{
	t_opt	*new;

	str = 0;
	if (!(new = (t_opt *)malloc(sizeof(t_opt))))
		return (NULL);
	new->posi = 0;
	new->hash = 0;
	new->lzero = 0;
	new->space = 0;
	new->lalign = 0;
	return (new);
}

static t_form	*ft_initform(char *str)
{
	t_form	*new;

	str = 0;
	if (!(new = (t_form *)malloc(sizeof(t_form))))
		return (NULL);
	new->size = 48;
	new->width = 0;
	new->precision = 0;
	new->content = NULL;
	new->result = NULL;
	new->conversion = 0;
	new->opt = NULL;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_env	*ft_processinit(char *str)
{
	t_env	*env;

	env = ft_initenv(str);
	return (env);
}
