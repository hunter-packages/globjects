#include "LegacyUniformImplementation.h"

#include <glm/gtc/type_ptr.hpp>

#include <glbinding/constants.h>
#include <glbinding/functions.h>

#include <glow/Error.h>

namespace glow
{

void LegacyUniformImplementation::set(const Program * program, const gl::GLint location, const float & value) const
{
    program->use();
    gl::Uniform1f(location, value);
    CheckGLError();
}

void LegacyUniformImplementation::set(const Program * program, const gl::GLint location, const int & value) const
{
    program->use();
    gl::Uniform1i(location, value);
    CheckGLError();
}

void LegacyUniformImplementation::set(const Program * program, const gl::GLint location, const unsigned int & value) const
{
    program->use();
    gl::Uniform1ui(location, value);
    CheckGLError();
}

void LegacyUniformImplementation::set(const Program * program, const gl::GLint location, const bool & value) const
{
    program->use();
    gl::Uniform1i(location, value ? 1 : 0);
    CheckGLError();
}

void LegacyUniformImplementation::set(const Program * program, const gl::GLint location, const glm::vec2 & value) const
{
    program->use();
    gl::Uniform2fv(location, 1, glm::value_ptr(value));
    CheckGLError();
}

void LegacyUniformImplementation::set(const Program * program, const gl::GLint location, const glm::vec3 & value) const
{
    program->use();
    gl::Uniform3fv(location, 1, glm::value_ptr(value));
    CheckGLError();
}

void LegacyUniformImplementation::set(const Program * program, const gl::GLint location, const glm::vec4 & value) const
{
    program->use();
    gl::Uniform4fv(location, 1, glm::value_ptr(value));
    CheckGLError();
}

void LegacyUniformImplementation::set(const Program * program, const gl::GLint location, const glm::ivec2 & value) const
{
    program->use();
    gl::Uniform2iv(location, 1, glm::value_ptr(value));
    CheckGLError();
}

void LegacyUniformImplementation::set(const Program * program, const gl::GLint location, const glm::ivec3 & value) const
{
    program->use();
    gl::Uniform3iv(location, 1, glm::value_ptr(value));
    CheckGLError();
}

void LegacyUniformImplementation::set(const Program * program, const gl::GLint location, const glm::ivec4 & value) const
{
    program->use();
    gl::Uniform4iv(location, 1, glm::value_ptr(value));
    CheckGLError();
}

void LegacyUniformImplementation::set(const Program * program, const gl::GLint location, const glm::uvec2 & value) const
{
    program->use();
    gl::Uniform2uiv(location, 1, glm::value_ptr(value));
    CheckGLError();
}

void LegacyUniformImplementation::set(const Program * program, const gl::GLint location, const glm::uvec3 & value) const
{
    program->use();
    gl::Uniform3uiv(location, 1, glm::value_ptr(value));
    CheckGLError();
}

void LegacyUniformImplementation::set(const Program * program, const gl::GLint location, const glm::uvec4 & value) const
{
    program->use();
    gl::Uniform4uiv(location, 1, glm::value_ptr(value));
    CheckGLError();
}

void LegacyUniformImplementation::set(const Program * program, const gl::GLint location, const glm::mat2 & value) const
{
    program->use();
    gl::UniformMatrix2fv(location, 1, gl::FALSE, glm::value_ptr(value));
    CheckGLError();
}

void LegacyUniformImplementation::set(const Program * program, const gl::GLint location, const glm::mat3 & value) const
{
    program->use();
    gl::UniformMatrix3fv(location, 1, gl::FALSE, glm::value_ptr(value));
    CheckGLError();
}

void LegacyUniformImplementation::set(const Program * program, const gl::GLint location, const glm::mat4 & value) const
{
    program->use();
    gl::UniformMatrix4fv(location, 1, gl::FALSE, glm::value_ptr(value));
    CheckGLError();
}

void LegacyUniformImplementation::set(const Program * program, const gl::GLint location, const glm::mat2x3 & value) const
{
    program->use();
    gl::UniformMatrix2x3fv(location, 1, gl::FALSE, glm::value_ptr(value));
    CheckGLError();
}

void LegacyUniformImplementation::set(const Program * program, const gl::GLint location, const glm::mat3x2 & value) const
{
    program->use();
    gl::UniformMatrix3x2fv(location, 1, gl::FALSE, glm::value_ptr(value));
    CheckGLError();
}

void LegacyUniformImplementation::set(const Program * program, const gl::GLint location, const glm::mat2x4 & value) const
{
    program->use();
    gl::UniformMatrix2x4fv(location, 1, gl::FALSE, glm::value_ptr(value));
    CheckGLError();
}

void LegacyUniformImplementation::set(const Program * program, const gl::GLint location, const glm::mat4x2 & value) const
{
    program->use();
    gl::UniformMatrix4x2fv(location, 1, gl::FALSE, glm::value_ptr(value));
    CheckGLError();
}

void LegacyUniformImplementation::set(const Program * program, const gl::GLint location, const glm::mat3x4 & value) const
{
    program->use();
    gl::UniformMatrix3x4fv(location, 1, gl::FALSE, glm::value_ptr(value));
    CheckGLError();
}

void LegacyUniformImplementation::set(const Program * program, const gl::GLint location, const glm::mat4x3 & value) const
{
    program->use();
    gl::UniformMatrix4x3fv(location, 1, gl::FALSE, glm::value_ptr(value));
    CheckGLError();
}

void LegacyUniformImplementation::set(const Program * program, const gl::GLint location, const TextureHandle & value) const
{
    program->use();
    gl::UniformHandleui64ARB(location, value);
    CheckGLError();
}

void LegacyUniformImplementation::set(const Program * program, const gl::GLint location, const std::vector<float> & value) const
{
    program->use();
    gl::Uniform1fv(location, static_cast<gl::GLint>(value.size()), value.data());
    CheckGLError();
}

void LegacyUniformImplementation::set(const Program * program, const gl::GLint location, const std::vector<int> & value) const
{
    program->use();
    gl::Uniform1iv(location, static_cast<gl::GLint>(value.size()), value.data());
    CheckGLError();
}

void LegacyUniformImplementation::set(const Program * program, const gl::GLint location, const std::vector<unsigned int> & value) const
{
    program->use();
    gl::Uniform1uiv(location, static_cast<gl::GLint>(value.size()), value.data());
    CheckGLError();
}

void LegacyUniformImplementation::set(const Program * program, gl::GLint location, const std::vector<bool> & value) const
{
    std::vector<int> values(value.size());
    for (unsigned i = 0; i < values.size(); ++i)
    {
        values[i] = value[i] ? 1 : 0;
    }

    program->use();
    gl::Uniform1iv(location, static_cast<gl::GLint>(values.size()), values.data());
    CheckGLError();
}

void LegacyUniformImplementation::set(const Program * program, const gl::GLint location, const std::vector<glm::vec2> & value) const
{
    program->use();
    gl::Uniform2fv(location, static_cast<gl::GLint>(value.size()), reinterpret_cast<const float*>(value.data()));
    CheckGLError();
}

void LegacyUniformImplementation::set(const Program * program, const gl::GLint location, const std::vector<glm::vec3> & value) const
{
    program->use();
    gl::Uniform3fv(location, static_cast<gl::GLint>(value.size()), reinterpret_cast<const float*>(value.data()));
    CheckGLError();
}

void LegacyUniformImplementation::set(const Program * program, const gl::GLint location, const std::vector<glm::vec4> & value) const
{
    program->use();
    gl::Uniform4fv(location, static_cast<gl::GLint>(value.size()), reinterpret_cast<const float*>(value.data()));
    CheckGLError();
}

void LegacyUniformImplementation::set(const Program * program, const gl::GLint location, const std::vector<glm::ivec2> & value) const
{
    program->use();
    gl::Uniform2iv(location, static_cast<gl::GLint>(value.size()), reinterpret_cast<const int*>(value.data()));
    CheckGLError();
}

void LegacyUniformImplementation::set(const Program * program, const gl::GLint location, const std::vector<glm::ivec3> & value) const
{
    program->use();
    gl::Uniform3iv(location, static_cast<gl::GLint>(value.size()), reinterpret_cast<const int*>(value.data()));
    CheckGLError();
}

void LegacyUniformImplementation::set(const Program * program, const gl::GLint location, const std::vector<glm::ivec4> & value) const
{
    program->use();
    gl::Uniform4iv(location, static_cast<gl::GLint>(value.size()), reinterpret_cast<const int*>(value.data()));
    CheckGLError();
}

void LegacyUniformImplementation::set(const Program * program, const gl::GLint location, const std::vector<glm::uvec2> & value) const
{
    program->use();
    gl::Uniform2uiv(location, static_cast<gl::GLint>(value.size()), reinterpret_cast<const unsigned*>(value.data()));
    CheckGLError();
}

void LegacyUniformImplementation::set(const Program * program, const gl::GLint location, const std::vector<glm::uvec3> & value) const
{
    program->use();
    gl::Uniform3uiv(location, static_cast<gl::GLint>(value.size()), reinterpret_cast<const unsigned*>(value.data()));
    CheckGLError();
}

void LegacyUniformImplementation::set(const Program * program, const gl::GLint location, const std::vector<glm::uvec4> & value) const
{
    program->use();
    gl::Uniform4uiv(location, static_cast<gl::GLint>(value.size()), reinterpret_cast<const unsigned*>(value.data()));
    CheckGLError();
}

void LegacyUniformImplementation::set(const Program * program, const gl::GLint location, const std::vector<glm::mat2> & value) const
{
    program->use();
    gl::UniformMatrix2fv(location, static_cast<gl::GLint>(value.size()), gl::FALSE, reinterpret_cast<const float*>(value.data()));
    CheckGLError();
}

void LegacyUniformImplementation::set(const Program * program, const gl::GLint location, const std::vector<glm::mat3> & value) const
{
    program->use();
    gl::UniformMatrix3fv(location, static_cast<gl::GLint>(value.size()), gl::FALSE, reinterpret_cast<const float*>(value.data()));
    CheckGLError();
}

void LegacyUniformImplementation::set(const Program * program, const gl::GLint location, const std::vector<glm::mat4> & value) const
{
    program->use();
    gl::UniformMatrix4fv(location, static_cast<gl::GLint>(value.size()), gl::FALSE, reinterpret_cast<const float*>(value.data()));
    CheckGLError();
}

void LegacyUniformImplementation::set(const Program * program, const gl::GLint location, const std::vector<glm::mat2x3> & value) const
{
    program->use();
    gl::UniformMatrix2x3fv(location, static_cast<gl::GLint>(value.size()), gl::FALSE, reinterpret_cast<const float*>(value.data()));
    CheckGLError();
}

void LegacyUniformImplementation::set(const Program * program, const gl::GLint location, const std::vector<glm::mat3x2> & value) const
{
    program->use();
    gl::UniformMatrix3x2fv(location, static_cast<gl::GLint>(value.size()), gl::FALSE, reinterpret_cast<const float*>(value.data()));
    CheckGLError();
}

void LegacyUniformImplementation::set(const Program * program, const gl::GLint location, const std::vector<glm::mat2x4> & value) const
{
    program->use();
    gl::UniformMatrix2x4fv(location, static_cast<gl::GLint>(value.size()), gl::FALSE, reinterpret_cast<const float*>(value.data()));
    CheckGLError();
}

void LegacyUniformImplementation::set(const Program * program, const gl::GLint location, const std::vector<glm::mat4x2> & value) const
{
    program->use();
    gl::UniformMatrix4x2fv(location, static_cast<gl::GLint>(value.size()), gl::FALSE, reinterpret_cast<const float*>(value.data()));
    CheckGLError();
}

void LegacyUniformImplementation::set(const Program * program, const gl::GLint location, const std::vector<glm::mat3x4> & value) const
{
    program->use();
    gl::UniformMatrix3x4fv(location, static_cast<gl::GLint>(value.size()), gl::FALSE, reinterpret_cast<const float*>(value.data()));
    CheckGLError();
}

void LegacyUniformImplementation::set(const Program * program, const gl::GLint location, const std::vector<glm::mat4x3> & value) const
{
    program->use();
    gl::UniformMatrix4x3fv(location, static_cast<gl::GLint>(value.size()), gl::FALSE, reinterpret_cast<const float*>(value.data()));
    CheckGLError();
}

void LegacyUniformImplementation::set(const Program * program, const gl::GLint location, const std::vector<TextureHandle> & value) const
{
    program->use();
    gl::UniformHandleui64vARB(location, static_cast<gl::GLint>(value.size()), value.data());
    CheckGLError();
}

} // namespace glow
