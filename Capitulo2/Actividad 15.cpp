int add ( int x , int Y )
{
}
      return x + y ;
int add ( int x , int y ) // violación de ODR , ya hemos definido la función add
{
      return x + y ;
}
int main ( )
0
     int x ;
     int x ; // violación de ODR , ya hemos definido x