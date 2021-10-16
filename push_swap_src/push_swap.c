/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldavids <ldavids@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 15:41:31 by ldavids           #+#    #+#             */
/*   Updated: 2021/03/30 12:19:12 by ldavids          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_push.h"

void	ft_stack_b(t_struct *checker, int argc)
{
	checker->stack_b = ft_calloc_exit(argc, sizeof(char *));
}

int	ft_duplicate_check(int argc, t_struct *ps)
{
	int		i;
	int		x;

	i = 0;
	while (i < argc - 1)
	{
		x = 0;
		while (x < argc - 1)
		{
			if (ps->stack_a[i] == ps->stack_a[x] && \
			i != x)
				ft_error();
			x++;
		}
		i++;
	}
	return (TRUE);
}

int	ft_args_check(int argc, t_struct *ps)
{
	int		i;
	int		x;

	i = 0;
	while (i < argc - 1)
	{
		x = 0;
		while (ps->args_a[i][x])
		{
			if (ft_isdigit(ps->args_a[i][x]))
				x++;
			else if (ps->args_a[i][x] == '-' || \
			ps->args_a[i][x] == '+')
				x++;
			else
				ft_error();
		}
		ps->stack_a[i] = ft_atoi_spec(ps->args_a[i]);
		i++;
	}
	ft_duplicate_check(argc, ps);
	return (TRUE);
}

void	ft_args_to_tab(int argc, char **argv, t_struct *ps)
{
	int		i;

	i = 0;
	ps->args_a = (char **)ft_calloc_exit(argc, sizeof(char *));
	ps->stack_a = ft_calloc_exit(argc, sizeof(char *));
	while (i < argc - 1)
	{
		ps->args_a[i] = ft_strdup(argv[i + 1]);
		i++;
	}
	i = 0;
	ft_args_check(argc, ps);
	return ;
}

int	main(int argc, char **argv)
{
	t_struct	*ps;

	if (argc <= 1)
		return (0);
	ps = malloc(sizeof(t_struct));
	if (!ps)
		exit(EXIT_FAILURE);
	if (ft_bonus(argc, argv, ps) == 0)
	{
		argv = ft_relocate(argc, argv);
		argc--;
	}
	ft_args_to_tab(argc, argv, ps);
	ft_stack_b(ps, argc);
	if (ft_ok_ko(ps, argc) == 0)
		exit(EXIT_SUCCESS);
	ft_sort(argc, ps);
}
