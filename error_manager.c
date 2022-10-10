/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 06:13:46 by rschlott          #+#    #+#             */
/*   Updated: 2022/10/10 08:05:31 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* checks if arguments are not integers */
void	error_manager_int(const char *str)
{
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
		str++;
	if (*str == '-' || *str == '+')
	{
		write(1, "Error! More than one sign.\n", 27);
		exit(0);
	}
	while (*str != '\0')
	{
		if (!(*str > 47 && *str < 58))
		{
			write(1, "Error isn't int\n", 16);
			exit(0);
		}
		str++;
	}
}

/* checks if arguments are duplicates */
void	error_manager_duplicate(struct s_node **a_liste)
{
	struct s_node	*ptr;
	struct s_node	*next;

	ptr = *a_liste;
	next = ptr->link;
	while (ptr->link != NULL)
	{
		while (next != NULL)
		{
			if (ptr->data == next->data)
			{
				write(1, "Error duplicate\n", 16);
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
		if ((convert > 2147483647 && sign == 1) || (convert > 2147483648 && sign == -1))
		{
			write(1, "Error bigger than int\n", 22);
			exit(0);
		}
	}
	return (convert * sign);
}
