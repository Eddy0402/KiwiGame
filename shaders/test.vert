#version 330

layout(location = 0)in vec3 vertexPosition;
layout(location = 0)in vec3 vertexNormal;
layout(location = 1)in vec2 vertexUV;

uniform mat4 MVP;

out vec3 normal;
out vec2 UV;

void main( void )
{
	gl_Position =  MVP * vec4(vertexPosition,1.0);
	normal = vertexNormal ;
	UV = vertexUV;
}
/*
attribute vec4 qt_Vertex;
attribute vec4 qt_MultiTexCoord0;
uniform mat4 qt_ModelViewProjectionMatrix;
varying vec4 qt_TexCoord0;

void main(void)
{
	gl_Position = qt_ModelViewProjectionMatrix * qt_Vertex;
	qt_TexCoord0 = qt_MultiTexCoord0;
}
*/
