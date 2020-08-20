/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useful_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jconcent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 12:49:01 by jconcent          #+#    #+#             */
/*   Updated: 2020/08/18 22:01:33 by jconcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_smart_rotate(t_array *a, t_array *b)
{
	int i;

	i = -1;
	while (++i < (int)a->size)
		if (CONTENT_ARRAY(a, i) == ps_get_max(a))
			break ;
	if (i <= (int)a->size / 2)
		ps_rev_rotate(a, b, "rrb");
	else
		ps_rotate(a, b, "rb");
}

/*
**  Push max values of stack (b) to down of stack (a).
*/

void	ps_push_max_to_a(t_array *a, t_array *b)
{
	if (ps_get_max(b) == CONTENT_ARRAY(b, b->size - 1))
		ps_push(a, b, "pa");
	else
	{
		if (CONTENT_ARRAY(b, b->size - 1) == CONTENT_ARRAY(a, 0) + 1
			|| CONTENT_ARRAY(b, b->size - 1) == 1)
		{
			ps_push(a, b, "pa");
			ps_rotate(a, b, "ra");
		}
		else
			ps_smart_rotate(b, a);
	}
}

/*
**  Push all elements of stack (b) to stack (a).
**	This merge the array after sorting.
*/

void	ps_merge(t_array *a, t_array *b)
{
	while (b->size > 0)
		ps_push(a, b, "pa");
}

/*
**  Find the minimum value in an array
*/

int		ps_get_min(t_array *ar)
{
	size_t	i;
	int		min;

	if (ar->size == 0)
		return (0);
	i = 0;
	min = CONTENT_ARRAY(ar, i);
	while (i < ar->size)
	{
		if (min > CONTENT_ARRAY(ar, i))
			min = CONTENT_ARRAY(ar, i);
		i++;
	}
	return (min);
}

/*
** Find the maximum value in an array
*/

int		ps_get_max(t_array *ar)
{
	size_t	i;
	int		max;

	if (ar->size == 0)
		return (0);
	i = 0;
	max = 0;
	while (i < ar->size)
	{
		if (max < CONTENT_ARRAY(ar, i))
			max = CONTENT_ARRAY(ar, i);
		i++;
	}
	return (max);
}
