template <typename Object>
class Vector
{

  public:
    class const_iterator
    {
      public:
        const_iterator( ) : current( 0 )
          { }
    
        const Object & operator* ( ) const
          { return retrieve( ); }
            
        const_iterator & operator++ ( )
        {
            return *this;
        }
    
        const_iterator operator++ ( int )
        {
            const_iterator old = *this;
            ++( *this );
            return old;
        }
    
        bool operator== ( const const_iterator & rhs ) const
          { return current == rhs.current; }
        bool operator!= ( const const_iterator & rhs ) const
          { return !( *this == rhs ); }
    
      protected:
        Object *current;
    
        Object & retrieve( ) const
          { return current; }
    
        const_iterator( Object *p ) : current( p )
          { }
            
        friend class Vector<Object>;
    };

    class iterator : public const_iterator
    {
      public:
        iterator( )
          { }
    
        Object & operator* ( )
          { return retrieve( ); }
        const Object & operator* ( ) const
          { return const_iterator::operator*( ); }
            
        iterator & operator++ ( )
        {
            
            return *this;
        }
    
        iterator operator++ ( int )
        {
            iterator old = *this;
            ++( *this );
            return old;
        }
    
      protected:
        Object * current;

        iterator(Object *p ) : const_iterator( p )
          { }
    
        Object & retrieve( )
          { return current; }

        friend class Vector<Object>;
    };

  public:
    explicit Vector( int initSize = 0 )
      : theSize( initSize ), theCapacity( initSize + SPARE_CAPACITY )
      { objects = new Object[ theCapacity ]; }
    Vector( const Vector & rhs ) : objects( 0 )
      { operator=( rhs ); }
    ~Vector( )
      { delete [ ] objects; }

    const Vector & operator= ( const Vector & rhs )
    {
        if( this != &rhs )
        {
            delete [ ] objects;
            theSize = rhs.size( );
            theCapacity = rhs.theCapacity;

            objects = new Object[ capacity( ) ];
            for( int k = 0; k < size( ); k++ )
                objects[ k ] = rhs.objects[ k ];
        }
        return *this;
    }

    void resize( int newSize )
    {
        if( newSize > theCapacity )
            reserve( newSize * 2 + 1 );
        theSize = newSize;
    }

    void reserve( int newCapacity )
    {
        if( newCapacity < theSize )
            return;

        Object *oldArray = objects;

        objects = new Object[ newCapacity ];
        for( int k = 0; k < theSize; k++ )
            objects[ k ] = oldArray[ k ];

        theCapacity = newCapacity;

        delete [ ] oldArray;
    }
    Object & operator[]( int index )
      { return objects[ index ]; }
    const Object & operator[]( int index ) const
      { return objects[ index ]; }

    bool empty( ) const
      { return size( ) == 0; }
    int size( ) const
      { return theSize; }
    int capacity( ) const
      { return theCapacity; }

    void push_back( const Object & x )
    {
        if( theSize == theCapacity )
            reserve( 2 * theCapacity + 1 );
        objects[ theSize++ ] = x;
    }

    void pop_back( )
      { theSize--; }

    const Object & back ( ) const
      { return objects[ theSize - 1 ]; }

    typedef Object * iterator;
    typedef const Object * const_iterator;

    iterator begin( )
      { return &objects[ 0 ]; }
    const_iterator begin( ) const
      { return &objects[ 0 ]; }
    iterator end( )
      { return &objects[ size( ) ]; }
    const_iterator end( ) const
      { return &objects[ size( ) ]; }

    enum { SPARE_CAPACITY = 16 };

  private:
    int theSize;
    int theCapacity;
    Object * objects;
};
