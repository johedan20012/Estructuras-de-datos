#version 330 core
in vec3 vp;

out vec3 color;
void main() {
	color = vp;
	gl_Position = vec4(vp, 1.0);

}