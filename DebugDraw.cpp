#include "DebugDraw.h"

DebugDraw::DebugDraw(float32 aRatio) : _ptmRatio(aRatio)
{
}

void DebugDraw::DrawSolidPolygon(const b2Vec2* aVertices, int32 aVertexCount, const b2Color& aColor)
{

}

void DebugDraw::DrawSolidCircle(const b2Vec2& aCenter, float32 aRadius, const b2Vec2& aAxis, const b2Color& aColor)
{

}

	/// Draw a closed polygon provided in CCW order.
	void DebugDraw::DrawPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color) {}

	/// Draw a circle.
	void DebugDraw::DrawCircle(const b2Vec2& center, float32 radius, const b2Color& color) {}

	/// Draw a line segment.
	void DebugDraw::DrawSegment(const b2Vec2& p1, const b2Vec2& p2, const b2Color& color) {}
	/// Draw a transform. Choose your own length scale.
	/// @param xf a transform.
	void DebugDraw::DrawTransform(const b2Transform& xf) {}
