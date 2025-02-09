#version 410 core

out vec4 FragColor;

in vec2 texCoords;

uniform sampler2D gPosition;
uniform sampler2D gAlbedoSpec;

struct Light {
    vec2 pos;
    vec3 color;

    float radius;
    float intensity;
};

uniform Light light;

void main() {
    // Retrieve data from g-buffer
    vec2 fragPos = texture(gPosition, texCoords).rg;
    vec3 diffuse = texture(gAlbedoSpec, texCoords).rgb;

    float distance = distance(fragPos, light.pos);
    float attenuation = max(0.0, 1.0 - distance / light.radius);
    diffuse *= (attenuation * attenuation * light.intensity * light.color);

    FragColor = vec4(diffuse, 1);
}
