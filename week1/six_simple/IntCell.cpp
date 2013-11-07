#include "IntCell.h"

/**
 * Construct the IntCell with initialValue
 */
IntCell::IntCell( int initialValue ) : storedValue( initialValue )
{
}

/**
 * Return the stored value.
 */
int IntCell::read( ) const
{
    return storedValue;
}

/**
 * Store x.
 */
void IntCell::write( int x )
{
    storedValue = x;
}


void IntCell::add_to(int a){
 this.write(storedValue + a);
}

IntCell IntCell::add(int a) const {
return IntCell c( this.read() + a );
}

IntCell IntCell::add(IntCell a) const {
 return IntCell c( a.read() + this.read() );
}

void IntCell::sub_from(int a){
 this.write(storedValue - a);
}

IntCell IntCell::sub(int a) const {
 return IntCell c( this.read() - a );
}

IntCell IntCell::sub(IntCell a) const {
 return IntCell c( a.read() - this.read() );
}
