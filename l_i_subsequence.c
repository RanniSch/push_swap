/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_i_subsequence.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 22:45:09 by rschlott          #+#    #+#             */
/*   Updated: 2022/06/15 00:05:15 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

int    *ft_one_calloc(int argc, int size)
{
    int    *ptr;
    int     i;

    /*if ((argc - 1) == 0 || size == 0)
    {
        (argc - 1) = 1;
        size = 4;
    }*/
    /*if ((argc - 1) >= __SIZE_MAX__ || size >= __SIZE_MAX__)
        return (0);*/
    ptr = malloc((argc - 1) * size);
    if (!ptr)
        return (NULL);
    i = 0;
    while (i < (argc - 1))
    {
        ptr[i] = 1;
        i++;
    }
    return (ptr);
}

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
    int    *ptr_len;
    int length[argc - 1];

    ptr_len = &length[0];

    j = 0;
    i = 1;
    ptr_len = *ft_one_calloc(argc, 4);
    while (i <= argc - 1)
    {
        j = 0;
        while (j < i)
        {
            if (ints[j] < ints[i])
        {
            ptr_len[i] = ptr_len[j] + 1;
        }
            j++;
        }
        i++;        
    }
    return (0);         // hier muss noch was anderes hin! Pointer zu length!
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
