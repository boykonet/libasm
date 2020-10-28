#include <stdio.h>
#include <string.h>

//size_t		ft_strlen(const char *s);
//char		*ft_strcpy(char *dst, const char *src);

int		main(void)
{
//	char	buff[10];


//	printf("%zu\n", ft_strlen("aaabbbccc"));
//	printf("%zu\n", strlen("aaabbbccc"));
//	printf("%s\n", ft_strcpy(buff, "aaabbbccc"));
//	printf("%zu\n", ft_strlen(buff));
	printf("%d\n", strcmp("aaabbbccc", "aaabbbccc"));
	printf("%d\n", strcmp("aaabbb\n", "aaabbbccc"));
	printf("%d\n", strcmp("aaabbbccc", "aaabbb\n"));
	return (0);
}
