#version 330 core
uniform float adicion;

in vec3 color;

out vec4 frag_colour;

void main(){
	vec3 aux = color;
	aux.x = (aux.x+1) * adicion;

	aux.z = (aux.y+1) * adicion;

	aux.x = aux.x + aux.x * aux.x;
	
	aux.z = aux.z + aux.z * aux.z;


	aux.x = int(aux.x) % 256;
	
	aux.z = int(aux.z) % 256;

	aux.x /= 255;

	aux.z /= 255;

	aux.y = 0;

	frag_colour = vec4(aux.x,aux.y,aux.z,1.0); //vec4(0.5, 0.5, 0.5,1.0);
}