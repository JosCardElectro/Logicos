#include <iostream>
#include <string.h>
#include <math.h>
int num2dec(char *n,int base);//Cualquier Base a decimal
int hex_dec(char hexnum[]);//Auxiliar de num2dec
void dec_xbase(int dec,char *num,int base);//Decimal a cualquier base
void Hex_Bin(char *hexdec);//Hexadecimal a Binario
void Bin_Hex();
using namespace std;

int main()
{
bool bandera=false;
char tecla;

do
    {
        cin.clear();

        cout << "\n Conversor" << endl;

        cout << "-----------" << endl << endl;

        cout << "\t1 .- Cualquier Base a Decimal" << endl;

        cout << "\t2 .- Decimal a Cualquier Base" << endl;

        cout << "\t3 .- Hexadecimal a Binario" << endl;

        cout << "\t4 .- Binario a Hexadecimal" << endl;

        cout << "\t5 .- Salir" << endl << endl;

        cout << "Elije una opcion: ";

        cin >> tecla;

        switch(tecla)

		{

case '1':
            cout << "X Base - Decimal.\n";
    int b;
    char num[65];
    char *n;
    n=num;
    printf("Numero:\n");
    scanf("%s",num);
	cout<<"Base:"<<endl;
    cin>>b;

    if(b==16){
        cout << hex_dec(num) << endl;

    }else{
        cout<<num2dec(n,b)<<endl;
    }

				break;
case '2':

            cout << "Decimal- X Base.\n";
    int d1,b1;
    char num1[650];
    cout<<"Decimal:"<<endl;
    cin>>d1;
    cout<<"Base:"<<endl;
    cin>>b1;
    dec_xbase(d1,num1,b1);

				break;
case '3':
            cout << "Hexadecimal-Binario .\n";
    char hexdec[1000];
    cout<<"Numero :"<<endl;
    cin>>hexdec;
    cout << "\n El Valor en Bibario es : " ;
    Hex_Bin(hexdec);
                break;
case '4':
            cout << "Binario-Hexadecimal.\n";
        Bin_Hex();
				break;



			case '5':

				bandera=true;


				break;



			default:
                cout << "Opcion no valida.\a\n";
                break;
        }

    }while(bandera!=true);
            return 0;
}

void pausa()
{
    cout << "Pulsa una tecla para continuar...";

    getwchar();

    getwchar();

}
int hex_dec(char hexVal[])//Hex a decimal
{
    for (int indice = 0; hexVal[indice] != '\0'; ++indice){
		hexVal[indice] = toupper(hexVal[indice]);
	}
    int len = strlen(hexVal);
    int base = 1;//Inicializar el valor de la base en 1, i.e 16^0
    int dec_val = 0;//Evitar datos basura.

    for (int i=len-1; i>=0; i--) // Se extraen los caracteres (tamaño - 1)
    {
        if (hexVal[i]>='0' && hexVal[i]<='9')// los caractares de 0 a 9 se convierten sustrallendo el valor en ASCII -48
        {
            dec_val += (hexVal[i] - 48)*base;//HexVal-48, donde HexVal={0...9} en ACII 48=0 y susecivamente
                        base *= 16;// se incrementa la base en 16--> cada ciclo da 16*16=16^2=16^n
            }   else if (hexVal[i]>='A' && hexVal[i]<='F')// Rango exadecimal A hasta F ó 10-15
        {
            dec_val += (hexVal[i] - 55)*base;//HexVal-55= {A...F}-55, donde A-F=65-70 en ASCII
                        base *=16;// 16*16=16^n
        }
        //cout<<"\n Hexa : "<<hexVal[i]<<"\n Base:"
          //  <<base<<"\n Hexa - 55 : "<<hexVal[i]-55<<"\n valor: "<<dec_val<<endl;
    }
    cout<<"Decimal: ";
    return dec_val;
}
    int num2dec(char *n,int base)//Funcion para X Base a decimal
    {
        unsigned int dec=0, len; //Variables sin signo enteros
        len = strlen(n)-1;//>Tamaño - 1
        for(int bit=0; bit<=len; bit++){
        dec+=(n[len-bit]-48)*pow(base,bit);// Valor_ACII - 48 ¿Que instruccion hace que trabaje en ASCII?, ¿Como sabe el pc?
      //  printf("Op %i : %d\n",bit,num[len-bit]);
        // printf("Paso %i : %d\n",bit,n[len-bit]-48);
            }
    printf("Decimal: %d \n");
    return dec;
}
void dec_xbase(int dec,char *num,int base) //Decimal a x Base
{
    int i = 0;//Cuando defino aux, error sepmetation fault.
      while (dec > 0)
        {
         num[i] = (dec % base);
         //cout<<"paso:"<<num[i]<<endl;
            if(num[i]<=9){
                num[i]+=48;
                }else{
                num[i]+=55;
                    }
         dec= dec / base;
         i++;
     }
     int len=strlen(num);
     char aux[650];
     cout<<"El numero es: ";
      for ( int j = i - 1; j >= 0; j--){
               aux[j]=num[len-1-j];
               //num[j]=aux[j];
               // printf("%s",aux);
         }
    for(int i=0;i<=len;i++){
        num[i]=aux[i];
    }
printf("\n Correcto: %6s% ",num);
 }

 void Hex_Bin(char *hexdec)
 {
      long int i = 0;

      while (hexdec[i]) {

          switch (hexdec[i]) {
          case '0' :
              cout << " 0000" ;
              break;
          case '1' :
              cout << " 0001" ;
              break;
          case '2' :
              cout << " 0010" ;
              break;
          case '3' :
              cout << " 0011" ;
              break;
          case '4' :
              cout << " 0100" ;
              break;
          case '5' :
              cout << " 0101" ;
              break;
          case '6' :
              cout << " 0110" ;
              break;
          case '7' :
              cout << " 0111" ;
              break;
          case '8' :
              cout << " 1000" ;
              break;
          case '9' :
              cout << " 1001" ;
              break;
          case 'A' :
          case 'a' :
              cout << " 1010" ;
              break;
          case 'B' :
          case 'b' :
              cout << " 1011" ;
              break;
          case 'C' :
          case 'c' :
              cout << " 1100" ;
              break;
          case 'D' :
          case 'd' :
              cout << " 1101" ;
              break;
          case 'E' :
          case 'e' :
              cout << " 1110" ;
              break;
          case 'F' :
          case 'f' :
              cout << " 1111" ;
              break;
          default :
              cout << "\n Digito Invalido "
                  << hexdec[i];
         }
         i++;
     }
 }
void Bin_Hex(){
int base1=2, dec1,b2=16;
char n[650],nx[650];
cin>>n;
dec1 = num2dec(n,base1);
dec_xbase(dec1,nx,b2);

}
