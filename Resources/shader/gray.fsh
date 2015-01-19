#ifdef GL_ES
precision mediump float;
#endif
varying vec2 v_texCoord;
varying vec4 v_fragmentColor;
uniform vec4 u_paramColor;

void main(void)
{
    vec4 v_orColor = v_fragmentColor * texture2D(CC_Texture0, v_texCoord);
    float gray = dot(v_orColor.rgb, u_paramColor.rgb);
	gl_FragColor = vec4(gray,gray,gray,v_orColor.a);
     
}