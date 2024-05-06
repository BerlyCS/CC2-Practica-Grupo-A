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

   array< array< int, TAMANIO >, TAMANIO > tablero{};

   size_t filaActual{ 0 };
   size_t columnaActual{ 0 };

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

   for ( const auto& fila : tablero ) {
      for ( const auto& elemento : fila ) {         
         cout << setw( 4 );
         if ( !elemento ) cout << '.';
         else cout << elemento;
      }
      cout << "\n\n";
   }

   cout << "Casillas visitadas: " << contador << endl;

   return 0;
}

