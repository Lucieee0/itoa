/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusimon <lusimon@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 13:46:47 by lusimon           #+#    #+#             */
/*   Updated: 2025/01/24 18:14:14 by lusimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int count(int number)
{
	int i = 0;
	if (number == 0)
		return 1;
	while (number >= 10)
	{
		number = number / 10;
		i++;
	}
	return (i + 1);
}

char	*ft_itoa(int nbr)
{
	int negative = 0;
	if (nbr < 0)
		negative = 1;
		
	int allocate = count(nbr);
	int final = (allocate);

	char *string;
	string = (char *)malloc(sizeof(char) * (allocate + negative));
	if (!string)
		return (NULL);
	
	while(allocate > 0)
	{
		string[allocate - 1] = (nbr % 10 + '0');
		nbr = nbr / 10;
		allocate--;
	}
	string[final] = '\0';
	return (string);
}

//it is because a string begins at 0 
//the first character of the string is at position 0, so we need to do allocate -1

int main()
{
	int a = 123;
	char *test;
	test = ft_itoa(a);
	printf("%s", test);
	return (0);
}
