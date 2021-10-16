/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldavids <ldavids@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 16:21:40 by ldavids           #+#    #+#             */
/*   Updated: 2021/04/27 21:56:07 by ldavids          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_push.h"

void	ft_stack_copy_b(int argc, t_struct *ps)
{
	int	i;

	i = 0;
	ps->stack_temp_b = ft_calloc_exit(argc, sizeof(char *));
	while (i < argc - 1)
	{
		ps->stack_temp_b[i] = ps->stack_b[i];
		i++;
	}
}

int	ft_selection_loop_b(t_struct *ps, int i, int j)
{
	ps->min_select = 0;
	ps->temp = 0;
	while (i < ps->ele_b)
	{
		j = i + 1;
		ps->min_select = ps->stack_temp_b[i];
		ps->temp = i;
		while (j < ps->ele_b)
		{
			if (ps->stack_temp_b[j] < ps->min_select)
			{
				ps->min_select = ps->stack_temp_b[j];
				ps->temp = j;
			}
			j++;
		}
		ps->stack_temp_b[ps->temp] = ps->stack_temp_b[i];
		ps->stack_temp_b[i] = ps->min_select;
		i++;
	}
	return (i);
}

int	ft_selection_b_pivot(int argc, t_struct *ps, int chunk, int i)
{
	if (argc <= 110)
	{
		if (chunk < 8)
			i = ps->ele_b - (chunk / 2);
		else
			i = ps->ele_b - (3);
	}
	if (argc > 110)
	{
		if (chunk < 8)
			i = ps->ele_b - (chunk / 2);
		else if (chunk < 50)
			i = ps->ele_b - (3);
		else if (chunk < 80)
			i = ps->ele_b - (5);
		else if (chunk < 100)
			i = ps->ele_b - (10);
		else if (chunk < 150)
			i = ps->ele_b - (25);
		else if (chunk < 300)
			i = ps->ele_b - (45);
		else
			i = ps->ele_b - (75);
	}
	return (i);
}

void	ft_selection_chunk(int argc, t_struct *ps, \
int chunk, int counter)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (ps->bonus == 1)
	{
		ft_putstr_fd("\n\x1B[35mSTACK B\n", 1);
		ft_print_tab(ps->stack_b, argc);
		ft_putstr_fd("\n\x1B[0m", 1);
	}
	ft_stack_copy_b(argc, ps);
	i = ft_selection_loop_b(ps, i, j);
	chunk = chunk - counter;
	i = ft_selection_b_pivot(argc, ps, chunk, i);
	if (chunk % 2 == 0)
		ps->med = ps->stack_temp_b[i];
	else
		ps->med = ps->stack_temp_b[i - 1];
	free(ps->stack_temp_b);
}
