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

IntCell IntCell::sub( int a ) const {
    IntCell m( read() - a );
    return m; 
}

IntCell IntCell::sub( IntCell a ) const {
    IntCell m( read() - a.read() );
    return m;
}

void IntCell::sub_from( int a ) {
    storedValue -= a;
}

IntCell IntCell::add( int a ) const {
    IntCell m( a + read() );
    return m; 
}

IntCell IntCell::add( IntCell a ) const {
    IntCell m( a.read() + read() );
    return m;
}

void IntCell::add_to( int a ) {
    storedValue += a;
}
