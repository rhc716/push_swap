/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_2d_c_arr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 14:56:16 by hroh              #+#    #+#             */
/*   Updated: 2021/02/26 15:01:52 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_2d_c_arr(char **arr)
{
	int		i;
	int		j;
	int		k;
	char	*temp;

	i = -1;
	while (arr[++i])
	{
		j = -1;
		while (arr[++j + 1])
		{
			k = -1;
			while (arr[j][++k] && arr[j + 1][k] && arr[j][k] >= arr[j + 1][k])
			{
				if (arr[j][k] > arr[j + 1][k])
				{
					temp = arr[j + 1];
					arr[j + 1] = arr[j];
					arr[j] = temp;
					break ;
				}
			}
		}
	}
}
