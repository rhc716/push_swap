/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 16:59:21 by hroh              #+#    #+#             */
/*   Updated: 2021/03/14 14:37:16 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct	s_env
{
	char		**arr_a;
	char		**arr_b;
	int			a_cnt;
	int			b_cnt;
	int			ori_cnt;
	int			a_min;
	int			a_min_pos;
	int			a_max;
	int			before_pb_rb;
	int			before_pb_ra;
	int			pb_pos;
	int			b_min;
	int			b_min_pos;
	int			b_max_pos;
	int			save_ra;
	int			save_rb;
	int			save_cost;
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
int				ft_find_a_min(t_env *env, int end);
int				ft_putmsg(char *str);
void			ft_free_all(t_env *env, char *line);
int				ft_is_ok(t_env *env, int end);
void			ft_sort_3_num(t_env *env);
void			ft_sort_5_num(t_env *env, int num);
int				ft_find_b_max(t_env *env);
int				ft_is_b_desc(t_env *env);
int				ft_find_pb_pos(t_env *env, int a);
int				ft_get_rb_cnt(t_env *env, int a);
void			ft_sort_big(t_env *env);
#endif
