/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jconcent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 17:29:53 by jconcent          #+#    #+#             */
/*   Updated: 2020/08/19 22:13:14 by jconcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ch_swap(t_array *a, t_array *b)
{
	int temp;

	(void)b;
	if (a->size < 2)
		return ;
	temp = CONTENT_ARRAY(a, a->size - 2);
	CONTENT_ARRAY(a, a->size - 2) = CONTENT_ARRAY(a, a->size - 1);
	CONTENT_ARRAY(a, a->size - 1) = temp;
}

void	ch_push(t_array *a, t_array *b)
{
	int temp;

	if (b->size == 0)
		return ;
	temp = CONTENT_ARRAY(b, b->size - 1);
	ft_array_pop(b, 1);
	ft_array_add(a, &temp, 1);
}

void	ch_rev_rotate(t_array *a, t_array *b)
{
	int temp;

	(void)b;
	if (a->size == 0)
		return ;
	temp = CONTENT_ARRAY(a, 0);
	ft_array_add(a, &temp, 1);
	ft_array_pop_index(a, 0, 1);
}

void	ch_rotate(t_array *a, t_array *b)
{
	int temp;

	(void)b;
	if (a->size == 0)
		return ;
	temp = CONTENT_ARRAY(a, a->size - 1);
	ft_array_pop(a, 1);
	ft_array_insert(a, &temp, 1, 0);
}
