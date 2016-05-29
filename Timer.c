#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include <stdlib.h>
#include <time.h>

void mgotoxy(int x, int y)
{
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){x,y});
}


void beep(){
	
	puts("\a");
}

void telarelogio(){ //funcao de impressao do quadrado
	
	int x;
	for(x=8;x<16;x++){ 
	mgotoxy(27,x); //vertical esquerda
 	printf("%c",219);
	
	}
 
 	for(x=8;x<16;x++){
 	mgotoxy(50,x); //vertical direita
 	printf("%c",219);
 	
	}
 
 	for(x=28;x<50;x++){
 	mgotoxy(x,8); //horizontal superior
 	printf("%c",219);
 	
	}
 	
 	for(x=28;x<50;x++){
 	mgotoxy(x,15); //horizontal inferior
 	printf("%c",219);
 	
	}
 
}

int main() {
	
	
	int x=0, y = 0, velo;
	char tecla, resposta;
	
	velo = 50; //velocidade do relogio
	
	do{
	
	telarelogio();
	
	mgotoxy(34,10);
	printf("Minutos: ");
	scanf("%d", &x);
	
	mgotoxy(34,11);
	printf("Segundos: ", &y);
	scanf("%d", &y);
	
	if((x < 0 || x > 60) && (y < 60 || x >60 )){
	
	mgotoxy(30,18);
	printf("Numeros invalidos!!!");
	mgotoxy(32,19);
	printf("Tente novamente");
	
	scanf("%c", &resposta);
		
	system("PAUSE>>null");

	}
	system("CLS");
	
	}while( (x < 0 || x > 60) && (y < 60 || x >60 ) );
	system("CLS");

	mgotoxy(34,9);
	printf("CRONOMETRO");
	
	while (tecla!='s'){
	
	telarelogio(); 
	mgotoxy(36,11);
	printf("%02d:%02d",x , y);
	
	
	if(y == 0 && x == 0){
			
		mgotoxy(0,23);
		beep(); //da um beep
		system("pause");
		
		return 0;
	}
	if(y == 0){
		x--;
		y=60;
	}
	Sleep(velo);
	
	y--;
	
	}
		

}
