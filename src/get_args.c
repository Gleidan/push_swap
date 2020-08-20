/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jconcent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 12:48:11 by jconcent          #+#    #+#             */
/*   Updated: 2020/08/20 12:10:58 by jconcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**  Checking arguments for correct integers
*/

static int		ps_isint(char *str)
{
	long int	value;
	int			sign;

	value = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n' ||
			*str == '\f' || *str == '\r' || *str == '\v')
		str++;
	if (*str == '-')
		sign = -1;
	else
		sign = 1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		value = value * 10 + (*str - '0');
		str++;
	}
	if ((value * sign) <= 2147483647 && (value * sign) >= -2147483648)
		return (1);
	else
		return (0);
}

/*
**  Checking arguments for duplicates
*/

static int		ps_duplicate(t_array *a, int num)
{
	size_t i;

	if (a->size == 0)
		return (0);
	i = 0;
	while (i < a->size)
	{
		if (CONTENT_ARRAY(a, i) == num)
			return (1);
		i++;
	}
	return (0);
}

/*
**  Record arguments from (argv) to stack. Check all errors;
*/

int				get_args(t_array *a, int i, int argc, char **argv)
{
	int num;
	int single;

	single = 0;
	if (argc - i == 1)
	{
		argc = ft_wordcounter(argv[i], ' ');
		argv = ft_strsplit(argv[i], ' ');
		i = 0;
		single = 1;
	}
	while (i < argc)
	{
		num = ft_atoi(argv[i]);
		if ((num == 0 && !ft_isdigit(argv[i][0]) && argv[i][1] != '0') ||
				ps_duplicate(a, num) || !ps_isint(argv[i++]))
		{
			ft_putstr_fd("Error\n", 2);
			single ? ft_clear_table(argv) : 0;
			return (-1);
		}
		ft_array_insert(a, &num, 1, 0);
	}
	single ? ft_clear_table(argv) : 0;
	return (1);
}
