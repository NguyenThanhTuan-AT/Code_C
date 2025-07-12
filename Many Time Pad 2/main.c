#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int hex_to_int(char c)
{
    if (c >= '0' && c <= '9')
        return c - '0';
    else if (c >= 'a' && c <= 'f')
        return c - 'a' + 10;
    else if (c >= 'A' && c <= 'F')
        return c - 'A' + 10;
    else
        return -1;
}
void hex_to_bytes(const char hex_str[], unsigned char bytes[], int len)
{
    for (int i = 0; i < len; ++i)
        bytes[i] = (hex_to_int(hex_str[2 * i]) << 4) | hex_to_int(hex_str[2 * i + 1]);
}

int main()
{
    //freopen("D:\\Code\\input.txt", "r", stdin);
    int plen, klen;
    scanf("%d", &klen);
    char *key_hex = (char *)malloc(2 * klen + 1);
    if (key_hex == NULL)
    {
        printf("Không đủ bộ nhớ để cấp phát.\n");
        return 1;
    }
    scanf("%s", key_hex);
    scanf("%d", &plen);
    char *plaintext_hex = (char *)malloc(2 * plen + 1);
    if (plaintext_hex == NULL)
    {
        printf("Không đủ bộ nhớ để cấp phát.\n");
        free(key_hex);
        return 1;
    }
    scanf("%s", plaintext_hex);
    unsigned char *plaintext = (unsigned char *)malloc(plen);
    unsigned char *key = (unsigned char *)malloc(klen);
    if (plaintext == NULL || key == NULL)
    {
        printf("Không đủ bộ nhớ để cấp phát.\n");
        free(key_hex);
        free(plaintext_hex);
        free(plaintext);
        free(key);
        return 1;
    }
    hex_to_bytes(plaintext_hex, plaintext, plen);
    hex_to_bytes(key_hex, key, klen);
    for (int i = 0; i < plen; ++i)
        printf("%02X", plaintext[i] ^ key[i % klen]);
    printf("\n");
    free(key_hex);
    free(key);
    free(plaintext_hex);
    free(plaintext);
    fclose(stdin);
    return 0;
}
