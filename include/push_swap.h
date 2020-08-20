/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jconcent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 12:47:25 by jconcent          #+#    #+#             */
/*   Updated: 2020/08/20 11:57:52 by jconcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

int		get_args(t_array *a, int i, int argc, char **argv);
void	ps_sort_array(t_array *b, int left, int right);
void	ps_position(t_array *a, t_array *b);
void	ps_simple(t_array *a, t_array *b);
int		ps_is_sorted(t_array *ar);
void	ps_split(t_array *a, t_array *b);
int		ps_get_average(t_array *ar);
int		ps_get_min(t_array *ar);
int		ps_get_max(t_array *ar);
void	ps_rotate(t_array *a, t_array *b, char *instruction);
void	ps_rev_rotate(t_array *a, t_array *b, char *instruction);
void	ps_rev_rotate_a(t_array *a, t_array *b);
void	ps_push(t_array *dest, t_array *source, char *instruction);
void	ps_merge(t_array *a, t_array *b);
void	ps_swap(t_array *a, t_array *b, char *instuction);
void	ps_push_max_to_a(t_array *a, t_array *b);
void	ps_smart_rotate(t_array *a, t_array *b);
int		ps_get_size(t_array *ar, int limit);
void	ps_swap_backtrack(t_array *a, t_array *b);
int		ps_get_average_limit(t_array *ar, int limit);
void	ps_rev_rotate_r(t_array *ar, t_array *ar_2, char *instruction);
void	ps_backtrack_split(t_array *a, t_array *b, int limit);
void	ps_backtrack(t_array *a, t_array *b, int limit);
void	ch_swap(t_array *a, t_array *b);
void	ch_push(t_array *a, t_array *b);
void	ch_rev_rotate(t_array *a, t_array *b);
void	ch_rotate(t_array *a, t_array *b);

#endif
