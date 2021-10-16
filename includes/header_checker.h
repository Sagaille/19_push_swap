/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_checker.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldavids <ldavids@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 15:43:35 by ldavids           #+#    #+#             */
/*   Updated: 2021/04/27 17:24:26 by ldavids          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_CHECKER_H
# define HEADER_CHECKER_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# define TRUE 1
# define FALSE 0

typedef struct s_struct
{
	char		**args_a;
	int			*stack_a;
	int			*stack_b;
	int			elements_a;
	int			ele_b;
	char		*input;
	int			eof;
	char		**tab_input;
	int			i;
	int			bonus;
}					t_struct;

/*
** c_utility00.c
*/
int				ft_atoi_spec(const char *str);
void			ft_error(void);
unsigned int	ft_checkmax(unsigned long nb, int pos);
void			*ft_realloc(void *ptr, size_t size);
char			*ft_strcpy(char *dest, char *src);

/*
** c_utility01.c
*/
void			*ft_calloc_exit(size_t num, size_t size);
void			ft_checker_init(t_struct *checker, int argc);
void			ft_print_stack_a(t_struct *checker, int argc);
void			ft_print_stack_b(t_struct *checker, int argc);
void			ft_ok_ko(t_struct *checker, int argc);

/*
** read.c
*/
char			*getinput(t_struct *checker, int count, char buffer, int ret);
void			loop_prompt(t_struct *checker, int argc);

/*
** cmds.c
*/
void			ft_cmds_rest(t_struct *checker, int argc, int i);
void			ft_cmds(t_struct *checker, int argc);
int				ft_check_cmds(char *str);

/*
** operators00.c
*/
void			ft_sa(t_struct *checker);
void			ft_sb(t_struct *checker);
void			ft_ss(t_struct *checker);
void			ft_pa(t_struct *checker, int argc);
void			ft_pb(t_struct *checker, int argc);

/*
** operators01.c
*/
void			ft_ra(t_struct *checker);
void			ft_rb(t_struct *checker);
void			ft_rr(t_struct *checker);

/*
** operators02.c
*/
void			ft_rra(t_struct *checker);
void			ft_rrb(t_struct *checker);
void			ft_rrr(t_struct *checker);

/*
** bonus.c
*/
char			**ft_relocate(int argc, char **argv);
int				ft_bonus(int argc, char **argv, t_struct *checker);
void			ft_loop_bonus(t_struct *checker, int argc);

#endif
