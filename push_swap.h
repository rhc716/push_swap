/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 16:59:21 by hroh              #+#    #+#             */
/*   Updated: 2021/03/10 21:10:23 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "./libft/libft.h"

typedef struct	s_env
{
	char		**arr_a;
	char		**arr_b;
	int			a_cnt;
	int			b_cnt;
	int			ori_cnt;
	int			lowest;
	int			lowest_pos;
}				t_env;

void			ft_check_argv(char **argv);
int				ft_puterr(void);
char			**ft_make_arr_a(int argc, char **argv);
char			**ft_make_arr_b(int argc);
void			ft_action_sa(t_env *env, int mute);
void			ft_action_sb(t_env *env, int mute);
void			ft_action_ss(t_env *env, int mute);
void			ft_action_pa(t_env *env, int mute);
void			ft_action_pb(t_env *env, int mute);
void			ft_action_ra(t_env *env, int mute);
void			ft_action_rb(t_env *env, int mute);
void			ft_action_rr(t_env *env, int mute);
void			ft_action_rra(t_env *env, int mute, int push_call);
void			ft_action_rrb(t_env *env, int mute, int push_call);
void			ft_action_rrr(t_env *env, int mute);
void			ft_set_env(t_env *env, int argc, char **argv);
void			ft_sort(t_env *env);
void			ft_find_lowest(t_env *env);
int				ft_putmsg(char *str);
void			ft_free_all(t_env *env, char *line);
#endif
