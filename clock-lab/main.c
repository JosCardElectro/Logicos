#include "interface.h"
#include "convert.h"
#include <math.h>
#include <string.h>
void dec_xbase(int dec,char *num,int base);
int num2dec(char *n,int base);//Cualquier Base a decimal
int hex_dec(char hexnum[]);//Auxiliar de num2dec
int main()
{
	int key, currKey;
	time_t s;
	struct tm* current_time;
	char hour[3], minute[3], seconds[3];
    char ns[100];
    char nm[100];
    char nh[100];


	initScreen();
	timeout(500);

	//drawNumber(0, 3, 4);
	//drawDots(45,4);

	do
	{
		key = getch();
		if(key != ERR) currKey = key;

		s = time(NULL);
		current_time = localtime(&s);
	sprintf(hour, "%02d", current_time->tm_hour);//(cadenas enteros)
    sprintf(minute, "%02d", current_time->tm_min);
    sprintf(seconds, "%02d", current_time->tm_sec);
		switch(currKey)
		{
			case KEY_F(2):

               // mvprintw(4,100, "%02d", current_time->tm_sec);

               mvprintw(4,10,"%s :",hour);
               printw("%s :", minute);//Imprinme
               printw("%s ",seconds);
                //mvprintw(4,100, "%02d", );

                dec_xbase(current_time->tm_sec,ns,2);
                dec_xbase(current_time->tm_min,nm,2);
                dec_xbase(current_time->tm_hour,nh,2);

                mvprintw(6,10,"%6s: ",nh);
                printw("%6s: ",nm);
                printw("%6s ",ns);
                //Llamar la funcion
                //Guardarla
                //Imprimir. dos imoresiones..
				break;
			case KEY_F(3):


                mvprintw(4,10,"%s :",hour);
                printw("%s :", minute);//Imprinme
                printw("%s ",seconds);

                dec_xbase(current_time->tm_sec,ns,16);
                dec_xbase(current_time->tm_min,nm,16);
                dec_xbase(current_time->tm_hour,nh,16);

                mvprintw(8,10,"%6s: ",nh);
                printw("%6s: ",nm);
                printw("%6s ",ns);

				break;
			case KEY_F(4):

                mvprintw(4,18, "%s", seconds);//Imprinme
                mvprintw(4,14,"%s :",minute);
                mvprintw(4,10,"%s :",hour);

                dec_xbase(current_time->tm_sec,ns,8);
                dec_xbase(current_time->tm_min,nm,8);
                dec_xbase(current_time->tm_hour,nh,8);

                mvprintw(11,10,"%6s: ",nh);
                printw("%6s: ",nm);
                printw("%6s ",ns);
				break;
			case KEY_F(5):
				sprintf(hour, "%02x", current_time->tm_hour);
				sprintf(minute, "%02x", current_time->tm_min);
				sprintf(seconds, "%02x", current_time->tm_sec);
                mvprintw(4,60, "%s", seconds);//Imprinme
                mvprintw(4,50,"%s :",minute);
                mvprintw(4,40,"%s :",hour);

                // int b;
                char *h,*h1,*h2;
            h=seconds;
            h1=minute;
            h2=hour;
              //  char *n;
                mvprintw(6,40,"%02d :",hex_dec(h2));
                mvprintw(6,50,"%02d :",hex_dec(h1));
                mvprintw(6,60,"%02d",hex_dec(h));



				break;
			case KEY_F(6):
			    sprintf(hour, "%02o", current_time->tm_hour);
				sprintf(minute, "%02o", current_time->tm_min);
				sprintf(seconds, "%02o", current_time->tm_sec);
                mvprintw(10,60, "%s :", hour);//Imprinme
                printw("%s :",minute);
                printw("%s ",seconds);
            //char num[65];
            char *n,*n1,*n2;
            n=seconds;
            n1=minute;
            n2=hour;

           mvprintw(14,60,"%02d :",num2dec(n2,8));
           printw("%02d :",num2dec(n1,8));
            printw("%02d ",num2dec(n,8));

				break;
			default:
				break;
		}

		refreshScreen();
	}while( (toupper(key) != 'Q') );

	endScreen();

	return 0;
}
void dec_xbase(int dec,char *num,int base){
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
//     cout<<"El numero es: ";
      for ( int j = i - 1; j >= 0; j--){
               aux[j]=num[len-1-j];
               //num[j]=aux[j];
               // printf("%s",aux);
         }
    for(int i=0;i<=len;i++){
        num[i]=aux[i];
}
num[i] = NULL;
//printf("\n Correcto: %s% ",num);
//mvprintw(4,4,"%6s",num);
 }
int hex_dec(char hexVal[])//Hex a decimal
{
    for (int indice = 0; hexVal[indice] != '\0'; ++indice){
		hexVal[indice] = toupper(hexVal[indice]);
	}//Evita error del reloj manda minusculas
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
    //printf("Decimal: %d \n");
    return dec;
}
