#include < iostream >
int add ( int x , int y ) ; // declaración de avance de add ( ) ( usando un prototipo de función )
int main ( )
{
     std :: cout << " La suma de 3 y 4 es : " << add ( 3 , 4 ) << ' \ n ' ; // esto funciona porque reenviamos declarado add ( ) arriba
     return 0 ;
}
int add ( int x , int y ) // aunque el cuerpo de add ( ) no está definido hasta aquí
{
     return x + y ;