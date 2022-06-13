/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_i_subsequence.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 22:45:09 by rschlott          #+#    #+#             */
/*   Updated: 2022/06/13 23:06:05 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>

int	ft_atoi(const char *str)
{
	int			sign;
	long int	convert;

	sign = 1;
	convert = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = sign * (-1);
		str++;
	}
	while (*str && *str > 47 && *str < 58)
	{
		convert = (convert * 10) + *str - '0';
		str++;
		if (convert > 2147483647 && sign == 1)
			return (-1);
		if (convert > 2147483648 && sign == -1)
			return (0);
	}
	return (convert * sign);
}

int ft_l_i_subsequence(int argc, int *ints)
{
    int i;
    int j;
    int *len;
    int length;

    j = 0;
    i = 1;
    length = 1;
    len = &length[0];
    while (i <= argc - 1)
    {
        if (ints[j] < ints[i])
        {
            length[i] = length[j] + length[i];
        }
        else
        {
            i++
        }
    }
}

int *ft_stack_receive(int argc, char **argv)
{
    int *pointer;
    int ints[argc - 1];
    int convert;
    int i;

    pointer = &ints[0];
    i = 1;
    while (i < argc)        // argc zählt den ersten String in argv mit und der ist immer ./a.out
    {
        convert = ft_atoi(argv[i]);
        ints[i - 1] = convert;
        ft_l_i_subsequence(argc, ints[i - 1]);
        printf("loop:%d", ints[i - 1]);
        i++;
    }
    return(pointer);
}

int main(int argc, char **argv)
{ 
    printf("sequence of 2, 1, 3, 6, 5, 8 = %d\n", *ft_stack_receive(argc, argv));  
    return(0);
}
