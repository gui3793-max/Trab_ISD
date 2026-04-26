#include <stdio.h>
#include "lib.h"

void vetora_binario (int bin[], int tam, int binario)
{
    int i;
    for (i = tam - 1; i >= 0 ; i--)
    {
        bin[i] = binario % 10;
        binario = binario / 10;
    }
}

int converte_decimal (int bin[], int tam)
{
    int decimal = 0;
    int i;
    for (i = 0; i < tam; i++)
    {
        decimal = decimal * 2 + bin[i];
    }
    return decimal;
}

/*int converte_hexadecimal (int bin[], int tam)
{
    int i,j,vl,r;
    char map[] ="0123456789ABCDEF";
    r = tam % 4 ;
    
    if(r != 0)
    {
        vl = 0;
        for(i = 0; i< r;i++)
            {
                vl= vl * 2 * bin[i];
            }
        printf("c", map[vl]);
    }
    for(i=r,i< tam; i+=4)
        {
            valor=0;
            for(j=0; j < 4; j++)
                {
                    vl=vl *2 + bin[i+j];
                }
                printf("c", map[vl]);
        }
}*/
                    
        
    
}

void complementa1 (int bin[], int tam)
{
    int i = 0;
    for (i = 0; i < tam; i++)
    {
        if (bin[i] == 0)
        {
            bin[i] = 1;
        }
        else
        {
            bin[i] = 0;
        }
    }
}

void soma (int bin1[], int bin2[], int result_bin[], int tam)
{
    int carry;
    int i;
    carry = 0;
    for (i = tam - 1; i >= 0; i--)
    {
        if ((bin1[i] + bin2[i] + carry) == 1)
        {
            result_bin[i] = 1;
            carry = 0;
        }
        else
        {
            if ((bin1[i] + bin2[i] + carry) == 2)
            {
                result_bin[i] = 0;
                carry = 1;
            }
            else
            {
                if ((bin1[i] + bin2[i] + carry) == 3)
                {
                    result_bin[i] = 1;
                    carry = 1;
                }
                else
                {
                    result_bin[i] = 0;
                    carry = 0;
                }
            }
        }
    }
    if (result_bin[0] == 1 || (result_bin[0] == 0 && carry == 1))
    {
        printf("Overflow\n");
    }
}

void subtrai (int bin1[], int bin2[], int result_bin[], int tam)
{
    int borrow = 0, i;
    for (i = tam - 1; i >= 0; i--)
    {
        if ((bin1[i] - bin2[i] - borrow) == -1)
        {
            result_bin[i] = 1;
            borrow = 1;
        }
        else
        {
            if ((bin1[i] - bin2[i] - borrow) == 1)
            {
                result_bin[i] = 1;
                borrow = 0; 
            }
            else
            {
                result_bin[i] = 0;
                borrow = 0;
            }
            
        }
    }
    
}

int verifica_bin_negativo (int bin[], int tam)
{
    if (bin[0] == 1)
    {
        return 1; /*negativo*/
    }
    return 0; /*positivo*/
}

void copia_para_aux (int bin_primario[], int bin_auxiliar[], int tam)
{
    int i;
    for (i = 0; i < tam; i++)
    {
        bin_auxiliar[i] = bin_primario[i];
    }
}
