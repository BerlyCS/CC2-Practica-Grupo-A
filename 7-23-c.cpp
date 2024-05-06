#include <array>
#include <iomanip>
#include <iostream>
#include <random>
#include <vector>

using namespace std;

int main() {

   default_random_engine generador{ static_cast< unsigned >( time( 0 ) ) };
   uniform_int_distribution< size_t > uid{ 0, 7 };

   const size_t TAMANIO{ 8 };

   const array< int, TAMANIO > horizontal{ 2, 1, -1, -2, -2, -1, 1, 2 };
   const array< int, TAMANIO > vertical{ -1, -2, -2, -1, 1, 2, 2, 1 };

   vector< int > recorridos;

   while ( true ) {

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

      recorridos.push_back( contador );

      if ( contador == 64 )
         break;
   }

   for ( size_t i{ 0 }; i < recorridos.size(); ++i ) {
      cout << setw( 3 ) << recorridos[ i ];
      if ( ( i + 1 ) % 25 == 0 ) cout << endl;
   }

   cout << "\n\nNúmero de intentos: " << recorridos.size() << endl;

   return 0;
}

