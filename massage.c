/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   massage.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 19:03:13 by hroh              #+#    #+#             */
/*   Updated: 2021/03/10 21:07:37 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_puterr(void)
{
	write(STDERR_FILENO, "Error\n", 6);
	return (1);
}

int	ft_putmsg(char *str)
{
	write(STDOUT_FILENO, str, ft_strlen(str));
	return (0);
}
