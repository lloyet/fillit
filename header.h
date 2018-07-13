/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   header.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: augberna <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/09 13:01:27 by augberna     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/11 18:47:18 by augberna    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "libft/libft.h"
# include <fcntl.h>


typedef enum		e_type
{
	I_1 = 15,
	I_2 = 4369,
	J_1 = 113,
	J_2 = 275,
	J_3 = 71,
	J_4 = 401,
	L_1 = 29,
	L_2 = 785,
	L_3 = 23,
	L_4 = 547,
	O = 51,
	S_1 = 27,
	S_2 = 561,
	T_1 = 57,
	T_2 = 305,
	T_3 = 39,
	T_4 = 281,
	Z_1 = 99,
	Z_2 = 153,
}					t_type;

typedef struct		s_piece
{
	char				letter;
	t_type				type;
	struct s_piece		*next;
}					t_piece;

	int				parsing(char *file_name, t_piece *list);
	int				resolution(t_piece *list);

#endif
