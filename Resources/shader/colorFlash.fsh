#ifdef GL_ES
precision mediump float;
#endif
varying vec2 v_texCoord;
varying vec4 v_fragmentColor;
uniform vec3 u_color;
float Density = 4.0;
float Exposure = 1.0;
void main(void)
{
	vec4 color = texture2D(CC_Texture0, v_texCoord);
	color.rgb *= u_color.rgb;
	gl_FragColor = color;
}