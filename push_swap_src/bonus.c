/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldavids <ldavids@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 21:24:02 by ldavids           #+#    #+#             */
/*   Updated: 2021/04/27 21:24:47 by ldavids          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_push.h"

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

int	ft_bonus(int argc, char **argv, t_struct *ps)
{
	ps->bonus = 0;
	if (argc == 2 && (ft_strncmp(argv[1], "-v", 3) == 0 || \
	 ft_strncmp(argv[1], "-c", 3) == 0))
		exit(EXIT_SUCCESS);
	if (ft_strncmp(argv[1], "-v", 3) == 0)
		ps->bonus = 1;
	if (ft_strncmp(argv[1], "-c", 3) == 0)
		ps->bonus = 2;
	if (ps->bonus == 0)
		return (1);
	else
		return (0);
}
