#ifndef MAP_H
#define MAP_H

#include <Magnum/Shader.h>
#include <Magnum/Version.h>
#include <Magnum/Renderer.h>
#include <Magnum/Context.h>

#include <Magnum/Shaders/VertexColor.h>

#include "IMap.h"

using namespace Magnum;

class MyShader : public AbstractShaderProgram
{
	public:
		typedef Attribute<0, Vector3> Position;

		MyShader()
		{
			MAGNUM_ASSERT_VERSION_SUPPORTED(Version::GL330);

			Shader vertexShader(Version::GL330, Shader::Type::Vertex);
			Shader fragmentShader(Version::GL330, Shader::Type::Fragment);

			vertexShader.addFile("shader.vert");
			fragmentShader.addFile("shader.frag");

			CORRADE_INTERNAL_ASSERT_OUTPUT(vertexShader.compile());
			CORRADE_INTERNAL_ASSERT_OUTPUT(fragmentShader.compile());

			attachShaders({ vertexShader, fragmentShader });

			CORRADE_INTERNAL_ASSERT_OUTPUT(link());

			m_colorUniform = uniformLocation("color");
		}

		MyShader& setColor(const Color3& color)
		{
			setUniform(m_colorUniform, color);

			return *this;
		}

	private:
		int m_colorUniform;
};


class Map : public IMap
{
	public:
		Map();

		QList<IMapTile *> tiles() const override;

	private:
		MyShader m_shader;
};

#endif // MAP_H
