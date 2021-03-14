/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_checker_param.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 01:28:10 by cbaek             #+#    #+#             */
/*   Updated: 2021/03/12 22:08:48 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>

static int	ft_atoi(const char *str)
{
	int	idx;
	int	result;
	int	sign;

	idx = 0;
	result = 0;
	sign = 0;
	while (str[idx] == ' ' || (str[idx] > 8 && str[idx] < 14))
		idx++;
	if (str[idx] == '+' || str[idx] == '-')
		sign = -(str[idx++] - 44);
	if (str[idx] >= '0' && str[idx] <= '9')
	{
		if (sign == 0)
			sign = 1;
		while (str[idx] >= '0' && str[idx] <= '9')
			result = (result * 10) + (str[idx++] - '0');
	}
	return (sign * result);
}
int main(int argc, char **argv)
{
    struct timeval time; 
    gettimeofday(&time,NULL);
    srand((time.tv_sec * 1000) + (time.tv_usec / 1000));

	int count;
	int *nums;
	if (argc == 2)
		count = ft_atoi(argv[1]);
	else
		count = 10;
	if (!(nums = (int *)malloc(sizeof(int) * count)))
		return (0);
	int temp;
	int ran1;
	int ran2;

	for (int i = 0; i < count; i++)
	{
		nums[i] = i + 1;
	}
	for (int i = 0; i < count * 2; i++)
	{
		ran1 = rand()%count;
		ran2 = rand()%count;
		temp = nums[ran1];
		nums[ran1] = nums[ran2];
		nums[ran2] = temp;
	}
	for (int i = 0; i < count; i++)
	{
		printf("%d ", nums[i]);
	}
	printf("\n");
	free(nums);
	return (0);
}
