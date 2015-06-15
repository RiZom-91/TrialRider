#include "GL/gl.h"
#include "GL/glu.h"
#include "Box2D/Box2D.h"

class DebugDraw : public b2Draw
{

private:

float32 _ptmRatio; // local box2d pixels-to-metres

public:

DebugDraw(float32 aRatio);

// MARK: b2Draw implementation

void DrawSolidPolygon(const b2Vec2* aVertices, int32 aVertexCount, const b2Color& aColor);
void DrawSolidCircle(const b2Vec2& aCenter, float32 aRadius, const b2Vec2& aAxis, const b2Color& aColor);

	/// Draw a closed polygon provided in CCW order.
	void DrawPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color);

	/// Draw a circle.
	void DrawCircle(const b2Vec2& center, float32 radius, const b2Color& color);

	/// Draw a line segment.
	void DrawSegment(const b2Vec2& p1, const b2Vec2& p2, const b2Color& color);

	/// Draw a transform. Choose your own length scale.
	/// @param xf a transform.
	void DrawTransform(const b2Transform& xf);

};
