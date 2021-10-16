/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldavids <ldavids@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 16:27:55 by ldavids           #+#    #+#             */
/*   Updated: 2021/04/27 17:22:24 by ldavids          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_checker.h"

void	ft_print_bonus(t_struct *checker, int argc)
{
	if (checker->bonus == 2)
	{
		ft_print_stack_a(checker, argc);
		ft_print_stack_b(checker, argc);
	}
}

void	input_to_tab(t_struct *checker)
{
	if (ft_check_cmds(checker->input) == 1)
	{
		checker->tab_input[checker->i] = ft_strdup(checker->input);
		checker->i++;
	}
	else if (checker->eof == 1)
		return ;
	else
		ft_error();
}

char	*getinput(t_struct *checker, int count, char buffer, int ret)
{
	int		i;
	char	*input;

	input = ft_calloc_exit(2, sizeof(char));
	i = -1;
	while (ret > -1 && buffer != '\n')
	{
		ret = read(0, &buffer, 1);
		if (ret != 0 && buffer != 0 && buffer != '\n')
		{
			input[++i] = buffer;
			count++;
		}
		if (ret == 0)
		{
			checker->eof = 1;
			return (input);
		}
		input = ft_realloc(input, count + 1);
	}
	return (input);
}

void	loop_prompt(t_struct *checker, int argc)
{
	if (checker->bonus == 1)
	{
		ft_loop_bonus(checker, argc);
		return ;
	}
	while (1)
	{
		checker->input = getinput(checker, 1, 0, 0);
		input_to_tab(checker);
		if (checker->input[0] == '\0')
		{
			ft_cmds(checker, argc);
			free(checker->input);
			ft_print_bonus(checker, argc);
			return ;
		}
		free(checker->input);
	}
	ft_print_bonus(checker, argc);
	return ;
}
