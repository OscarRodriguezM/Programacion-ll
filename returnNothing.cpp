
#include <iostream>

//void significa que la funcion no devuelve un valor a la persona que 
void retornoNada()
{
    cout<<"Hola"<<'\n';
    //esta funcion no devuelve un valor, por lo que no necesita una declaracion de devolucion
    
}

int main()
{
    returnNothing(); //bien: se llama a la funcion returnNothing(), no se devuelve ningun valor
    cout<<returnNothing();//error: esta linea no se compilara. debera comentarlo para continuar...
}