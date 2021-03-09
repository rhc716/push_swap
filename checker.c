/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 16:41:54 by hroh              #+#    #+#             */
/*   Updated: 2021/03/09 22:10:28 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	// argc 2부터 인자들이 int 값 범위의 숫자로 되어있는지 확인
	// argc == 2 이면 OK\n
	
	// 표준출력을 gnl로 읽음
	// 표준출력에 Error 일 경우
/*****************************************************/
	int i = 0;
	printf("%d\n", argc);
	while (++i < argc)
		printf("argv[%d] : %s\n", i, argv[i]);
/*****************************************************/

	return (0);
}
