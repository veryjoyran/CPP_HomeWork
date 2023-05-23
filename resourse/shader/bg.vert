#version 330 core

layout(location = 0) in vec3 aPos; // 输入顶点位置
layout(location = 1) in vec2 aTexCord; // 输入纹理坐标

out vec2 TexCord; // 输出纹理坐标

void main()
{
    gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0f); // 设置变换后的顶点位置
    TexCord = aTexCord; // 传递纹理坐标给片段着色器
}
