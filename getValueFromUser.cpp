
#include <iostream>

int getValueFromUser() //esta funcion ahora devuelve un valor entero
{
    cout<<"Ingrese un entero:";
    input();
    cin>>entrada;
    
    retorno de entrada;//devuelve el valor que el usuario ingreso
    
}

int main()
{
    int num{getValueFromUser()};//Inicializa num con el valor de retornoo de getValueFromUser()
    cout<<num<<"duplicado es:"<<num*2<<'\n';
    return 0;
}