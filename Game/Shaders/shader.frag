#version 460 core

uniform vec3 vCol;
uniform sampler2D texture;

out vec4 color;

void main(){
	color = vec4(vCol, 1.0f);
}