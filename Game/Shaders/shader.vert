#version 460 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aUV;

uniform mat4 MVP;

out vec2 texCoord;

void main(){
	
	texCoord = aUV;
	
	gl_Position = MVP * vec4(aPos, 1.0);
}