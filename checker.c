/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 16:41:54 by hroh              #+#    #+#             */
/*   Updated: 2021/03/12 15:44:57 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_action_call(char *line, t_env *env)
{
	if (ft_strlen(line) == 3 && line[2] == 'a')
		ft_action_rra(env, 1, 0);
	else if (ft_strlen(line) == 3 && line[2] == 'b')
		ft_action_rrb(env, 1, 0);
	else if (ft_strlen(line) == 3 && line[2] == 'r')
		ft_action_rrr(env, 1);
	else if (line[0] == 's' && line[1] == 'a')
		ft_action_sa(env, 1);
	else if (line[0] == 's' && line[1] == 'b')
		ft_action_sb(env, 1);
	else if (line[0] == 's' && line[1] == 's')
		ft_action_ss(env, 1);
	else if (line[0] == 'p' && line[1] == 'a')
		ft_action_pa(env, 1);
	else if (line[0] == 'p' && line[1] == 'b')
		ft_action_pb(env, 1);
	else if (line[0] == 'r' && line[1] == 'a')
		ft_action_ra(env, 1);
	else if (line[0] == 'r' && line[1] == 'b')
		ft_action_rb(env, 1);
	else if (line[0] == 'r' && line[1] == 'r')
		ft_action_rr(env, 1);
}

int		ft_check_cmd(char *line)
{
	int ret;

	ret = 0;
	if (ft_strlen(line) < 2 || ft_strlen(line) > 3)
		ret++;
	if (ft_strncmp(line, "rra", 3) != 0 &&
		ft_strncmp(line, "rrb", 3) != 0 &&
		ft_strncmp(line, "rrr", 3) != 0 &&
		ft_strncmp(line, "ra", 2) != 0 &&
		ft_strncmp(line, "rb", 2) != 0 &&
		ft_strncmp(line, "rr", 2) != 0 &&
		ft_strncmp(line, "pa", 2) != 0 &&
		ft_strncmp(line, "pb", 2) != 0 &&
		ft_strncmp(line, "sa", 2) != 0 &&
		ft_strncmp(line, "sb", 2) != 0 &&
		ft_strncmp(line, "ss", 2) != 0)
		ret++;
	return (ret);
}

int		ft_checker_exit(int err, t_env *env, char *line)
{
	int ret;

	if (err > 0)
		ret = ft_puterr();
	else if (ft_is_ok(env, env->ori_cnt) == 1)
		ret = ft_putmsg("OK\n");
	else
		ret = ft_putmsg("KO\n");
	ft_free_all(env, line);
	return (ret);
}

int		main(int argc, char **argv)
{
	t_env	env;
	int		read_i;
	char	*line;
	int		err;

	if (argc < 2)
		return (0);
	ft_check_argv(argv);
	if (argc == 2)
		return (ft_putmsg("OK\n"));
	err = 0;
	ft_set_env(&env, argc, argv);
	while ((read_i = get_next_line(STDIN_FILENO, &line)) > 0)
	{
		err += ft_check_cmd(line);
		ft_action_call(line, &env);
		free(line);
		line = NULL;
	}
	return (ft_checker_exit(err, &env, line));
}
