#include < iostream > // para std :: cout
void doB ( )
{
}
void doA ( )
{
     std :: cout << " En doB ( ) \ n " ;
    std :: cout << " Iniciando doA ( ) \ n " ;
    doB ( ) ;
     std :: cout << " Finalizando doA ( ) \ n " ;
}
// Definición de la función main ( )
int main ( )
(
     std :: cout << " Iniciando main ( ) \ n " ;
    doA ( ) ;
     std :: cout << " Finalizando main ( ) \ n " ;
    return 0 ;