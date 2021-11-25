#include "libft.h"

# define BLACK (0x00000000)
# define WHITE (0x00FFFFFF)
# define RED (0x00FF0000)
# define GREEN (0x00008000)
# define YELLOW (0x00FFFF00)
# define BLUE (0x000000FF)

int		ft_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}