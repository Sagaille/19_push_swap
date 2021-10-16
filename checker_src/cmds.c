/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldavids <ldavids@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 17:20:13 by ldavids           #+#    #+#             */
/*   Updated: 2021/04/27 15:12:03 by ldavids          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_checker.h"

void	ft_cmds_rest(t_struct *checker, int argc, int i)
{
	if (strncmp(checker->tab_input[i], "sa", 3) == 0)
		ft_sa(checker);
	else if (strncmp(checker->tab_input[i], "sb", 3) == 0)
		ft_sb(checker);
	else if (strncmp(checker->tab_input[i], "ss", 3) == 0)
		ft_ss(checker);
	else if (strncmp(checker->tab_input[i], "pa", 3) == 0)
		ft_pa(checker, argc);
	else if (strncmp(checker->tab_input[i], "pb", 3) == 0)
		ft_pb(checker, argc);
	else if (strncmp(checker->tab_input[i], "ra", 3) == 0)
		ft_ra(checker);
	else if (strncmp(checker->tab_input[i], "rb", 3) == 0)
		ft_rb(checker);
	else if (strncmp(checker->tab_input[i], "rr", 3) == 0)
		ft_rr(checker);
	else if (strncmp(checker->tab_input[i], "rra", 3) == 0)
		ft_rra(checker);
	else if (strncmp(checker->tab_input[i], "rrb", 3) == 0)
		ft_rrb(checker);
	else if (strncmp(checker->tab_input[i], "rrr", 3) == 0)
		ft_rrr(checker);
}

void	ft_cmds(t_struct *checker, int argc)
{
	int		i;

	i = 0;
	while (i < checker->i && checker->tab_input[i])
	{
		ft_cmds_rest(checker, argc, i);
		i++;
	}
}

int	ft_check_cmds_rest(char *str)
{
	if (strncmp(str, "rr", 3) == 0)
		return (1);
	if (strncmp(str, "rb", 3) == 0)
		return (1);
	if (strncmp(str, "rra", 4) == 0)
		return (1);
	if (strncmp(str, "rrb", 4) == 0)
		return (1);
	if (strncmp(str, "rrr", 4) == 0)
		return (1);
	if (strncmp(str, "rr", 3) == 0)
		return (1);
	else
		return (0);
}

int	ft_check_cmds(char *str)
{
	if (strncmp(str, "sa", 3) == 0)
		return (1);
	if (strncmp(str, "sb", 3) == 0)
		return (1);
	if (strncmp(str, "ss", 3) == 0)
		return (1);
	if (strncmp(str, "pa", 3) == 0)
		return (1);
	if (strncmp(str, "pb", 3) == 0)
		return (1);
	if (strncmp(str, "ra", 3) == 0)
		return (1);
	if (ft_check_cmds_rest(str) == 1)
		return (1);
	else
		return (0);
}
