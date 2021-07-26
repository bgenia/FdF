char	ft_basedigit(unsigned int n, unsigned int base)
{
	if (base > 36)
		base = 36;
	if (n % base < 10)
		return ('0' + (n % base));
	return ('a' + ((n % base) - 10));
}
