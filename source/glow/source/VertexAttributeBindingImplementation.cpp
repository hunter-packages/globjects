#include "VertexAttributeBindingImplementation.h"

#include <cassert>

#include <glow/Error.h>
#include <glow/Buffer.h>
#include <glow/VertexArrayObject.h>
#include <glow/VertexAttributeBinding.h>

namespace glow {

VertexAttributeBindingImplementation::VertexAttributeBindingImplementation(const VertexAttributeBinding* binding)
: m_binding(binding)
{
    assert(binding != nullptr);
}

VertexAttributeBindingImplementation::~VertexAttributeBindingImplementation()
{
}

GLint VertexAttributeBindingImplementation::attributeIndex() const
{
    return m_binding->m_attributeIndex;
}

GLint VertexAttributeBindingImplementation::bindingIndex() const
{
    return m_binding->m_bindingIndex;
}

const VertexArrayObject* VertexAttributeBindingImplementation::vao() const
{
    return m_binding->m_vao;
}

const Buffer* VertexAttributeBindingImplementation::vbo() const
{
    return m_binding->m_vbo;
}


VertexAttributeBinding_GL_3_0::VertexAttributeBinding_GL_3_0(const VertexAttributeBinding* binding)
: VertexAttributeBindingImplementation(binding)
, m_baseoffset(0)
, m_stride(0)
, m_hasFormat(false)
, m_hasBuffer(false)
, m_hasAttribute(false)
{
}

void VertexAttributeBinding_GL_3_0::bindAttribute(GLint /*attributeIndex*/)
{
    m_hasAttribute = true;
    finishIfComplete();
}

void VertexAttributeBinding_GL_3_0::bindBuffer(const Buffer* /*vbo*/, GLint baseoffset, GLint stride)
{
    //assert(vbo != nullptr);

    m_baseoffset = baseoffset;
    m_stride = stride;

    m_hasBuffer = true;
    finishIfComplete();
}

void VertexAttributeBinding_GL_3_0::setFormat(GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset)
{
    m_format = Format(Format::O, size, type, normalized, relativeoffset);

    m_hasFormat = true;
    finishIfComplete();
}

void VertexAttributeBinding_GL_3_0::setIFormat(GLint size, GLenum type, GLuint relativeoffset)
{
    m_format = Format(Format::I, size, type, gl::FALSE, relativeoffset);

    m_hasFormat = true;
    finishIfComplete();
}

void VertexAttributeBinding_GL_3_0::setLFormat(GLint size, GLenum type, GLuint relativeoffset)
{
    m_format = Format(Format::L, size, type, gl::FALSE, relativeoffset);

    m_hasFormat = true;
    finishIfComplete();
}

void VertexAttributeBinding_GL_3_0::finishIfComplete()
{
    if (m_hasAttribute && m_hasFormat && m_hasBuffer)
    {
        finish();
    }
}

void VertexAttributeBinding_GL_3_0::finish()
{
    vao()->bind();
    void * offset = nullptr;
    
    if (vbo())
    {
        vbo()->bind(gl::ARRAY_BUFFER);
        offset = reinterpret_cast<void*>(m_baseoffset + m_format.relativeoffset);
    }
    else
    {
        Buffer::unbind(gl::ARRAY_BUFFER);
    }


    const GLint attribute = attributeIndex();

    switch (m_format.method)
    {
    case Format::I:
        glVertexAttribIPointer(attribute, m_format.size, m_format.type, m_stride, offset);
        CheckGLError();
        break;
    case Format::L:
        glVertexAttribLPointer(attribute, m_format.size, m_format.type, m_stride, offset);
        CheckGLError();
        break;
    default:
        glVertexAttribPointer(attribute, m_format.size, m_format.type, m_format.normalized, m_stride, offset);
        CheckGLError();
    }
}

VertexAttributeBinding_GL_3_0::Format::Format()
: method(O)
, size(0)
, type(0)
, normalized(gl::FALSE)
, relativeoffset(0)
{
}

VertexAttributeBinding_GL_3_0::Format::Format(Method method, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset)
: method(method)
, size(size)
, type(type)
, normalized(normalized)
, relativeoffset(relativeoffset)
{
}


VertexAttributeBinding_GL_4_3::VertexAttributeBinding_GL_4_3(const VertexAttributeBinding* binding)
: VertexAttributeBindingImplementation(binding)
{
}

void VertexAttributeBinding_GL_4_3::bindAttribute(GLint attributeIndex)
{
    vao()->bind();

    glVertexAttribBinding(attributeIndex, bindingIndex());
    CheckGLError();
}

void VertexAttributeBinding_GL_4_3::bindBuffer(const Buffer* vbo, GLint baseoffset, GLint stride)
{
    vao()->bind();

    glBindVertexBuffer(bindingIndex(), vbo ? vbo->id() : 0, baseoffset, stride);
    CheckGLError();
}

void VertexAttributeBinding_GL_4_3::setFormat(GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset)
{
    vao()->bind();

    glVertexAttribFormat(attributeIndex(), size, type, normalized, relativeoffset);
    CheckGLError();
}

void VertexAttributeBinding_GL_4_3::setIFormat(GLint size, GLenum type, GLuint relativeoffset)
{
    vao()->bind();

    glVertexAttribIFormat(attributeIndex(), size, type, relativeoffset);
    CheckGLError();
}

void VertexAttributeBinding_GL_4_3::setLFormat(GLint size, GLenum type, GLuint relativeoffset)
{
    vao()->bind();

    glVertexAttribLFormat(attributeIndex(), size, type, relativeoffset);
    CheckGLError();
}

} // namespace glow
