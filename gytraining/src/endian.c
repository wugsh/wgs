uint32_t endian_conv(uint32_t x)
{
	return ((x & 0x000000ffUL) << 24) |
	       ((x & 0x0000ff00UL) << 8) |
	       ((x & 0x00ff0000UL) >> 8) |
	       ((x & 0xff000000UL) >> 24);
}
