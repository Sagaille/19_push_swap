/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_utility01.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldavids <ldavids@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 17:32:38 by ldavids           #+#    #+#             */
/*   Updated: 2021/04/27 22:49:29 by ldavids          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_checker.h"

void	*ft_calloc_exit(size_t num, size_t size)
{
	void	*result;

	result = malloc(size * num);
	if (!result)
		return (NULL);
	ft_bzero(result, size * num);
	return (result);
}

void	ft_checker_init(t_struct *checker, int argc)
{
	checker->i = 0;
	checker->tab_input = malloc(sizeof(char **) + (argc * 250));
	checker->elements_a = argc - 1;
	checker->ele_b = 0;
	checker->eof = 0;
}

void	ft_print_stack_a(t_struct *checker, int argc)
{
	int	i;

	i = 0;
	ft_putstr_fd("\x1B[36m", 1);
	ft_putstr_fd("\nSTACK A\n", 1);
	while (i < argc - 1)
	{
		ft_putnbr_fd(checker->stack_a[i], 1);
		ft_putstr_fd("\n", 1);
		i++;
	}
}

void	ft_print_stack_b(t_struct *checker, int argc)
{
	int	i;

	i = 0;
	ft_putstr_fd("\x1B[33m", 1);
	ft_putstr_fd("\nSTACK B\n", 1);
	while (i < argc - 1)
	{
		ft_putnbr_fd(checker->stack_b[i], 1);
		ft_putstr_fd("\n", 1);
		i++;
	}
	ft_putstr_fd("\n\x1B[0m", 1);
}

void	ft_ok_ko(t_struct *checker, int argc)
{
	int	i;

	i = 0;
	while (i < argc - 1)
	{
		if (checker->stack_b[i] != 0)
		{
			ft_putstr_fd("\x1B[31mKO\n", 1);
			exit(EXIT_SUCCESS);
		}
		i++;
	}
	i = 0;
	while (i < argc - 2)
	{
		if (checker->stack_a[i] > checker->stack_a[i + 1])
		{
			ft_putstr_fd("\x1B[31mKO\n", 1);
			exit(EXIT_SUCCESS);
		}
		i++;
	}
	ft_putstr_fd("\x1B[32mOK\n", 1);
	exit(EXIT_SUCCESS);
}
