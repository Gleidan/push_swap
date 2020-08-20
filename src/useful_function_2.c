/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useful_function_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jconcent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 12:49:09 by jconcent          #+#    #+#             */
/*   Updated: 2020/08/19 11:54:39 by jconcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**  Summ all elements of array and find the average
*/

int		ps_get_average(t_array *ar)
{
	int		i;
	float	total;

	if (ar->size == 0)
		return (0);
	i = ar->size - 1;
	total = 0;
	while (i >= 0)
	{
		total += CONTENT_ARRAY(ar, i);
		i--;
	}
	return ((int)(total / (int)ar->size + 0.5));
}

void	ps_rev_rotate_r(t_array *ar, t_array *ar_2, char *instruction)
{
	int temp;

	if (ar->size == 0)
		return ;
	temp = CONTENT_ARRAY(ar, 0);
	ft_array_add(ar, &temp, 1);
	ft_array_pop_index(ar, 0, 1);
	if (ar_2->size == 0)
		return ;
	temp = CONTENT_ARRAY(ar_2, 0);
	ft_array_add(ar_2, &temp, 1);
	ft_array_pop_index(ar_2, 0, 1);
	ft_putstr(instruction);
	ft_putstr("\n");
}

int		ps_get_average_limit(t_array *ar, int limit)
{
	int		i;
	float	total;

	if (ar->size == 0)
		return (0);
	i = 0;
	total = 0;
	while (CONTENT_ARRAY(ar, (int)ar->size - 1 - i) <= limit &&
			CONTENT_ARRAY(ar, (int)ar->size - 1 - i) != 1)
	{
		total += CONTENT_ARRAY(ar, (int)ar->size - 1 - i);
		i++;
	}
	return ((int)(total / i + 0.5));
}

int		ps_get_size(t_array *ar, int limit)
{
	int i;

	if (ar->size == 0)
		return (0);
	i = 0;
	while (CONTENT_ARRAY(ar, (int)ar->size - 1 - i) <= limit &&
			CONTENT_ARRAY(ar, (int)ar->size - 1 - i) != 1)
		i++;
	return (i);
}
