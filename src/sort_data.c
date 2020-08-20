/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jconcent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 12:48:49 by jconcent          #+#    #+#             */
/*   Updated: 2020/08/19 12:01:22 by jconcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ps_is_sorted(t_array *ar)
{
	int i;

	if (ar->size == 0)
		return (1);
	i = ar->size - 1;
	while (i > 0)
	{
		if (CONTENT_ARRAY(ar, i - 1) < CONTENT_ARRAY(ar, i))
			return (0);
		i--;
	}
	return (1);
}

/*
**  Find the place of the element in the sorted
**	array and write it to the array (a)
*/

void		ps_position(t_array *a, t_array *b)
{
	int i;
	int j;

	i = (int)a->size - 1;
	while (i >= 0)
	{
		j = 0;
		while (j < (int)b->size - 1)
		{
			if (CONTENT_ARRAY(a, i) == CONTENT_ARRAY(b, (int)b->size - 1 - j) &&
				CONTENT_ARRAY(b, (int)b->size - 1 - j) != 999999)
			{
				CONTENT_ARRAY(b, (int)b->size - 1 - j) = 999999;
				break ;
			}
			j++;
		}
		CONTENT_ARRAY(a, i) = j + 1;
		i--;
	}
	ft_array_clear(b);
	*b = INIT_ARRAY(int);
}

static int	ps_sorting(t_array *b, int left, int right, int base)
{
	int temp;

	while (left <= right)
	{
		while (CONTENT_ARRAY(b, left) > base)
			left++;
		while (CONTENT_ARRAY(b, right) < base)
			right--;
		if (left <= right)
		{
			temp = CONTENT_ARRAY(b, right);
			CONTENT_ARRAY(b, right) = CONTENT_ARRAY(b, left);
			CONTENT_ARRAY(b, left) = temp;
			left++;
			right--;
		}
	}
	return (left);
}

/*
**  Calculates the middle of an array. Use it how an base for sorting array (b).
*/

void		ps_sort_array(t_array *b, int left, int right)
{
	int base;
	int index;

	if (left >= right)
		return ;
	base = CONTENT_ARRAY(b, (right + left) / 2);
	index = ps_sorting(b, left, right, base);
	ps_sort_array(b, left, index - 1);
	ps_sort_array(b, index, right);
}
