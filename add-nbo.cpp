#include <stddef.h> // for size_t
#include <stdint.h> // for uint8_t
#include <stdio.h> // for printfs
#include <netinet/in.h>

int main(int argc, char **argv)
{
    uint32_t num1, num2;
    FILE *f1, *f2 = NULL;

    f1 = fopen(argv[1], "rb");
    if(f1==NULL)
        printf("File open FAIL\n");
    fread(&num1, sizeof(uint32_t), 1, f1);
    num1 = ntohl(num1);

    f2 = fopen(argv[2], "rb");
    if(f2==NULL)
        printf("File open FAIL\n");
    fread(&num2, sizeof(uint32_t), 1, f2);
    num2 = ntohl(num2);

    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", num1, num1, num2, num2, num1+num2, num1+num2);

    fclose(f1);
    fclose(f2);
    return 0;
}
