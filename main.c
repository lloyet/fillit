/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: augberna <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/09 12:59:38 by augberna     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/11 19:22:20 by augberna    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "header.h"

int			ex_prg(t_piece *lst)
{
	t_piece		*tmp;

	tmp = lst;
	while (tmp)
	{
		tmp = lst->next;
		free(lst);
		lst = tmp;
	}
	return (0);
}

int			error_parsing(t_piece *lst)
{
	t_piece		*tmp;

	tmp = lst;
	while (tmp)
	{
		tmp = lst->next;
		free(lst);
		lst = tmp;
	}
	ft_putstr_fd("Erreur parsing\n", 2);
	return (0);
}

int			usage(void)
{
	ft_putstr("usage: ./fillit source_file\n");
	return (0);
}

int			main(int ac, char **av)
{
	t_piece		*list;
	char		**sol;

	list = malloc(sizeof(t_piece));
	if (ac != 2)
		return (usage());
	if (!parsing(av[1], list))
		return (error_parsing(list));
	sol = resolution(list);
	print_sol(sol);
	free_tab(sol);
	return (ex_prg(list));
}
