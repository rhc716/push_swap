/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_number.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 01:28:10 by cbaek             #+#    #+#             */
/*   Updated: 2021/03/14 15:15:30 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>
#include "../../libft/libft.h"

void	ft_random_arr(int count, int *nums)
{
	int	i;
	int	temp;
	int	ran1;
	int	ran2;

	i = -1;
	while (++i < count)
		nums[i] = i + 1;
	i = -1;
	while (++i < count * 2)
	{
		ran1 = rand() % count;
		ran2 = rand() % count;
		temp = nums[ran1];
		nums[ran1] = nums[ran2];
		nums[ran2] = temp;
	}
}

int		main(int argc, char **argv)
{
	int				count;
	int				*nums;
	struct timeval	time;
	int				i;

	if (argc != 2)
		return (0);
	gettimeofday(&time, NULL);
	srand((time.tv_sec * 1000) + (time.tv_usec / 1000));
	count = ft_atoi(argv[1]);
	if (!(nums = (int *)malloc(sizeof(int) * count)))
		return (0);
	ft_random_arr(count, nums);
	i = -1;
	while (++i < count)
		printf("%d ", nums[i]);
	printf("\n");
	free(nums);
	return (0);
}
