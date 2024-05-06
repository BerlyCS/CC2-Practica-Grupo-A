#include <ctime>
#include <iomanip>
#include <iostream>
#include <random>

using namespace std;
void moveTurtle( int* const, const int );
void moveHare( int* const, const int );

int main(){
   default_random_engine gen{ static_cast< unsigned >( time( 0 ) ) };
   uniform_int_distribution< int > uid{ 1, 50 };
   int t{ 1 };
   int l{ 1 };
   const int F{ 70 };

   cout<<"BANG !!!!!\nAND THEY'RE OFF !!!!!"<<endl;

   do{
      int i{ uid(gen) };
      moveTurtle(&t, i);
      moveHare(&l, i);

      if (t<l)
         cout<<setw(t)<<'T'<<setw(l - t)<<'H';
      else if (l<t)
         cout<<setw(l)<<'H'<<setw( t - l )<<'T';
      else
         cout<<setw(t + 6)<<"OUCH!!!";
      cout<<endl;

   } while (t<F && l<F);

   if (t>=F && l<F ) cout<<"TORTOISE WINS!!! YAY!!!";
   else if (l>=F && t<F) cout<<"Hare wins. Yuck.";
   else cout<<"It's a tie.";
   cout<<endl;
   return 0;
}

void moveTurtle( int* const position, const int random ) {

   if (random<=25) *position += 3;
   else if (random<=33) *position -= 6;
   else *position += 1;
   if (*position < 1) *position = 1;
}

void moveHare( int* const position, const int random ) {
   if ( random <= 19 ) return;
   else if ( random <= 27 ) *position += 11;
   else if ( random <= 35 ) *position -= 9;
   else if ( random <= 45 ) *position += 1;
   else *position -= 2;
   if (*position<1) *position = 1;
}
