bool is_prime(unsigned long long value) {
	for (unsigned long long i = 2;i <= value / 2;i++)
	{
		if (value % i == 0)
		{
			return false;
		}
	}

	return true;
}