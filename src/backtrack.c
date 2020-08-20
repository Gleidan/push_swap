/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jconcent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 12:47:55 by jconcent          #+#    #+#             */
/*   Updated: 2020/08/20 12:03:23 by jconcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**  Push max value of stack (b) to stack (a).
*/

void	ps_split_a(t_array *a, t_array *b, int average, int size)
{
	while (size-- > 0)
	{
		if (b->size < 13)
			ps_push_max_to_a(a, b);
		else
		{
			if (average <= CONTENT_ARRAY(b, b->size - 1))
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
					ps_rotate(b, a, "rb");
			}
		}
	}
}

/*
**  Resursive function that adds elements of stack (b)
**	to the end of stack (a) in sorted form, until array (b) is empty.
*/

void	ps_swap_backtrack(t_array *a, t_array *b)
{
	int max;

	if (b->size == 0)
		return ;
	max = ps_get_max(b);
	ps_split_a(a, b, ps_get_average(b), b->size);
	while ((CONTENT_ARRAY(a, a->size - 1) == CONTENT_ARRAY(a, 0) + 1 ||
			CONTENT_ARRAY(a, a->size - 1) == 1) && !ps_is_sorted(a))
		ps_rotate(a, b, "ra");
	ps_swap_backtrack(a, b);
	if (ps_get_size(a, max) >= 20)
		ps_backtrack_split(a, b, max);
	ps_backtrack(a, b, max);
}

/*
**  Push the unsorted elements of stack (a)
**	to stack (b) and repeat ps_swap_backtrack.
*/

void	ps_backtrack(t_array *a, t_array *b, int limit)
{
	while (CONTENT_ARRAY(a, a->size - 1) <= limit
			&& CONTENT_ARRAY(a, a->size - 1) != 1)
	{
		if (CONTENT_ARRAY(a, a->size - 1) == CONTENT_ARRAY(a, 0) + 1)
			ps_rotate(a, b, "ra");
		else
			ps_push(b, a, "pb");
	}
	if (ps_get_min(b) == CONTENT_ARRAY(a, 0) + 1)
		ps_swap_backtrack(a, b);
}

void	ps_backtrack_split(t_array *a, t_array *b, int limit)
{
	int c;
	int i;
	int average;

	c = 0;
	average = ps_get_average_limit(a, limit);
	while (CONTENT_ARRAY(a, a->size - 1) <= limit
			&& CONTENT_ARRAY(a, a->size - 1) != 1)
	{
		if (CONTENT_ARRAY(a, a->size - 1) >= average)
		{
			ps_rotate(a, b, "ra");
			c++;
		}
		else
			ps_push(b, a, "pb");
	}
	i = -1;
	while (++i < c)
		if (CONTENT_ARRAY(b, b->size - 1) != ps_get_max(b))
			ps_rev_rotate_r(a, b, "rrr");
		else
			ps_rev_rotate(a, b, "rra");
	if (ps_get_min(b) == CONTENT_ARRAY(a, 0) + 1 && c > 0)
		ps_swap_backtrack(a, b);
}
