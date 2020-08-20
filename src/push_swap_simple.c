/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_simple.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jconcent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 12:48:38 by jconcent          #+#    #+#             */
/*   Updated: 2020/08/19 12:05:37 by jconcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**  Sorting array (b) with values less than half.
**	But in this array all values must be on descending order
*/

void	ps_descsort(t_array *a, t_array *b)
{
	int i;

	if (b->size == 0)
		return ;
	i = b->size - 1;
	while (i > 0)
	{
		if (CONTENT_ARRAY(b, b->size - 1) == ps_get_min(b) &&
			CONTENT_ARRAY(b, b->size - 2) == ps_get_max(b))
			ps_rotate(b, a, "rb");
		if (CONTENT_ARRAY(b, i - 1) > CONTENT_ARRAY(b, i))
		{
			while (i < (int)b->size - 1)
			{
				ps_rotate(b, a, "rb");
				i++;
			}
			if (CONTENT_ARRAY(b, b->size - 1) == ps_get_min(b) &&
				CONTENT_ARRAY(b, b->size - 2) == ps_get_max(b))
				ps_rotate(b, a, "rb");
			else
				ps_swap(b, a, "sb");
		}
		i--;
	}
}

/*
**  Sorting array (a) with values greater than half
*/

void	ps_sort(t_array *a, t_array *b)
{
	int i;

	if (a->size == 0)
		return ;
	i = a->size - 1;
	while (i > 0)
	{
		if (CONTENT_ARRAY(a, a->size - 2) == ps_get_min(a) &&
			CONTENT_ARRAY(a, a->size - 1) == ps_get_max(a))
			ps_rotate(a, b, "ra");
		if (CONTENT_ARRAY(a, i - 1) < CONTENT_ARRAY(a, i))
		{
			while (i < (int)a->size - 1)
			{
				ps_rotate(a, b, "ra");
				i++;
			}
			if (CONTENT_ARRAY(a, a->size - 2) == ps_get_min(a) &&
				CONTENT_ARRAY(a, a->size - 1) == ps_get_max(a))
				ps_rotate(a, b, "ra");
			else
				ps_swap(a, b, "sa");
		}
		i--;
	}
}

/*
**  Find the average and minimum value.
**	While minimum less then average - check the first element of stack.
**  If it less then average and last value must be
**	before then the first value in stack - make reverse_rotate_a;
**  Or push it in (b);
*/

void	ps_split(t_array *a, t_array *b)
{
	int average;

	average = ps_get_average(a);
	while (ps_get_min(a) < average)
	{
		if (CONTENT_ARRAY(a, a->size - 1) < average)
		{
			if (CONTENT_ARRAY(a, 0) + 1 == CONTENT_ARRAY(a, a->size - 1))
			{
				ps_rev_rotate_a(a, b);
				if (ps_is_sorted(a))
					return ;
			}
			ps_push(b, a, "pb");
		}
		else
			ps_rev_rotate_a(a, b);
	}
}

/*
**  Simple sorting can use only for 5 and less elements
*/

void	ps_simple(t_array *a, t_array *b)
{
	if (ps_is_sorted(a))
		return ;
	if (a->size > 4)
		ps_split(a, b);
	ps_sort(a, b);
	ps_descsort(a, b);
	ps_merge(a, b);
}
