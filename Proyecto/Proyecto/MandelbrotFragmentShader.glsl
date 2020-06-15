#version 330 core

precision highp float;

uniform sampler1D tex;
uniform float scala;

vec2 center;
float scale;
int iter;

in vec3 color;

out vec4 frag_colour;

void main() {
	center.x = -0.5f;
	center.y = -0.5f;
	scale =0.01f;
	iter = 1000;
	
	scale = scala;

    vec2 z, c;

    c.x = 1.3333 * (color.x - 0.5) * scale - center.x;
    c.y = (color.y - 0.5) * scale - center.y;

    int i;
    z = c;
    for(i=0; i<iter; i++) {
        float x = (z.x * z.x - z.y * z.y) + c.x;
        float y = (z.y * z.x + z.x * z.y) + c.y;

        if((x * x + y * y) > 4.0) break;
        z.x = x;
        z.y = y;
    }

	float posi = (i == iter ? 0.0 : float(i)) / 100.0;
	if(posi>19){
		posi = 10;
	}
    frag_colour = texture(tex,posi );
}