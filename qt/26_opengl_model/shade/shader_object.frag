#version 330 core
out vec4 FragColor;

in vec3 FragPos;
in vec3 Normal;

void main(){
    //vec3 norm = normalize(Normal);
    //vec3 viewDir = normalize(viewPos - FragPos);

    FragColor = vec4(0.2f, 0.8f, 0.8f, 1.0f);
}
