/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 13:23:03 by rschlott          #+#    #+#             */
/*   Updated: 2022/08/28 20:19:55 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

/* defines the data structure */
struct node
{
    int data;
    struct node *link;
};

/* converts char to int */
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

/* receiving arguments from user input */
int ft_stack_receive(int argc, char **argv)
{
    int *pt_ints;
    //int *ptr_len;
    int ints;
    int i;

    pt_ints = &ints;
    i = 1;
    struct node *head = NULL;
    /* argc zählt den ersten String in argv mit und der ist immer ./a.out */
    while (i < argc)
    {
        if (i == 1 && argv)
        {
            head = (struct node *)malloc(sizeof(struct node));
            head->data = ft_atoi(argv[i]);
            head->link = NULL;
            printf("Data: %d", head->data);
        }
        //ints = ft_atoi(argv[i]);      //shows the output of ft_atoi
        //printf("input: %d \n", ints);  //to check each input
        *pt_ints = ints;
        i++;
    }
    //printf("loop: %d \n", *pt_ints);   //to check the output after the loop (should be the last entry)
    return(head->data);
}

int main(int argc, char **argv)
{ 
    printf("output main: %d\n", ft_stack_receive(argc, argv));  
    return(0);
}
