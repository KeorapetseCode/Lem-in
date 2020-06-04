#include "lem_in.h"
//Checks the string passed (which is the first string of the input file)
//This finction will ignore SPACES, FORM FEED, HORIZONTAL TAB, VERTICAL TAB, AND CARRIAGE RETURN.(ascii decimal 10 to 13)
//Finally it will check if the number is greater than zero and lesser than int_max.

int		 ft_int_max(char *str)
{
	long long	value;
	int			sign;

	value = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\f'
			|| *str == '\r' || *str == '\v')
		str++;
	if (*str == '-')
		sign = -1;
	else
		sign = 1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		value = value * 10 + (*str - '0');
		str++;
	}
	if ((value * sign) <= 2147483647 && (value * sign) >= -2147483648)
		return (1);
	else
		return (0);
}