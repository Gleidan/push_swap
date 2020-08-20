/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jconcent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 12:48:19 by jconcent          #+#    #+#             */
/*   Updated: 2020/08/20 12:00:42 by jconcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**  Push all values less than average to an array (b).
**	In array (a) stay values high than average.
*/

void	ps_split_b(t_array *a, t_array *b, int average, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (average > CONTENT_ARRAY(a, a->size - 1))
			ps_push(b, a, "pb");
		else
			ps_rotate(a, b, "ra");
		i++;
	}
}

/*
**  Push all values less then average in stack (b).
**	Sort it and push in down of stack (a).
*/

void	ps_not_simple(t_array *a, t_array *b)
{
	if (ps_is_sorted(a))
		return ;
	ps_split_b(a, b, ps_get_average(a), a->size);
	ps_swap_backtrack(a, b);
	if (ps_get_size(a, ps_get_max(a)) >= 20)
	{
		ps_backtrack_split(a, b, ps_get_max(a));
		ps_backtrack_split(a, b, ps_get_max(a));
	}
	ps_backtrack(a, b, ps_get_max(a));
}

/*
**  Initiate two stacks (a) and (b). Record argv in (a) ->
**  record argv in (b) -> sort the array (b) ->
**  record the position of the sorted elements in stack (a) ->
**  reliaze simple push_swap if size stacks <= 5
**	 and not_simple push_swap otherwise
*/

int		main(int argc, char **argv)
{
	t_array	a;
	t_array	b;
	int		i;

	a = INIT_ARRAY(int);
	b = INIT_ARRAY(int);
	if (argc > 1)
	{
		i = 1;
		if (get_args(&a, i, argc, argv) == -1)
		{
			ft_array_clear(&a);
			return (0);
		}
		get_args(&b, i, argc, argv);
		ps_sort_array(&b, 0, b.size - 1);
		ps_position(&a, &b);
		if (a.size <= 5)
			ps_simple(&a, &b);
		else
			ps_not_simple(&a, &b);
		ft_array_clear(&a);
		ft_array_clear(&b);
	}
	return (0);
}
