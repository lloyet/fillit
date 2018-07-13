/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parsing.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/13 02:27:06 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2018/07/13 02:49:45 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parsing.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: augberna <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/09 12:59:22 by augberna     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/11 18:45:16 by augberna    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "header.h"

int			ft_value(char *buff, int ret)
{
	int		i;
	int		k;
	int		value;

	i = 0;
	k = -1;
	while (buff[i])
	{
		if (buff[i] != '.' && buff[i] != '#')
			return (0);
		if (buff[i] == '.' && k == -1)
			i++;
		if (buff[i] == '#' && k == -1)
		{
			k = 1;
			value = 1;
			i++;
		}
		if (buff[i] == '.')
		{
			i++;
			k++;
		}
		if (buff[i] == '#')
		{
			value += ft_power(2, k);
			i++;
			k++;
		}
		if (i % 5 == 4)
		{
			if (buff[i] == '\n')
				i++;
			else
				return (0);
		}
		if (i == 20 && ret == 21)
		{
			if (buff[i] == '\n')
				i++;
			else
				return (0);
		}
	}
	return (value);
}

int			check_value(int value)
{
	if (value == 0)
		return (0);
	if (value == 15)
		return (1);
	if (value == 4369)
		return (1);
	if (value == 113)
		return (1);
	if (value == 275)
		return (1);
	if (value == 71)
		return (1);
	if (value == 401)
		return (1);
	if (value == 29)
		return (1);
	if (value == 785)
		return (1);
	if (value == 23)
		return (1);
	if (value == 547)
		return (1);
	if (value == 51)
		return (1);
	if (value == 27)
		return (1);
	if (value == 561)
		return (1);
	if (value == 57)
		return (1);
	if (value == 305)
		return (1);
	if (value == 39)
		return (1);
	if (value == 281)
		return (1);
	if (value == 99)
		return (1);
	if (value == 153)
		return (1);
	return (0);
}

int			parsing(char *file_name, t_piece *list)
{
	int		fd;
	char	buff[22];
	int		ret;
	int		value;
	int		letter;

	fd = open(file_name, O_RDONLY);
	lettre = 0;
	while ((ret = read(fd, buff, 21)) && ret != -1)
	{
		buff[ret] = '\0';
		if (ret == 21)
			list->next = malloc(sizeof(t_piece));
		else
			list->next = NULL;
		if (ret != 21 && ret != 20)
			return (0);
		value = ft_value(buff, ret);
		if (check_value(value) == 0)
			return (0);
		list->type = value;
		list->letter = letter + 'A';
		list = list->next;
		letter++;
		value = ret;
	}
	if (value == 21)
		return (0);
	return (1);
}
