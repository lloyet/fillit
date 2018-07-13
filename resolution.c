/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   resolution.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: augberna <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/11 18:40:46 by augberna     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/11 19:21:23 by augberna    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "header.h"

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
