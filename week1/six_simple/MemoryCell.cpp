#include <ostream>

using namespace std;
/**
 * A class for simulating a memory cell.
 */
template <typename Object>
class MemoryCell
{
  public:
    explicit MemoryCell( const Object & initialValue = Object( ) )
      : storedValue( initialValue ) { }
    const Object & read( ) const
      { return storedValue; }
    void print( ostream & out )
      { out << read(); }
//    ostream & operator<< ( ostream & out ) const
//      { print(out); return out; }
    friend ostream & operator<< ( ostream & out, const MemoryCell & rhs )
      { out << rhs.read(); return out; }
    void write( const Object & x )
      { storedValue = x; }
    bool operator< ( MemoryCell rhs )
      { return (read() < rhs.read()); }
    bool operator<= ( MemoryCell rhs )
      { return (read() <= rhs.read()); }
    bool operator== ( MemoryCell rhs )
      { return (read() == rhs.read()); }
    bool operator!= ( MemoryCell rhs )
      { return (read() != rhs.read()); }
    
  private:
    Object storedValue;
};
