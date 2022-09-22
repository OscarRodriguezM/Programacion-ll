#include < iostream >
// x no está dentro del alcance en ninguna parte de esta función
void dosomething ( )
{
     std :: cout << " ¡ Hola ! \ n " ;
}
int main ( )
{
     // x no se puede usar aquí porque aún no está dentro del alcance
     int x { 0 } ; // x ingresa al alcance aquí y ahora se puede usar
     dosomething ( ) ;
     return 0 ;
} // x se sale del alcance aquí y ya no se puede usar