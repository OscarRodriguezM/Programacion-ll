#include < iostream >
int add ( int x , int y ) // xey se crean e ingresan el alcance aquí
{
     // xey son visibles / utilizables solo dentro de esta función
     return x + y ;
} // y y x salen del alcance y se destruyen aquí
int main ( )
(
     int a ( 5 ) ; // a se crea , se inicializa y entra al alcance aquí
     int b ( 6 ) ; // b se crea , se inicializa y entra al alcance aquí
    // ayb solo se pueden usar dentro de esta función
    std :: cout << add ( a , b ) << ' \ n ' ; // llama a la función add ( ) con x = 5 e y = 6
    return 0 ;
} // by a salen del alcance y se destruyen aquí