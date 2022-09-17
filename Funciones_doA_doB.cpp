
#include <iostream> //PARA STD::COUT

   void doB()
   {
       std::cout<<"En doB() \n";
   }
   
    void doA()
   {
       std::cout<<"Inicializando doA() \n";
       doB();
       std::cout<<"Finalizandl doA() \n";
   }



int main()
{
    std::cout<<"Iniciando Main() \n";
    doA();
    std::cout<<"Finalizando Main() \n";//ESTA SENTENCIA SE EJECUTA DESPUÉS DE QUE TERMINE doPrint()
    return 0;
}
