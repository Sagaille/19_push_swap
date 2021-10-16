/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldavids <ldavids@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 15:59:41 by ldavids           #+#    #+#             */
/*   Updated: 2021/04/27 21:56:10 by ldavids          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_push.h"

void	ft_stack_copy(int argc, t_struct *ps)
{
	int	i;

	i = 0;
	ps->stack_temp_a = ft_calloc_exit(argc, sizeof(char *));
	while (i < argc - 1)
	{
		ps->stack_temp_a[i] = ps->stack_a[i];
		i++;
	}
}

int	ft_selection_a_pivot_med(int i)
{
	if (i > 550)
		i = 100;
	else if (i > 300)
		i = 46;
	else if (i > 200)
		i = 36;
	else if (i > 150)
		i = 34;
	else if (i > 100)
		i = 32;
	else if (i > 50)
		i = 24;
	else if (i <= 50 && i > 40)
		i = 16;
	else if (i <= 40 && i > 30)
		i = 12;
	else if (i <= 30 && i > 20)
		i = 10;
	else if (i <= 20 && i > 10)
		i = 8;
	else
		i = i / 2;
	return (i);
}

int	ft_selection_a_pivot(int i, int argc)
{
	if (argc < 120)
	{
		if (i > 500)
			i = 60;
		else if (i > 100)
			i = 32;
		else if (i > 50)
			i = 24;
		else if (i <= 50 && i > 40)
			i = 16;
		else if (i <= 40 && i > 30)
			i = 12;
		else if (i <= 30 && i > 20)
			i = 10;
		else if (i <= 20 && i > 10)
			i = 8;
		else
			i = i / 2;
		return (i);
	}
	else
		return (ft_selection_a_pivot_med(i));
}

int	ft_selection_loop_a(t_struct *ps, int i, int j, int counter)
{
	while (i < ps->elements_a && i < ps->order - counter)
	{
		j = i + 1;
		ps->min_select = ps->stack_temp_a[i];
		ps->temp = i;
		while (j < ps->elements_a && i < ps->order)
		{
			if (ps->stack_temp_a[j] < ps->min_select)
			{
				ps->min_select = ps->stack_temp_a[j];
				ps->temp = j;
			}
			j++;
		}
		ps->stack_temp_a[ps->temp] = ps->stack_temp_a[i];
		ps->stack_temp_a[i] = ps->min_select;
		i++;
	}
	return (i);
}

void	ft_selection_a(int argc, t_struct *ps, int counter)
{
	int	j;
	int	i;

	ps->temp = 0;
	ps->min_select = 0;
	i = 0;
	j = 0;
	if (ps->bonus == 1)
	{
		ft_putstr_fd("\n\x1B[35mSTACK A\n", 1);
		ft_print_tab(ps->stack_a, argc);
		ft_putstr_fd("\n\x1B[0m", 1);
	}
	ft_stack_copy(argc, ps);
	i = ft_selection_loop_a(ps, i, j, counter);
	i = ft_selection_a_pivot(i, argc);
	if (i % 2 == 0)
		ps->med = ps->stack_temp_a[i];
	else
		ps->med = ps->stack_temp_a[i];
	free(ps->stack_temp_a);
}
