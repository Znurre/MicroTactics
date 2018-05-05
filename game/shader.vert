in vec3 position;
in vec3 normal;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

out vec3 v_V;
out vec3 v_N;

void main()
{
	gl_Position = (projection * view * model) * vec4(position, 1);

	v_V = (view * model * vec4(position, 1)).xyz;
	v_N = (view * model * vec4(normal, 0)).xyz;
}
