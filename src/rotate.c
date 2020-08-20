/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jconcent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 12:48:28 by jconcent          #+#    #+#             */
/*   Updated: 2020/08/20 12:10:30 by jconcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**  p* command execution
*/

void	ps_push(t_array *dest, t_array *source, char *instruction)
{
	int temp;

	if (source->size == 0)
		return ;
	temp = CONTENT_ARRAY(source, source->size - 1);
	ft_array_pop(source, 1);
	ft_array_add(dest, &temp, 1);
	ft_printf("%s\n", instruction);
}

void	ps_swap(t_array *a, t_array *b, char *instuction)
{
	int temp;

	(void)b;
	if (a->size < 2)
		return ;
	temp = CONTENT_ARRAY(a, a->size - 2);
	CONTENT_ARRAY(a, a->size - 2) = CONTENT_ARRAY(a, a->size - 1);
	CONTENT_ARRAY(a, a->size - 1) = temp;
	ft_printf("%s\n", instuction);
}

/*
**  r* command execution
*/

void	ps_rotate(t_array *a, t_array *b, char *instruction)
{
	int temp;

	(void)b;
	if (a->size == 0)
		return ;
	temp = CONTENT_ARRAY(a, a->size - 1);
	ft_array_pop(a, 1);
	ft_array_insert(a, &temp, 1, 0);
	ft_printf("%s\n", instruction);
}

/*
** rr* command execution
*/

void	ps_rev_rotate(t_array *a, t_array *b, char *instruction)
{
	int temp;

	(void)b;
	if (a->size == 0)
		return ;
	temp = CONTENT_ARRAY(a, 0);
	ft_array_add(a, &temp, 1);
	ft_array_pop_index(a, 0, 1);
	ft_printf("%s\n", instruction);
}

/*
**  Find position of minimum value and if it in
**	the left half - use rra or use ra;
*/

void	ps_rev_rotate_a(t_array *a, t_array *b)
{
	int i;

	i = -1;
	while (++i < (int)a->size)
		if (CONTENT_ARRAY(a, i) == ps_get_min(a))
			break ;
	if (i <= (int)a->size / 2)
		ps_rev_rotate(a, b, "rra");
	else
		ps_rotate(a, b, "ra");
}
