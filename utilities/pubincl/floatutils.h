//
// Created by Parsa Noori on 2/5/2022 AD.
//

#ifndef COMPILER_FLOATUTILS_H
#define COMPILER_FLOATUTILS_H
#include <cstring>

unsigned int floatToInt( float f )
{
    static_assert( sizeof( float ) == sizeof( unsigned int ), "Sizes must match" );
    unsigned int ret;
    memcpy( &ret, &f, sizeof( float ) );
    return ret;
}

#endif //COMPILER_FLOATUTILS_H
