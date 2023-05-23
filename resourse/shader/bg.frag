#version 330 core

out vec4 FragColor; // 输出颜色

in vec2 TexCord; // 输入的纹理坐标

uniform sampler2D m_texture; // 输入的纹理采样器
uniform float dx; // x 方向的偏移量
uniform float dy; // y 方向的偏移量

void main(void)
{
    FragColor = texture(m_texture, vec2(TexCord.x + dx, TexCord.y + dy)); // 对纹理进行采样并输出颜色
}
