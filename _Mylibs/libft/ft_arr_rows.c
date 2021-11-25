#include "libft.h"

int	ft_arr_rows(char **arr)
{
	int	i;
	int j;

	if (!arr)
		return (-1);
	i = 0;
	j = 0;
	while (arr[i])
	{
		if ((int) ft_strlen(arr[i]) > j)
			j = ft_strlen(arr[i]); 
		i++;
	}
	return (j);
}