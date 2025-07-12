#include <stdio.h>
#include <stdlib.h>

int main()
{
    char plaintext, ciphertext;
    unsigned int key;
    scanf("%c %u", &plaintext, &key);
    if (plaintext >= 'a' && plaintext <= 'z')
    {
        plaintext = plaintext - 32;
    }
    ciphertext = (plaintext - 'A' + key) % 26 + 'A';
    printf("%c\n", ciphertext);

    return 0;
}
