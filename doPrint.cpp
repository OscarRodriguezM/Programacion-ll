
#include <iostream>
//DEFINICION DE LA FUNCION DEFINIDA POR EL USUARIO doPrint() 
   void doPrint() //doPrint() ES LA FUNCIÓN LLAMADA EN ESTE EJEMPLO
   {
       std::cout<<"En doPrint() \n";
   }


int main()
{
    std::cout<<"Iniciando Main() \n";
    doPrint();//INTERRUMPE MAIN() HACIENDO UNA LLAMADA DE LA FUNCIÓN doPrint(). Main() es la persona que llama 
    std::cout<<"Finalizando Main() \n";//ESTA SENTENCIA SE EJECUTA DESPUÉS DE QUE TERMINE doPrint()
    return 0;
}
