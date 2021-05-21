/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avilla-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 13:25:16 by avilla-m          #+#    #+#             */
/*   Updated: 2021/04/22 18:50:14 by avilla-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdarg.h>
# include <unistd.h>

typedef struct s_flg
{
	int	int_sign;
	int	width;
	int	precision;
	int	only_dot;
}				t_flg;


int		ft_strlen(const char *s)
{
	int	n;

	n = 0;
	while (*s++)
		n++;
	return (n);
}

int		nbr_len(long n, int base)
{
	int	i;

	if (base == 10 && n < 0)
		n *= -1;
	i = 1;
	while (n > (base - 1))
	{
		n /= base;
		i++;
	}
	return (i);
}


void	put_str(char **str, int *n_ch)
{
	write(1, (*str)++, 1);
	(*n_ch)++;
}

void	put_char(int c, int *n_ch)
{
	write(1, &c, 1);
	(*n_ch)++;
}

void	put_nbr(int n, int *n_ch)
{
	long int		long_n;

	if (n < 0)
		long_n = -(long int)n;
	else
		long_n = n;
	if (long_n > 9)
	{
		put_nbr(long_n / 10, n_ch);
		put_char((long_n % 10) + '0', n_ch);
	}
	else
		put_char((long_n % 10) + '0', n_ch);
}

void	put_nbr_hx(unsigned long n, int *n_ch)
{
	char	n_hx;

	if (n)
	{
		n_hx = "0123456789abcdef" [n % 16];
		put_nbr_hx((unsigned long) n / 16, n_ch);
		put_char(n_hx, n_ch);
	}
}


void	print_hex(t_flg *flg, unsigned int n, int *n_ch)
{
	int	n_len;
	int	padding;
	int	zero_p;

	n_len = nbr_len((unsigned long) n, 16);
	zero_p = flg->precision - n_len;
	if (zero_p < 0)
		zero_p = 0;
	padding = flg->width - n_len - zero_p;
	if (padding < 0)
		padding = 0;
	if (n == 0 && flg->only_dot == 1)
		padding = flg->width;
	while (padding--)
		put_char(' ', n_ch);
	while (zero_p--)
		put_char('0', n_ch);
	if (!(n == 0 && flg->only_dot == 1))
		put_nbr_hx((unsigned long) n, n_ch);
	if (n == 0 && !flg->only_dot)
		put_char('0', n_ch);
}

void	print_int(t_flg *flg, int n, int *n_ch)
{
	int		n_len;
	int		padding;
	int		zero_p;

	flg->int_sign = n < 0;
	n_len = nbr_len((long)n, 10);
	if (n < 0)
		n *= -1;
	zero_p = flg->precision - n_len;
	if (zero_p < 0)
		zero_p = 0;
	padding = flg->width - n_len - zero_p - flg->int_sign;
	if (padding < 0)
		padding = 0;
	if (n == 0 && flg->only_dot == 1)
		padding = flg->width;
	while (padding--)
		put_char(' ', n_ch);
	if (flg->int_sign)
		put_char('-', n_ch);
	while (zero_p--)
		put_char('0', n_ch);
	if (!(n == 0 && flg->only_dot == 1))
		put_nbr(n, n_ch);
}

void	print_str(t_flg *flg, char *str, int *n_ch)
{
	int		str_len;

	if (!str)
		str = "(null)";
	str_len = ft_strlen(str);
	if (flg->width)
	{
		if (flg->precision > -1 && flg->precision < str_len)
			flg->width -= flg->precision;
		else
			flg->width -= str_len;
		if (flg->width < 0)
			flg->width = 0;
		while ((flg->width)--)
			put_char(' ', n_ch);	
	}
	if (flg->precision > -1 && flg->precision < str_len)
		str_len = flg->precision;
	while (str_len--)
		put_str(&str, n_ch);
}


void	set_width(const char **in, t_flg *flg, va_list ap)
{
	if (**in == '*')
	{
		flg->width = va_arg(ap, int);
		if (flg->width < 0)
			flg->width *= -1;
		(*in)++;
	}
	else if ((**in >= '0' && **in <= '9'))
	{
		if (**in == '0')
			(*in)++;
		while (**in >= '0' && **in <= '9')
		{
			flg->width *= 10;
			flg->width += **in - '0';
			(*in)++;
		}
	}
}

void	set_only_dot(t_flg *flg)
{
	flg->only_dot = 1;
	flg->precision = 0;
}

void	set_precision(const char **in, t_flg *flg, va_list ap)
{
	(*in)++;
	if (**in == '*')
	{
		flg->precision = va_arg(ap, int);
		if (flg->precision < 0)
			flg->precision = -1;
		(*in)++;
	}
	else if ((**in >= '0' && **in <= '9'))
	{
		flg->precision = 0;
		while (**in >= '0' && **in <= '9')
		{
			flg->precision *= 10;
			flg->precision += **in - '0';
			(*in)++;
		}
	}
	else
		set_only_dot(flg);
	if (flg->precision == 0)
		set_only_dot(flg);
}


void	print_arg(const char **in, t_flg flg, va_list ap, int *n_ch)
{
	if (**in == 's')
		print_str(&flg, va_arg(ap, char *), n_ch);
	else if (**in == 'd')
		print_int(&flg, va_arg(ap, int), n_ch);
	else if (**in == 'x')
		print_hex(&flg, va_arg(ap, unsigned int), n_ch);
	else
		*n_ch = -1;
	(*in)++;
}

void	init_flg(t_flg *flg)
{
	flg->int_sign = 0;
	flg->width = 0;
	flg->precision = -1;
	flg->only_dot = 0;
}

void	set_flg(const char **in, t_flg *flg, va_list ap)
{
	init_flg(flg);
	if (**in == '*' || (**in >= '0' && **in <= '9'))
		set_width(in, flg, ap);
	if (**in == '.')
		set_precision(in, flg, ap);
}

void	print_in(const char **in, va_list ap, int *n_ch)
{
	t_flg	flg;

	while (**in)
	{
		if (**in == '%')
		{
			(*in)++;
			set_flg(in, &flg, ap);
			print_arg(in, flg, ap, n_ch);
			if (*n_ch == -1)
				return ;
		}
		else
			put_str((char **)in, n_ch);
	}
}

int		ft_printf(const char *in, ...)
{
	va_list	ap;
	int		n_ch;

	if (!in)
		return (-1);
	n_ch = 0;
	va_start(ap, in);
	print_in(&in, ap, &n_ch);
	va_end(ap);
	return (n_ch);
}
