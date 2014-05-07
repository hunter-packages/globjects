#pragma once

#include <GL/glew.h>

#include <glbinding/constants.h>

#include <glow/glow_api.h>
#include <glow/Object.h>

namespace glow 
{

class ObjectVisitor;

/** \brief Encapsulates OpenGL render buffer objects.
 
    \see http://www.opengl.org/wiki/Renderbuffer_Objects
 */
class GLOW_API RenderBufferObject : public Object
{
public:
    RenderBufferObject();

    virtual void accept(ObjectVisitor & visitor) override;

    void bind(GLenum target = gl::RENDERBUFFER) const;
    static void unbind(GLenum target = gl::RENDERBUFFER);

    void storage(GLenum internalformat, GLsizei width, GLsizei height);
    void storageMultisample(GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);

    GLint getParameter(GLenum pname) const;
protected:
    virtual ~RenderBufferObject();

	static GLuint genRenderBuffer();
};

} // namespace glow
