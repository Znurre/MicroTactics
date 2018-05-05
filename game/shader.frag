in vec3 v_V;
in vec3 v_N;

uniform vec3 color;
uniform vec3 light;

out vec4 fragmentColor;

void main(void)
{
	const float threshold = 0.02;
	const float amb = 0.5;

	vec3 N = normalize(v_N);
	vec3 L = normalize(light);

	vec3 ambient = color.xyz * amb;
	vec3 diffuse = color.xyz * (1.0 - amb) * max(dot(L, N), 0.0);

	vec3 V = normalize(v_V);
	vec3 R = reflect(V, N);

	vec3 specular = vec3(1.0, 1.0, 1.0) * pow(max(dot(R, L), 0.0), 8.0);

	fragmentColor = vec4(ambient + diffuse + specular, 1.0);
}
