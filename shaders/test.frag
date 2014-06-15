#version 330

in vec2 UV;

layout(location = 0) out vec4 fragColor;

uniform sampler2D  myTextureSampler;

void main( void ){
	fragColor = vec4(0.5,0.5,0.5,1);//texture2D( myTextureSampler, UV ).rgba;
}

