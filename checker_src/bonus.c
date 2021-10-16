/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldavids <ldavids@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 16:27:34 by ldavids           #+#    #+#             */
/*   Updated: 2021/04/27 17:00:15 by ldavids          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_checker.h"

void	input_to_tab_bonus(t_struct *checker)
{
	if (ft_check_cmds(checker->input) == 1)
	{
		checker->tab_input[0] = ft_strdup(checker->input);
		checker->i++;
	}
	else if (checker->eof == 1)
		return ;
	else
		ft_error();
}

void	ft_loop_bonus(t_struct *checker, int argc)
{
	while (1)
	{
		checker->input = getinput(checker, 1, 0, 0);
		if (checker->input[0] == '\0')
		{
			free(checker->input);
			return ;
		}
		input_to_tab_bonus(checker);
		ft_cmds_rest(checker, argc, 0);
		ft_print_stack_a(checker, argc);
		ft_print_stack_b(checker, argc);
		free(checker->tab_input[0]);
		if (checker->input[0] == '\0')
		{
			free(checker->input);
			return ;
		}
		free(checker->input);
	}
	return ;
}

char	**ft_relocate(int argc, char **argv)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		argv[i] = argv[i + 1];
		i++;
	}
	argc--;
	return (argv);
}

int	ft_bonus(int argc, char **argv, t_struct *checker)
{
	checker->bonus = 0;
	if (argc == 2 && (ft_strncmp(argv[1], "-v", 3) == 0 || \
	 ft_strncmp(argv[1], "-c", 3) == 0))
		exit(EXIT_SUCCESS);
	if (ft_strncmp(argv[1], "-v", 3) == 0)
		checker->bonus = 1;
	if (ft_strncmp(argv[1], "-c", 3) == 0)
		checker->bonus = 2;
	if (checker->bonus == 0)
		return (1);
	else
		return (0);
}
