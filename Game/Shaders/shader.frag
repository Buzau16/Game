#version 460 core

uniform vec3 vCol;
out vec4 color;

void main(){
	color = vec4(vCol, 1.0f);
}