//Juego Ahorcado FIS

#include <iostream>
#include <chrono> //Son para crear el numero random
#include <thread>
#include <conio.h> 
#include <string.h> //Para la función strlen()
#include <algorithm>//Para algoritmo de ordenamiento sort

using namespace std;
using namespace std::chrono;
using namespace std::this_thread;

struct Puntajesjug{
	string name;
	int puntaje=0;	
}p_player[10];

void inicio();
bool validar_numeros(char numero[]);
void dibujo (int intentos);
int veces_jug=0;

bool comparar(const Puntajesjug a, const Puntajesjug b) {
    return a.puntaje > b.puntaje;
}

void jugar(){
	system("cls");
	char palabras[9][15] = {"LUDOLAB","SEGUNDAESTODO","BIELA","DOSQUETRES","PANTERA","REINICIAR","AEIS","BANDIDAS","ASO"};
	int n_pal, longitud, espacios, puntos=2500, i, opcion, j;
	char letra, vali_letra;
	int aciertos = 0;
	int intentos = 0;
	srand(time(NULL));
	
	opcion = rand() % 9; //SE GENERA UN NUMERO ALEATORIO COMPRENDIDO ENTRE 0 Y 8
	longitud = strlen(palabras[opcion]); //SE ALMACENA LA LONGITUD DE LA PALABRA 
	char frase[longitud];
	
	//SE COLOCAN GUIONES BAJOS EN EL ARRAY DE CARACTERES FRASE
	for(i=0; i < longitud; i++){
		frase[i] = '_';
	}
	
	while(intentos !=7){
		aciertos=0;
	    system("cls");
		cout<<"\n\t\t\t\t!!!ADIVINA LA PALABRA Y SÁLVATE!!!\n\n";
		cout<<"Intentos Disponibles: "<<6-intentos<<" \nPuntuacion: "<<puntos;
		dibujo(intentos);
		
		//IMPRIME EL ARRAY DE CARACTERES FRASE
		cout<<"\n\n\n";
		for(i=0; i < longitud; i++){
			cout<<frase[i];
		}
		
		if (intentos == 6){
			cout<<"\n\nPERDISTE!!\n";
			cout<<"\nLA SOLUCION ERA: "<<palabras[opcion]<<"\n";
			cout<<"\nINGRESA TU NOMBRE:"<<endl;
			cin>>p_player[veces_jug].name;
		 	p_player[veces_jug].puntaje=puntos;
		 	veces_jug++;
			cout<<"\nPresiona una tecla para volver al menú principal";	
			getch();
			break;
		}
				
		//PROCESO QUE COMPRUEBA SI SE HA ADIVINADO LA PALABRA
		espacios=0;
		
		for (i = 0; i < longitud; i++){
			if (frase[i] == '_')
				espacios++;
		}
		
		if (espacios == 0){
			cout<<"\n\nFELICIDADES.. GANASTE!!\n\n";
			cout<<"INGRESA TU NOMBRE:"<<endl;
			cin>>p_player[veces_jug].name;
		 	p_player[veces_jug].puntaje=puntos;
		 	veces_jug++;
			cout<<"\nPresiona una tecla para volver al menú principal";
			getch();	
			break;		
		}
		
			cout<<"\n\nDigite una letra: ";
			cin>>vali_letra;
			if(!(vali_letra>=65 && vali_letra<=90) && !(vali_letra>=97 && vali_letra<=122)){
			 letra='.';
		  	}else{
		  	  letra=toupper(vali_letra);
			}
			
			//PROCESO QUE VERIFICA SI LA LETRA INGRESADA EXISTE EN LA PALABRA, SI ESTO ES VERDADERO, SE REEMPLAZA EL CARACTER GUION BAJO POR LA LETRA INGRESADA 
			for (j = 0; j < longitud; j++){
				if (letra == palabras[opcion][j]){
					frase[j] = letra;
					aciertos++;
				}
		}
			
		if (aciertos == 0){
				intentos++;
				puntos -= 200;
		    }		
 }
 inicio();
}
                     
void puntajes(){
	system("cls");
	cout<<"\t\t\t\tPUNTAJES"<<endl;
	cout<<"\tJUGADOR\t\tPUNTOS"<<endl;
	sort(p_player, p_player + 10, comparar);
	for(int i=0; i<veces_jug; i++){
		cout<<"\t"<<p_player[i].name<<"\t\t"<<p_player[i].puntaje<<endl;
	}
	cout<<"Presiona una tecla para volver al menú principal";
	getch();
	inicio();
}

void creditos(){
	system("cls");
	cout<<"\t\t\t\tCRÉDITOS"<<endl;
	cout<<"PROGRAMADORES"<<endl;
	cout<<"\nANTHONY ALANGASÍ"<<endl;
	cout<<"\nGUILLERMO CALVACHE"<<endl;
	cout<<"\n\nDISEÑADORES"<<endl;
	cout<<"\nANTHONY ALANGASÍ"<<endl;
	cout<<"\nGUILLERMO CALVACHE"<<endl;
	cout<<"\nPresiona una tecla para volver al menú principal";
	getch();
	inicio();
}       

void inicio(){
	
	int op=0;
	char cadena [10];
	bool valido=false;
	//Pantalla inicio
	do{
		system("cls");
		cout<<" ====            ____    =====     ___   ====   ====     ____"<<endl;
		cout<<"||  ||  ||  ||  /    \\  ||   ||   /     ||  || ||   \\   /    \\"<<endl;
		cout<<"||==||  ||==|| |      | ||===//  |	||==|| ||   || |      |"<<endl;
		cout<<"||  ||  ||  ||  \\____/  ||   ||   \\___  ||  || ||___/   \\____/"<<endl;
		
		cout<<"\n";
		cout<<"\t\t ====== ||======||  ======"<<endl;
		cout<<"\t\t||          ||     ||____"<<endl;
		cout<<"\t\t||===       ||           ||"<<endl;
		cout<<"\t\t||      ||======|| ======/"<<endl;
		
		cout<<"\nSELECCIONA UNA OPCIÓN :)"<<endl;
		cout<<"1.JUGAR"<<endl;
		cout<<"2.PUNTAJES"<<endl;
		cout<<"3.CRÉDITOS"<<endl;
		cout<<"4.SALIR"<<endl;
		cin>>cadena;
		valido=validar_numeros(cadena);
		
	}while(valido==false);
	
	op=atoi(cadena);
	
	switch(op){
		case 1: 
		jugar();
		break;
		
		case 2: 
		puntajes();
		break;
		
		case 3: 
		creditos();
		break;
		
		case 4: 
			system("exit");
			break;
		
		default: 
			cout<<"\nNo existe esa opción...\nPresione ENTER para continuar";
			getch();
			system("cls");
			inicio();
	}
	
}

bool validar_numeros(char numero[]){
	int i;
	for(i=0; i<strlen(numero); i++){
		if(!(numero[i]>=48 && numero[i]<=57)){
			cout<<"\nSolo ingrese números\nPresione ENTER para continuar";
			getch();
			return false;
		}
	}	
	return true;
}

//FUNCION QUE REALIZA EL DIBUJO DE EL AHORCADO, RECIBE EL NUMERO DE INTENTOS Y CON ESE DATO REALIZA EL DIBUJO
void dibujo (int intentos){
	switch(intentos){
		case 0:
			cout<<"\n     _______\n    |       |\n    |\n    |\n    |\n    |\n    |\n ----------";
			break;
		case 1:
			cout<<"\n     _______\n    |       |\n    |       0\n    |\n    |\n    |\n    |\n ----------";
			break;
		case 2:
			cout<<"\n     _______\n    |       |\n    |       0\n    |       |\n    |\n    |\n    |\n ----------";
			break;
		case 3:
			cout<<"\n     _______\n    |       |\n    |       0\n    |      /|\n    |\n    |\n    |\n ----------";
			break;
		case 4:
			cout<<"\n     _______\n    |       |\n    |       0\n    |      /|";
			cout<<"\\";
			cout<<"\n";
			cout<<"    |\n    |\n    |\n ----------";
			break;
		case 5:
			cout<<"\n     _______\n    |       |\n    |       0\n    |      /|";
			cout<<"\\";
			cout<<"\n";
			cout<<"    |      /\n    |\n    |\n ----------";
			break;
		case 6:
			cout<<"\n     _______\n    |       |\n    |       0\n    |      /|";
			cout<<"\\";
			cout<<"\n";
			cout<<"    |      / ";
			cout<<"\\";
			cout<<"\n";
			cout<<"    |\n    |\n ----------";
			break;
	}           
	            
}                                   

int main(){
	system("mode con cols=80 lines=25");
	inicio();
//	system("pause");
	return 0;
}

