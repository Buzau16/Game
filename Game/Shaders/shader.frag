#version 460 core


in vec2 texCoord;

uniform vec3 vCol;
uniform sampler2D Texture;
uniform bool hasTexture;

out vec4 color;

void main(){
	if(hasTexture){
		color = texture(Texture, texCoord);
	}else{
		color = vec4(vCol, 1.0f);
	}
}