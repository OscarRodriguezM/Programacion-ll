
#include <iostream>

//int es el tipo de retorno
//un tipo de retorno de int significa que la funcion devolvera algun valor entero a la persona que llama (el valor especifico)
int returnFive()
{
    //la declaracion de retorno indica el valor especifico que se devolvera
    return 5; //devuelve el valor especifico 5 a la persona que llama
}

int main()
{
    cout<<returnCinco()<<'\n';//imprime 5
    cout<<returnCinco()+2<<'\n';//imprime 7
    returnFive();//bien; se devuelve el valor 5, pero se ignora ya que main() no hace nada con el
    return 0;
}