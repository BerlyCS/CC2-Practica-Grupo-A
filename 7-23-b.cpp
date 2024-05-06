#include <array>
#include <iomanip>
#include <iostream>
#include <random>

using namespace std;

int main() {

   default_random_engine generador{ static_cast< unsigned >( time( 0 ) ) };
   uniform_int_distribution< size_t > uid{ 0, 7 };

   const size_t TAMANIO{ 8 };

   const array< int, TAMANIO > horizontal{ 2, 1, -1, -2, -2, -1, 1, 2 };
   const array< int, TAMANIO > vertical{ -1, -2, -2, -1, 1, 2, 2, 1 };

   const size_t RECORRIDOS{ 1000 };
   array< int, RECORRIDOS > recorridos{};

   for ( int recorrido{ 0 }; recorrido < RECORRIDOS; ++recorrido ) {

      array< array< int, TAMANIO >, TAMANIO > tablero{};

      size_t filaActual{ uid( generador ) }; // fila inicial aleatoria
      size_t columnaActual{ uid( generador ) }; // columna inicial aleatoria

      int contador{ 0 };

      tablero[ filaActual ][ columnaActual ] = ++contador;

      for ( int i{ 0 }; i < 1000; ++i ) {

         size_t numeroMovimiento{ uid( generador ) };
         size_t filaPrueba{ filaActual + vertical[ numeroMovimiento ] };
         size_t columnaPrueba{ columnaActual + horizontal[ numeroMovimiento ] };

         if ( filaPrueba >= 0 && filaPrueba < TAMANIO && columnaPrueba >= 0
            && columnaPrueba < TAMANIO && !tablero[ filaPrueba ][ columnaPrueba ] ) {

            filaActual = filaPrueba;
            columnaActual = columnaPrueba;
            tablero[ filaActual ][ columnaActual ] = ++contador;
         }
      }

      recorridos[ recorrido ] = contador;
   }

   int mejor{ 0 };

   for ( size_t i{ 0 }; i < RECORRIDOS; ++i ) {
      
      cout << setw( 3 ) << recorridos[ i ];
      if ( ( i + 1 ) % 25 == 0 ) cout << endl;
      
      if ( recorridos[ i ] > mejor )
         mejor = recorridos[ i ];
   }

   cout << "\nEl mejor resultado es " << mejor << endl;

   return 0;
}

