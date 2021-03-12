/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 19:02:16 by hroh              #+#    #+#             */
/*   Updated: 2021/03/11 15:53:02 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_isnum_argv(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[++i])
	{
		j = -1;
		while (argv[i][++j])
		{
			if (j == 0 && !ft_isdigit(argv[i][0]) && !(argv[i][0] == '-'))
				return (0);
			if (j > 0 && !ft_isdigit(argv[i][j]))
				return (0);
		}
	}
	return (1);
}

int		ft_check_duplicate(char **argv)
{
	int i;
	int j;
	int len_i;
	int len_j;

	i = 0;
	while (argv[++i])
	{
		len_i = ft_strlen(argv[i]);
		j = i;
		while (argv[++j])
		{
			len_j = ft_strlen(argv[j]);
			if (len_i >= len_j && ft_strncmp(argv[i], argv[j], len_i) == 0)
				return (0);
			if (len_i < len_j && ft_strncmp(argv[i], argv[j], len_j) == 0)
				return (0);
		}
	}
	return (1);
}

int		ft_isint_argv(char **argv)
{
	int		i;
	long	num;

	i = 0;
	while (argv[i])
	{
		num = ft_atoi_long(argv[i]);
		if (num > 2147483647 || num < -2147483648)
			return (0);
		i++;
	}
	return (1);
}

int		ft_is_ok(t_env *env, int end)
{
	int i;

	i = 0;
	if (end == env->ori_cnt && (env->a_cnt != env->ori_cnt || env->b_cnt != 0))
		return (0);
	while (env->arr_a[i] && env->arr_a[i + 1] && i + 1 < end)
	{
		if (env->arr_a[i][0] == 'B' || env->arr_a[i + 1][0] == 'B')
			return (0);
		if (ft_atoi(env->arr_a[i]) > ft_atoi(env->arr_a[i + 1]))
			return (0);
		i++;
	}
	return (1);
}

void	ft_check_argv(char **argv)
{
	if (!ft_isnum_argv(argv) ||
		!ft_check_duplicate(argv) ||
		!ft_isint_argv(argv))
		exit(ft_puterr());
}
