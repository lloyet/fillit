/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   resolution.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: augberna <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/11 18:40:46 by augberna     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/14 03:42:02 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "header.h"

int			ft_listlen(t_piece *list)
{
	int len;

	while (list->next)
		len++;
	return (len);
}

void		free_tab(char **tab)
{
	while (tab)
		free((*tab)++);
	return ;
}

int			can_i_put(char ***tab, t_type type, int *i, int n)
{

	if ()
}

void		put(t_piece *next, char ***tab, int n)
{
	return ;
}

void		unput(t_piece *list, int *i, char ***tab)
{
	return ;
}

void		created_tab(char ***tab, int n)
{

	return ;
}

int			special_sqrt(int size)
{
	int sqrt;

	return (sqrt);
}

int			backtrack(t_piece *list, char ***tab, int n)
{
	int		i[2];

	if (list == NULL)
		return (1);
	i[0] = 0;
	while (i[0] < n)
	{
		i[1] = 0;
		while (i[1] < n)
		{
			if (can_i_put(tab, list->type, i, n))
			{
				put(list, i, tab);
				if (backtrack(list->next, tab, n))
					return (1);
				unput(list, i, tab);
			}
			i[1]++;
		}
		i[0]++;
	}
	return (0);
}

int			resolution_n(t_piece *list, int n, char ***tab)
{
	created_tab(&tab, n);
	return (backtrack(list, tab, n));
}

char		**resolution(t_piece *list)
{
	char		**tab;
	int			n;

	n = special_sqrt(ft_listlen(list) * 4);
	while (!resolution_n(list, n, &tab))
	{
		n++;
		free_tab(tab);
	}
	return (tab);
}
