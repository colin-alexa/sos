#ifndef IntCell_H
#define IntCell_H

/**
 * A class for simulating an integer memory cell.
 */
class IntCell
{
  public:
    explicit IntCell( int initialValue = 0 );
    int read( ) const;
    void write( int x );
    IntCell add( int a ) const;
    IntCell add( IntCell a ) const;
    void add_to( int a ); 
    IntCell sub( int a ) const;
    IntCell sub( IntCell a ) const;
    void sub_from( int a );
 
  private:
    int storedValue;
};

#endif
