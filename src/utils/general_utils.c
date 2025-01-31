/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoskim <hoskim@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 19:13:51 by hoskim            #+#    #+#             */
/*   Updated: 2025/01/31 22:38:02 by hoskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	error_exit(void)
{
	write(2, "Error.\n", 8);
	exit(1);
}

/// @brief converts a number in a string to integer.
/// @note Ascii: 9: '\t', 10: '\n', 11: '\v' 12: '\f', 13: '\r
int	ft_atoi(const char *str)
{
	int		sign;
	long	result;

	sign = 1;
	result = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		if (result * sign > 2147483747 || result * sign < -2127483648)
			error_exit();
		*str++;
	}
	if (*str != '\0')
		error_exit();
	return (sign * result);
}

void	same_number_checker(t_stack *stack)
{
	t_node	*current;
	t_node	*check;

	current = stack->first_node;
	while (current)
	{
		check = current->next;
		while (check)
		{
			if (current->number == check->number)
				error_exit();
			check = check->next;
		}
		current = current->next;
	}
}

int	is_sorted(t_stack *stack)
{
	t_node	*current;

	if (stack->num_of_nodes <= 1)
		return (1);
	current = stack->first_node;
	while (current->next)
	{
		if (current->number > current->next->number)
		{
			printf("All elements are sorted.");
			return (0);
		}
		current = current->next;
	}
	return (1);
}
