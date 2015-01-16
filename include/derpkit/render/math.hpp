#ifndef DERPKIT_RENDER_MATH_HPP
#define DERPKIT_RENDER_MATH_HPP

#include <cmath>

#ifdef ENABLE_DEBUG
#include <ostream>
#endif

namespace derpkit {
namespace render {

struct DERPKIT_EXPORT vec2 {
	vec2(float v=0.f);
	vec2(float x, float y);

	float x;
	float y;

	float length() const;

	vec2 operator*(float f) const;
	vec2 operator*(const vec2& v) const;
	vec2 operator+(const vec2& v) const;
	vec2 operator-(const vec2& v) const;
};

struct DERPKIT_EXPORT ivec2 {
	ivec2(int v=0);
	ivec2(int x, int y);

	int x;
	int y;

	float length() const;
};

struct DERPKIT_EXPORT vec3 {
	vec3(float v=0.f);
	vec3(float x, float y, float z);

	union {
		struct {
			float x;
			float y;
			float z;
		};
		struct {
			float r;
			float g;
			float b;
		};
		float value[3];
	};

	float length() const;
};

struct DERPKIT_EXPORT vec4 {
	vec4(float v=0.f);
	vec4(float x, float y, float z, float w);

	union {
		struct {
			float x;
			float y;
			float z;
			float w;
		};
		struct {
			float r;
			float g;
			float b;
			float a;
		};
	};

	float length() const;
};

struct DERPKIT_EXPORT box {
	box();
	box(float x, float y, float w, float h);

	float x;
	float y;
	float w;
	float h;
};

struct DERPKIT_EXPORT mat3 {
	mat3();
	mat3(float m00, float m01, float m02,
		 float m10, float m11, float m12,
		 float m20, float m21, float m22);
	mat3(const mat3& m);

	union {
		float m[9];
		vec3 row[3];
	};

	mat3 operator*(const mat3& m) const;
};

class DERPKIT_EXPORT Transform {
	Transform();
	Transform(const vec2& pos);
	Transform(const vec2& pos, float rotation);
	Transform(float rotation);
	Transform(const vec2& pos, float rotation, const vec2& scale);

	void set_position(const vec2& pos);
	void set_rotation(float rot);
	void set_scale(const vec2& scale);

	bool has_position() const { return m_has_position; }
	bool has_rotation() const { return m_has_rotation; }
	bool has_scale() const { return m_has_scale; }

	const vec2& position() const { return m_position; }
	float rotation() const { return m_rotation; }
	const vec2& scale() const { return m_scale; }
private:
	bool m_has_position;
	bool m_has_rotation;
	bool m_has_scale;

	vec2 m_position;
	float m_rotation;
	vec2 m_scale;
};

inline const float* value_ptr(const vec2& v) { return reinterpret_cast<const float*>(&v); }
inline const float* value_ptr(const vec3& v) { return reinterpret_cast<const float*>(&v); }
inline const float* value_ptr(const vec4& v) { return reinterpret_cast<const float*>(&v); }
inline const float* value_ptr(const mat3& m) { return m.m; }

float DERPKIT_EXPORT dot(const vec2& v1, const vec2& v2);
float DERPKIT_EXPORT dot(const vec3& v1, const vec3& v2);
float DERPKIT_EXPORT dot(const vec4& v1, const vec4& v2);

vec2 DERPKIT_EXPORT normalized(const vec2& v);
vec3 DERPKIT_EXPORT normalized(const vec3& v);
vec4 DERPKIT_EXPORT normalized(const vec4& v);

mat3 DERPKIT_EXPORT ortho(const ivec2& size);
mat3 DERPKIT_EXPORT model_matrix(const vec2& pos, const vec2& size);
mat3 DERPKIT_EXPORT model_matrix(const box& box);

#ifdef ENABLE_DEBUG
std::ostream& operator<<(std::ostream& os, const vec3& m);
std::ostream& operator<<(std::ostream& os, const mat3& m);
#endif

}
}

#endif
