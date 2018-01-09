//Example using CHarmonicMapper

#include "HarmonicMapper/HarmonicMapper.h"

using namespace MeshLib;


//compute harmonic map, between a topological disk to a disk
void _harmonic_map( const char * _input, const char * _output )
{
    CHMMesh mesh;
    mesh.read_m( _input );

    CHarmonicMapper mapper( & mesh );
    mapper._map();
    mesh.write_m( _output );
};

int main( int argc, char * argv[] )
{

    _harmonic_map("data/alex.m","data/alex_uv.m");

    return 0;
}