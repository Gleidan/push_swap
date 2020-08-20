/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jconcent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 12:12:58 by jconcent          #+#    #+#             */
/*   Updated: 2020/08/20 12:08:32 by jconcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			line_valid(char *line)
{
	if (ft_strnequ(line, "sa", 3))
		return (1);
	else if (ft_strnequ(line, "sb", 3))
		return (1);
	else if (ft_strnequ(line, "ss", 3))
		return (1);
	else if (ft_strnequ(line, "pa", 3))
		return (1);
	else if (ft_strnequ(line, "pb", 3))
		return (1);
	else if (ft_strnequ(line, "ra", 3))
		return (1);
	else if (ft_strnequ(line, "rb", 3))
		return (1);
	else if (ft_strnequ(line, "rr", 3))
		return (1);
	else if (ft_strnequ(line, "rra", 4))
		return (1);
	else if (ft_strnequ(line, "rrb", 4))
		return (1);
	else if (ft_strnequ(line, "rrr", 4))
		return (1);
	else
		return (0);
}

void		ps_checker(char *line, t_array *a, t_array *b)
{
	int			i;
	int			index;
	char		*c;
	void		*op[4];

	i = 0;
	index = 1;
	c = "spr";
	op[0] = &ch_swap;
	op[1] = &ch_push;
	op[2] = &ch_rotate;
	op[3] = &ch_rev_rotate;
	while (c[i] != '\0' && line[0] != c[i])
		i++;
	if (ft_strlen(line) == 3)
	{
		i = 3;
		index++;
	}
	if (line[0] == 's' && line[index] == 's')
		line[index] = 'r';
	if (line[index] == 'a' || line[index] == 'r')
		(((void (*)())op[i])(a, b));
	if (line[index] == 'b' || line[index] == 'r')
		(((void (*)())op[i])(b, a));
}

static int	check_line(t_array *a, t_array *b)
{
	int		i;
	char	*line;

	i = 0;
	while (get_next_line(0, &line))
	{
		if (!line_valid(line))
		{
			ft_putstr_fd("Error\n", 2);
			free(line);
			return (-1);
		}
		ps_checker(line, a, b);
		free(line);
		i++;
	}
	return (0);
}

int			main(int argc, char **argv)
{
	t_array a;
	t_array b;
	int		ret;

	a = INIT_ARRAY(int);
	b = INIT_ARRAY(int);
	ret = 0;
	if (argc > 1)
	{
		if ((ret = get_args(&a, 1, argc, argv)) != -1)
			if ((ret = check_line(&a, &b)) != -1)
			{
				if (b.size == 0 && ps_is_sorted(&a))
					ft_printf("OK\n");
				else
					ft_printf("KO\n");
			}
		ft_array_clear(&a);
		ft_array_clear(&b);
	}
	return (ret);
}
