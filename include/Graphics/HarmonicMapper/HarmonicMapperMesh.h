/*!
*      \file HarmonicMapperMesh.h
*      \brief Mesh for Harmonic Mapping
*	   \author David Gu
*      \date Documented 10/07/2010
*
*/

#ifndef  _HARMONIC_MAPPER_MESH_H_
#define  _HARMONIC_MAPPER_MESH_H_

#include <map>
#include <vector>

#include "Mesh/BaseMesh.h"
#include "Mesh/Vertex.h"
#include "Mesh/HalfEdge.h"
#include "Mesh/Edge.h"
#include "Mesh/Face.h"
#include "Mesh/iterators.h"
#include "Mesh/boundary.h"
#include "Parser/parser.h"

namespace MeshLib
{
/*!
*	\brief CHarmonicVertex class
*
*	Vertex class for harmonic mapping
*   adding vertex uv trait and vertex index trait
*/
class CHarmonicVertex : public CVertex
{

public:
    /*!
     *	CHarmonicVertex constructor
     */
    CHarmonicVertex()
    {
        m_index = 0;
        m_huv=CPoint2(0,0);
    };
    /*!
     *	CHarmonicVertex destructor
     */
    ~CHarmonicVertex() {};

    /*!
     *	Vertex uv trait, the image of the harmonic map
     */
    CPoint2 & huv()
    {
        return m_huv;
    };
    /*!
     *	Vertex index trait
     */
    int &     idx()
    {
        return m_index;
    };
    /*!
     *	Vertex rgb trait
     */
    CPoint & rgb()
    {
        return m_rgb;
    };
    /*!
     *	Write vertex uv to vertex string
     */
    void _to_string();

protected:
    /*! Vertex huv, image of the harmonic mapping */
    CPoint2 m_huv;
    /*! Vertex index */
    int     m_index;
    /*! Vertex normal */
    CPoint  m_normal;
    /*! Vertex rgb */
    CPoint  m_rgb;
};



/*!
*	\brief CHarmonicEdge class
*
*	Edge class for harmonic mapping
*   adding edge weight trait
*/
class CHarmonicEdge : public  CEdge
{
public:
    /*!	CHarmonicEdge constructor
     */
    CHarmonicEdge()
    {
        m_weight = 0;
        m_length=0;
        m_sharp = false;
    };
    /*!	CHarmonicEdge destructor
     */
    ~CHarmonicEdge() {};
    /*!	edge weight trait
     */
    double & weight()
    {
        return m_weight;
    };
    /*! edge length trait
     */
    double & length()
    {
        return m_length;
    };
    /*! read edge traits from string, such as edge length
     */
    void _from_string();
    /*! sharp edge
     */
    bool & sharp()
    {
        return m_sharp;
    };

protected:
    /*! edge weight trait */
    double   m_weight;
    /*! edge length trait */
    double   m_length;
    /*! sharp edge */
    bool	 m_sharp;
};


//converting vertex uv trait to string

/*! write v->huv to the string
*/
inline void CHarmonicVertex::_to_string()
{
    CParser parser( m_string );
    parser._removeToken( "uv" );
    parser._toString( m_string );
    std::stringstream iss;
    iss << "uv=(" << m_huv[0] << " " << m_huv[1] << ")";

    if( m_string.length() > 0 )
    {
        m_string += " ";
    }
    m_string += iss.str();
}

//read edge length from string
/*!	Read edge->length from the edge->string
 *
 */
inline void CHarmonicEdge::_from_string()
{

    CParser parser( m_string );

    for( std::list<CToken*>::iterator iter = parser.tokens().begin() ; iter != parser.tokens().end(); ++ iter )
    {
        CToken * token = *iter;
        /*
          if( token->m_key == "l" )
          {
             std::string line = strutil::trim( token->m_value, "()");
             m_length = strutil::parseString<double>(line) ;
          }
        */
        if( token->m_key == "sharp" )
        {
            m_sharp = true;
        }
    }

}

/*!
*	\brief CHarmonicEdge class
*
*	Face class for harmonic mapping
*   adding face normal trait
*/
class CHarmonicFace : public  CFace
{
public:
    /*!	CHarmonicFace constructor
     */
    CHarmonicFace() {};
    /*!	CHarmonicFace destructor
     */
    ~CHarmonicFace() {};
};


/*!
*	\brief CHarmonicHalfEdge class
*
*	HalfEdge class for harmonic mapping
*   adding Corner Angle trait
*/
class CHarmonicHalfEdge : public  CHalfEdge
{
public:
    /*!	CHarmonicHalfEdge constructor
     */
    CHarmonicHalfEdge() {};
    /*!	CHarmonicHalfEdge destructor
     */
    ~CHarmonicHalfEdge() {};
    /*!	Corner angle trait
     */
    double & angle()
    {
        return m_angle;
    };

protected:
    /*! Corner angle trait */
    double m_angle;
};

/*-------------------------------------------------------------------------------------------------------------------------------------

	Harmonic Mapper Mesh Class

--------------------------------------------------------------------------------------------------------------------------------------*/
/*!
 *	\brief CHarmonicMapperMesh class
 *
 *	Mesh class for harmonic mapping purpose
 */
template<typename V, typename E, typename F, typename H>
class CHarmonicMapperMesh : public CBaseMesh<V,E,F,H>
{
public:
    typedef MeshLib::CBoundary<V,E,F,H> CBoundary;
    typedef MeshLib::CLoop<V,E,F,H> CLoop;
    typedef MeshLib::MeshVertexIterator<V,E,F,H> MeshVertexIterator;
    typedef MeshLib::MeshEdgeIterator<V,E,F,H> MeshEdgeIterator;
    typedef MeshLib::VertexVertexIterator<V,E,F,H> VertexVertexIterator;
    typedef MeshLib::VertexEdgeIterator<V,E,F,H> VertexEdgeIterator;
    typedef MeshLib::MeshFaceIterator<V,E,F,H> MeshFaceIterator;
    typedef MeshLib::FaceVertexIterator<V,E,F,H> FaceVertexIterator;
    typedef MeshLib::VertexFaceIterator<V,E,F,H> VertexFaceIterator;
    typedef MeshLib::FaceHalfedgeIterator<V,E,F,H> FaceHalfedgeIterator;
};

/*! Mesh class for CHarmonicMapper class, Abbreviated as 'CHMMesh'
 */
typedef CHarmonicMapperMesh<CHarmonicVertex, CHarmonicEdge, CHarmonicFace, CHarmonicHalfEdge> CHMMesh;
/*! CHMMesh has no input traits, and has VERTEX_UV output traits
 */

//unsigned  long  CHMMesh::m_input_traits = 0;
//unsigned  long  CHMMesh::m_output_traits = VERTEX_UV;
};
#endif  _HARMONIC_MAPPER_MESH_H_