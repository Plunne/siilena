// MEMO 2 - Les Types
// Pre-requis :
// Memo1_FormattageDeChaines.c
// Notion de conversions binaires
// Decimal      = <valeur>
// Binaire      = 0b<valeur>
// Hexadecimal  = 0x<valeur>
// Octal        = 0<valeur>

#include <stdio.h>

int main(void) {

    /*
        Syntaxe
        <typename> <name>;
    */

    /* Entiers */
    char unOctet = 123;             // 1 Octet = 8 bits
    short deuxOctets = 1234;        // 2 Octet = 16 bits
    int intOctets = 12345;          // 2 Octet = 32 bits
    long longOctet = 12345;         // 4 Octet = 32 bits
    long long tresLong = 123456;    // 8 Octet = 64 bits

    /* Flottants */
    float quatreFlottant = 123.456          // 4 Octets = 32 bits
    double huitFlottant = 1234.5678         // 8 Octets = 64 bits
    long double dixFlottant = 12345.6789    // 10 Octets = 80 bits

    /*
        Determination du signe positif ou negatif
        - signed : valeur signee, le signe +/- est determine grace au MSB (bit de poids fort)
        - unsigned : valeur non signee sur l'entierete des bits
    */

    /*
        Valeurs minimales et maximales signed
        - signed char :         -128 -> 127
        - signed short :        -32 768 -> 32 767
        - signed int :          -32 768 -> 32 767
        - signed long :         -2 147 483 648 -> 2 147 483 647
        - signed long long :    -(2^63 -1) -> 2^63 -1
    */

    /*
        Valeurs minimales et maximales unsigned
        - unsigned char :         0 -> 255
        - unsigned short :        0 -> 65 535
        - unsigned int :          0 -> 65 535
        - unsigned long :         0 -> 4 294 967 295
        - unsigned long long :    0 -> 18 446 744 073 709 551 615
    */

    /*
        Valeurs minimales et maximales flottants
        float :         3.4 x 10^-38 -> 3.4 x 10^38
        double :        1.7 x 10^-308 -> 1.7 x 10^308
        float :         1.7 x 10^-4932 -> 1.7 x 10^4932
    */
    
    printf("char     \n    signed : -%d -> %d       |    unsigned : %u -> %u\n",        0x80,   0x7F, 0x00, 0xFF);
    printf("short    \n    signed : -%d -> %d       |    unsigned : %u -> %u\n",        0x8000, 0x7FFF, 0x0000, 0xFFFF);
    printf("int      \n    signed : -%d -> %d       |    unsigned : %u -> %u\n",        0x8000, 0x7FFF, 0x0000, 0xFFFF);
    printf("long     \n    signed : -%ld -> %ld     |    unsigned : %lu -> %lu\n",      0x80000000, 0x7FFFFFFF, 0x00000000, 0xFFFFFFFF);
    printf("long long\n    signed : %lld -> %lld    |    unsigned : %llu -> %llu\n",    0x8000000000000000, 0x7FFFFFFFFFFFFFFF, 0x0000000000000000, 0xFFFFFFFFFFFFFFFF);
    
    return 0;
}