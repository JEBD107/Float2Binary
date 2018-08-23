#include <stdio.h>

int main()
{
    //Numero Ingresado y Parte decimal.
    float num,dec;
    //Arreglo de parte entera y real en binario, exponente y signo.
    int be[32],s,exp[8],br[32],res[32];
    //Auxiliares
    int i=0,j,n,e,c,e2,k;
    //Iniciar valores en 0
    for(j=0;j<32;j++)
    {
        be[j]=0;
        br[j]=0;
        res[j]=0;
    }

    printf("\n Ingrese un numero: ");
    scanf("%f",&num);

    //Obtener el signo
    if(num<0)
    {
        num=-num;
        s=1;
    }
    else
        s=0;

    printf("\n%d\n",s);
    //Parte entera
    n=(int)num;
    //Parte decimal
    dec=num-n;
    //Numero sin parte entera c=1
    c=n==0?1:0;

    //Convertir entero a binario
    do
    {
        be[i++]=n%2;
        n=n/2;
    }while(n!=0);

    for(j=i-1;j>=0;j--)
        printf("%d",be[j]);
    printf("\n");

    //Convertir decimal a binario
    for(j=0;j<=23;j++)
    {
        br[j]=(int)(2.0*dec);
        dec=2*dec-(int)(2*dec);
    }

    for(j=0;j<=23;j++)
        printf("%d",br[j]);
    printf("\n");

    //Calcular el exponente
    if(c==0)
        e=i-1;
    else
    {
        for(j=0;j<=23;j++)
        {
            if(br[j]==1)
                break;
        }
        e=-(j+1);
        e2=-e;
    }
    e=e+127;
    for(j=0;j<8;j++)
    {
        exp[j]=e%2;
        e=e/2;
    }

    for(j=7;j>=0;j--)
        printf("%d",exp[j]);
    printf("\n");

    //Resultado
    res[0]=s;
    for(j=7;j>=0;j--)
        res[8-j]=exp[j];
    if(c==1)
    {
        //sin entero
        k=9;
        for(j=e2;j<=23;j++)
            res[k++]=br[j];
        for(j=k;j<=31;j++)
            res[j]=0;
    }
    else
    {
        printf("\n%d\n",i);
        k=9;
        for(j=i-2;j>=0;j--)
            res[k++]=be[j];
        j=k;
        k=0;
        for(;j<32;j++)
            res[j]=br[k++];
    }
    for(j=0;j<=31;j++)
        printf("%d",res[j]);
    return 0;
}
