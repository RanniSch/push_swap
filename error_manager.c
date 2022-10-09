/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 06:13:46 by rschlott          #+#    #+#             */
/*   Updated: 2022/10/09 06:21:04 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* checks if arguments are not integers */
void    error_manager_int(const char *str)
{
    while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
		str++;
    if (*str == '-' || *str == '+')
    {
        printf("Error1\n");
        exit (0);
    }
    while (*str != '\0')
    {
        if (!(*str > 47 && *str < 58))
        {
            printf("Error isn't int\n");
            exit (0);
        }
        str++;
    }
}

/* checks if arguments are duplicates */
void    error_manager_duplicate(struct node **a_liste)
{
    struct node *ptr;
    struct node *next;
    ptr = *a_liste;
    next = ptr->link;
    while (ptr->link != NULL)
    {
        while (next != NULL)
        {
            if (ptr->data == next->data)
            {
                printf("Error duplicate\n");
                exit(0);
            }
            else
                next = next->link;
        }
        ptr = ptr->link;
        next = ptr->link;
    }
}

/* modified with checker if arguments are bigger than an integer */
int ft_atoi(const char *str)
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
		if ((convert > 2147483647 && sign == 1) || (convert > 2147483648 && sign == -1))
        {
            printf("Error bigger than int\n");
            exit (0);
        }
	}
	return (convert * sign);
}
