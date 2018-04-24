#include <iostream>

using namespace std;

void inicial(double *a, double min, double dx, int n);
void iteracion(double *nuevo, double *ant, int n, double dx, double dt, int c);
//en el main se declaran las variables necesarias 
int main(){
	int c=1.0;
	double dt=0.01;
	double dx=0.01;		
	double min=-2.0;
	double max=2.0;
	int n=700;
	int nx= (max-min)/dx;
	double *ant;
	double *nuevo ;
	ant= new double[nx];
	nuevo= new double[nx];
	//se declaran los 5 puntos equidistantes 	
	int pos1=n/5, pos2=2*n/5, pos3=3*n/5, pos4=4*n/5;
	//le doy la orden al main que ejecute la funcion inicial lam cual me da los valores iniciales
	inicial(ant,min,dx,nx);
	for (int i=1;i<n;i++){//se utliza la funcion que itera, en la funcion se definieron las 700 itercaiones necesarias
		 iteracion(nuevo,ant,nx,dx,dt,c);
		 cout << nuevo << "" <<nuevo[pos1] << "" << nuevo[pos3] << "" << nuevo[pos4] << endl;
	}
}


//la funcion inicial define los primeros valores 
void inicial(double *a, double min, double dx, int n){
	double x;
	for(int i=0;i<n;i++){
		x= min + i*dx;
		if(x<=0.5){	
		a[i]=0.5;//se utlizan las condiciones que se dan en el ejercicio 		
		}
		else{
		a[i]=0.0;

		}	
	}

}

//la funcion iteracion hace las iteraciones sobre x 
void iteracion(double *nuevo, double *ant, int n, double dx, double dt, int c){
  int i;
  double a = (c/2)*(dt/dx) ;
  for(i=1;i<n-1;i++){
   nuevo[i]=ant[i]-a*(ant[i+1]-ant[i-1]);//se define el nuevo valor 
  }

  for(i=1;i<n-1;i++){
   ant[i]=nuevo[i];//se cambia el valor anterior 
  }
}
