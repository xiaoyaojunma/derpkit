#version 130
#pragma stage fragment

uniform vec4 color = vec4(1.f);

in vec2 uv;

out vec4 out_color;

void main() {
	out_color = color;
}
