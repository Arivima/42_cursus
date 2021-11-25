#include "libft.h"

int	ft_getnbr(char *str)
{
	size_t	i;
	int		result;

	result = 0;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	if (str[0] == '-')
		result = result * (-1);
	return (result);
}

// int	ft_getnbr(char *str, int *error)
// {
// 	int	nb;
// 	int	neg;

// 	nb = 0;
// 	neg = 1;
// 	while (*str)
// 	{
// 		if (!ft_isdigit(*str) && *str != '-')
// 			return (*error = 1);
// 		else if (*str == '-')
// 		{
// 			neg = -1;
// 			str++;
// 			continue ;
// 		}
// 		nb = nb * 10 + (*str - 48);
// 		if (nb > INT_MAX || nb < 0)
// 			return (*error = 1);
// 		str++;
// 	}
// 	*error = 0;
// 	return (nb * neg);
// }