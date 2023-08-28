// RGB To Hex Conversion

// The rgb function is incomplete. Complete it so that passing in RGB decimal values will result in a hexadecimal representation being returned. Valid decimal values for RGB are 0 - 255. Any values that fall out of that range must be rounded to the closest valid value.

// Note: Your answer should always be 6 characters long, the shorthand with 3 will not work here.
// Examples (input --> output):

// 255, 255, 255 --> "FFFFFF"
// 255, 255, 300 --> "FFFFFF"
// 0, 0, 0       --> "000000"
// 148, 0, 211   --> "9400D3"

void rgb (int r, int g, int b, char hex[6 + 1])
{
	if (r < 0)
		r = 0;
	else if (r > 255)
		r = 255;
	if (g < 0)
		g = 0;
	else if (g > 255)
		g = 255;
	if (b < 0)
		b = 0;
	else if (b > 255)
		b = 255;
	hex[0] = "0123456789ABCDEF"[r / 16];
	hex[1] = "0123456789ABCDEF"[r % 16];
	hex[2] = "0123456789ABCDEF"[g / 16];
	hex[3] = "0123456789ABCDEF"[g % 16];
	hex[4] = "0123456789ABCDEF"[b / 16];
	hex[5] = "0123456789ABCDEF"[b % 16];
	hex[6] = '\0';
}

// #include <stdio.h>

// int main()
// {
// 	int	r;
// 	int	g;
// 	int b;
// 	char hex[7];

// 	r = -20;
// 	g = 275;
// 	b = 125;
// 	rgb(r, g, b, hex);
// 	printf("%s\n", hex);
// }

// int rgb(int r, int g, int b, char *output)
// {
//    r = r > 255 ? 255 : r < 0 ? 0 : r; //if r > 255 -> r = 255 else if r < 0 -> r = 0;
//    g = g > 255 ? 255 : g < 0 ? 0 : g;
//    b = b > 255 ? 255 : b < 0 ? 0 : b;

//    sprintf(output, "%02.2X%02.2X%02.2X", r, g, b);

//    return 0;
// }
