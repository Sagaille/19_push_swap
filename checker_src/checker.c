/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldavids <ldavids@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 15:45:53 by ldavids           #+#    #+#             */
/*   Updated: 2021/04/27 21:20:11 by ldavids          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_checker.h"

void	ft_stack_b(t_struct *checker, int argc)
{
	checker->stack_b = ft_calloc_exit(argc, sizeof(char *));
}

int	ft_duplicate_check(int argc, t_struct *checker)
{
	int		i;
	int		x;

	i = 0;
	while (i < argc - 1)
	{
		x = 0;
		while (x < argc - 1)
		{
			if (checker->stack_a[i] == checker->stack_a[x] && \
			i != x)
				ft_error();
			x++;
		}
		i++;
	}
	return (TRUE);
}

int	ft_args_check(int argc, t_struct *checker)
{
	int		i;
	int		x;

	i = 0;
	while (i < argc - 1)
	{
		x = 0;
		while (checker->args_a[i][x])
		{
			if (ft_isdigit(checker->args_a[i][x]))
				x++;
			else if (checker->args_a[i][x] == '-' || \
			checker->args_a[i][x] == '+')
				x++;
			else
				ft_error();
		}
		checker->stack_a[i] = ft_atoi_spec(checker->args_a[i]);
		i++;
	}
	ft_duplicate_check(argc, checker);
	return (TRUE);
}

void	ft_args_to_tab(int argc, char **argv, t_struct *checker)
{
	int		i;

	i = 0;
	checker->args_a = (char **)ft_calloc_exit(argc, sizeof(char *));
	checker->stack_a = ft_calloc_exit(argc, sizeof(char *));
	while (i < argc - 1)
	{
		checker->args_a[i] = ft_strdup(argv[i + 1]);
		i++;
	}
	i = 0;
	ft_args_check(argc, checker);
	return ;
}

int	main(int argc, char **argv)
{
	t_struct	*checker;

	if (argc <= 1)
		return (0);
	checker = malloc(sizeof(t_struct));
	if (!checker)
		exit(EXIT_FAILURE);
	if (ft_bonus(argc, argv, checker) == 0)
	{
		argv = ft_relocate(argc, argv);
		argc--;
	}
	ft_args_to_tab(argc, argv, checker);
	ft_stack_b(checker, argc);
	ft_checker_init(checker, argc);
	loop_prompt(checker, argc);
	ft_ok_ko(checker, argc);
	return (0);
}
