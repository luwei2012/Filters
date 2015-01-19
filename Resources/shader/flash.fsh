#ifdef GL_ES
precision mediump float;
#endif
varying vec2 v_texCoord;
varying vec4 v_fragmentColor;

uniform float u_alpha;

void main(void)
{
  // Convert to greyscale using NTSC weightings
  vec4 color = texture2D(CC_Texture0, v_texCoord);
  gl_FragColor = vec4(color.r,color.g,color.b,u_alpha);
}