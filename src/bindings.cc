#include <napi.h>
#include <GL/glew.h>
#include <iostream>

void setObjPtr(Napi::Env env, Napi::Object obj, Napi::Value value) {
    obj.Set("$", value);
}

template <typename T>
T getObjPtr(Napi::Env env, Napi::Object obj) {
    return obj.Get("$").As<T>();
}

#define INIT_METHOD Napi::Env env = info.Env(); \
    Napi::HandleScope scope(env);

#define EXPORT_GL(name) gl.Set(#name, Napi::Function::New(env, __##name, #name));
#define EXPORT_GLEW(name) glew.Set(#name, Napi::Function::New(env, __##name, #name));

// GLEW methods

Napi::Number __glewInit(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);
  
    return Napi::Number::New(env, glewInit());
}

Napi::Boolean __glewIsSupported(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    const char* extension = info[0].As<Napi::String>().Utf8Value().c_str();
  
    return Napi::Boolean::New(env, glewIsSupported(extension));
}

Napi::Boolean __glewGetExtension(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    const char* extension = info[0].As<Napi::String>().Utf8Value().c_str();
  
    return Napi::Boolean::New(env, glewGetExtension(extension));
}

Napi::String __glewGetErrorString(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    int error = info[0].As<Napi::Number>().Int32Value();
  
    return Napi::String::New(env, (const char*)glewGetErrorString(error));
}

Napi::String __glewGetString(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    int name = info[0].As<Napi::Number>().Int32Value();
  
    return Napi::String::New(env, (const char*)glewGetString(name));
}

// OpenGL Core 1.1 methods
void __glAccum(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    int op = info[0].As<Napi::Number>().Int32Value();
    float value = info[1].As<Napi::Number>().FloatValue();
  
    glAccum(op, value);
}

void __glAlphaFunc(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    int func = info[0].As<Napi::Number>().Int32Value();
    float ref = info[1].As<Napi::Number>().FloatValue();
  
    glAlphaFunc(func, ref);
}

Napi::Boolean __glAreTexturesResident(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    int n = info[0].As<Napi::Number>().Uint32Value();
    GLuint* textures = info[1].As<Napi::Uint32Array>().Data();
    Napi::Array _residences = info[2].As<Napi::Array>();

    bool* residences = new bool[n];
    bool ret = glAreTexturesResident(n, textures, (GLboolean*)residences);

    for (int i = 0; i < n; i++) {
        _residences.Set(i, Napi::Boolean::New(env, residences[i]));
    }

    delete[] residences;

    return Napi::Boolean::New(env, ret);
}

void __glArrayElement(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    int i = info[0].As<Napi::Number>().Int32Value();
  
    glArrayElement(i);
}

void __glBegin(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    int mode = info[0].As<Napi::Number>().Int32Value();
  
    glBegin(mode);
}

void __glBindTexture(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    int target = info[0].As<Napi::Number>().Int32Value();
    int texture = info[1].As<Napi::Number>().Int32Value();
  
    glBindTexture(target, texture);
}

void __glBitmap(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    int width = info[0].As<Napi::Number>().Int32Value();
    int height = info[1].As<Napi::Number>().Int32Value();
    float xorig = info[2].As<Napi::Number>().FloatValue();
    float yorig = info[3].As<Napi::Number>().FloatValue();
    float xmove = info[4].As<Napi::Number>().FloatValue();
    float ymove = info[5].As<Napi::Number>().FloatValue();
    const GLubyte* bitmap = info[6].As<Napi::Uint8Array>().Data();
  
    glBitmap(width, height, xorig, yorig, xmove, ymove, bitmap);
}

void __glBlendFunc(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    int sfactor = info[0].As<Napi::Number>().Int32Value();
    int dfactor = info[1].As<Napi::Number>().Int32Value();
  
    glBlendFunc(sfactor, dfactor);
}

void __glCallList(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    int list = info[0].As<Napi::Number>().Int32Value();
  
    glCallList(list);
}

void __glCallLists(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    int n = info[0].As<Napi::Number>().Int32Value();
    GLenum type = info[1].As<Napi::Number>().Int32Value();
    const void* lists = info[2].As<Napi::Buffer<GLubyte>>().Data();

    glCallLists(n, type, lists);
}

void __glClear(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    int mask = info[0].As<Napi::Number>().Int32Value();
  
    glClear(mask);
}

void __glClearAccum(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    float red = info[0].As<Napi::Number>().FloatValue();
    float green = info[1].As<Napi::Number>().FloatValue();
    float blue = info[2].As<Napi::Number>().FloatValue();
    float alpha = info[3].As<Napi::Number>().FloatValue();
  
    glClearAccum(red, green, blue, alpha);
}

void __glClearColor(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    float red = info[0].As<Napi::Number>().FloatValue();
    float green = info[1].As<Napi::Number>().FloatValue();
    float blue = info[2].As<Napi::Number>().FloatValue();
    float alpha = info[3].As<Napi::Number>().FloatValue();
  
    glClearColor(red, green, blue, alpha);
}

void __glClearDepth(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    double depth = info[0].As<Napi::Number>().DoubleValue();
  
    glClearDepth(depth);
}

void __glClearIndex(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    float c = info[0].As<Napi::Number>().FloatValue();
  
    glClearIndex(c);
}

void __glClearStencil(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    int s = info[0].As<Napi::Number>().Int32Value();
  
    glClearStencil(s);
}

void __glClipPlane(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    int plane = info[0].As<Napi::Number>().Int32Value();
    const GLdouble* equation = info[1].As<Napi::Float64Array>().Data();
  
    glClipPlane(plane, equation);
}

void __glColor3b(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    int red = info[0].As<Napi::Number>().Int32Value();
    int green = info[1].As<Napi::Number>().Int32Value();
    int blue = info[2].As<Napi::Number>().Int32Value();
  
    glColor3b(red, green, blue);
}

void __glColor3bv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    const GLbyte* v = info[0].As<Napi::Int8Array>().Data();
  
    glColor3bv(v);
}

void __glColor3d(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    double red = info[0].As<Napi::Number>().DoubleValue();
    double green = info[1].As<Napi::Number>().DoubleValue();
    double blue = info[2].As<Napi::Number>().DoubleValue();
  
    glColor3d(red, green, blue);
}

void __glColor3dv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    const GLdouble* v = info[0].As<Napi::Float64Array>().Data();
  
    glColor3dv(v);
}

void __glColor3f(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    float red = info[0].As<Napi::Number>().FloatValue();
    float green = info[1].As<Napi::Number>().FloatValue();
    float blue = info[2].As<Napi::Number>().FloatValue();
  
    glColor3f(red, green, blue);
}

void __glColor3fv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    const GLfloat* v = info[0].As<Napi::Float32Array>().Data();
  
    glColor3fv(v);
}

void __glColor3i(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    int red = info[0].As<Napi::Number>().Int32Value();
    int green = info[1].As<Napi::Number>().Int32Value();
    int blue = info[2].As<Napi::Number>().Int32Value();
  
    glColor3i(red, green, blue);
}

void __glColor3iv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    const GLint* v = info[0].As<Napi::Int32Array>().Data();
  
    glColor3iv(v);
}

void __glColor3s(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    int red = info[0].As<Napi::Number>().Int32Value();
    int green = info[1].As<Napi::Number>().Int32Value();
    int blue = info[2].As<Napi::Number>().Int32Value();
  
    glColor3s(red, green, blue);
}

void __glColor3sv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    const GLshort* v = info[0].As<Napi::Int16Array>().Data();
  
    glColor3sv(v);
}

void __glColor3ub(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    unsigned int red = info[0].As<Napi::Number>().Uint32Value();
    unsigned int green = info[1].As<Napi::Number>().Uint32Value();
    unsigned int blue = info[2].As<Napi::Number>().Uint32Value();
  
    glColor3ub(red, green, blue);
}

void __glColor3ubv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    const GLubyte* v = info[0].As<Napi::Uint8Array>().Data();
  
    glColor3ubv(v);
}

void __glColor3ui(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    unsigned int red = info[0].As<Napi::Number>().Uint32Value();
    unsigned int green = info[1].As<Napi::Number>().Uint32Value();
    unsigned int blue = info[2].As<Napi::Number>().Uint32Value();
  
    glColor3ui(red, green, blue);
}

void __glColor3uiv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    const GLuint* v = info[0].As<Napi::Uint32Array>().Data();
  
    glColor3uiv(v);
}

void __glColor3us(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    unsigned short red = info[0].As<Napi::Number>().Uint32Value();
    unsigned short green = info[1].As<Napi::Number>().Uint32Value();
    unsigned short blue = info[2].As<Napi::Number>().Uint32Value();
  
    glColor3us(red, green, blue);
}

void __glColor3usv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    const GLushort* v = info[0].As<Napi::Uint16Array>().Data();
  
    glColor3usv(v);
}

void __glColor4b(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    char red = info[0].As<Napi::Number>().Int32Value();
    char green = info[1].As<Napi::Number>().Int32Value();
    char blue = info[2].As<Napi::Number>().Int32Value();
    char alpha = info[3].As<Napi::Number>().Int32Value();
  
    glColor4b(red, green, blue, alpha);
}

void __glColor4bv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    const GLbyte* v = info[0].As<Napi::Int8Array>().Data();
  
    glColor4bv(v);
}

void __glColor4d(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    double red = info[0].As<Napi::Number>().DoubleValue();
    double green = info[1].As<Napi::Number>().DoubleValue();
    double blue = info[2].As<Napi::Number>().DoubleValue();
    double alpha = info[3].As<Napi::Number>().DoubleValue();
  
    glColor4d(red, green, blue, alpha);
}

void __glColor4dv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    const GLdouble* v = info[0].As<Napi::Float64Array>().Data();
  
    glColor4dv(v);
}

void __glColor4f(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    float red = info[0].As<Napi::Number>().FloatValue();
    float green = info[1].As<Napi::Number>().FloatValue();
    float blue = info[2].As<Napi::Number>().FloatValue();
    float alpha = info[3].As<Napi::Number>().FloatValue();
  
    glColor4f(red, green, blue, alpha);
}

void __glColor4fv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    const GLfloat* v = info[0].As<Napi::Float32Array>().Data();
  
    glColor4fv(v);
}

void __glColor4i(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    int red = info[0].As<Napi::Number>().Int32Value();
    int green = info[1].As<Napi::Number>().Int32Value();
    int blue = info[2].As<Napi::Number>().Int32Value();
    int alpha = info[3].As<Napi::Number>().Int32Value();
  
    glColor4i(red, green, blue, alpha);
}

void __glColor4iv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    const GLint* v = info[0].As<Napi::Int32Array>().Data();
  
    glColor4iv(v);
}

void __glColor4s(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    short red = info[0].As<Napi::Number>().Int32Value();
    short green = info[1].As<Napi::Number>().Int32Value();
    short blue = info[2].As<Napi::Number>().Int32Value();
    short alpha = info[3].As<Napi::Number>().Int32Value();
  
    glColor4s(red, green, blue, alpha);
}

void __glColor4sv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    const GLshort* v = info[0].As<Napi::Int16Array>().Data();
  
    glColor4sv(v);
}

void __glColor4ub(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    unsigned char red = info[0].As<Napi::Number>().Uint32Value();
    unsigned char green = info[1].As<Napi::Number>().Uint32Value();
    unsigned char blue = info[2].As<Napi::Number>().Uint32Value();
    unsigned char alpha = info[3].As<Napi::Number>().Uint32Value();
  
    glColor4ub(red, green, blue, alpha);
}

void __glColor4ubv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    const GLubyte* v = info[0].As<Napi::Uint8Array>().Data();
  
    glColor4ubv(v);
}

void __glColor4ui(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    unsigned int red = info[0].As<Napi::Number>().Uint32Value();
    unsigned int green = info[1].As<Napi::Number>().Uint32Value();
    unsigned int blue = info[2].As<Napi::Number>().Uint32Value();
    unsigned int alpha = info[3].As<Napi::Number>().Uint32Value();
  
    glColor4ui(red, green, blue, alpha);
}

void __glColor4uiv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    const GLuint* v = info[0].As<Napi::Uint32Array>().Data();
  
    glColor4uiv(v);
}

void __glColor4us(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    unsigned short red = info[0].As<Napi::Number>().Uint32Value();
    unsigned short green = info[1].As<Napi::Number>().Uint32Value();
    unsigned short blue = info[2].As<Napi::Number>().Uint32Value();
    unsigned short alpha = info[3].As<Napi::Number>().Uint32Value();
  
    glColor4us(red, green, blue, alpha);
}

void __glColor4usv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    const GLushort* v = info[0].As<Napi::Uint16Array>().Data();
  
    glColor4usv(v);
}

void __glColorMask(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    bool red = info[0].As<Napi::Boolean>().Value();
    bool green = info[1].As<Napi::Boolean>().Value();
    bool blue = info[2].As<Napi::Boolean>().Value();
    bool alpha = info[3].As<Napi::Boolean>().Value();
  
    glColorMask(red, green, blue, alpha);
}

void __glColorMaterial(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum face = info[0].As<Napi::Number>().Int32Value();
    GLenum mode = info[1].As<Napi::Number>().Int32Value();
  
    glColorMaterial(face, mode);
}

void __glColorPointer(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLint size = info[0].As<Napi::Number>().Int32Value();
    GLenum type = info[1].As<Napi::Number>().Int32Value();
    GLsizei stride = info[2].As<Napi::Number>().Int32Value();
    const void* pointer = info[3].As<Napi::Buffer<GLubyte>>().Data();

    glColorPointer(size, type, stride, pointer);
}

void __glCopyPixels(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLint x = info[0].As<Napi::Number>().Int32Value();
    GLint y = info[1].As<Napi::Number>().Int32Value();
    GLsizei width = info[2].As<Napi::Number>().Int32Value();
    GLsizei height = info[3].As<Napi::Number>().Int32Value();
    GLenum type = info[4].As<Napi::Number>().Int32Value();
  
    glCopyPixels(x, y, width, height, type);
}

void __glCopyTexImage1D(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum target = info[0].As<Napi::Number>().Int32Value();
    GLint level = info[1].As<Napi::Number>().Int32Value();
    GLenum internalFormat = info[2].As<Napi::Number>().Int32Value();
    GLint x = info[3].As<Napi::Number>().Int32Value();
    GLint y = info[4].As<Napi::Number>().Int32Value();
    GLsizei width = info[5].As<Napi::Number>().Int32Value();
    GLint border = info[6].As<Napi::Number>().Int32Value();

    glCopyTexImage1D(target, level, internalFormat, x, y, width, border);
}

void __glCopyTexImage2D(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum target = info[0].As<Napi::Number>().Int32Value();
    GLint level = info[1].As<Napi::Number>().Int32Value();
    GLenum internalFormat = info[2].As<Napi::Number>().Int32Value();
    GLint x = info[3].As<Napi::Number>().Int32Value();
    GLint y = info[4].As<Napi::Number>().Int32Value();
    GLsizei width = info[5].As<Napi::Number>().Int32Value();
    GLsizei height = info[6].As<Napi::Number>().Int32Value();
    GLint border = info[7].As<Napi::Number>().Int32Value();
  
    glCopyTexImage2D(target, level, internalFormat, x, y, width, height, border);
}

void __glCopyTexSubImage1D(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum target = info[0].As<Napi::Number>().Int32Value();
    GLint level = info[1].As<Napi::Number>().Int32Value();
    GLint xoffset = info[2].As<Napi::Number>().Int32Value();
    GLint x = info[3].As<Napi::Number>().Int32Value();
    GLint y = info[4].As<Napi::Number>().Int32Value();
    GLsizei width = info[5].As<Napi::Number>().Int32Value();
  
    glCopyTexSubImage1D(target, level, xoffset, x, y, width);
}

void __glCopyTexSubImage2D(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum target = info[0].As<Napi::Number>().Int32Value();
    GLint level = info[1].As<Napi::Number>().Int32Value();
    GLint xoffset = info[2].As<Napi::Number>().Int32Value();
    GLint yoffset = info[3].As<Napi::Number>().Int32Value();
    GLint x = info[4].As<Napi::Number>().Int32Value();
    GLint y = info[5].As<Napi::Number>().Int32Value();
    GLsizei width = info[6].As<Napi::Number>().Int32Value();
    GLsizei height = info[7].As<Napi::Number>().Int32Value();
  
    glCopyTexSubImage2D(target, level, xoffset, yoffset, x, y, width, height);
}

void __glCullFace(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum mode = info[0].As<Napi::Number>().Int32Value();
  
    glCullFace(mode);
}

void __glDeleteLists(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint list = info[0].As<Napi::Number>().Int32Value();
    GLsizei range = info[1].As<Napi::Number>().Int32Value();
  
    glDeleteLists(list, range);
}

void __glDeleteTextures(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLsizei n = info[0].As<Napi::Number>().Int32Value();
    GLuint* textures = info[1].As<Napi::Uint32Array>().Data();
  
    glDeleteTextures(n, textures);
}

void __glDepthFunc(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum func = info[0].As<Napi::Number>().Int32Value();
  
    glDepthFunc(func);
}

void __glDepthMask(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLboolean flag = info[0].As<Napi::Boolean>();
  
    glDepthMask(flag);
}

void __glDepthRange(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLclampd zNear = info[0].As<Napi::Number>().DoubleValue();
    GLclampd zFar = info[1].As<Napi::Number>().DoubleValue();
  
    glDepthRange(zNear, zFar);
}

void __glDisable(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum cap = info[0].As<Napi::Number>().Int32Value();
  
    glDisable(cap);
}

void __glDisableClientState(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum array = info[0].As<Napi::Number>().Int32Value();
  
    glDisableClientState(array);
}

void __glDrawArrays(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum mode = info[0].As<Napi::Number>().Int32Value();
    GLint first = info[1].As<Napi::Number>().Int32Value();
    GLsizei count = info[2].As<Napi::Number>().Int32Value();
  
    glDrawArrays(mode, first, count);
}

void __glDrawBuffer(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum mode = info[0].As<Napi::Number>().Int32Value();
  
    glDrawBuffer(mode);
}

void __glDrawElements(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum mode = info[0].As<Napi::Number>().Int32Value();
    GLsizei count = info[1].As<Napi::Number>().Int32Value();
    GLenum type = info[2].As<Napi::Number>().Int32Value();
    GLvoid* indices = (GLvoid*)info[3].As<Napi::Number>().Uint32Value();

    glDrawElements(mode, count, type, indices);
}

void __glDrawPixels(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLsizei width = info[0].As<Napi::Number>().Int32Value();
    GLsizei height = info[1].As<Napi::Number>().Int32Value();
    GLenum format = info[2].As<Napi::Number>().Int32Value();
    GLenum type = info[3].As<Napi::Number>().Int32Value();
    GLvoid* pixels = info[4].As<Napi::Buffer<GLubyte>>().Data();

    glDrawPixels(width, height, format, type, pixels);
}

void __glEdgeFlag(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLboolean flag = info[0].As<Napi::Boolean>().Value();
  
    glEdgeFlag(flag);
}

void __glEdgeFlagPointer(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLsizei stride = info[0].As<Napi::Number>().Int32Value();
    GLubyte* pointer = (GLubyte*)info[1].As<Napi::Uint8Array>().Data();
  
    glEdgeFlagPointer(stride, pointer);
}

void __glEdgeFlagv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    Napi::Array _flag = info[0].As<Napi::Array>();
    GLboolean* flag = (GLboolean*)_flag.Get(0u).As<Napi::Boolean>().Value();
  
    glEdgeFlagv(flag);
}

void __glEnable(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum cap = info[0].As<Napi::Number>().Int32Value();
  
    glEnable(cap);
}

void __glEnableClientState(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum array = info[0].As<Napi::Number>().Int32Value();
  
    glEnableClientState(array);
}

void __glEnd(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);
  
    glEnd();
}

void __glEndList(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);
  
    glEndList();
}

void __glEvalCoord1d(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLdouble u = info[0].As<Napi::Number>().DoubleValue();
  
    glEvalCoord1d(u);
}

void __glEvalCoord1dv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLdouble *u = (GLdouble*)info[0].As<Napi::Float64Array>().Data();
  
    glEvalCoord1dv(u);
}

void __glEvalCoord1f(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLfloat u = info[0].As<Napi::Number>().FloatValue();
  
    glEvalCoord1f(u);
}

void __glEvalCoord1fv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLfloat *u = (GLfloat*)info[0].As<Napi::Float32Array>().Data();
  
    glEvalCoord1fv(u);
}

void __glEvalCoord2d(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLdouble u = info[0].As<Napi::Number>().DoubleValue();
    GLdouble v = info[1].As<Napi::Number>().DoubleValue();
  
    glEvalCoord2d(u, v);
}

void __glEvalCoord2dv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLdouble *u = (GLdouble*)info[0].As<Napi::Float64Array>().Data();
  
    glEvalCoord2dv(u);
}

void __glEvalCoord2f(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLfloat u = info[0].As<Napi::Number>().FloatValue();
    GLfloat v = info[1].As<Napi::Number>().FloatValue();
  
    glEvalCoord2f(u, v);
}

void __glEvalCoord2fv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLfloat *u = (GLfloat*)info[0].As<Napi::Float32Array>().Data();
  
    glEvalCoord2fv(u);
}

void __glEvalMesh1(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum mode = info[0].As<Napi::Number>().Int32Value();
    GLint i1 = info[1].As<Napi::Number>().Int32Value();
    GLint i2 = info[2].As<Napi::Number>().Int32Value();
  
    glEvalMesh1(mode, i1, i2);
}

void __glEvalMesh2(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum mode = info[0].As<Napi::Number>().Int32Value();
    GLint i1 = info[1].As<Napi::Number>().Int32Value();
    GLint i2 = info[2].As<Napi::Number>().Int32Value();
    GLint j1 = info[3].As<Napi::Number>().Int32Value();
    GLint j2 = info[4].As<Napi::Number>().Int32Value();
  
    glEvalMesh2(mode, i1, i2, j1, j2);
}

void __glEvalPoint1(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLint i = info[0].As<Napi::Number>().Int32Value();
  
    glEvalPoint1(i);
}

void __glEvalPoint2(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLint i = info[0].As<Napi::Number>().Int32Value();
    GLint j = info[1].As<Napi::Number>().Int32Value();
  
    glEvalPoint2(i, j);
}

void __glFeedbackBuffer(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLsizei size = info[0].As<Napi::Number>().Int32Value();
    GLenum type = info[1].As<Napi::Number>().Int32Value();
    GLfloat *buffer = (GLfloat*)info[2].As<Napi::Float32Array>().Data();
  
    glFeedbackBuffer(size, type, buffer);
}

void __glFinish(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);
  
    glFinish();
}

void __glFlush(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);
  
    glFlush();
}

void __glFogf(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum pname = info[0].As<Napi::Number>().Int32Value();
    GLfloat param = info[1].As<Napi::Number>().FloatValue();
  
    glFogf(pname, param);
}

void __glFogfv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum pname = info[0].As<Napi::Number>().Int32Value();
    GLfloat *params = (GLfloat*)info[1].As<Napi::Float32Array>().Data();
  
    glFogfv(pname, params);
}

void __glFogi(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum pname = info[0].As<Napi::Number>().Int32Value();
    GLint param = info[1].As<Napi::Number>().Int32Value();
  
    glFogi(pname, param);
}

void __glFogiv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum pname = info[0].As<Napi::Number>().Int32Value();
    GLint *params = (GLint*)info[1].As<Napi::Int32Array>().Data();
  
    glFogiv(pname, params);
}

void __glFrontFace(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum mode = info[0].As<Napi::Number>().Int32Value();
  
    glFrontFace(mode);
}

void __glFrustum(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLdouble left = info[0].As<Napi::Number>().FloatValue();
    GLdouble right = info[1].As<Napi::Number>().FloatValue();
    GLdouble bottom = info[2].As<Napi::Number>().FloatValue();
    GLdouble top = info[3].As<Napi::Number>().FloatValue();
    GLdouble zNear = info[4].As<Napi::Number>().FloatValue();
    GLdouble zFar = info[5].As<Napi::Number>().FloatValue();
  
    glFrustum(left, right, bottom, top, zNear, zFar);
}

Napi::Number __glGenLists(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLsizei range = info[0].As<Napi::Number>().Int32Value();
  
    return Napi::Number::New(env, glGenLists(range));
}

void __glGenTextures(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLsizei n = info[0].As<Napi::Number>().Int32Value();
    GLuint *textures = (GLuint*)info[1].As<Napi::Uint32Array>().Data();
  
    glGenTextures(n, textures);
}

void __glGetBooleanv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum pname = info[0].As<Napi::Number>().Int32Value();
    GLboolean *params = (GLboolean*)info[1].As<Napi::Array>().Get(0u).As<Napi::Boolean>().Value();
  
    glGetBooleanv(pname, params);
}

void __glGetClipPlane(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum plane = info[0].As<Napi::Number>().Int32Value();
    GLdouble *equation = (GLdouble*)info[1].As<Napi::Float32Array>().Data();
  
    glGetClipPlane(plane, equation);
}

void __glGetDoublev(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum pname = info[0].As<Napi::Number>().Int32Value();
    GLdouble *params = (GLdouble*)info[1].As<Napi::Float32Array>().Data();
  
    glGetDoublev(pname, params);
}

Napi::Number __glGetError(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);
  
    return Napi::Number::New(env, glGetError());
}

void __glGetFloatv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum pname = info[0].As<Napi::Number>().Int32Value();
    GLfloat *params = (GLfloat*)info[1].As<Napi::Float32Array>().Data();
  
    glGetFloatv(pname, params);
}

void __glGetIntegerv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum pname = info[0].As<Napi::Number>().Int32Value();
    GLint *params = (GLint*)info[1].As<Napi::Int32Array>().Data();
  
    glGetIntegerv(pname, params);
}

void __glGetLightfv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum light = info[0].As<Napi::Number>().Int32Value();
    GLenum pname = info[1].As<Napi::Number>().Int32Value();
    GLfloat *params = (GLfloat*)info[2].As<Napi::Float32Array>().Data();
  
    glGetLightfv(light, pname, params);
}

void __glGetLightiv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum light = info[0].As<Napi::Number>().Int32Value();
    GLenum pname = info[1].As<Napi::Number>().Int32Value();
    GLint *params = (GLint*)info[2].As<Napi::Int32Array>().Data();
  
    glGetLightiv(light, pname, params);
}

void __glGetMapdv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum target = info[0].As<Napi::Number>().Int32Value();
    GLenum query = info[1].As<Napi::Number>().Int32Value();
    GLdouble *v = (GLdouble*)info[2].As<Napi::Float32Array>().Data();
  
    glGetMapdv(target, query, v);
}

void __glGetMapfv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum target = info[0].As<Napi::Number>().Int32Value();
    GLenum query = info[1].As<Napi::Number>().Int32Value();
    GLfloat *v = (GLfloat*)info[2].As<Napi::Float32Array>().Data();
  
    glGetMapfv(target, query, v);
}

void __glGetMapiv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum target = info[0].As<Napi::Number>().Int32Value();
    GLenum query = info[1].As<Napi::Number>().Int32Value();
    GLint *v = (GLint*)info[2].As<Napi::Int32Array>().Data();
  
    glGetMapiv(target, query, v);
}

void __glGetMaterialfv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum face = info[0].As<Napi::Number>().Int32Value();
    GLenum pname = info[1].As<Napi::Number>().Int32Value();
    GLfloat *params = (GLfloat*)info[2].As<Napi::Float32Array>().Data();
  
    glGetMaterialfv(face, pname, params);
}

void __glGetMaterialiv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum face = info[0].As<Napi::Number>().Int32Value();
    GLenum pname = info[1].As<Napi::Number>().Int32Value();
    GLint *params = (GLint*)info[2].As<Napi::Int32Array>().Data();
  
    glGetMaterialiv(face, pname, params);
}

void __glGetPixelMapfv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum map = info[0].As<Napi::Number>().Int32Value();
    GLfloat *values = (GLfloat*)info[1].As<Napi::Float32Array>().Data();
  
    glGetPixelMapfv(map, values);
}

void __glGetPixelMapuiv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum map = info[0].As<Napi::Number>().Int32Value();
    GLuint *values = (GLuint*)info[1].As<Napi::Uint32Array>().Data();
  
    glGetPixelMapuiv(map, values);
}

void __glGetPixelMapusv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum map = info[0].As<Napi::Number>().Int32Value();
    GLushort *values = (GLushort*)info[1].As<Napi::Uint16Array>().Data();
  
    glGetPixelMapusv(map, values);
}

void __glGetPointerv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum pname = info[0].As<Napi::Number>().Int32Value();
    void *params = (void*)info[1].As<Napi::Uint8Array>().Data();
  
    glGetPointerv(pname, &params);
}

void __glGetPolygonStipple(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLubyte *mask = (GLubyte*)info[0].As<Napi::Uint8Array>().Data();
  
    glGetPolygonStipple(mask);
}

Napi::String __glGetString(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum name = info[0].As<Napi::Number>().Int32Value();
  
    return Napi::String::New(env, (char*)glGetString(name));
}

void __glGetTexEnvfv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum target = info[0].As<Napi::Number>().Int32Value();
    GLenum pname = info[1].As<Napi::Number>().Int32Value();
    GLfloat *params = (GLfloat*)info[2].As<Napi::Float32Array>().Data();
  
    glGetTexEnvfv(target, pname, params);
}

void __glGetTexEnviv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum target = info[0].As<Napi::Number>().Int32Value();
    GLenum pname = info[1].As<Napi::Number>().Int32Value();
    GLint *params = (GLint*)info[2].As<Napi::Int32Array>().Data();
  
    glGetTexEnviv(target, pname, params);
}

void __glGetTexGendv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum coord = info[0].As<Napi::Number>().Int32Value();
    GLenum pname = info[1].As<Napi::Number>().Int32Value();
    GLdouble *params = (GLdouble*)info[2].As<Napi::Float64Array>().Data();
  
    glGetTexGendv(coord, pname, params);
}

void __glGetTexGenfv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum coord = info[0].As<Napi::Number>().Int32Value();
    GLenum pname = info[1].As<Napi::Number>().Int32Value();
    GLfloat *params = (GLfloat*)info[2].As<Napi::Float32Array>().Data();
  
    glGetTexGenfv(coord, pname, params);
}

void __glGetTexGeniv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum coord = info[0].As<Napi::Number>().Int32Value();
    GLenum pname = info[1].As<Napi::Number>().Int32Value();
    GLint *params = (GLint*)info[2].As<Napi::Int32Array>().Data();
  
    glGetTexGeniv(coord, pname, params);
}

void __glGetTexImage(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum target = info[0].As<Napi::Number>().Int32Value();
    GLint level = info[1].As<Napi::Number>().Int32Value();
    GLenum format = info[2].As<Napi::Number>().Int32Value();
    GLenum type = info[3].As<Napi::Number>().Int32Value();
    void *pixels = (void*)info[4].As<Napi::Buffer<GLubyte>>().Data();

    glGetTexImage(target, level, format, type, pixels);
}

void __glGetTexLevelParameterfv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum target = info[0].As<Napi::Number>().Int32Value();
    GLint level = info[1].As<Napi::Number>().Int32Value();
    GLenum pname = info[2].As<Napi::Number>().Int32Value();
    GLfloat *params = (GLfloat*)info[3].As<Napi::Float32Array>().Data();
  
    glGetTexLevelParameterfv(target, level, pname, params);
}

void __glGetTexLevelParameteriv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum target = info[0].As<Napi::Number>().Int32Value();
    GLint level = info[1].As<Napi::Number>().Int32Value();
    GLenum pname = info[2].As<Napi::Number>().Int32Value();
    GLint *params = (GLint*)info[3].As<Napi::Int32Array>().Data();
  
    glGetTexLevelParameteriv(target, level, pname, params);
}

void __glGetTexParameterfv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum target = info[0].As<Napi::Number>().Int32Value();
    GLenum pname = info[1].As<Napi::Number>().Int32Value();
    GLfloat *params = (GLfloat*)info[2].As<Napi::Float32Array>().Data();
  
    glGetTexParameterfv(target, pname, params);
}

void __glGetTexParameteriv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum target = info[0].As<Napi::Number>().Int32Value();
    GLenum pname = info[1].As<Napi::Number>().Int32Value();
    GLint *params = (GLint*)info[2].As<Napi::Int32Array>().Data();
  
    glGetTexParameteriv(target, pname, params);
}

void __glHint(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum target = info[0].As<Napi::Number>().Int32Value();
    GLenum mode = info[1].As<Napi::Number>().Int32Value();
  
    glHint(target, mode);
}

void __glIndexMask(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint mask = info[0].As<Napi::Number>().Uint32Value();
  
    glIndexMask(mask);
}

void __glIndexPointer(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum type = info[0].As<Napi::Number>().Int32Value();
    GLsizei stride = info[1].As<Napi::Number>().Int32Value();
    GLvoid *pointer = (GLvoid*)info[2].As<Napi::Uint8Array>().Data();
  
    glIndexPointer(type, stride, pointer);
}

void __glIndexd(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLdouble c = info[0].As<Napi::Number>().DoubleValue();
  
    glIndexd(c);
}

void __glIndexdv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLdouble *c = (GLdouble*)info[0].As<Napi::Float64Array>().Data();
  
    glIndexdv(c);
}

void __glIndexf(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLfloat c = info[0].As<Napi::Number>().FloatValue();
  
    glIndexf(c);
}

void __glIndexfv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLfloat *c = (GLfloat*)info[0].As<Napi::Float32Array>().Data();
  
    glIndexfv(c);
}

void __glIndexi(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLint c = info[0].As<Napi::Number>().Int32Value();
  
    glIndexi(c);
}

void __glIndexiv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLint *c = (GLint*)info[0].As<Napi::Int32Array>().Data();
  
    glIndexiv(c);
}

void __glIndexs(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    int c = info[0].As<Napi::Number>().Int32Value();
  
    glIndexs(c);
}

void __glIndexsv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLshort *c = (GLshort*)info[0].As<Napi::Int16Array>().Data();
  
    glIndexsv(c);
}

void __glIndexub(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    unsigned int c = info[0].As<Napi::Number>().Uint32Value();
  
    glIndexub(c);
}

void __glIndexubv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLubyte *c = (GLubyte*)info[0].As<Napi::Uint8Array>().Data();
  
    glIndexubv(c);
}

void __glInitNames(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

  
    glInitNames();
}

void __glInterleavedArrays(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum format = info[0].As<Napi::Number>().Int32Value();
    GLsizei stride = info[1].As<Napi::Number>().Int32Value();
    GLvoid *pointer = (GLvoid*)info[2].As<Napi::Uint8Array>().Data();
  
    glInterleavedArrays(format, stride, pointer);
}

Napi::Boolean __glIsEnabled(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum cap = info[0].As<Napi::Number>().Int32Value();
  
    return Napi::Boolean::New(env, glIsEnabled(cap));
}

Napi::Boolean __glIsList(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint list = info[0].As<Napi::Number>().Uint32Value();
  
    return Napi::Boolean::New(env, glIsList(list));
}

Napi::Boolean __glIsTexture(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint texture = info[0].As<Napi::Number>().Uint32Value();
  
    return Napi::Boolean::New(env, glIsTexture(texture));
}

void __glLightModelf(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum pname = info[0].As<Napi::Number>().Int32Value();
    GLfloat param = info[1].As<Napi::Number>().FloatValue();
  
    glLightModelf(pname, param);
}

void __glLightModelfv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum pname = info[0].As<Napi::Number>().Int32Value();
    GLfloat *params = (GLfloat*)info[1].As<Napi::Float32Array>().Data();
  
    glLightModelfv(pname, params);
}

void __glLightModeli(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum pname = info[0].As<Napi::Number>().Int32Value();
    GLint param = info[1].As<Napi::Number>().Int32Value();
  
    glLightModeli(pname, param);
}

void __glLightModeliv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum pname = info[0].As<Napi::Number>().Int32Value();
    GLint *params = (GLint*)info[1].As<Napi::Int32Array>().Data();
  
    glLightModeliv(pname, params);
}

void __glLightf(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum light = info[0].As<Napi::Number>().Int32Value();
    GLenum pname = info[1].As<Napi::Number>().Int32Value();
    GLfloat param = info[2].As<Napi::Number>().FloatValue();
  
    glLightf(light, pname, param);
}

void __glLightfv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum light = info[0].As<Napi::Number>().Int32Value();
    GLenum pname = info[1].As<Napi::Number>().Int32Value();
    GLfloat *params = (GLfloat*)info[2].As<Napi::Float32Array>().Data();
  
    glLightfv(light, pname, params);
}

void __glLighti(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum light = info[0].As<Napi::Number>().Int32Value();
    GLenum pname = info[1].As<Napi::Number>().Int32Value();
    GLint param = info[2].As<Napi::Number>().Int32Value();
  
    glLighti(light, pname, param);
}

void __glLightiv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum light = info[0].As<Napi::Number>().Int32Value();
    GLenum pname = info[1].As<Napi::Number>().Int32Value();
    GLint *params = (GLint*)info[2].As<Napi::Int32Array>().Data();
  
    glLightiv(light, pname, params);
}

void __glLineStipple(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLint factor = info[0].As<Napi::Number>().Int32Value();
    unsigned int pattern = info[1].As<Napi::Number>().Uint32Value();
  
    glLineStipple(factor, pattern);
}

void __glLineWidth(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLfloat width = info[0].As<Napi::Number>().FloatValue();
  
    glLineWidth(width);
}

void __glListBase(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint base = info[0].As<Napi::Number>().Uint32Value();
  
    glListBase(base);
}

void __glLoadIdentity(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    glLoadIdentity();
}

void __glLoadMatrixd(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLdouble *m = (GLdouble*)info[0].As<Napi::Float64Array>().Data();
  
    glLoadMatrixd(m);
}

void __glLoadMatrixf(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLfloat *m = (GLfloat*)info[0].As<Napi::Float32Array>().Data();
  
    glLoadMatrixf(m);
}

void __glLoadName(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint name = info[0].As<Napi::Number>().Uint32Value();
  
    glLoadName(name);
}

void __glLogicOp(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum opcode = info[0].As<Napi::Number>().Int32Value();
  
    glLogicOp(opcode);
}

void __glMap1d(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum target = info[0].As<Napi::Number>().Int32Value();
    GLdouble u1 = info[1].As<Napi::Number>().FloatValue();
    GLdouble u2 = info[2].As<Napi::Number>().FloatValue();
    GLint stride = info[3].As<Napi::Number>().Int32Value();
    GLint order = info[4].As<Napi::Number>().Int32Value();
    GLdouble *points = (GLdouble*)info[5].As<Napi::Float64Array>().Data();
  
    glMap1d(target, u1, u2, stride, order, points);
}

void __glMap1f(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum target = info[0].As<Napi::Number>().Int32Value();
    GLfloat u1 = info[1].As<Napi::Number>().FloatValue();
    GLfloat u2 = info[2].As<Napi::Number>().FloatValue();
    GLint stride = info[3].As<Napi::Number>().Int32Value();
    GLint order = info[4].As<Napi::Number>().Int32Value();
    GLfloat *points = (GLfloat*)info[5].As<Napi::Float32Array>().Data();
  
    glMap1f(target, u1, u2, stride, order, points);
}

void __glMap2d(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum target = info[0].As<Napi::Number>().Int32Value();
    GLdouble u1 = info[1].As<Napi::Number>().FloatValue();
    GLdouble u2 = info[2].As<Napi::Number>().FloatValue();
    GLint ustride = info[3].As<Napi::Number>().Int32Value();
    GLint uorder = info[4].As<Napi::Number>().Int32Value();
    GLdouble v1 = info[5].As<Napi::Number>().FloatValue();
    GLdouble v2 = info[6].As<Napi::Number>().FloatValue();
    GLint vstride = info[7].As<Napi::Number>().Int32Value();
    GLint vorder = info[8].As<Napi::Number>().Int32Value();
    GLdouble *points = (GLdouble*)info[9].As<Napi::Float64Array>().Data();
  
    glMap2d(target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, points);
}

void __glMap2f(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum target = info[0].As<Napi::Number>().Int32Value();
    GLfloat u1 = info[1].As<Napi::Number>().FloatValue();
    GLfloat u2 = info[2].As<Napi::Number>().FloatValue();
    GLint ustride = info[3].As<Napi::Number>().Int32Value();
    GLint uorder = info[4].As<Napi::Number>().Int32Value();
    GLfloat v1 = info[5].As<Napi::Number>().FloatValue();
    GLfloat v2 = info[6].As<Napi::Number>().FloatValue();
    GLint vstride = info[7].As<Napi::Number>().Int32Value();
    GLint vorder = info[8].As<Napi::Number>().Int32Value();
    GLfloat *points = (GLfloat*)info[9].As<Napi::Float32Array>().Data();
  
    glMap2f(target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, points);
}

void __glMapGrid1d(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLint un = info[0].As<Napi::Number>().Int32Value();
    GLdouble u1 = info[1].As<Napi::Number>().FloatValue();
    GLdouble u2 = info[2].As<Napi::Number>().FloatValue();
  
    glMapGrid1d(un, u1, u2);
}

void __glMapGrid1f(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLint un = info[0].As<Napi::Number>().Int32Value();
    GLfloat u1 = info[1].As<Napi::Number>().FloatValue();
    GLfloat u2 = info[2].As<Napi::Number>().FloatValue();
  
    glMapGrid1f(un, u1, u2);
}

void __glMapGrid2d(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLint un = info[0].As<Napi::Number>().Int32Value();
    GLdouble u1 = info[1].As<Napi::Number>().FloatValue();
    GLdouble u2 = info[2].As<Napi::Number>().FloatValue();
    GLint vn = info[3].As<Napi::Number>().Int32Value();
    GLdouble v1 = info[4].As<Napi::Number>().FloatValue();
    GLdouble v2 = info[5].As<Napi::Number>().FloatValue();
  
    glMapGrid2d(un, u1, u2, vn, v1, v2);
}

void __glMapGrid2f(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLint un = info[0].As<Napi::Number>().Int32Value();
    GLfloat u1 = info[1].As<Napi::Number>().FloatValue();
    GLfloat u2 = info[2].As<Napi::Number>().FloatValue();
    GLint vn = info[3].As<Napi::Number>().Int32Value();
    GLfloat v1 = info[4].As<Napi::Number>().FloatValue();
    GLfloat v2 = info[5].As<Napi::Number>().FloatValue();
  
    glMapGrid2f(un, u1, u2, vn, v1, v2);
}

void __glMaterialf(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum face = info[0].As<Napi::Number>().Int32Value();
    GLenum pname = info[1].As<Napi::Number>().Int32Value();
    GLfloat param = info[2].As<Napi::Number>().FloatValue();
  
    glMaterialf(face, pname, param);
}

void __glMaterialfv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum face = info[0].As<Napi::Number>().Int32Value();
    GLenum pname = info[1].As<Napi::Number>().Int32Value();
    GLfloat *params = (GLfloat*)info[2].As<Napi::Float32Array>().Data();
  
    glMaterialfv(face, pname, params);
}

void __glMateriali(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum face = info[0].As<Napi::Number>().Int32Value();
    GLenum pname = info[1].As<Napi::Number>().Int32Value();
    GLint param = info[2].As<Napi::Number>().Int32Value();
  
    glMateriali(face, pname, param);
}

void __glMaterialiv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum face = info[0].As<Napi::Number>().Int32Value();
    GLenum pname = info[1].As<Napi::Number>().Int32Value();
    GLint *params = (GLint*)info[2].As<Napi::Int32Array>().Data();
  
    glMaterialiv(face, pname, params);
}

void __glMatrixMode(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum mode = info[0].As<Napi::Number>().Int32Value();
  
    glMatrixMode(mode);
}

void __glMultMatrixd(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLdouble *m = (GLdouble*)info[0].As<Napi::Float64Array>().Data();
  
    glMultMatrixd(m);
}

void __glMultMatrixf(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLfloat *m = (GLfloat*)info[0].As<Napi::Float32Array>().Data();
  
    glMultMatrixf(m);
}

void __glNewList(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint list = info[0].As<Napi::Number>().Int32Value();
    GLenum mode = info[1].As<Napi::Number>().Int32Value();
  
    glNewList(list, mode);
}

void __glNormal3b(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLbyte nx = (GLbyte)info[0].As<Napi::Number>().Int32Value();
    GLbyte ny = (GLbyte)info[1].As<Napi::Number>().Int32Value();
    GLbyte nz = (GLbyte)info[2].As<Napi::Number>().Int32Value();
  
    glNormal3b(nx, ny, nz);
}

void __glNormal3bv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLbyte *v = (GLbyte*)info[0].As<Napi::Int8Array>().Data();
  
    glNormal3bv(v);
}

void __glNormal3d(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLdouble nx = info[0].As<Napi::Number>().DoubleValue();
    GLdouble ny = info[1].As<Napi::Number>().DoubleValue();
    GLdouble nz = info[2].As<Napi::Number>().DoubleValue();
  
    glNormal3d(nx, ny, nz);
}

void __glNormal3dv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLdouble *v = (GLdouble*)info[0].As<Napi::Float64Array>().Data();
  
    glNormal3dv(v);
}

void __glNormal3f(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLfloat nx = info[0].As<Napi::Number>().FloatValue();
    GLfloat ny = info[1].As<Napi::Number>().FloatValue();
    GLfloat nz = info[2].As<Napi::Number>().FloatValue();
  
    glNormal3f(nx, ny, nz);
}

void __glNormal3fv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLfloat *v = (GLfloat*)info[0].As<Napi::Float32Array>().Data();
  
    glNormal3fv(v);
}

void __glNormal3i(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLint nx = info[0].As<Napi::Number>().Int32Value();
    GLint ny = info[1].As<Napi::Number>().Int32Value();
    GLint nz = info[2].As<Napi::Number>().Int32Value();
  
    glNormal3i(nx, ny, nz);
}

void __glNormal3iv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLint *v = (GLint*)info[0].As<Napi::Int32Array>().Data();
  
    glNormal3iv(v);
}

void __glNormal3s(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLshort nx = (GLshort)info[0].As<Napi::Number>().Int32Value();
    GLshort ny = (GLshort)info[1].As<Napi::Number>().Int32Value();
    GLshort nz = (GLshort)info[2].As<Napi::Number>().Int32Value();
  
    glNormal3s(nx, ny, nz);
}

void __glNormal3sv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLshort *v = (GLshort*)info[0].As<Napi::Int16Array>().Data();
  
    glNormal3sv(v);
}

void __glNormalPointer(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum type = info[0].As<Napi::Number>().Int32Value();
    GLsizei stride = info[1].As<Napi::Number>().Int32Value();
    GLvoid *pointer = (GLvoid*)info[2].As<Napi::Buffer<GLubyte>>().Data();
}

void __glOrtho(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLdouble left = info[0].As<Napi::Number>().DoubleValue();
    GLdouble right = info[1].As<Napi::Number>().DoubleValue();
    GLdouble bottom = info[2].As<Napi::Number>().DoubleValue();
    GLdouble top = info[3].As<Napi::Number>().DoubleValue();
    GLdouble zNear = info[4].As<Napi::Number>().DoubleValue();
    GLdouble zFar = info[5].As<Napi::Number>().DoubleValue();
  
    glOrtho(left, right, bottom, top, zNear, zFar);
}

void __glPassThrough(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLfloat token = info[0].As<Napi::Number>().FloatValue();
  
    glPassThrough(token);
}

void __glPixelMapfv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum map = info[0].As<Napi::Number>().Int32Value();
    GLsizei mapsize = info[1].As<Napi::Number>().Int32Value();
    GLfloat *values = (GLfloat*)info[2].As<Napi::Float32Array>().Data();
  
    glPixelMapfv(map, mapsize, values);
}

void __glPixelMapuiv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum map = info[0].As<Napi::Number>().Int32Value();
    GLsizei mapsize = info[1].As<Napi::Number>().Int32Value();
    GLuint *values = (GLuint*)info[2].As<Napi::Uint32Array>().Data();
  
    glPixelMapuiv(map, mapsize, values);
}

void __glPixelMapusv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum map = info[0].As<Napi::Number>().Int32Value();
    GLsizei mapsize = info[1].As<Napi::Number>().Int32Value();
    GLushort *values = (GLushort*)info[2].As<Napi::Uint16Array>().Data();
  
    glPixelMapusv(map, mapsize, values);
}

void __glPixelStoref(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum pname = info[0].As<Napi::Number>().Int32Value();
    GLfloat param = info[1].As<Napi::Number>().FloatValue();
  
    glPixelStoref(pname, param);
}

void __glPixelStorei(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum pname = info[0].As<Napi::Number>().Int32Value();
    GLint param = info[1].As<Napi::Number>().Int32Value();
  
    glPixelStorei(pname, param);
}

void __glPixelTransferf(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum pname = info[0].As<Napi::Number>().Int32Value();
    GLfloat param = info[1].As<Napi::Number>().FloatValue();
  
    glPixelTransferf(pname, param);
}

void __glPixelTransferi(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum pname = info[0].As<Napi::Number>().Int32Value();
    GLint param = info[1].As<Napi::Number>().Int32Value();
  
    glPixelTransferi(pname, param);
}

void __glPixelZoom(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLfloat xfactor = info[0].As<Napi::Number>().FloatValue();
    GLfloat yfactor = info[1].As<Napi::Number>().FloatValue();
  
    glPixelZoom(xfactor, yfactor);
}

void __glPointSize(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLfloat size = info[0].As<Napi::Number>().FloatValue();
  
    glPointSize(size);
}

void __glPolygonMode(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum face = info[0].As<Napi::Number>().Int32Value();
    GLenum mode = info[1].As<Napi::Number>().Int32Value();
  
    glPolygonMode(face, mode);
}

void __glPolygonOffset(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLfloat factor = info[0].As<Napi::Number>().FloatValue();
    GLfloat units = info[1].As<Napi::Number>().FloatValue();
  
    glPolygonOffset(factor, units);
}

void __glPolygonStipple(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLubyte *mask = (GLubyte*)info[0].As<Napi::Uint8Array>().Data();
  
    glPolygonStipple(mask);
}

void __glPopAttrib(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    glPopAttrib();
}

void __glPopClientAttrib(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    glPopClientAttrib();
}

void __glPopMatrix(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    glPopMatrix();
}

void __glPopName(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    glPopName();
}

void __glPrioritizeTextures(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLsizei n = info[0].As<Napi::Number>().Int32Value();
    GLuint *textures = (GLuint*)info[1].As<Napi::Uint32Array>().Data();
    GLclampf *priorities = (GLclampf*)info[2].As<Napi::Float32Array>().Data();
  
    glPrioritizeTextures(n, textures, priorities);
}

void __glPushAttrib(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLbitfield mask = info[0].As<Napi::Number>().Int32Value();
  
    glPushAttrib(mask);
}

void __glPushClientAttrib(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLbitfield mask = info[0].As<Napi::Number>().Int32Value();
  
    glPushClientAttrib(mask);
}

void __glPushMatrix(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    glPushMatrix();
}

void __glPushName(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint name = info[0].As<Napi::Number>().Int32Value();
  
    glPushName(name);
}

void __glRasterPos2d(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLdouble x = info[0].As<Napi::Number>().DoubleValue();
    GLdouble y = info[1].As<Napi::Number>().DoubleValue();
  
    glRasterPos2d(x, y);
}

void __glRasterPos2dv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLdouble *v = (GLdouble*)info[0].As<Napi::Float64Array>().Data();
  
    glRasterPos2dv(v);
}

void __glRasterPos2f(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLfloat x = info[0].As<Napi::Number>().FloatValue();
    GLfloat y = info[1].As<Napi::Number>().FloatValue();
  
    glRasterPos2f(x, y);
}

void __glRasterPos2fv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLfloat *v = (GLfloat*)info[0].As<Napi::Float32Array>().Data();
  
    glRasterPos2fv(v);
}

void __glRasterPos2i(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLint x = info[0].As<Napi::Number>().Int32Value();
    GLint y = info[1].As<Napi::Number>().Int32Value();
  
    glRasterPos2i(x, y);
}

void __glRasterPos2iv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLint *v = (GLint*)info[0].As<Napi::Int32Array>().Data();
  
    glRasterPos2iv(v);
}

void __glRasterPos2s(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLshort x = (GLshort)info[0].As<Napi::Number>().Int32Value();
    GLshort y = (GLshort)info[1].As<Napi::Number>().Int32Value();
  
    glRasterPos2s(x, y);
}

void __glRasterPos2sv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLshort *v = (GLshort*)info[0].As<Napi::Int16Array>().Data();
  
    glRasterPos2sv(v);
}

void __glRasterPos3d(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLdouble x = info[0].As<Napi::Number>().DoubleValue();
    GLdouble y = info[1].As<Napi::Number>().DoubleValue();
    GLdouble z = info[2].As<Napi::Number>().DoubleValue();
  
    glRasterPos3d(x, y, z);
}

void __glRasterPos3dv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLdouble *v = (GLdouble*)info[0].As<Napi::Float64Array>().Data();
  
    glRasterPos3dv(v);
}

void __glRasterPos3f(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLfloat x = info[0].As<Napi::Number>().FloatValue();
    GLfloat y = info[1].As<Napi::Number>().FloatValue();
    GLfloat z = info[2].As<Napi::Number>().FloatValue();
  
    glRasterPos3f(x, y, z);
}

void __glRasterPos3fv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLfloat *v = (GLfloat*)info[0].As<Napi::Float32Array>().Data();
  
    glRasterPos3fv(v);
}

void __glRasterPos3i(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLint x = info[0].As<Napi::Number>().Int32Value();
    GLint y = info[1].As<Napi::Number>().Int32Value();
    GLint z = info[2].As<Napi::Number>().Int32Value();
  
    glRasterPos3i(x, y, z);
}

void __glRasterPos3iv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLint *v = (GLint*)info[0].As<Napi::Int32Array>().Data();
  
    glRasterPos3iv(v);
}

void __glRasterPos3s(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLshort x = (GLshort)info[0].As<Napi::Number>().Int32Value();
    GLshort y = (GLshort)info[1].As<Napi::Number>().Int32Value();
    GLshort z = (GLshort)info[2].As<Napi::Number>().Int32Value();
  
    glRasterPos3s(x, y, z);
}

void __glRasterPos3sv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLshort *v = (GLshort*)info[0].As<Napi::Int16Array>().Data();
  
    glRasterPos3sv(v);
}

void __glRasterPos4d(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLdouble x = info[0].As<Napi::Number>().DoubleValue();
    GLdouble y = info[1].As<Napi::Number>().DoubleValue();
    GLdouble z = info[2].As<Napi::Number>().DoubleValue();
    GLdouble w = info[3].As<Napi::Number>().DoubleValue();
  
    glRasterPos4d(x, y, z, w);
}

void __glRasterPos4dv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLdouble *v = (GLdouble*)info[0].As<Napi::Float64Array>().Data();
  
    glRasterPos4dv(v);
}

void __glRasterPos4f(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLfloat x = info[0].As<Napi::Number>().FloatValue();
    GLfloat y = info[1].As<Napi::Number>().FloatValue();
    GLfloat z = info[2].As<Napi::Number>().FloatValue();
    GLfloat w = info[3].As<Napi::Number>().FloatValue();
  
    glRasterPos4f(x, y, z, w);
}

void __glRasterPos4fv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLfloat *v = (GLfloat*)info[0].As<Napi::Float32Array>().Data();
  
    glRasterPos4fv(v);
}

void __glRasterPos4i(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLint x = info[0].As<Napi::Number>().Int32Value();
    GLint y = info[1].As<Napi::Number>().Int32Value();
    GLint z = info[2].As<Napi::Number>().Int32Value();
    GLint w = info[3].As<Napi::Number>().Int32Value();
  
    glRasterPos4i(x, y, z, w);
}

void __glRasterPos4iv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLint *v = (GLint*)info[0].As<Napi::Int32Array>().Data();
  
    glRasterPos4iv(v);
}

void __glRasterPos4s(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLshort x = (GLshort)info[0].As<Napi::Number>().Int32Value();
    GLshort y = (GLshort)info[1].As<Napi::Number>().Int32Value();
    GLshort z = (GLshort)info[2].As<Napi::Number>().Int32Value();
    GLshort w = (GLshort)info[3].As<Napi::Number>().Int32Value();
  
    glRasterPos4s(x, y, z, w);
}

void __glRasterPos4sv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLshort *v = (GLshort*)info[0].As<Napi::Int16Array>().Data();
  
    glRasterPos4sv(v);
}

void __glReadBuffer(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum mode = info[0].As<Napi::Number>().Int32Value();
  
    glReadBuffer(mode);
}

void __glReadPixels(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLint x = info[0].As<Napi::Number>().Int32Value();
    GLint y = info[1].As<Napi::Number>().Int32Value();
    GLsizei width = info[2].As<Napi::Number>().Int32Value();
    GLsizei height = info[3].As<Napi::Number>().Int32Value();
    GLenum format = info[4].As<Napi::Number>().Int32Value();
    GLenum type = info[5].As<Napi::Number>().Int32Value();
    void *pixels = (void*)info[6].As<Napi::Buffer<GLubyte>>().Data();

    glReadPixels(x, y, width, height, format, type, pixels);
}

void __glRectd(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLdouble x1 = info[0].As<Napi::Number>().FloatValue();
    GLdouble y1 = info[1].As<Napi::Number>().FloatValue();
    GLdouble x2 = info[2].As<Napi::Number>().FloatValue();
    GLdouble y2 = info[3].As<Napi::Number>().FloatValue();
  
    glRectd(x1, y1, x2, y2);
}

void __glRectdv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLdouble *v1 = (GLdouble*)info[0].As<Napi::Float64Array>().Data();
    GLdouble *v2 = (GLdouble*)info[1].As<Napi::Float64Array>().Data();
  
    glRectdv(v1, v2);
}

void __glRectf(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLfloat x1 = info[0].As<Napi::Number>().FloatValue();
    GLfloat y1 = info[1].As<Napi::Number>().FloatValue();
    GLfloat x2 = info[2].As<Napi::Number>().FloatValue();
    GLfloat y2 = info[3].As<Napi::Number>().FloatValue();
  
    glRectf(x1, y1, x2, y2);
}

void __glRectfv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLfloat *v1 = (GLfloat*)info[0].As<Napi::Float32Array>().Data();
    GLfloat *v2 = (GLfloat*)info[1].As<Napi::Float32Array>().Data();
  
    glRectfv(v1, v2);
}

void __glRecti(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLint x1 = info[0].As<Napi::Number>().Int32Value();
    GLint y1 = info[1].As<Napi::Number>().Int32Value();
    GLint x2 = info[2].As<Napi::Number>().Int32Value();
    GLint y2 = info[3].As<Napi::Number>().Int32Value();
  
    glRecti(x1, y1, x2, y2);
}

void __glRectiv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLint *v1 = (GLint*)info[0].As<Napi::Int32Array>().Data();
    GLint *v2 = (GLint*)info[1].As<Napi::Int32Array>().Data();
  
    glRectiv(v1, v2);
}

void __glRects(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLshort x1 = (GLshort)info[0].As<Napi::Number>().Int32Value();
    GLshort y1 = (GLshort)info[1].As<Napi::Number>().Int32Value();
    GLshort x2 = (GLshort)info[2].As<Napi::Number>().Int32Value();
    GLshort y2 = (GLshort)info[3].As<Napi::Number>().Int32Value();
  
    glRects(x1, y1, x2, y2);
}

void __glRectsv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLshort *v1 = (GLshort*)info[0].As<Napi::Int16Array>().Data();
    GLshort *v2 = (GLshort*)info[1].As<Napi::Int16Array>().Data();
  
    glRectsv(v1, v2);
}

Napi::Number __glRenderMode(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLint mode = info[0].As<Napi::Number>().Int32Value();
  
    return Napi::Number::New(env, glRenderMode(mode));
}

void __glRotated(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLdouble angle = info[0].As<Napi::Number>().DoubleValue();
    GLdouble x = info[1].As<Napi::Number>().DoubleValue();
    GLdouble y = info[2].As<Napi::Number>().DoubleValue();
    GLdouble z = info[3].As<Napi::Number>().DoubleValue();
  
    glRotated(angle, x, y, z);
}

void __glRotatef(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLfloat angle = info[0].As<Napi::Number>().FloatValue();
    GLfloat x = info[1].As<Napi::Number>().FloatValue();
    GLfloat y = info[2].As<Napi::Number>().FloatValue();
    GLfloat z = info[3].As<Napi::Number>().FloatValue();
  
    glRotatef(angle, x, y, z);
}

void __glScaled(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLdouble x = info[0].As<Napi::Number>().DoubleValue();
    GLdouble y = info[1].As<Napi::Number>().DoubleValue();
    GLdouble z = info[2].As<Napi::Number>().DoubleValue();
  
    glScaled(x, y, z);
}

void __glScalef(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLfloat x = info[0].As<Napi::Number>().FloatValue();
    GLfloat y = info[1].As<Napi::Number>().FloatValue();
    GLfloat z = info[2].As<Napi::Number>().FloatValue();
  
    glScalef(x, y, z);
}

void __glScissor(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLint x = info[0].As<Napi::Number>().Int32Value();
    GLint y = info[1].As<Napi::Number>().Int32Value();
    GLsizei width = info[2].As<Napi::Number>().Int32Value();
    GLsizei height = info[3].As<Napi::Number>().Int32Value();
  
    glScissor(x, y, width, height);
}

void __glSelectBuffer(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLsizei size = info[0].As<Napi::Number>().Int32Value();
    GLuint *buffer = (GLuint*)info[1].As<Napi::Uint32Array>().Data();
  
    glSelectBuffer(size, buffer);
}

void __glShadeModel(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum mode = info[0].As<Napi::Number>().Int32Value();
  
    glShadeModel(mode);
}

void __glStencilFunc(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum func = info[0].As<Napi::Number>().Int32Value();
    GLint ref = info[1].As<Napi::Number>().Int32Value();
    GLuint mask = info[2].As<Napi::Number>().Uint32Value();
  
    glStencilFunc(func, ref, mask);
}

void __glStencilMask(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint mask = info[0].As<Napi::Number>().Uint32Value();
  
    glStencilMask(mask);
}

void __glStencilOp(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum fail = info[0].As<Napi::Number>().Int32Value();
    GLenum zfail = info[1].As<Napi::Number>().Int32Value();
    GLenum zpass = info[2].As<Napi::Number>().Int32Value();
  
    glStencilOp(fail, zfail, zpass);
}

void __glTexCoord1d(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLdouble s = info[0].As<Napi::Number>().DoubleValue();
  
    glTexCoord1d(s);
}

void __glTexCoord1dv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLdouble *v = (GLdouble*)info[0].As<Napi::Float64Array>().Data();
  
    glTexCoord1dv(v);
}

void __glTexCoord1f(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLfloat s = info[0].As<Napi::Number>().FloatValue();
  
    glTexCoord1f(s);
}

void __glTexCoord1fv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLfloat *v = (GLfloat*)info[0].As<Napi::Float32Array>().Data();
  
    glTexCoord1fv(v);
}

void __glTexCoord1i(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLint s = info[0].As<Napi::Number>().Int32Value();
  
    glTexCoord1i(s);
}

void __glTexCoord1iv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLint *v = (GLint*)info[0].As<Napi::Int32Array>().Data();
  
    glTexCoord1iv(v);
}

void __glTexCoord1s(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLshort s = (GLshort)info[0].As<Napi::Number>().Int32Value();
  
    glTexCoord1s(s);
}

void __glTexCoord1sv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLshort *v = (GLshort*)info[0].As<Napi::Int16Array>().Data();
  
    glTexCoord1sv(v);
}

void __glTexCoord2d(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLdouble s = info[0].As<Napi::Number>().DoubleValue();
    GLdouble t = info[1].As<Napi::Number>().DoubleValue();
  
    glTexCoord2d(s, t);
}

void __glTexCoord2dv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLdouble *v = (GLdouble*)info[0].As<Napi::Float64Array>().Data();
  
    glTexCoord2dv(v);
}

void __glTexCoord2f(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLfloat s = info[0].As<Napi::Number>().FloatValue();
    GLfloat t = info[1].As<Napi::Number>().FloatValue();
  
    glTexCoord2f(s, t);
}

void __glTexCoord2fv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLfloat *v = (GLfloat*)info[0].As<Napi::Float32Array>().Data();
  
    glTexCoord2fv(v);
}

void __glTexCoord2i(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLint s = info[0].As<Napi::Number>().Int32Value();
    GLint t = info[1].As<Napi::Number>().Int32Value();
  
    glTexCoord2i(s, t);
}

void __glTexCoord2iv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLint *v = (GLint*)info[0].As<Napi::Int32Array>().Data();
  
    glTexCoord2iv(v);
}

void __glTexCoord2s(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLshort s = (GLshort)info[0].As<Napi::Number>().Int32Value();
    GLshort t = (GLshort)info[1].As<Napi::Number>().Int32Value();
  
    glTexCoord2s(s, t);
}

void __glTexCoord2sv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLshort *v = (GLshort*)info[0].As<Napi::Int16Array>().Data();
  
    glTexCoord2sv(v);
}

void __glTexCoord3d(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLdouble s = info[0].As<Napi::Number>().DoubleValue();
    GLdouble t = info[1].As<Napi::Number>().DoubleValue();
    GLdouble r = info[2].As<Napi::Number>().DoubleValue();
  
    glTexCoord3d(s, t, r);
}

void __glTexCoord3dv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLdouble *v = (GLdouble*)info[0].As<Napi::Float64Array>().Data();
  
    glTexCoord3dv(v);
}

void __glTexCoord3f(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLfloat s = info[0].As<Napi::Number>().FloatValue();
    GLfloat t = info[1].As<Napi::Number>().FloatValue();
    GLfloat r = info[2].As<Napi::Number>().FloatValue();
  
    glTexCoord3f(s, t, r);
}

void __glTexCoord3fv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLfloat *v = (GLfloat*)info[0].As<Napi::Float32Array>().Data();
  
    glTexCoord3fv(v);
}

void __glTexCoord3i(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLint s = info[0].As<Napi::Number>().Int32Value();
    GLint t = info[1].As<Napi::Number>().Int32Value();
    GLint r = info[2].As<Napi::Number>().Int32Value();
  
    glTexCoord3i(s, t, r);
}

void __glTexCoord3iv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLint *v = (GLint*)info[0].As<Napi::Int32Array>().Data();
  
    glTexCoord3iv(v);
}

void __glTexCoord3s(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLshort s = (GLshort)info[0].As<Napi::Number>().Int32Value();
    GLshort t = (GLshort)info[1].As<Napi::Number>().Int32Value();
    GLshort r = (GLshort)info[2].As<Napi::Number>().Int32Value();
  
    glTexCoord3s(s, t, r);
}

void __glTexCoord3sv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLshort *v = (GLshort*)info[0].As<Napi::Int16Array>().Data();
  
    glTexCoord3sv(v);
}

void __glTexCoord4d(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLdouble s = info[0].As<Napi::Number>().DoubleValue();
    GLdouble t = info[1].As<Napi::Number>().DoubleValue();
    GLdouble r = info[2].As<Napi::Number>().DoubleValue();
    GLdouble q = info[3].As<Napi::Number>().DoubleValue();
  
    glTexCoord4d(s, t, r, q);
}

void __glTexCoord4dv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLdouble *v = (GLdouble*)info[0].As<Napi::Float64Array>().Data();
  
    glTexCoord4dv(v);
}

void __glTexCoord4f(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLfloat s = info[0].As<Napi::Number>().FloatValue();
    GLfloat t = info[1].As<Napi::Number>().FloatValue();
    GLfloat r = info[2].As<Napi::Number>().FloatValue();
    GLfloat q = info[3].As<Napi::Number>().FloatValue();
  
    glTexCoord4f(s, t, r, q);
}

void __glTexCoord4fv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLfloat *v = (GLfloat*)info[0].As<Napi::Float32Array>().Data();
  
    glTexCoord4fv(v);
}

void __glTexCoord4i(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLint s = info[0].As<Napi::Number>().Int32Value();
    GLint t = info[1].As<Napi::Number>().Int32Value();
    GLint r = info[2].As<Napi::Number>().Int32Value();
    GLint q = info[3].As<Napi::Number>().Int32Value();
  
    glTexCoord4i(s, t, r, q);
}

void __glTexCoord4iv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLint *v = (GLint*)info[0].As<Napi::Int32Array>().Data();
  
    glTexCoord4iv(v);
}

void __glTexCoord4s(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLshort s = (GLshort)info[0].As<Napi::Number>().Int32Value();
    GLshort t = (GLshort)info[1].As<Napi::Number>().Int32Value();
    GLshort r = (GLshort)info[2].As<Napi::Number>().Int32Value();
    GLshort q = (GLshort)info[3].As<Napi::Number>().Int32Value();
  
    glTexCoord4s(s, t, r, q);
}

void __glTexCoord4sv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLshort *v = (GLshort*)info[0].As<Napi::Int16Array>().Data();
  
    glTexCoord4sv(v);
}

void __glTexCoordPointer(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLint size = info[0].As<Napi::Number>().Int32Value();
    GLenum type = info[1].As<Napi::Number>().Int32Value();
    GLsizei stride = info[2].As<Napi::Number>().Int32Value();
    GLvoid *pointer = (GLvoid*)info[3].As<Napi::Buffer<GLubyte>>().Data();

    glTexCoordPointer(size, type, stride, pointer);
}

void __glTexEnvf(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum target = info[0].As<Napi::Number>().Int32Value();
    GLenum pname = info[1].As<Napi::Number>().Int32Value();
    GLfloat param = info[2].As<Napi::Number>().FloatValue();
  
    glTexEnvf(target, pname, param);
}

void __glTexEnvfv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum target = info[0].As<Napi::Number>().Int32Value();
    GLenum pname = info[1].As<Napi::Number>().Int32Value();
    GLfloat *params = (GLfloat*)info[2].As<Napi::Float32Array>().Data();
  
    glTexEnvfv(target, pname, params);
}

void __glTexEnvi(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum target = info[0].As<Napi::Number>().Int32Value();
    GLenum pname = info[1].As<Napi::Number>().Int32Value();
    GLint param = info[2].As<Napi::Number>().Int32Value();
  
    glTexEnvi(target, pname, param);
}

void __glTexEnviv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum target = info[0].As<Napi::Number>().Int32Value();
    GLenum pname = info[1].As<Napi::Number>().Int32Value();
    GLint *params = (GLint*)info[2].As<Napi::Int32Array>().Data();
  
    glTexEnviv(target, pname, params);
}

void __glTexGend(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum coord = info[0].As<Napi::Number>().Int32Value();
    GLenum pname = info[1].As<Napi::Number>().Int32Value();
    GLdouble param = info[2].As<Napi::Number>().DoubleValue();
  
    glTexGend(coord, pname, param);
}

void __glTexGendv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum coord = info[0].As<Napi::Number>().Int32Value();
    GLenum pname = info[1].As<Napi::Number>().Int32Value();
    GLdouble *params = (GLdouble*)info[2].As<Napi::Float64Array>().Data();
  
    glTexGendv(coord, pname, params);
}

void __glTexGenf(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum coord = info[0].As<Napi::Number>().Int32Value();
    GLenum pname = info[1].As<Napi::Number>().Int32Value();
    GLfloat param = info[2].As<Napi::Number>().FloatValue();
  
    glTexGenf(coord, pname, param);
}

void __glTexGenfv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum coord = info[0].As<Napi::Number>().Int32Value();
    GLenum pname = info[1].As<Napi::Number>().Int32Value();
    GLfloat *params = (GLfloat*)info[2].As<Napi::Float32Array>().Data();
  
    glTexGenfv(coord, pname, params);
}

void __glTexGeni(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum coord = info[0].As<Napi::Number>().Int32Value();
    GLenum pname = info[1].As<Napi::Number>().Int32Value();
    GLint param = info[2].As<Napi::Number>().Int32Value();
  
    glTexGeni(coord, pname, param);
}

void __glTexGeniv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum coord = info[0].As<Napi::Number>().Int32Value();
    GLenum pname = info[1].As<Napi::Number>().Int32Value();
    GLint *params = (GLint*)info[2].As<Napi::Int32Array>().Data();
  
    glTexGeniv(coord, pname, params);
}

void __glTexImage1D(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum target = info[0].As<Napi::Number>().Int32Value();
    GLint level = info[1].As<Napi::Number>().Int32Value();
    GLint internalformat = info[2].As<Napi::Number>().Int32Value();
    GLsizei width = info[3].As<Napi::Number>().Int32Value();
    GLint border = info[4].As<Napi::Number>().Int32Value();
    GLenum format = info[5].As<Napi::Number>().Int32Value();
    GLenum type = info[6].As<Napi::Number>().Int32Value();
    void *pixels = info[7].As<Napi::Buffer<GLubyte>>().Data();

    glTexImage1D(target, level, internalformat, width, border, format, type, pixels);
}

void __glTexImage2D(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum target = info[0].As<Napi::Number>().Int32Value();
    GLint level = info[1].As<Napi::Number>().Int32Value();
    GLint internalformat = info[2].As<Napi::Number>().Int32Value();
    GLsizei width = info[3].As<Napi::Number>().Int32Value();
    GLsizei height = info[4].As<Napi::Number>().Int32Value();
    GLint border = info[5].As<Napi::Number>().Int32Value();
    GLenum format = info[6].As<Napi::Number>().Int32Value();
    GLenum type = info[7].As<Napi::Number>().Int32Value();
    void *pixels = info[8].As<Napi::Buffer<GLubyte>>().Data();

    glTexImage2D(target, level, internalformat, width, height, border, format, type, pixels);
}

void __glTexParameterf(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum target = info[0].As<Napi::Number>().Int32Value();
    GLenum pname = info[1].As<Napi::Number>().Int32Value();
    GLfloat param = info[2].As<Napi::Number>().FloatValue();
  
    glTexParameterf(target, pname, param);
}

void __glTexParameterfv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum target = info[0].As<Napi::Number>().Int32Value();
    GLenum pname = info[1].As<Napi::Number>().Int32Value();
    GLfloat *params = (GLfloat*)info[2].As<Napi::Float32Array>().Data();
  
    glTexParameterfv(target, pname, params);
}

void __glTexParameteri(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum target = info[0].As<Napi::Number>().Int32Value();
    GLenum pname = info[1].As<Napi::Number>().Int32Value();
    GLint param = info[2].As<Napi::Number>().Int32Value();
  
    glTexParameteri(target, pname, param);
}

void __glTexParameteriv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum target = info[0].As<Napi::Number>().Int32Value();
    GLenum pname = info[1].As<Napi::Number>().Int32Value();
    GLint *params = (GLint*)info[2].As<Napi::Int32Array>().Data();
  
    glTexParameteriv(target, pname, params);
}

void __glTexSubImage1D(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum target = info[0].As<Napi::Number>().Int32Value();
    GLint level = info[1].As<Napi::Number>().Int32Value();
    GLint xoffset = info[2].As<Napi::Number>().Int32Value();
    GLsizei width = info[3].As<Napi::Number>().Int32Value();
    GLenum format = info[4].As<Napi::Number>().Int32Value();
    GLenum type = info[5].As<Napi::Number>().Int32Value();
    void *pixels = info[6].As<Napi::Buffer<GLubyte>>().Data();

    glTexSubImage1D(target, level, xoffset, width, format, type, pixels);
}

void __glTexSubImage2D(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum target = info[0].As<Napi::Number>().Int32Value();
    GLint level = info[1].As<Napi::Number>().Int32Value();
    GLint xoffset = info[2].As<Napi::Number>().Int32Value();
    GLint yoffset = info[3].As<Napi::Number>().Int32Value();
    GLsizei width = info[4].As<Napi::Number>().Int32Value();
    GLsizei height = info[5].As<Napi::Number>().Int32Value();
    GLenum format = info[6].As<Napi::Number>().Int32Value();
    GLenum type = info[7].As<Napi::Number>().Int32Value();
    void *pixels = info[8].As<Napi::Buffer<GLubyte>>().Data();

    glTexSubImage2D(target, level, xoffset, yoffset, width, height, format, type, pixels);
}

void __glTranslated(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLdouble x = info[0].As<Napi::Number>().DoubleValue();
    GLdouble y = info[1].As<Napi::Number>().DoubleValue();
    GLdouble z = info[2].As<Napi::Number>().DoubleValue();
  
    glTranslated(x, y, z);
}

void __glTranslatef(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLfloat x = info[0].As<Napi::Number>().FloatValue();
    GLfloat y = info[1].As<Napi::Number>().FloatValue();
    GLfloat z = info[2].As<Napi::Number>().FloatValue();
  
    glTranslatef(x, y, z);
}

void __glVertex2d(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLdouble x = info[0].As<Napi::Number>().DoubleValue();
    GLdouble y = info[1].As<Napi::Number>().DoubleValue();
  
    glVertex2d(x, y);
}

void __glVertex2dv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLdouble *v = (GLdouble*)info[0].As<Napi::Float64Array>().Data();
  
    glVertex2dv(v);
}

void __glVertex2f(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLfloat x = info[0].As<Napi::Number>().FloatValue();
    GLfloat y = info[1].As<Napi::Number>().FloatValue();
  
    glVertex2f(x, y);
}

void __glVertex2fv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLfloat *v = (GLfloat*)info[0].As<Napi::Float32Array>().Data();
  
    glVertex2fv(v);
}

void __glVertex2i(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLint x = info[0].As<Napi::Number>().Int32Value();
    GLint y = info[1].As<Napi::Number>().Int32Value();
  
    glVertex2i(x, y);
}

void __glVertex2iv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLint *v = (GLint*)info[0].As<Napi::Int32Array>().Data();
  
    glVertex2iv(v);
}

void __glVertex2s(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLshort x = (GLshort)info[0].As<Napi::Number>().Int32Value();
    GLshort y = (GLshort)info[1].As<Napi::Number>().Int32Value();
  
    glVertex2s(x, y);
}

void __glVertex2sv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLshort *v = (GLshort*)info[0].As<Napi::Int16Array>().Data();
  
    glVertex2sv(v);
}

void __glVertex3d(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLdouble x = info[0].As<Napi::Number>().DoubleValue();
    GLdouble y = info[1].As<Napi::Number>().DoubleValue();
    GLdouble z = info[2].As<Napi::Number>().DoubleValue();
  
    glVertex3d(x, y, z);
}

void __glVertex3dv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLdouble *v = (GLdouble*)info[0].As<Napi::Float64Array>().Data();
  
    glVertex3dv(v);
}

void __glVertex3f(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLfloat x = info[0].As<Napi::Number>().FloatValue();
    GLfloat y = info[1].As<Napi::Number>().FloatValue();
    GLfloat z = info[2].As<Napi::Number>().FloatValue();
  
    glVertex3f(x, y, z);
}

void __glVertex3fv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLfloat *v = (GLfloat*)info[0].As<Napi::Float32Array>().Data();
  
    glVertex3fv(v);
}

void __glVertex3i(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLint x = info[0].As<Napi::Number>().Int32Value();
    GLint y = info[1].As<Napi::Number>().Int32Value();
    GLint z = info[2].As<Napi::Number>().Int32Value();
  
    glVertex3i(x, y, z);
}

void __glVertex3iv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLint *v = (GLint*)info[0].As<Napi::Int32Array>().Data();
  
    glVertex3iv(v);
}

void __glVertex3s(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLshort x = (GLshort)info[0].As<Napi::Number>().Int32Value();
    GLshort y = (GLshort)info[1].As<Napi::Number>().Int32Value();
    GLshort z = (GLshort)info[2].As<Napi::Number>().Int32Value();
  
    glVertex3s(x, y, z);
}

void __glVertex3sv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLshort *v = (GLshort*)info[0].As<Napi::Int16Array>().Data();
  
    glVertex3sv(v);
}

void __glVertex4d(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLdouble x = info[0].As<Napi::Number>().DoubleValue();
    GLdouble y = info[1].As<Napi::Number>().DoubleValue();
    GLdouble z = info[2].As<Napi::Number>().DoubleValue();
    GLdouble w = info[3].As<Napi::Number>().DoubleValue();
  
    glVertex4d(x, y, z, w);
}

void __glVertex4dv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLdouble *v = (GLdouble*)info[0].As<Napi::Float64Array>().Data();
  
    glVertex4dv(v);
}

void __glVertex4f(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLfloat x = info[0].As<Napi::Number>().FloatValue();
    GLfloat y = info[1].As<Napi::Number>().FloatValue();
    GLfloat z = info[2].As<Napi::Number>().FloatValue();
    GLfloat w = info[3].As<Napi::Number>().FloatValue();
  
    glVertex4f(x, y, z, w);
}

void __glVertex4fv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLfloat *v = (GLfloat*)info[0].As<Napi::Float32Array>().Data();
  
    glVertex4fv(v);
}

void __glVertex4i(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLint x = info[0].As<Napi::Number>().Int32Value();
    GLint y = info[1].As<Napi::Number>().Int32Value();
    GLint z = info[2].As<Napi::Number>().Int32Value();
    GLint w = info[3].As<Napi::Number>().Int32Value();
  
    glVertex4i(x, y, z, w);
}

void __glVertex4iv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLint *v = (GLint*)info[0].As<Napi::Int32Array>().Data();
  
    glVertex4iv(v);
}

void __glVertex4s(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLshort x = (GLshort)info[0].As<Napi::Number>().Int32Value();
    GLshort y = (GLshort)info[1].As<Napi::Number>().Int32Value();
    GLshort z = (GLshort)info[2].As<Napi::Number>().Int32Value();
    GLshort w = (GLshort)info[3].As<Napi::Number>().Int32Value();
  
    glVertex4s(x, y, z, w);
}

void __glVertex4sv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLshort *v = (GLshort*)info[0].As<Napi::Int16Array>().Data();
  
    glVertex4sv(v);
}

void __glVertexPointer(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLint size = info[0].As<Napi::Number>().Int32Value();
    GLenum type = info[1].As<Napi::Number>().Int32Value();
    GLsizei stride = info[2].As<Napi::Number>().Int32Value();
    void *pointer = (void*)info[3].As<Napi::Buffer<GLubyte>>().Data();

    glVertexPointer(size, type, stride, pointer);
}

void __glViewport(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLint x = info[0].As<Napi::Number>().Int32Value();
    GLint y = info[1].As<Napi::Number>().Int32Value();
    GLsizei width = info[2].As<Napi::Number>().Int32Value();
    GLsizei height = info[3].As<Napi::Number>().Int32Value();
  
    glViewport(x, y, width, height);
}

// OpenGL 1.2

void __glCopyTexSubImage3D(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum target = info[0].As<Napi::Number>().Int32Value();
    GLint level = info[1].As<Napi::Number>().Int32Value();
    GLint xoffset = info[2].As<Napi::Number>().Int32Value();
    GLint yoffset = info[3].As<Napi::Number>().Int32Value();
    GLint zoffset = info[4].As<Napi::Number>().Int32Value();
    GLint x = info[5].As<Napi::Number>().Int32Value();
    GLint y = info[6].As<Napi::Number>().Int32Value();
    GLsizei width = info[7].As<Napi::Number>().Int32Value();
    GLsizei height = info[8].As<Napi::Number>().Int32Value();
  
    glCopyTexSubImage3D(target, level, xoffset, yoffset, zoffset, x, y, width, height);
}

void __glDrawRangeElements(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum mode = info[0].As<Napi::Number>().Int32Value();
    GLuint start = info[1].As<Napi::Number>().Uint32Value();
    GLuint end = info[2].As<Napi::Number>().Uint32Value();
    GLsizei count = info[3].As<Napi::Number>().Int32Value();
    GLenum type = info[4].As<Napi::Number>().Int32Value();
    void *indices = (void*)info[5].As<Napi::Buffer<GLubyte>>().Data();

    glDrawRangeElements(mode, start, end, count, type, indices);
}

void __glTexImage3D(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum target = info[0].As<Napi::Number>().Int32Value();
    GLint level = info[1].As<Napi::Number>().Int32Value();
    GLenum internalformat = info[2].As<Napi::Number>().Int32Value();
    GLsizei width = info[3].As<Napi::Number>().Int32Value();
    GLsizei height = info[4].As<Napi::Number>().Int32Value();
    GLsizei depth = info[5].As<Napi::Number>().Int32Value();
    GLint border = info[6].As<Napi::Number>().Int32Value();
    GLenum format = info[7].As<Napi::Number>().Int32Value();
    GLenum type = info[8].As<Napi::Number>().Int32Value();
    void *pixels = (void*)info[9].As<Napi::Buffer<GLubyte>>().Data();

    glTexImage3D(target, level, internalformat, width, height, depth, border, format, type, pixels);
}

void __glTexSubImage3D(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum target = info[0].As<Napi::Number>().Int32Value();
    GLint level = info[1].As<Napi::Number>().Int32Value();
    GLint xoffset = info[2].As<Napi::Number>().Int32Value();
    GLint yoffset = info[3].As<Napi::Number>().Int32Value();
    GLint zoffset = info[4].As<Napi::Number>().Int32Value();
    GLsizei width = info[5].As<Napi::Number>().Int32Value();
    GLsizei height = info[6].As<Napi::Number>().Int32Value();
    GLsizei depth = info[7].As<Napi::Number>().Int32Value();
    GLenum format = info[8].As<Napi::Number>().Int32Value();
    GLenum type = info[9].As<Napi::Number>().Int32Value();
    void *pixels = (void*)info[10].As<Napi::Buffer<GLubyte>>().Data();

    glTexSubImage3D(target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels);
}

// OpenGL 1.3

void __glActiveTexture(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum texture = info[0].As<Napi::Number>().Int32Value();
  
    glActiveTexture(texture);
}

void __glClientActiveTexture(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum texture = info[0].As<Napi::Number>().Int32Value();
  
    glClientActiveTexture(texture);
}

void __glCompressedTexImage1D(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum target = info[0].As<Napi::Number>().Int32Value();
    GLint level = info[1].As<Napi::Number>().Int32Value();
    GLenum internalformat = info[2].As<Napi::Number>().Int32Value();
    GLsizei width = info[3].As<Napi::Number>().Int32Value();
    GLsizei imageSize = info[4].As<Napi::Number>().Int32Value();
    GLint border = info[5].As<Napi::Number>().Int32Value();
    GLubyte *data = info[6].As<Napi::Uint8Array>().Data();

    glCompressedTexImage1D(target, level, internalformat, width, border, imageSize, data);
}

void __glCompressedTexImage2D(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum target = info[0].As<Napi::Number>().Int32Value();
    GLint level = info[1].As<Napi::Number>().Int32Value();
    GLenum internalformat = info[2].As<Napi::Number>().Int32Value();
    GLsizei width = info[3].As<Napi::Number>().Int32Value();
    GLsizei height = info[4].As<Napi::Number>().Int32Value();
    GLsizei imageSize = info[5].As<Napi::Number>().Int32Value();
    GLint border = info[6].As<Napi::Number>().Int32Value();
    GLubyte *data = info[7].As<Napi::Uint8Array>().Data();
  
    glCompressedTexImage2D(target, level, internalformat, width, height, border, imageSize, data);
}

void __glCompressedTexImage3D(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum target = info[0].As<Napi::Number>().Int32Value();
    GLint level = info[1].As<Napi::Number>().Int32Value();
    GLenum internalformat = info[2].As<Napi::Number>().Int32Value();
    GLsizei width = info[3].As<Napi::Number>().Int32Value();
    GLsizei height = info[4].As<Napi::Number>().Int32Value();
    GLsizei depth = info[5].As<Napi::Number>().Int32Value();
    GLsizei imageSize = info[6].As<Napi::Number>().Int32Value();
    GLint border = info[7].As<Napi::Number>().Int32Value();
    GLubyte *data = info[8].As<Napi::Uint8Array>().Data();
  
    glCompressedTexImage3D(target, level, internalformat, width, height, depth, border, imageSize, data);
}

void __glCompressedTexSubImage1D(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum target = info[0].As<Napi::Number>().Int32Value();
    GLint level = info[1].As<Napi::Number>().Int32Value();
    GLint xoffset = info[2].As<Napi::Number>().Int32Value();
    GLsizei width = info[3].As<Napi::Number>().Int32Value();
    GLenum format = info[4].As<Napi::Number>().Int32Value();
    GLsizei imageSize = info[5].As<Napi::Number>().Int32Value();
    GLubyte *data = info[6].As<Napi::Uint8Array>().Data();
  
    glCompressedTexSubImage1D(target, level, xoffset, width, format, imageSize, data);
}

void __glCompressedTexSubImage2D(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum target = info[0].As<Napi::Number>().Int32Value();
    GLint level = info[1].As<Napi::Number>().Int32Value();
    GLint xoffset = info[2].As<Napi::Number>().Int32Value();
    GLint yoffset = info[3].As<Napi::Number>().Int32Value();
    GLsizei width = info[4].As<Napi::Number>().Int32Value();
    GLsizei height = info[5].As<Napi::Number>().Int32Value();
    GLenum format = info[6].As<Napi::Number>().Int32Value();
    GLsizei imageSize = info[7].As<Napi::Number>().Int32Value();
    GLubyte *data = info[8].As<Napi::Uint8Array>().Data();
  
    glCompressedTexSubImage2D(target, level, xoffset, yoffset, width, height, format, imageSize, data);
}

void __glCompressedTexSubImage3D(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum target = info[0].As<Napi::Number>().Int32Value();
    GLint level = info[1].As<Napi::Number>().Int32Value();
    GLint xoffset = info[2].As<Napi::Number>().Int32Value();
    GLint yoffset = info[3].As<Napi::Number>().Int32Value();
    GLint zoffset = info[4].As<Napi::Number>().Int32Value();
    GLsizei width = info[5].As<Napi::Number>().Int32Value();
    GLsizei height = info[6].As<Napi::Number>().Int32Value();
    GLsizei depth = info[7].As<Napi::Number>().Int32Value();
    GLenum format = info[8].As<Napi::Number>().Int32Value();
    GLsizei imageSize = info[9].As<Napi::Number>().Int32Value();
    GLubyte *data = info[10].As<Napi::Uint8Array>().Data();
  
    glCompressedTexSubImage3D(target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data);
}

void __glGetCompressedTexImage(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum target = info[0].As<Napi::Number>().Int32Value();
    GLint level = info[1].As<Napi::Number>().Int32Value();
    GLubyte *data = info[2].As<Napi::Uint8Array>().Data();
  
    glGetCompressedTexImage(target, level, data);
}

void __glLoadTransposeMatrixd(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLdouble *m = info[0].As<Napi::Float64Array>().Data();
  
    glLoadTransposeMatrixd(m);
}

void __glLoadTransposeMatrixf(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLfloat *m = info[0].As<Napi::Float32Array>().Data();
  
    glLoadTransposeMatrixf(m);
}

void __glMultTransposeMatrixd(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLdouble *m = info[0].As<Napi::Float64Array>().Data();
  
    glMultTransposeMatrixd(m);
}

void __glMultTransposeMatrixf(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLfloat *m = info[0].As<Napi::Float32Array>().Data();
  
    glMultTransposeMatrixf(m);
}

void __glMultiTexCoord1d(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum target = info[0].As<Napi::Number>().Int32Value();
    GLdouble s = info[1].As<Napi::Number>().DoubleValue();
  
    glMultiTexCoord1d(target, s);
}

void __glMultiTexCoord1dv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum target = info[0].As<Napi::Number>().Int32Value();
    GLdouble *v = info[1].As<Napi::Float64Array>().Data();
  
    glMultiTexCoord1dv(target, v);
}

void __glMultiTexCoord1f(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum target = info[0].As<Napi::Number>().Int32Value();
    GLfloat s = info[1].As<Napi::Number>().FloatValue();
  
    glMultiTexCoord1f(target, s);
}

void __glMultiTexCoord1fv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum target = info[0].As<Napi::Number>().Int32Value();
    GLfloat *v = info[1].As<Napi::Float32Array>().Data();
  
    glMultiTexCoord1fv(target, v);
}

void __glMultiTexCoord1i(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum target = info[0].As<Napi::Number>().Int32Value();
    GLint s = info[1].As<Napi::Number>().Int32Value();
  
    glMultiTexCoord1i(target, s);
}

void __glMultiTexCoord1iv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum target = info[0].As<Napi::Number>().Int32Value();
    GLint *v = info[1].As<Napi::Int32Array>().Data();
  
    glMultiTexCoord1iv(target, v);
}

void __glMultiTexCoord1s(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum target = info[0].As<Napi::Number>().Int32Value();
    GLshort s = (GLshort)info[1].As<Napi::Number>().Int32Value();
  
    glMultiTexCoord1s(target, s);
}

void __glMultiTexCoord1sv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum target = info[0].As<Napi::Number>().Int32Value();
    GLshort *v = info[1].As<Napi::Int16Array>().Data();
  
    glMultiTexCoord1sv(target, v);
}

void __glMultiTexCoord2d(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum target = info[0].As<Napi::Number>().Int32Value();
    GLdouble s = info[1].As<Napi::Number>().DoubleValue();
    GLdouble t = info[2].As<Napi::Number>().DoubleValue();
  
    glMultiTexCoord2d(target, s, t);
}

void __glMultiTexCoord2dv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum target = info[0].As<Napi::Number>().Int32Value();
    GLdouble *v = info[1].As<Napi::Float64Array>().Data();
  
    glMultiTexCoord2dv(target, v);
}

void __glMultiTexCoord2f(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum target = info[0].As<Napi::Number>().Int32Value();
    GLfloat s = info[1].As<Napi::Number>().FloatValue();
    GLfloat t = info[2].As<Napi::Number>().FloatValue();
  
    glMultiTexCoord2f(target, s, t);
}

void __glMultiTexCoord2fv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum target = info[0].As<Napi::Number>().Int32Value();
    GLfloat *v = info[1].As<Napi::Float32Array>().Data();
  
    glMultiTexCoord2fv(target, v);
}

void __glMultiTexCoord2i(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum target = info[0].As<Napi::Number>().Int32Value();
    GLint s = info[1].As<Napi::Number>().Int32Value();
    GLint t = info[2].As<Napi::Number>().Int32Value();
  
    glMultiTexCoord2i(target, s, t);
}

void __glMultiTexCoord2iv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum target = info[0].As<Napi::Number>().Int32Value();
    GLint *v = info[1].As<Napi::Int32Array>().Data();
  
    glMultiTexCoord2iv(target, v);
}

void __glMultiTexCoord2s(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum target = info[0].As<Napi::Number>().Int32Value();
    GLshort s = (GLshort)info[1].As<Napi::Number>().Int32Value();
    GLshort t = (GLshort)info[2].As<Napi::Number>().Int32Value();
  
    glMultiTexCoord2s(target, s, t);
}

void __glMultiTexCoord2sv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum target = info[0].As<Napi::Number>().Int32Value();
    GLshort *v = info[1].As<Napi::Int16Array>().Data();
  
    glMultiTexCoord2sv(target, v);
}

void __glMultiTexCoord3d(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum target = info[0].As<Napi::Number>().Int32Value();
    GLdouble s = info[1].As<Napi::Number>().DoubleValue();
    GLdouble t = info[2].As<Napi::Number>().DoubleValue();
    GLdouble r = info[3].As<Napi::Number>().DoubleValue();
  
    glMultiTexCoord3d(target, s, t, r);
}

void __glMultiTexCoord3dv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum target = info[0].As<Napi::Number>().Int32Value();
    GLdouble *v = info[1].As<Napi::Float64Array>().Data();
  
    glMultiTexCoord3dv(target, v);
}

void __glMultiTexCoord3f(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum target = info[0].As<Napi::Number>().Int32Value();
    GLfloat s = info[1].As<Napi::Number>().FloatValue();
    GLfloat t = info[2].As<Napi::Number>().FloatValue();
    GLfloat r = info[3].As<Napi::Number>().FloatValue();
  
    glMultiTexCoord3f(target, s, t, r);
}

void __glMultiTexCoord3fv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum target = info[0].As<Napi::Number>().Int32Value();
    GLfloat *v = info[1].As<Napi::Float32Array>().Data();
  
    glMultiTexCoord3fv(target, v);
}

void __glMultiTexCoord3i(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum target = info[0].As<Napi::Number>().Int32Value();
    GLint s = info[1].As<Napi::Number>().Int32Value();
    GLint t = info[2].As<Napi::Number>().Int32Value();
    GLint r = info[3].As<Napi::Number>().Int32Value();
  
    glMultiTexCoord3i(target, s, t, r);
}

void __glMultiTexCoord3iv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum target = info[0].As<Napi::Number>().Int32Value();
    GLint *v = info[1].As<Napi::Int32Array>().Data();
  
    glMultiTexCoord3iv(target, v);
}

void __glMultiTexCoord3s(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum target = info[0].As<Napi::Number>().Int32Value();
    GLshort s = (GLshort)info[1].As<Napi::Number>().Int32Value();
    GLshort t = (GLshort)info[2].As<Napi::Number>().Int32Value();
    GLshort r = (GLshort)info[3].As<Napi::Number>().Int32Value();
  
    glMultiTexCoord3s(target, s, t, r);
}

void __glMultiTexCoord3sv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum target = info[0].As<Napi::Number>().Int32Value();
    GLshort *v = info[1].As<Napi::Int16Array>().Data();
  
    glMultiTexCoord3sv(target, v);
}

void __glMultiTexCoord4d(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum target = info[0].As<Napi::Number>().Int32Value();
    GLdouble s = info[1].As<Napi::Number>().DoubleValue();
    GLdouble t = info[2].As<Napi::Number>().DoubleValue();
    GLdouble r = info[3].As<Napi::Number>().DoubleValue();
    GLdouble q = info[4].As<Napi::Number>().DoubleValue();
  
    glMultiTexCoord4d(target, s, t, r, q);
}

void __glMultiTexCoord4dv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum target = info[0].As<Napi::Number>().Int32Value();
    GLdouble *v = info[1].As<Napi::Float64Array>().Data();
  
    glMultiTexCoord4dv(target, v);
}

void __glMultiTexCoord4f(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum target = info[0].As<Napi::Number>().Int32Value();
    GLfloat s = info[1].As<Napi::Number>().FloatValue();
    GLfloat t = info[2].As<Napi::Number>().FloatValue();
    GLfloat r = info[3].As<Napi::Number>().FloatValue();
    GLfloat q = info[4].As<Napi::Number>().FloatValue();
  
    glMultiTexCoord4f(target, s, t, r, q);
}

void __glMultiTexCoord4fv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum target = info[0].As<Napi::Number>().Int32Value();
    GLfloat *v = info[1].As<Napi::Float32Array>().Data();
  
    glMultiTexCoord4fv(target, v);
}

void __glMultiTexCoord4i(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum target = info[0].As<Napi::Number>().Int32Value();
    GLint s = info[1].As<Napi::Number>().Int32Value();
    GLint t = info[2].As<Napi::Number>().Int32Value();
    GLint r = info[3].As<Napi::Number>().Int32Value();
    GLint q = info[4].As<Napi::Number>().Int32Value();
  
    glMultiTexCoord4i(target, s, t, r, q);
}

void __glMultiTexCoord4iv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum target = info[0].As<Napi::Number>().Int32Value();
    GLint *v = info[1].As<Napi::Int32Array>().Data();
  
    glMultiTexCoord4iv(target, v);
}

void __glMultiTexCoord4s(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum target = info[0].As<Napi::Number>().Int32Value();
    GLshort s = (GLshort)info[1].As<Napi::Number>().Int32Value();
    GLshort t = (GLshort)info[2].As<Napi::Number>().Int32Value();
    GLshort r = (GLshort)info[3].As<Napi::Number>().Int32Value();
    GLshort q = (GLshort)info[4].As<Napi::Number>().Int32Value();
  
    glMultiTexCoord4s(target, s, t, r, q);
}

void __glMultiTexCoord4sv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum target = info[0].As<Napi::Number>().Int32Value();
    GLshort *v = info[1].As<Napi::Int16Array>().Data();
  
    glMultiTexCoord4sv(target, v);
}

void __glSampleCoverage(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLclampf value = info[0].As<Napi::Number>().FloatValue();
    GLboolean invert = info[1].As<Napi::Boolean>().Value();
  
    glSampleCoverage(value, invert);
}

// OpenGL 1.4

void __glBlendColor(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLclampf red = info[0].As<Napi::Number>().FloatValue();
    GLclampf green = info[1].As<Napi::Number>().FloatValue();
    GLclampf blue = info[2].As<Napi::Number>().FloatValue();
    GLclampf alpha = info[3].As<Napi::Number>().FloatValue();
  
    glBlendColor(red, green, blue, alpha);
}

void __glBlendEquation(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum mode = info[0].As<Napi::Number>().Int32Value();
  
    glBlendEquation(mode);
}

void __glBlendFuncSeparate(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum sfactorRGB = info[0].As<Napi::Number>().Int32Value();
    GLenum dfactorRGB = info[1].As<Napi::Number>().Int32Value();
    GLenum sfactorAlpha = info[2].As<Napi::Number>().Int32Value();
    GLenum dfactorAlpha = info[3].As<Napi::Number>().Int32Value();
  
    glBlendFuncSeparate(sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha);
}

void __glFogCoordPointer(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum type = info[0].As<Napi::Number>().Int32Value();
    GLsizei stride = info[1].As<Napi::Number>().Int32Value();
    GLvoid *pointer = (GLvoid *)info[2].As<Napi::Buffer<GLubyte>>().Data();

    glFogCoordPointer(type, stride, pointer);
}

void __glFogCoordd(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLdouble coord = info[0].As<Napi::Number>().DoubleValue();
  
    glFogCoordd(coord);
}

void __glFogCoorddv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLdouble *coord = info[0].As<Napi::Float64Array>().Data();
  
    glFogCoorddv(coord);
}

void __glFogCoordf(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLfloat coord = info[0].As<Napi::Number>().FloatValue();
  
    glFogCoordf(coord);
}

void __glFogCoordfv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLfloat *coord = info[0].As<Napi::Float32Array>().Data();
  
    glFogCoordfv(coord);
}

void __glMultiDrawArrays(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum mode = info[0].As<Napi::Number>().Int32Value();
    GLint *first = info[1].As<Napi::Int32Array>().Data();
    GLsizei *count = info[2].As<Napi::Int32Array>().Data();
    GLsizei drawcount = info[3].As<Napi::Number>().Int32Value();
  
    glMultiDrawArrays(mode, first, count, drawcount);
}

void __glMultiDrawElements(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum mode = info[0].As<Napi::Number>().Int32Value();
    GLsizei *count = info[1].As<Napi::Int32Array>().Data();
    GLenum type = info[2].As<Napi::Number>().Int32Value();
    Napi::Array _indices = info[3].As<Napi::Array>();
    GLsizei drawcount = info[4].As<Napi::Number>().Int32Value();
    
    GLubyte **indices = new GLubyte*[drawcount];

    for (int i = 0; i < drawcount; i++) {
        indices[i] = _indices.Get(i).As<Napi::Buffer<GLubyte>>().Data();
    }

    glMultiDrawElements(mode, count, type, (void **)indices, drawcount);
}

void __glPointParameterf(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum pname = info[0].As<Napi::Number>().Int32Value();
    GLfloat param = info[1].As<Napi::Number>().FloatValue();
  
    glPointParameterf(pname, param);
}

void __glPointParameterfv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum pname = info[0].As<Napi::Number>().Int32Value();
    GLfloat *params = info[1].As<Napi::Float32Array>().Data();
  
    glPointParameterfv(pname, params);
}

void __glPointParameteri(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum pname = info[0].As<Napi::Number>().Int32Value();
    GLint param = info[1].As<Napi::Number>().Int32Value();
  
    glPointParameteri(pname, param);
}

void __glPointParameteriv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum pname = info[0].As<Napi::Number>().Int32Value();
    GLint *params = info[1].As<Napi::Int32Array>().Data();
  
    glPointParameteriv(pname, params);
}

void __glSecondaryColor3b(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLbyte red = (GLbyte)info[0].As<Napi::Number>().Int32Value();
    GLbyte green = (GLbyte)info[1].As<Napi::Number>().Int32Value();
    GLbyte blue = (GLbyte)info[2].As<Napi::Number>().Int32Value();
  
    glSecondaryColor3b(red, green, blue);
}

void __glSecondaryColor3bv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLbyte *v = info[0].As<Napi::Int8Array>().Data();
  
    glSecondaryColor3bv(v);
}

void __glSecondaryColor3d(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLdouble red = info[0].As<Napi::Number>().DoubleValue();
    GLdouble green = info[1].As<Napi::Number>().DoubleValue();
    GLdouble blue = info[2].As<Napi::Number>().DoubleValue();
  
    glSecondaryColor3d(red, green, blue);
}

void __glSecondaryColor3dv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLdouble *v = info[0].As<Napi::Float64Array>().Data();
  
    glSecondaryColor3dv(v);
}

void __glSecondaryColor3f(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLfloat red = info[0].As<Napi::Number>().FloatValue();
    GLfloat green = info[1].As<Napi::Number>().FloatValue();
    GLfloat blue = info[2].As<Napi::Number>().FloatValue();
  
    glSecondaryColor3f(red, green, blue);
}

void __glSecondaryColor3fv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLfloat *v = info[0].As<Napi::Float32Array>().Data();
  
    glSecondaryColor3fv(v);
}

void __glSecondaryColor3i(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLint red = info[0].As<Napi::Number>().Int32Value();
    GLint green = info[1].As<Napi::Number>().Int32Value();
    GLint blue = info[2].As<Napi::Number>().Int32Value();
  
    glSecondaryColor3i(red, green, blue);
}

void __glSecondaryColor3iv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLint *v = info[0].As<Napi::Int32Array>().Data();
  
    glSecondaryColor3iv(v);
}

void __glSecondaryColor3s(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLshort red = (GLshort)info[0].As<Napi::Number>().Int32Value();
    GLshort green = (GLshort)info[1].As<Napi::Number>().Int32Value();
    GLshort blue = (GLshort)info[2].As<Napi::Number>().Int32Value();
  
    glSecondaryColor3s(red, green, blue);
}

void __glSecondaryColor3sv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLshort *v = info[0].As<Napi::Int16Array>().Data();
  
    glSecondaryColor3sv(v);
}

void __glSecondaryColor3ub(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLubyte red = (GLubyte)info[0].As<Napi::Number>().Uint32Value();
    GLubyte green = (GLubyte)info[1].As<Napi::Number>().Uint32Value();
    GLubyte blue = (GLubyte)info[2].As<Napi::Number>().Uint32Value();
  
    glSecondaryColor3ub(red, green, blue);
}

void __glSecondaryColor3ubv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLubyte *v = info[0].As<Napi::Uint8Array>().Data();
  
    glSecondaryColor3ubv(v);
}

void __glSecondaryColor3ui(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint red = info[0].As<Napi::Number>().Uint32Value();
    GLuint green = info[1].As<Napi::Number>().Uint32Value();
    GLuint blue = info[2].As<Napi::Number>().Uint32Value();
  
    glSecondaryColor3ui(red, green, blue);
}

void __glSecondaryColor3uiv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint *v = info[0].As<Napi::Uint32Array>().Data();
  
    glSecondaryColor3uiv(v);
}

void __glSecondaryColor3us(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLushort red = (GLushort)info[0].As<Napi::Number>().Uint32Value();
    GLushort green = (GLushort)info[1].As<Napi::Number>().Uint32Value();
    GLushort blue = (GLushort)info[2].As<Napi::Number>().Uint32Value();
  
    glSecondaryColor3us(red, green, blue);
}

void __glSecondaryColor3usv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLushort *v = info[0].As<Napi::Uint16Array>().Data();
  
    glSecondaryColor3usv(v);
}

void __glSecondaryColorPointer(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLint size = info[0].As<Napi::Number>().Int32Value();
    GLenum type = info[1].As<Napi::Number>().Uint32Value();
    GLsizei stride = info[2].As<Napi::Number>().Int32Value();
    GLvoid *pointer = (GLvoid *)info[3].As<Napi::Buffer<GLubyte>>().Data();

    glSecondaryColorPointer(size, type, stride, pointer);
}

void __glWindowPos2d(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLdouble x = info[0].As<Napi::Number>().DoubleValue();
    GLdouble y = info[1].As<Napi::Number>().DoubleValue();
  
    glWindowPos2d(x, y);
}

void __glWindowPos2dv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLdouble *v = info[0].As<Napi::Float64Array>().Data();
  
    glWindowPos2dv(v);
}

void __glWindowPos2f(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLfloat x = info[0].As<Napi::Number>().FloatValue();
    GLfloat y = info[1].As<Napi::Number>().FloatValue();
  
    glWindowPos2f(x, y);
}

void __glWindowPos2fv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLfloat *v = info[0].As<Napi::Float32Array>().Data();
  
    glWindowPos2fv(v);
}

void __glWindowPos2i(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLint x = info[0].As<Napi::Number>().Int32Value();
    GLint y = info[1].As<Napi::Number>().Int32Value();
  
    glWindowPos2i(x, y);
}

void __glWindowPos2iv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLint *v = info[0].As<Napi::Int32Array>().Data();
  
    glWindowPos2iv(v);
}

void __glWindowPos2s(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLshort x = (GLshort)info[0].As<Napi::Number>().Int32Value();
    GLshort y = (GLshort)info[1].As<Napi::Number>().Int32Value();
  
    glWindowPos2s(x, y);
}

void __glWindowPos2sv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLshort *v = info[0].As<Napi::Int16Array>().Data();
  
    glWindowPos2sv(v);
}

void __glWindowPos3d(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLdouble x = info[0].As<Napi::Number>().DoubleValue();
    GLdouble y = info[1].As<Napi::Number>().DoubleValue();
    GLdouble z = info[2].As<Napi::Number>().DoubleValue();
  
    glWindowPos3d(x, y, z);
}

void __glWindowPos3dv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLdouble *v = info[0].As<Napi::Float64Array>().Data();
  
    glWindowPos3dv(v);
}

void __glWindowPos3f(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLfloat x = info[0].As<Napi::Number>().FloatValue();
    GLfloat y = info[1].As<Napi::Number>().FloatValue();
    GLfloat z = info[2].As<Napi::Number>().FloatValue();
  
    glWindowPos3f(x, y, z);
}

void __glWindowPos3fv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLfloat *v = info[0].As<Napi::Float32Array>().Data();
  
    glWindowPos3fv(v);
}

void __glWindowPos3i(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLint x = info[0].As<Napi::Number>().Int32Value();
    GLint y = info[1].As<Napi::Number>().Int32Value();
    GLint z = info[2].As<Napi::Number>().Int32Value();
  
    glWindowPos3i(x, y, z);
}

void __glWindowPos3iv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLint *v = info[0].As<Napi::Int32Array>().Data();
  
    glWindowPos3iv(v);
}

void __glWindowPos3s(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLshort x = (GLshort)info[0].As<Napi::Number>().Int32Value();
    GLshort y = (GLshort)info[1].As<Napi::Number>().Int32Value();
    GLshort z = (GLshort)info[2].As<Napi::Number>().Int32Value();
  
    glWindowPos3s(x, y, z);
}

void __glWindowPos3sv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLshort *v = info[0].As<Napi::Int16Array>().Data();
  
    glWindowPos3sv(v);
}

// OpenGL 1.5

void __glBeginQuery(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum target = info[0].As<Napi::Number>().Int32Value();
    GLuint id = info[1].As<Napi::Number>().Uint32Value();
  
    glBeginQuery(target, id);
}

void __glBindBuffer(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum target = info[0].As<Napi::Number>().Int32Value();
    GLuint buffer = info[1].As<Napi::Number>().Uint32Value();
  
    glBindBuffer(target, buffer);
}

void __glBufferData(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum target = info[0].As<Napi::Number>().Int32Value();
    GLsizeiptr size = info[1].As<Napi::Number>().Int32Value();
    void* pointer = info[2].As<Napi::Buffer<GLubyte>>().Data();
    GLenum usage = info[3].As<Napi::Number>().Int32Value();

    glBufferData(target, size, pointer, usage);
}

void __glBufferSubData(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum target = info[0].As<Napi::Number>().Int32Value();
    GLintptr offset = info[1].As<Napi::Number>().Int32Value();
    GLsizeiptr size = info[2].As<Napi::Number>().Int32Value();
    GLubyte *data = info[3].As<Napi::Buffer<GLubyte>>().Data();
  
    glBufferSubData(target, offset, size, data);
}

void __glDeleteBuffers(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLsizei n = info[0].As<Napi::Number>().Int32Value();
    GLuint *buffers = info[1].As<Napi::Uint32Array>().Data();
  
    glDeleteBuffers(n, buffers);
}

void __glDeleteQueries(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLsizei n = info[0].As<Napi::Number>().Int32Value();
    GLuint *ids = info[1].As<Napi::Uint32Array>().Data();
  
    glDeleteQueries(n, ids);
}

void __glEndQuery(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum target = info[0].As<Napi::Number>().Int32Value();
  
    glEndQuery(target);
}

void __glGenBuffers(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLsizei n = info[0].As<Napi::Number>().Int32Value();
    GLuint *buffers = info[1].As<Napi::Uint32Array>().Data();
  
    glGenBuffers(n, buffers);
}

void __glGenQueries(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLsizei n = info[0].As<Napi::Number>().Int32Value();
    GLuint *ids = info[1].As<Napi::Uint32Array>().Data();
  
    glGenQueries(n, ids);
}

void __glGetBufferParameteriv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum target = info[0].As<Napi::Number>().Int32Value();
    GLenum pname = info[1].As<Napi::Number>().Int32Value();
    GLint *params = info[2].As<Napi::Int32Array>().Data();
  
    glGetBufferParameteriv(target, pname, params);
}

void __glGetBufferPointerv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum target = info[0].As<Napi::Number>().Int32Value();
    GLenum pname = info[1].As<Napi::Number>().Int32Value();
    GLubyte *params = info[2].As<Napi::Buffer<GLubyte>>().Data();
  
    glGetBufferPointerv(target, pname, (void**)&params);
}

void __glGetBufferSubData(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum target = info[0].As<Napi::Number>().Int32Value();
    GLintptr offset = info[1].As<Napi::Number>().Int32Value();
    GLsizeiptr size = info[2].As<Napi::Number>().Int32Value();
    GLubyte *data = info[3].As<Napi::Buffer<GLubyte>>().Data();
  
    glGetBufferSubData(target, offset, size, data);
}

void __glGetQueryObjectiv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint id = info[0].As<Napi::Number>().Uint32Value();
    GLenum pname = info[1].As<Napi::Number>().Int32Value();
    GLint *params = info[2].As<Napi::Int32Array>().Data();
  
    glGetQueryObjectiv(id, pname, params);
}

void __glGetQueryObjectuiv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint id = info[0].As<Napi::Number>().Uint32Value();
    GLenum pname = info[1].As<Napi::Number>().Int32Value();
    GLuint *params = info[2].As<Napi::Uint32Array>().Data();
  
    glGetQueryObjectuiv(id, pname, params);
}

void __glGetQueryiv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum target = info[0].As<Napi::Number>().Int32Value();
    GLenum pname = info[1].As<Napi::Number>().Int32Value();
    GLint *params = info[2].As<Napi::Int32Array>().Data();
  
    glGetQueryiv(target, pname, params);
}

Napi::Boolean __glIsBuffer(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint buffer = info[0].As<Napi::Number>().Uint32Value();
  
    return Napi::Boolean::New(env, glIsBuffer(buffer));
}

Napi::Boolean __glIsQuery(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint id = info[0].As<Napi::Number>().Uint32Value();
  
    return Napi::Boolean::New(env, glIsQuery(id));
}

Napi::External<void> __glMapBuffer(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum target = info[0].As<Napi::Number>().Int32Value();
    GLenum access = info[1].As<Napi::Number>().Int32Value();
  
    void *ptr = glMapBuffer(target, access);
    return Napi::External<void>::New(env, ptr);
}

Napi::Boolean __glUnmapBuffer(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum target = info[0].As<Napi::Number>().Int32Value();
  
    return Napi::Boolean::New(env, glUnmapBuffer(target));
}

// OpenGL 2.0

void __glAttachShader(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint program = info[0].As<Napi::Number>().Uint32Value();
    GLuint shader = info[1].As<Napi::Number>().Uint32Value();
  
    glAttachShader(program, shader);
}

void __glBindAttribLocation(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint program = info[0].As<Napi::Number>().Uint32Value();
    GLuint index = info[1].As<Napi::Number>().Uint32Value();
    const GLchar *name = info[2].As<Napi::String>().Utf8Value().c_str();
  
    glBindAttribLocation(program, index, name);
}

void __glBlendEquationSeparate(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum modeRGB = info[0].As<Napi::Number>().Int32Value();
    GLenum modeAlpha = info[1].As<Napi::Number>().Int32Value();
  
    glBlendEquationSeparate(modeRGB, modeAlpha);
}

void __glCompileShader(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint shader = info[0].As<Napi::Number>().Uint32Value();
  
    glCompileShader(shader);
}

Napi::Number __glCreateProgram(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    return Napi::Number::New(env, glCreateProgram());
}

Napi::Number __glCreateShader(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum type = info[0].As<Napi::Number>().Int32Value();
  
    return Napi::Number::New(env, glCreateShader(type));
}

void __glDeleteProgram(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint program = info[0].As<Napi::Number>().Uint32Value();
  
    glDeleteProgram(program);
}

void __glDeleteShader(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint shader = info[0].As<Napi::Number>().Uint32Value();
  
    glDeleteShader(shader);
}

void __glDetachShader(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint program = info[0].As<Napi::Number>().Uint32Value();
    GLuint shader = info[1].As<Napi::Number>().Uint32Value();
  
    glDetachShader(program, shader);
}

void __glDisableVertexAttribArray(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint index = info[0].As<Napi::Number>().Uint32Value();
  
    glDisableVertexAttribArray(index);
}

void __glDrawBuffers(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLsizei n = info[0].As<Napi::Number>().Int32Value();
    const GLenum *bufs = info[1].As<Napi::Uint32Array>().Data();
  
    glDrawBuffers(n, bufs);
}

void __glEnableVertexAttribArray(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint index = info[0].As<Napi::Number>().Uint32Value();
  
    glEnableVertexAttribArray(index);
}

void __glGetActiveAttrib(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint program = info[0].As<Napi::Number>().Uint32Value();
    GLuint index = info[1].As<Napi::Number>().Uint32Value();
    GLsizei maxLength = info[2].As<Napi::Number>().Int32Value();
    GLsizei length = 0;
    GLint size = 0;
    GLenum type = 0;
    GLchar *name = new GLchar[maxLength];

    glGetActiveAttrib(program, index, maxLength, &length, &size, &type, name);

    setObjPtr(env, info[3].As<Napi::Object>(), Napi::Number::New(env, length));
    setObjPtr(env, info[4].As<Napi::Object>(), Napi::Number::New(env, size));
    setObjPtr(env, info[5].As<Napi::Object>(), Napi::Number::New(env, type));
    setObjPtr(env, info[6].As<Napi::Object>(), Napi::String::New(env, name));
}

void __glGetActiveUniform(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint program = info[0].As<Napi::Number>().Uint32Value();
    GLuint index = info[1].As<Napi::Number>().Uint32Value();
    GLsizei maxLength = info[2].As<Napi::Number>().Int32Value();
    GLsizei length = 0;
    GLint size = 0;
    GLenum type = 0;
    GLchar *name = new GLchar[maxLength];

    glGetActiveUniform(program, index, maxLength, &length, &size, &type, name);

    setObjPtr(env, info[3].As<Napi::Object>(), Napi::Number::New(env, length));
    setObjPtr(env, info[4].As<Napi::Object>(), Napi::Number::New(env, size));
    setObjPtr(env, info[5].As<Napi::Object>(), Napi::Number::New(env, type));
    setObjPtr(env, info[6].As<Napi::Object>(), Napi::String::New(env, name));
}

void __glGetAttachedShaders(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint program = info[0].As<Napi::Number>().Uint32Value();
    GLsizei maxCount = info[1].As<Napi::Number>().Int32Value();
    GLsizei count = 0;
    GLuint *shaders = info[3].As<Napi::Uint32Array>().Data();
  
    glGetAttachedShaders(program, maxCount, &count, shaders);
  
    setObjPtr(env, info[2].As<Napi::Object>(), Napi::Number::New(env, count));
}

Napi::Number __glGetAttribLocation(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint program = info[0].As<Napi::Number>().Uint32Value();
    const GLchar *name = info[1].As<Napi::String>().Utf8Value().c_str();
  
    return Napi::Number::New(env, glGetAttribLocation(program, name));
}

void __glGetProgramInfoLog(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint program = info[0].As<Napi::Number>().Uint32Value();
    GLsizei maxLength = info[1].As<Napi::Number>().Int32Value();
    GLsizei length = 0;
    GLchar *infoLog = new GLchar[maxLength];
  
    glGetProgramInfoLog(program, maxLength, &length, infoLog);
  
    setObjPtr(env, info[2].As<Napi::Object>(), Napi::Number::New(env, length));
    setObjPtr(env, info[3].As<Napi::Object>(), Napi::String::New(env, infoLog));
}

void __glGetProgramiv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint program = info[0].As<Napi::Number>().Uint32Value();
    GLenum pname = info[1].As<Napi::Number>().Uint32Value();
    GLint *params = info[2].As<Napi::Int32Array>().Data();
  
    glGetProgramiv(program, pname, params);
}

void __glGetShaderInfoLog(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint shader = info[0].As<Napi::Number>().Uint32Value();
    GLsizei maxLength = info[1].As<Napi::Number>().Int32Value();
    GLsizei length = 0;
    GLchar *infoLog = new GLchar[maxLength];
  
    glGetShaderInfoLog(shader, maxLength, &length, infoLog);
  
    setObjPtr(env, info[2].As<Napi::Object>(), Napi::Number::New(env, length));
    setObjPtr(env, info[3].As<Napi::Object>(), Napi::String::New(env, infoLog));
}

void __glGetShaderSource(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint shader = info[0].As<Napi::Number>().Uint32Value();
    GLsizei maxLength = info[1].As<Napi::Number>().Int32Value();
    GLsizei length = 0;
    GLchar *source = new GLchar[maxLength];
  
    glGetShaderSource(shader, maxLength, &length, source);
  
    setObjPtr(env, info[2].As<Napi::Object>(), Napi::Number::New(env, length));
    setObjPtr(env, info[3].As<Napi::Object>(), Napi::String::New(env, source));
}

void __glGetShaderiv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint shader = info[0].As<Napi::Number>().Uint32Value();
    GLenum pname = info[1].As<Napi::Number>().Uint32Value();
    GLint *params = info[2].As<Napi::Int32Array>().Data();
  
    glGetShaderiv(shader, pname, params);
}

Napi::Number __glGetUniformLocation(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint program = info[0].As<Napi::Number>().Uint32Value();
    // const GLchar *name = info[1].As<Napi::String>().Utf8Value().c_str();

    // std::cout << "glGetUniformLocation: " << info[1].As<Napi::String>().Utf8Value().c_str() << std::endl;
  
    return Napi::Number::New(env, glGetUniformLocation(program, info[1].As<Napi::String>().Utf8Value().c_str()));
}

void __glGetUniformfv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint program = info[0].As<Napi::Number>().Uint32Value();
    GLint location = info[1].As<Napi::Number>().Int32Value();
    GLfloat *params = info[2].As<Napi::Float32Array>().Data();
  
    glGetUniformfv(program, location, params);
}

void __glGetUniformiv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint program = info[0].As<Napi::Number>().Uint32Value();
    GLint location = info[1].As<Napi::Number>().Int32Value();
    GLint *params = info[2].As<Napi::Int32Array>().Data();
  
    glGetUniformiv(program, location, params);
}

void __glGetVertexAttribPointerv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint index = info[0].As<Napi::Number>().Uint32Value();
    GLenum pname = info[1].As<Napi::Number>().Uint32Value();
    GLubyte* data = info[2].As<Napi::Buffer<GLubyte>>().Data();
  
    glGetVertexAttribPointerv(index, pname, (void**)&data);
}

void __glGetVertexAttribdv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint index = info[0].As<Napi::Number>().Uint32Value();
    GLenum pname = info[1].As<Napi::Number>().Uint32Value();
    GLdouble *params = info[2].As<Napi::Float64Array>().Data();
  
    glGetVertexAttribdv(index, pname, params);
}

void __glGetVertexAttribfv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint index = info[0].As<Napi::Number>().Uint32Value();
    GLenum pname = info[1].As<Napi::Number>().Uint32Value();
    GLfloat *params = info[2].As<Napi::Float32Array>().Data();
  
    glGetVertexAttribfv(index, pname, params);
}

void __glGetVertexAttribiv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint index = info[0].As<Napi::Number>().Uint32Value();
    GLenum pname = info[1].As<Napi::Number>().Uint32Value();
    GLint *params = info[2].As<Napi::Int32Array>().Data();
  
    glGetVertexAttribiv(index, pname, params);
}

Napi::Boolean __glIsProgram(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint program = info[0].As<Napi::Number>().Uint32Value();
  
    return Napi::Boolean::New(env, glIsProgram(program));
}

Napi::Boolean __glIsShader(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint shader = info[0].As<Napi::Number>().Uint32Value();
  
    return Napi::Boolean::New(env, glIsShader(shader));
}

void __glLinkProgram(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint program = info[0].As<Napi::Number>().Uint32Value();
  
    glLinkProgram(program);
}

void __glShaderSource(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint shader = info[0].As<Napi::Number>().Uint32Value();
    GLsizei count = info[1].As<Napi::Number>().Int32Value();
    Napi::String source = info[2].As<Napi::String>();
    const GLint length = info[3].As<Napi::Number>().Int32Value();
    const auto str = info[2].As<Napi::String>().Utf8Value();
    const auto* c_str = str.c_str();

    glShaderSource(shader, count, &c_str, &length);
}

void __glStencilFuncSeparate(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum face = info[0].As<Napi::Number>().Uint32Value();
    GLenum func = info[1].As<Napi::Number>().Uint32Value();
    GLint ref = info[2].As<Napi::Number>().Int32Value();
    GLuint mask = info[3].As<Napi::Number>().Uint32Value();
  
    glStencilFuncSeparate(face, func, ref, mask);
}

void __glStencilMaskSeparate(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum face = info[0].As<Napi::Number>().Uint32Value();
    GLuint mask = info[1].As<Napi::Number>().Uint32Value();
  
    glStencilMaskSeparate(face, mask);
}

void __glStencilOpSeparate(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum face = info[0].As<Napi::Number>().Uint32Value();
    GLenum fail = info[1].As<Napi::Number>().Uint32Value();
    GLenum zfail = info[2].As<Napi::Number>().Uint32Value();
    GLenum zpass = info[3].As<Napi::Number>().Uint32Value();
  
    glStencilOpSeparate(face, fail, zfail, zpass);
}

void __glUniform1f(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLint location = info[0].As<Napi::Number>().Int32Value();
    GLfloat v0 = info[1].As<Napi::Number>().FloatValue();
  
    glUniform1f(location, v0);
}

void __glUniform1fv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLint location = info[0].As<Napi::Number>().Int32Value();
    GLsizei count = info[1].As<Napi::Number>().Int32Value();
    const GLfloat *value = info[2].As<Napi::Float32Array>().Data();
  
    glUniform1fv(location, count, value);
}

void __glUniform1i(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLint location = info[0].As<Napi::Number>().Int32Value();
    GLint v0 = info[1].As<Napi::Number>().Int32Value();
  
    glUniform1i(location, v0);
}

void __glUniform1iv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLint location = info[0].As<Napi::Number>().Int32Value();
    GLsizei count = info[1].As<Napi::Number>().Int32Value();
    const GLint *value = info[2].As<Napi::Int32Array>().Data();
  
    glUniform1iv(location, count, value);
}

void __glUniform2f(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLint location = info[0].As<Napi::Number>().Int32Value();
    GLfloat v0 = info[1].As<Napi::Number>().FloatValue();
    GLfloat v1 = info[2].As<Napi::Number>().FloatValue();
  
    glUniform2f(location, v0, v1);
}

void __glUniform2fv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLint location = info[0].As<Napi::Number>().Int32Value();
    GLsizei count = info[1].As<Napi::Number>().Int32Value();
    const GLfloat *value = info[2].As<Napi::Float32Array>().Data();
  
    glUniform2fv(location, count, value);
}

void __glUniform2i(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLint location = info[0].As<Napi::Number>().Int32Value();
    GLint v0 = info[1].As<Napi::Number>().Int32Value();
    GLint v1 = info[2].As<Napi::Number>().Int32Value();
  
    glUniform2i(location, v0, v1);
}

void __glUniform2iv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLint location = info[0].As<Napi::Number>().Int32Value();
    GLsizei count = info[1].As<Napi::Number>().Int32Value();
    const GLint *value = info[2].As<Napi::Int32Array>().Data();
  
    glUniform2iv(location, count, value);
}

void __glUniform3f(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLint location = info[0].As<Napi::Number>().Int32Value();
    GLfloat v0 = info[1].As<Napi::Number>().FloatValue();
    GLfloat v1 = info[2].As<Napi::Number>().FloatValue();
    GLfloat v2 = info[3].As<Napi::Number>().FloatValue();
  
    glUniform3f(location, v0, v1, v2);
}

void __glUniform3fv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLint location = info[0].As<Napi::Number>().Int32Value();
    GLsizei count = info[1].As<Napi::Number>().Int32Value();
    const GLfloat *value = info[2].As<Napi::Float32Array>().Data();
  
    glUniform3fv(location, count, value);
}

void __glUniform3i(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLint location = info[0].As<Napi::Number>().Int32Value();
    GLint v0 = info[1].As<Napi::Number>().Int32Value();
    GLint v1 = info[2].As<Napi::Number>().Int32Value();
    GLint v2 = info[3].As<Napi::Number>().Int32Value();
  
    glUniform3i(location, v0, v1, v2);
}

void __glUniform3iv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLint location = info[0].As<Napi::Number>().Int32Value();
    GLsizei count = info[1].As<Napi::Number>().Int32Value();
    const GLint *value = info[2].As<Napi::Int32Array>().Data();
  
    glUniform3iv(location, count, value);
}

void __glUniform4f(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLint location = info[0].As<Napi::Number>().Int32Value();
    GLfloat v0 = info[1].As<Napi::Number>().FloatValue();
    GLfloat v1 = info[2].As<Napi::Number>().FloatValue();
    GLfloat v2 = info[3].As<Napi::Number>().FloatValue();
    GLfloat v3 = info[4].As<Napi::Number>().FloatValue();
  
    glUniform4f(location, v0, v1, v2, v3);
}

void __glUniform4fv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLint location = info[0].As<Napi::Number>().Int32Value();
    GLsizei count = info[1].As<Napi::Number>().Int32Value();
    const GLfloat *value = info[2].As<Napi::Float32Array>().Data();
  
    glUniform4fv(location, count, value);
}

void __glUniform4i(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLint location = info[0].As<Napi::Number>().Int32Value();
    GLint v0 = info[1].As<Napi::Number>().Int32Value();
    GLint v1 = info[2].As<Napi::Number>().Int32Value();
    GLint v2 = info[3].As<Napi::Number>().Int32Value();
    GLint v3 = info[4].As<Napi::Number>().Int32Value();
  
    glUniform4i(location, v0, v1, v2, v3);
}

void __glUniform4iv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLint location = info[0].As<Napi::Number>().Int32Value();
    GLsizei count = info[1].As<Napi::Number>().Int32Value();
    const GLint *value = info[2].As<Napi::Int32Array>().Data();
  
    glUniform4iv(location, count, value);
}

void __glUniformMatrix2fv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLint location = info[0].As<Napi::Number>().Int32Value();
    GLsizei count = info[1].As<Napi::Number>().Int32Value();
    GLboolean transpose = info[2].As<Napi::Boolean>().Value();
    const GLfloat *value = info[3].As<Napi::Float32Array>().Data();
  
    glUniformMatrix2fv(location, count, transpose, value);
}

void __glUniformMatrix3fv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLint location = info[0].As<Napi::Number>().Int32Value();
    GLsizei count = info[1].As<Napi::Number>().Int32Value();
    GLboolean transpose = info[2].As<Napi::Boolean>().Value();
    const GLfloat *value = info[3].As<Napi::Float32Array>().Data();
  
    glUniformMatrix3fv(location, count, transpose, value);
}

void __glUniformMatrix4fv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLint location = info[0].As<Napi::Number>().Int32Value();
    GLsizei count = info[1].As<Napi::Number>().Int32Value();
    GLboolean transpose = info[2].As<Napi::Boolean>().Value();
    const GLfloat *value = info[3].As<Napi::Float32Array>().Data();
  
    glUniformMatrix4fv(location, count, transpose, value);
}

void __glUseProgram(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint program = info[0].As<Napi::Number>().Int32Value();
  
    glUseProgram(program);
}

void __glValidateProgram(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint program = info[0].As<Napi::Number>().Int32Value();
  
    glValidateProgram(program);
}

void __glVertexAttrib1d(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint index = info[0].As<Napi::Number>().Int32Value();
    GLdouble x = info[1].As<Napi::Number>().DoubleValue();
  
    glVertexAttrib1d(index, x);
}

void __glVertexAttrib1dv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint index = info[0].As<Napi::Number>().Int32Value();
    const GLdouble *v = info[1].As<Napi::Float64Array>().Data();
  
    glVertexAttrib1dv(index, v);
}

void __glVertexAttrib1f(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint index = info[0].As<Napi::Number>().Int32Value();
    GLfloat x = info[1].As<Napi::Number>().FloatValue();
  
    glVertexAttrib1f(index, x);
}

void __glVertexAttrib1fv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint index = info[0].As<Napi::Number>().Int32Value();
    const GLfloat *v = info[1].As<Napi::Float32Array>().Data();
  
    glVertexAttrib1fv(index, v);
}

void __glVertexAttrib1s(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint index = info[0].As<Napi::Number>().Int32Value();
    GLshort x = (GLshort)info[1].As<Napi::Number>().Int32Value();
  
    glVertexAttrib1s(index, x);
}

void __glVertexAttrib1sv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint index = info[0].As<Napi::Number>().Int32Value();
    const GLshort *v = info[1].As<Napi::Int16Array>().Data();
  
    glVertexAttrib1sv(index, v);
}

void __glVertexAttrib2d(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint index = info[0].As<Napi::Number>().Int32Value();
    GLdouble x = info[1].As<Napi::Number>().DoubleValue();
    GLdouble y = info[2].As<Napi::Number>().DoubleValue();
  
    glVertexAttrib2d(index, x, y);
}

void __glVertexAttrib2dv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint index = info[0].As<Napi::Number>().Int32Value();
    const GLdouble *v = info[1].As<Napi::Float64Array>().Data();
  
    glVertexAttrib2dv(index, v);
}

void __glVertexAttrib2f(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint index = info[0].As<Napi::Number>().Int32Value();
    GLfloat x = info[1].As<Napi::Number>().FloatValue();
    GLfloat y = info[2].As<Napi::Number>().FloatValue();
  
    glVertexAttrib2f(index, x, y);
}

void __glVertexAttrib2fv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint index = info[0].As<Napi::Number>().Int32Value();
    const GLfloat *v = info[1].As<Napi::Float32Array>().Data();
  
    glVertexAttrib2fv(index, v);
}

void __glVertexAttrib2s(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint index = info[0].As<Napi::Number>().Int32Value();
    GLshort x = (GLshort)info[1].As<Napi::Number>().Int32Value();
    GLshort y = (GLshort)info[2].As<Napi::Number>().Int32Value();
  
    glVertexAttrib2s(index, x, y);
}

void __glVertexAttrib2sv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint index = info[0].As<Napi::Number>().Int32Value();
    const GLshort *v = info[1].As<Napi::Int16Array>().Data();
  
    glVertexAttrib2sv(index, v);
}

void __glVertexAttrib3d(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint index = info[0].As<Napi::Number>().Int32Value();
    GLdouble x = info[1].As<Napi::Number>().DoubleValue();
    GLdouble y = info[2].As<Napi::Number>().DoubleValue();
    GLdouble z = info[3].As<Napi::Number>().DoubleValue();
  
    glVertexAttrib3d(index, x, y, z);
}

void __glVertexAttrib3dv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint index = info[0].As<Napi::Number>().Int32Value();
    const GLdouble *v = info[1].As<Napi::Float64Array>().Data();
  
    glVertexAttrib3dv(index, v);
}

void __glVertexAttrib3f(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint index = info[0].As<Napi::Number>().Int32Value();
    GLfloat x = info[1].As<Napi::Number>().FloatValue();
    GLfloat y = info[2].As<Napi::Number>().FloatValue();
    GLfloat z = info[3].As<Napi::Number>().FloatValue();
  
    glVertexAttrib3f(index, x, y, z);
}

void __glVertexAttrib3fv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint index = info[0].As<Napi::Number>().Int32Value();
    const GLfloat *v = info[1].As<Napi::Float32Array>().Data();
  
    glVertexAttrib3fv(index, v);
}

void __glVertexAttrib3s(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint index = info[0].As<Napi::Number>().Int32Value();
    GLshort x = (GLshort)info[1].As<Napi::Number>().Int32Value();
    GLshort y = (GLshort)info[2].As<Napi::Number>().Int32Value();
    GLshort z = (GLshort)info[3].As<Napi::Number>().Int32Value();
  
    glVertexAttrib3s(index, x, y, z);
}

void __glVertexAttrib3sv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint index = info[0].As<Napi::Number>().Int32Value();
    const GLshort *v = info[1].As<Napi::Int16Array>().Data();
  
    glVertexAttrib3sv(index, v);
}

void __glVertexAttrib4Nbv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint index = info[0].As<Napi::Number>().Int32Value();
    const GLbyte *v = info[1].As<Napi::Int8Array>().Data();
  
    glVertexAttrib4Nbv(index, v);
}

void __glVertexAttrib4Niv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint index = info[0].As<Napi::Number>().Int32Value();
    const GLint *v = info[1].As<Napi::Int32Array>().Data();
  
    glVertexAttrib4Niv(index, v);
}

void __glVertexAttrib4Nsv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint index = info[0].As<Napi::Number>().Int32Value();
    const GLshort *v = info[1].As<Napi::Int16Array>().Data();
  
    glVertexAttrib4Nsv(index, v);
}

void __glVertexAttrib4Nub(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint index = info[0].As<Napi::Number>().Int32Value();
    GLubyte x = (GLubyte)info[1].As<Napi::Number>().Uint32Value();
    GLubyte y = (GLubyte)info[2].As<Napi::Number>().Uint32Value();
    GLubyte z = (GLubyte)info[3].As<Napi::Number>().Uint32Value();
    GLubyte w = (GLubyte)info[4].As<Napi::Number>().Uint32Value();
  
    glVertexAttrib4Nub(index, x, y, z, w);
}

void __glVertexAttrib4Nubv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint index = info[0].As<Napi::Number>().Int32Value();
    const GLubyte *v = info[1].As<Napi::Uint8Array>().Data();
  
    glVertexAttrib4Nubv(index, v);
}

void __glVertexAttrib4Nuiv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint index = info[0].As<Napi::Number>().Int32Value();
    const GLuint *v = info[1].As<Napi::Uint32Array>().Data();
  
    glVertexAttrib4Nuiv(index, v);
}

void __glVertexAttrib4Nusv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint index = info[0].As<Napi::Number>().Int32Value();
    const GLushort *v = info[1].As<Napi::Uint16Array>().Data();
  
    glVertexAttrib4Nusv(index, v);
}

void __glVertexAttrib4bv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint index = info[0].As<Napi::Number>().Int32Value();
    const GLbyte *v = info[1].As<Napi::Int8Array>().Data();
  
    glVertexAttrib4bv(index, v);
}

void __glVertexAttrib4d(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint index = info[0].As<Napi::Number>().Int32Value();
    GLdouble x = info[1].As<Napi::Number>().DoubleValue();
    GLdouble y = info[2].As<Napi::Number>().DoubleValue();
    GLdouble z = info[3].As<Napi::Number>().DoubleValue();
    GLdouble w = info[4].As<Napi::Number>().DoubleValue();
  
    glVertexAttrib4d(index, x, y, z, w);
}

void __glVertexAttrib4dv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint index = info[0].As<Napi::Number>().Int32Value();
    const GLdouble *v = info[1].As<Napi::Float64Array>().Data();
  
    glVertexAttrib4dv(index, v);
}

void __glVertexAttrib4f(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint index = info[0].As<Napi::Number>().Int32Value();
    GLfloat x = info[1].As<Napi::Number>().FloatValue();
    GLfloat y = info[2].As<Napi::Number>().FloatValue();
    GLfloat z = info[3].As<Napi::Number>().FloatValue();
    GLfloat w = info[4].As<Napi::Number>().FloatValue();
  
    glVertexAttrib4f(index, x, y, z, w);
}

void __glVertexAttrib4fv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint index = info[0].As<Napi::Number>().Int32Value();
    const GLfloat *v = info[1].As<Napi::Float32Array>().Data();
  
    glVertexAttrib4fv(index, v);
}

void __glVertexAttrib4iv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint index = info[0].As<Napi::Number>().Int32Value();
    const GLint *v = info[1].As<Napi::Int32Array>().Data();
  
    glVertexAttrib4iv(index, v);
}

void __glVertexAttrib4s(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint index = info[0].As<Napi::Number>().Int32Value();
    GLshort x = (GLshort)info[1].As<Napi::Number>().Int32Value();
    GLshort y = (GLshort)info[2].As<Napi::Number>().Int32Value();
    GLshort z = (GLshort)info[3].As<Napi::Number>().Int32Value();
    GLshort w = (GLshort)info[4].As<Napi::Number>().Int32Value();
  
    glVertexAttrib4s(index, x, y, z, w);
}

void __glVertexAttrib4sv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint index = info[0].As<Napi::Number>().Int32Value();
    const GLshort *v = info[1].As<Napi::Int16Array>().Data();
  
    glVertexAttrib4sv(index, v);
}

void __glVertexAttrib4ubv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint index = info[0].As<Napi::Number>().Int32Value();
    const GLubyte *v = info[1].As<Napi::Uint8Array>().Data();
  
    glVertexAttrib4ubv(index, v);
}

void __glVertexAttrib4uiv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint index = info[0].As<Napi::Number>().Int32Value();
    const GLuint *v = info[1].As<Napi::Uint32Array>().Data();
  
    glVertexAttrib4uiv(index, v);
}

void __glVertexAttrib4usv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint index = info[0].As<Napi::Number>().Int32Value();
    const GLushort *v = info[1].As<Napi::Uint16Array>().Data();
  
    glVertexAttrib4usv(index, v);
}

void __glVertexAttribPointer(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint index = info[0].As<Napi::Number>().Int32Value();
    GLint size = info[1].As<Napi::Number>().Int32Value();
    GLenum type = info[2].As<Napi::Number>().Int32Value();
    GLboolean normalized = info[3].As<Napi::Boolean>().Value();
    GLsizei stride = info[4].As<Napi::Number>().Int32Value();
    GLvoid *pointer = (GLvoid *)info[5].As<Napi::Number>().Int32Value();

    glVertexAttribPointer(index, size, type, normalized, stride, pointer);
}

// OpenGL 2.1

void __glUniformMatrix2x3fv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLint location = info[0].As<Napi::Number>().Int32Value();
    GLsizei count = info[1].As<Napi::Number>().Int32Value();
    GLboolean transpose = info[2].As<Napi::Boolean>().Value();
    const GLfloat *value = info[3].As<Napi::Float32Array>().Data();
  
    glUniformMatrix2x3fv(location, count, transpose, value);
}

void __glUniformMatrix2x4fv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLint location = info[0].As<Napi::Number>().Int32Value();
    GLsizei count = info[1].As<Napi::Number>().Int32Value();
    GLboolean transpose = info[2].As<Napi::Boolean>().Value();
    const GLfloat *value = info[3].As<Napi::Float32Array>().Data();
  
    glUniformMatrix2x4fv(location, count, transpose, value);
}

void __glUniformMatrix3x2fv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLint location = info[0].As<Napi::Number>().Int32Value();
    GLsizei count = info[1].As<Napi::Number>().Int32Value();
    GLboolean transpose = info[2].As<Napi::Boolean>().Value();
    const GLfloat *value = info[3].As<Napi::Float32Array>().Data();

    glUniformMatrix3x2fv(location, count, transpose, value);
}

void __glUniformMatrix3x4fv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLint location = info[0].As<Napi::Number>().Int32Value();
    GLsizei count = info[1].As<Napi::Number>().Int32Value();
    GLboolean transpose = info[2].As<Napi::Boolean>().Value();
    const GLfloat *value = info[3].As<Napi::Float32Array>().Data();
  
    glUniformMatrix3x4fv(location, count, transpose, value);
}

void __glUniformMatrix4x2fv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLint location = info[0].As<Napi::Number>().Int32Value();
    GLsizei count = info[1].As<Napi::Number>().Int32Value();
    GLboolean transpose = info[2].As<Napi::Boolean>().Value();
    const GLfloat *value = info[3].As<Napi::Float32Array>().Data();
  
    glUniformMatrix4x2fv(location, count, transpose, value);
}

void __glUniformMatrix4x3fv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLint location = info[0].As<Napi::Number>().Int32Value();
    GLsizei count = info[1].As<Napi::Number>().Int32Value();
    GLboolean transpose = info[2].As<Napi::Boolean>().Value();
    const GLfloat *value = info[3].As<Napi::Float32Array>().Data();
  
    glUniformMatrix4x3fv(location, count, transpose, value);
}

// OpenGL 3.0

void __glBeginConditionalRender(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint id = info[0].As<Napi::Number>().Uint32Value();
    GLenum mode = info[1].As<Napi::Number>().Int32Value();

    glBeginConditionalRender(id, mode);
}

void __glBeginTransformFeedback(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum primitiveMode = info[0].As<Napi::Number>().Int32Value();

    glBeginTransformFeedback(primitiveMode);
}

void __glBindFragDataLocation(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint program = info[0].As<Napi::Number>().Uint32Value();
    GLuint colorNumber = info[1].As<Napi::Number>().Uint32Value();
    const GLchar *name = info[2].As<Napi::String>().Utf8Value().c_str();

    glBindFragDataLocation(program, colorNumber, name);
}

void __glClampColor(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum target = info[0].As<Napi::Number>().Int32Value();
    GLenum clamp = info[1].As<Napi::Number>().Int32Value();

    glClampColor(target, clamp);
}

void __glClearBufferfi(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum buffer = info[0].As<Napi::Number>().Int32Value();
    GLint drawbuffer = info[1].As<Napi::Number>().Int32Value();
    GLfloat depth = info[2].As<Napi::Number>().FloatValue();
    GLint stencil = info[3].As<Napi::Number>().Int32Value();

    glClearBufferfi(buffer, drawbuffer, depth, stencil);
}

void __glClearBufferfv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum buffer = info[0].As<Napi::Number>().Int32Value();
    GLint drawbuffer = info[1].As<Napi::Number>().Int32Value();
    const GLfloat *value = info[2].As<Napi::Float32Array>().Data();

    glClearBufferfv(buffer, drawbuffer, value);
}

void __glClearBufferiv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum buffer = info[0].As<Napi::Number>().Int32Value();
    GLint drawbuffer = info[1].As<Napi::Number>().Int32Value();
    const GLint *value = info[2].As<Napi::Int32Array>().Data();

    glClearBufferiv(buffer, drawbuffer, value);
}

void __glClearBufferuiv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum buffer = info[0].As<Napi::Number>().Int32Value();
    GLint drawbuffer = info[1].As<Napi::Number>().Int32Value();
    const GLuint *value = info[2].As<Napi::Uint32Array>().Data();

    glClearBufferuiv(buffer, drawbuffer, value);
}

void __glColorMaski(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint index = info[0].As<Napi::Number>().Uint32Value();
    GLboolean r = info[1].As<Napi::Boolean>().Value();
    GLboolean g = info[2].As<Napi::Boolean>().Value();
    GLboolean b = info[3].As<Napi::Boolean>().Value();
    GLboolean a = info[4].As<Napi::Boolean>().Value();

    glColorMaski(index, r, g, b, a);
}

void __glDisablei(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum target = info[0].As<Napi::Number>().Int32Value();
    GLuint index = info[1].As<Napi::Number>().Uint32Value();

    glDisablei(target, index);
}

void __glEnablei(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum target = info[0].As<Napi::Number>().Int32Value();
    GLuint index = info[1].As<Napi::Number>().Uint32Value();

    glEnablei(target, index);
}

void __glEndConditionalRender(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    glEndConditionalRender();
}

void __glEndTransformFeedback(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    glEndTransformFeedback();
}

void __glGetBooleani_v(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum target = info[0].As<Napi::Number>().Int32Value();
    GLuint index = info[1].As<Napi::Number>().Uint32Value();
    Napi::Array _data = info[2].As<Napi::Array>();
    GLboolean *data = new GLboolean[_data.Length()];

    glGetBooleani_v(target, index, data);

    for (unsigned int i = 0; i < _data.Length(); i++) {
        _data[i] = Napi::Boolean::New(env, data[i]);
    }
}

Napi::Number __glGetFragDataLocation(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint program = info[0].As<Napi::Number>().Uint32Value();
    const GLchar *name = info[1].As<Napi::String>().Utf8Value().c_str();

    return Napi::Number::New(env, glGetFragDataLocation(program, name));
}

Napi::String __glGetStringi(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum name = info[0].As<Napi::Number>().Int32Value();
    GLuint index = info[1].As<Napi::Number>().Uint32Value();

    return Napi::String::New(env, (char *)glGetStringi(name, index));
}

void __glGetTexParameterIiv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum target = info[0].As<Napi::Number>().Int32Value();
    GLenum pname = info[1].As<Napi::Number>().Int32Value();
    GLint *params = info[2].As<Napi::Int32Array>().Data();

    glGetTexParameterIiv(target, pname, params);
}

void __glGetTexParameterIuiv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum target = info[0].As<Napi::Number>().Int32Value();
    GLenum pname = info[1].As<Napi::Number>().Int32Value();
    GLuint *params = info[2].As<Napi::Uint32Array>().Data();

    glGetTexParameterIuiv(target, pname, params);
}

void __glGetTransformFeedbackVarying(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint program = info[0].As<Napi::Number>().Uint32Value();
    GLuint index = info[1].As<Napi::Number>().Uint32Value();
    GLsizei bufSize = info[2].As<Napi::Number>().Int32Value();
    GLsizei *length = info[3].As<Napi::Int32Array>().Data();
    GLsizei *size = info[4].As<Napi::Int32Array>().Data();
    GLenum *type = (GLenum*)info[5].As<Napi::Int32Array>().Data();
    GLchar *name = (char *)info[6].As<Napi::String>().Utf8Value().c_str();

    glGetTransformFeedbackVarying(program, index, bufSize, length, size, type, name);
}

void __glGetUniformuiv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint program = info[0].As<Napi::Number>().Uint32Value();
    GLint location = info[1].As<Napi::Number>().Int32Value();
    GLuint *params = info[2].As<Napi::Uint32Array>().Data();

    glGetUniformuiv(program, location, params);
}

void __glGetVertexAttribIiv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint index = info[0].As<Napi::Number>().Uint32Value();
    GLenum pname = info[1].As<Napi::Number>().Int32Value();
    GLint *params = info[2].As<Napi::Int32Array>().Data();

    glGetVertexAttribIiv(index, pname, params);
}

void __glGetVertexAttribIuiv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint index = info[0].As<Napi::Number>().Uint32Value();
    GLenum pname = info[1].As<Napi::Number>().Int32Value();
    GLuint *params = info[2].As<Napi::Uint32Array>().Data();

    glGetVertexAttribIuiv(index, pname, params);
}

Napi::Boolean __glIsEnabledi(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum target = info[0].As<Napi::Number>().Int32Value();
    GLuint index = info[1].As<Napi::Number>().Uint32Value();

    return Napi::Boolean::New(env, glIsEnabledi(target, index));
}

void __glTexParameterIiv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum target = info[0].As<Napi::Number>().Int32Value();
    GLenum pname = info[1].As<Napi::Number>().Int32Value();
    GLint *params = info[2].As<Napi::Int32Array>().Data();

    glTexParameterIiv(target, pname, params);
}

void __glTexParameterIuiv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum target = info[0].As<Napi::Number>().Int32Value();
    GLenum pname = info[1].As<Napi::Number>().Int32Value();
    GLuint *params = info[2].As<Napi::Uint32Array>().Data();

    glTexParameterIuiv(target, pname, params);
}

void __glTransformFeedbackVaryings(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint program = info[0].As<Napi::Number>().Uint32Value();
    GLsizei count = info[1].As<Napi::Number>().Int32Value();
    Napi::Array _varyings = info[2].As<Napi::Array>();
    GLenum bufferMode = info[3].As<Napi::Number>().Int32Value();
    const GLchar** varyings = new const GLchar*[count];

    for (int i = 0; i < count; i++) {
        varyings[i] = _varyings.Get(i).As<Napi::String>().Utf8Value().c_str();
    }

    glTransformFeedbackVaryings(program, count, varyings, bufferMode);
}

void __glUniform1ui(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLint location = info[0].As<Napi::Number>().Int32Value();
    GLuint v0 = info[1].As<Napi::Number>().Uint32Value();

    glUniform1ui(location, v0);
}

void __glUniform1uiv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLint location = info[0].As<Napi::Number>().Int32Value();
    GLsizei count = info[1].As<Napi::Number>().Int32Value();
    GLuint *value = info[2].As<Napi::Uint32Array>().Data();

    glUniform1uiv(location, count, value);
}

void __glUniform2ui(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLint location = info[0].As<Napi::Number>().Int32Value();
    GLuint v0 = info[1].As<Napi::Number>().Uint32Value();
    GLuint v1 = info[2].As<Napi::Number>().Uint32Value();

    glUniform2ui(location, v0, v1);
}

void __glUniform2uiv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLint location = info[0].As<Napi::Number>().Int32Value();
    GLsizei count = info[1].As<Napi::Number>().Int32Value();
    GLuint *value = info[2].As<Napi::Uint32Array>().Data();

    glUniform2uiv(location, count, value);
}

void __glUniform3ui(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLint location = info[0].As<Napi::Number>().Int32Value();
    GLuint v0 = info[1].As<Napi::Number>().Uint32Value();
    GLuint v1 = info[2].As<Napi::Number>().Uint32Value();
    GLuint v2 = info[3].As<Napi::Number>().Uint32Value();

    glUniform3ui(location, v0, v1, v2);
}

void __glUniform3uiv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLint location = info[0].As<Napi::Number>().Int32Value();
    GLsizei count = info[1].As<Napi::Number>().Int32Value();
    GLuint *value = info[2].As<Napi::Uint32Array>().Data();

    glUniform3uiv(location, count, value);
}

void __glUniform4ui(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLint location = info[0].As<Napi::Number>().Int32Value();
    GLuint v0 = info[1].As<Napi::Number>().Uint32Value();
    GLuint v1 = info[2].As<Napi::Number>().Uint32Value();
    GLuint v2 = info[3].As<Napi::Number>().Uint32Value();
    GLuint v3 = info[4].As<Napi::Number>().Uint32Value();

    glUniform4ui(location, v0, v1, v2, v3);
}

void __glUniform4uiv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLint location = info[0].As<Napi::Number>().Int32Value();
    GLsizei count = info[1].As<Napi::Number>().Int32Value();
    GLuint *value = info[2].As<Napi::Uint32Array>().Data();

    glUniform4uiv(location, count, value);
}

void __glVertexAttribI1i(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint index = info[0].As<Napi::Number>().Uint32Value();
    GLint x = info[1].As<Napi::Number>().Int32Value();

    glVertexAttribI1i(index, x);
}

void __glVertexAttribI1iv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint index = info[0].As<Napi::Number>().Uint32Value();
    GLint *v = info[1].As<Napi::Int32Array>().Data();

    glVertexAttribI1iv(index, v);
}

void __glVertexAttribI1ui(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint index = info[0].As<Napi::Number>().Uint32Value();
    GLuint x = info[1].As<Napi::Number>().Uint32Value();

    glVertexAttribI1ui(index, x);
}

void __glVertexAttribI1uiv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint index = info[0].As<Napi::Number>().Uint32Value();
    GLuint *v = info[1].As<Napi::Uint32Array>().Data();

    glVertexAttribI1uiv(index, v);
}

void __glVertexAttribI2i(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint index = info[0].As<Napi::Number>().Uint32Value();
    GLint x = info[1].As<Napi::Number>().Int32Value();
    GLint y = info[2].As<Napi::Number>().Int32Value();

    glVertexAttribI2i(index, x, y);
}

void __glVertexAttribI2iv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint index = info[0].As<Napi::Number>().Uint32Value();
    GLint *v = info[1].As<Napi::Int32Array>().Data();

    glVertexAttribI2iv(index, v);
}

void __glVertexAttribI2ui(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint index = info[0].As<Napi::Number>().Uint32Value();
    GLuint x = info[1].As<Napi::Number>().Uint32Value();
    GLuint y = info[2].As<Napi::Number>().Uint32Value();

    glVertexAttribI2ui(index, x, y);
}

void __glVertexAttribI2uiv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint index = info[0].As<Napi::Number>().Uint32Value();
    GLuint *v = info[1].As<Napi::Uint32Array>().Data();

    glVertexAttribI2uiv(index, v);
}

void __glVertexAttribI3i(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint index = info[0].As<Napi::Number>().Uint32Value();
    GLint x = info[1].As<Napi::Number>().Int32Value();
    GLint y = info[2].As<Napi::Number>().Int32Value();
    GLint z = info[3].As<Napi::Number>().Int32Value();

    glVertexAttribI3i(index, x, y, z);
}

void __glVertexAttribI3iv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint index = info[0].As<Napi::Number>().Uint32Value();
    GLint *v = info[1].As<Napi::Int32Array>().Data();

    glVertexAttribI3iv(index, v);
}

void __glVertexAttribI3ui(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint index = info[0].As<Napi::Number>().Uint32Value();
    GLuint x = info[1].As<Napi::Number>().Uint32Value();
    GLuint y = info[2].As<Napi::Number>().Uint32Value();
    GLuint z = info[3].As<Napi::Number>().Uint32Value();

    glVertexAttribI3ui(index, x, y, z);
}

void __glVertexAttribI3uiv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint index = info[0].As<Napi::Number>().Uint32Value();
    GLuint *v = info[1].As<Napi::Uint32Array>().Data();

    glVertexAttribI3uiv(index, v);
}

void __glVertexAttribI4bv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint index = info[0].As<Napi::Number>().Uint32Value();
    GLbyte *v = info[1].As<Napi::Int8Array>().Data();

    glVertexAttribI4bv(index, v);
}

void __glVertexAttribI4i(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint index = info[0].As<Napi::Number>().Uint32Value();
    GLint x = info[1].As<Napi::Number>().Int32Value();
    GLint y = info[2].As<Napi::Number>().Int32Value();
    GLint z = info[3].As<Napi::Number>().Int32Value();
    GLint w = info[4].As<Napi::Number>().Int32Value();

    glVertexAttribI4i(index, x, y, z, w);
}

void __glVertexAttribI4iv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint index = info[0].As<Napi::Number>().Uint32Value();
    GLint *v = info[1].As<Napi::Int32Array>().Data();

    glVertexAttribI4iv(index, v);
}

void __glVertexAttribI4sv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint index = info[0].As<Napi::Number>().Uint32Value();
    GLshort *v = info[1].As<Napi::Int16Array>().Data();

    glVertexAttribI4sv(index, v);
}

void __glVertexAttribI4ubv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint index = info[0].As<Napi::Number>().Uint32Value();
    GLubyte *v = info[1].As<Napi::Uint8Array>().Data();

    glVertexAttribI4ubv(index, v);
}

void __glVertexAttribI4ui(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint index = info[0].As<Napi::Number>().Uint32Value();
    GLuint x = info[1].As<Napi::Number>().Uint32Value();
    GLuint y = info[2].As<Napi::Number>().Uint32Value();
    GLuint z = info[3].As<Napi::Number>().Uint32Value();
    GLuint w = info[4].As<Napi::Number>().Uint32Value();

    glVertexAttribI4ui(index, x, y, z, w);
}

void __glVertexAttribI4uiv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint index = info[0].As<Napi::Number>().Uint32Value();
    GLuint *v = info[1].As<Napi::Uint32Array>().Data();

    glVertexAttribI4uiv(index, v);
}

void __glVertexAttribI4usv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint index = info[0].As<Napi::Number>().Uint32Value();
    GLushort *v = info[1].As<Napi::Uint16Array>().Data();

    glVertexAttribI4usv(index, v);
}

void __glVertexAttribIPointer(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint index = info[0].As<Napi::Number>().Uint32Value();
    GLint size = info[1].As<Napi::Number>().Int32Value();
    GLenum type = info[2].As<Napi::Number>().Uint32Value();
    GLsizei stride = info[3].As<Napi::Number>().Int32Value();
    GLint offset = info[4].As<Napi::Number>().Int32Value();

    glVertexAttribIPointer(index, size, type, stride, (const void *)offset);
}

// OpenGL 3.1

void __glDrawArraysInstanced(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum mode = info[0].As<Napi::Number>().Uint32Value();
    GLint first = info[1].As<Napi::Number>().Int32Value();
    GLsizei count = info[2].As<Napi::Number>().Int32Value();
    GLsizei instanceCount = info[3].As<Napi::Number>().Int32Value();

    glDrawArraysInstanced(mode, first, count, instanceCount);
}

void __glDrawElementsInstanced(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum mode = info[0].As<Napi::Number>().Uint32Value();
    GLsizei count = info[1].As<Napi::Number>().Int32Value();
    GLenum type = info[2].As<Napi::Number>().Uint32Value();
    void* indices = info[3].As<Napi::Buffer<GLubyte>>().Data();
    GLsizei instanceCount = info[4].As<Napi::Number>().Int32Value();

    glDrawElementsInstanced(mode, count, type, indices, instanceCount);
}

void __glPrimitiveRestartIndex(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint index = info[0].As<Napi::Number>().Uint32Value();

    glPrimitiveRestartIndex(index);
}

void __glTexBuffer(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum target = info[0].As<Napi::Number>().Uint32Value();
    GLenum internalformat = info[1].As<Napi::Number>().Uint32Value();
    GLuint buffer = info[2].As<Napi::Number>().Uint32Value();

    glTexBuffer(target, internalformat, buffer);
}

// OpenGL 3.2

void __glFramebufferTexture(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum target = info[0].As<Napi::Number>().Uint32Value();
    GLenum attachment = info[1].As<Napi::Number>().Uint32Value();
    GLuint texture = info[2].As<Napi::Number>().Uint32Value();
    GLint level = info[3].As<Napi::Number>().Int32Value();

    glFramebufferTexture(target, attachment, texture, level);
}

void __glGetBufferParameteri64v(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum target = info[0].As<Napi::Number>().Uint32Value();
    GLenum pname = info[1].As<Napi::Number>().Uint32Value();
    GLint64 *params = info[2].As<Napi::BigInt64Array>().Data();

    glGetBufferParameteri64v(target, pname, params);
}

void __glGetInteger64i_v(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum target = info[0].As<Napi::Number>().Uint32Value();
    GLuint index = info[1].As<Napi::Number>().Uint32Value();
    GLint64 *data = info[2].As<Napi::BigInt64Array>().Data();

    glGetInteger64i_v(target, index, data);
}

// OpenGL 3.3

void __glVertexAttribDivisor(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint index = info[0].As<Napi::Number>().Uint32Value();
    GLuint divisor = info[1].As<Napi::Number>().Uint32Value();

    glVertexAttribDivisor(index, divisor);
}

// OpenGL 4.0

void __glBlendEquationSeparatei(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint buf = info[0].As<Napi::Number>().Uint32Value();
    GLenum modeRGB = info[1].As<Napi::Number>().Uint32Value();
    GLenum modeAlpha = info[2].As<Napi::Number>().Uint32Value();

    glBlendEquationSeparatei(buf, modeRGB, modeAlpha);
}

void __glBlendEquationi(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint buf = info[0].As<Napi::Number>().Uint32Value();
    GLenum mode = info[1].As<Napi::Number>().Uint32Value();

    glBlendEquationi(buf, mode);
}

void __glBlendFuncSeparatei(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint buf = info[0].As<Napi::Number>().Uint32Value();
    GLenum srcRGB = info[1].As<Napi::Number>().Uint32Value();
    GLenum dstRGB = info[2].As<Napi::Number>().Uint32Value();
    GLenum srcAlpha = info[3].As<Napi::Number>().Uint32Value();
    GLenum dstAlpha = info[4].As<Napi::Number>().Uint32Value();

    glBlendFuncSeparatei(buf, srcRGB, dstRGB, srcAlpha, dstAlpha);
}

void __glBlendFunci(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint buf = info[0].As<Napi::Number>().Uint32Value();
    GLenum src = info[1].As<Napi::Number>().Uint32Value();
    GLenum dst = info[2].As<Napi::Number>().Uint32Value();

    glBlendFunci(buf, src, dst);
}

void __glMinSampleShading(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLfloat value = info[0].As<Napi::Number>().FloatValue();

    glMinSampleShading(value);
}

// OpenGL 4.5

Napi::Number __glGetGraphicsResetStatus(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    return Napi::Number::New(env, glGetGraphicsResetStatus());
}

void __glGetnCompressedTexImage(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum target = info[0].As<Napi::Number>().Uint32Value();
    GLint level = info[1].As<Napi::Number>().Int32Value();
    GLsizei bufSize = info[2].As<Napi::Number>().Int32Value();
    GLvoid *pixels = info[3].As<Napi::Uint8Array>().Data();

    glGetnCompressedTexImage(target, level, bufSize, pixels);
}

void __glGetnTexImage(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum target = info[0].As<Napi::Number>().Uint32Value();
    GLint level = info[1].As<Napi::Number>().Int32Value();
    GLenum format = info[2].As<Napi::Number>().Uint32Value();
    GLenum type = info[3].As<Napi::Number>().Uint32Value();
    GLsizei bufSize = info[4].As<Napi::Number>().Int32Value();
    GLvoid *pixels = info[5].As<Napi::Buffer<GLubyte>>().Data();

    glGetnTexImage(target, level, format, type, bufSize, pixels);
}

void __glGetnUniformdv(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint program = info[0].As<Napi::Number>().Uint32Value();
    GLint location = info[1].As<Napi::Number>().Int32Value();
    GLsizei bufSize = info[2].As<Napi::Number>().Int32Value();
    GLdouble *params = info[3].As<Napi::Float64Array>().Data();

    glGetnUniformdv(program, location, bufSize, params);
}

// OpenGL 4.6

void __glMultiDrawArraysIndirectCount(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLenum mode = info[0].As<Napi::Number>().Uint32Value();
    GLint* indirect = info[1].As<Napi::Int32Array>().Data();
    GLintptr drawcount = info[2].As<Napi::Number>().Int32Value();
    GLsizei maxdrawcount = info[3].As<Napi::Number>().Int32Value();
    GLsizei stride = info[4].As<Napi::Number>().Int32Value();

    glMultiDrawArraysIndirectCount(mode, indirect, drawcount, maxdrawcount, stride);
}

void __glMultiDrawElementsIndirectCount(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    bool lossless = true;

    GLenum mode = info[0].As<Napi::Number>().Uint32Value();
    GLenum type = info[1].As<Napi::Number>().Uint32Value();
    GLint* indirect = info[2].As<Napi::Int32Array>().Data();
    GLintptr drawcount = info[3].As<Napi::Number>().Int32Value();
    GLsizei maxdrawcount = info[4].As<Napi::Number>().Int32Value();
    GLsizei stride = info[5].As<Napi::Number>().Int32Value();

    glMultiDrawElementsIndirectCount(mode, type, indirect, drawcount, maxdrawcount, stride);
}

void __glSpecializeShader(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint shader = info[0].As<Napi::Number>().Uint32Value();
    const GLchar *pEntryPoint = info[1].As<Napi::String>().Utf8Value().c_str();
    GLuint numSpecializationConstants = info[2].As<Napi::Number>().Uint32Value();
    const GLuint *pConstantIndex = info[3].As<Napi::Uint32Array>().Data();
    const GLuint *pConstantValue = info[4].As<Napi::Uint32Array>().Data();

    glSpecializeShader(shader, pEntryPoint, numSpecializationConstants, pConstantIndex, pConstantValue);
}

// Extensions

// GL_ARB_vertex_array_object

void __glBindVertexArray(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint array = info[0].As<Napi::Number>().Uint32Value();

    glBindVertexArray(array);
}

void __glDeleteVertexArrays(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLsizei n = info[0].As<Napi::Number>().Int32Value();
    const GLuint *arrays = info[1].As<Napi::Uint32Array>().Data();

    glDeleteVertexArrays(n, arrays);
}

void __glGenVertexArrays(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLsizei n = info[0].As<Napi::Number>().Int32Value();
    GLuint *arrays = info[1].As<Napi::Uint32Array>().Data();

    glGenVertexArrays(n, arrays);
}

Napi::Boolean __glIsVertexArray(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    GLuint array = info[0].As<Napi::Number>().Uint32Value();

    return Napi::Boolean::New(env, glIsVertexArray(array));
}

Napi::Object init(Napi::Env env, Napi::Object exports) {
    // GLEW methods
    Napi::Object glew = Napi::Object::New(env);

    EXPORT_GLEW(glewInit);
    EXPORT_GLEW(glewIsSupported);
    EXPORT_GLEW(glewGetExtension);
    EXPORT_GLEW(glewGetErrorString);
    EXPORT_GLEW(glewGetString);

    // OpenGL methods
    Napi::Object gl = Napi::Object::New(env);

    // OpenGL 1.1 methods
    EXPORT_GL(glAccum);
    EXPORT_GL(glAlphaFunc);
    EXPORT_GL(glAreTexturesResident);
    EXPORT_GL(glArrayElement);
    EXPORT_GL(glBegin);
    EXPORT_GL(glBindTexture);
    EXPORT_GL(glBitmap);
    EXPORT_GL(glBlendFunc);
    EXPORT_GL(glCallList);
    EXPORT_GL(glCallLists);
    EXPORT_GL(glClear);
    EXPORT_GL(glClearAccum);
    EXPORT_GL(glClearColor);
    EXPORT_GL(glClearDepth);
    EXPORT_GL(glClearIndex);
    EXPORT_GL(glClearStencil);
    EXPORT_GL(glClipPlane);
    EXPORT_GL(glColor3b);
    EXPORT_GL(glColor3bv);
    EXPORT_GL(glColor3d);
    EXPORT_GL(glColor3dv);
    EXPORT_GL(glColor3f);
    EXPORT_GL(glColor3fv);
    EXPORT_GL(glColor3i);
    EXPORT_GL(glColor3iv);
    EXPORT_GL(glColor3s);
    EXPORT_GL(glColor3sv);
    EXPORT_GL(glColor3ub);
    EXPORT_GL(glColor3ubv);
    EXPORT_GL(glColor3ui);
    EXPORT_GL(glColor3uiv);
    EXPORT_GL(glColor3us);
    EXPORT_GL(glColor3usv);
    EXPORT_GL(glColor4b);
    EXPORT_GL(glColor4bv);
    EXPORT_GL(glColor4d);
    EXPORT_GL(glColor4dv);
    EXPORT_GL(glColor4f);
    EXPORT_GL(glColor4fv);
    EXPORT_GL(glColor4i);
    EXPORT_GL(glColor4iv);
    EXPORT_GL(glColor4s);
    EXPORT_GL(glColor4sv);
    EXPORT_GL(glColor4ub);
    EXPORT_GL(glColor4ubv);
    EXPORT_GL(glColor4ui);
    EXPORT_GL(glColor4uiv);
    EXPORT_GL(glColor4us);
    EXPORT_GL(glColor4usv);
    EXPORT_GL(glColorMask);
    EXPORT_GL(glColorMaterial);
    EXPORT_GL(glColorPointer);
    EXPORT_GL(glCopyPixels);
    EXPORT_GL(glCopyTexImage1D);
    EXPORT_GL(glCopyTexImage2D);
    EXPORT_GL(glCopyTexSubImage1D);
    EXPORT_GL(glCopyTexSubImage2D);
    EXPORT_GL(glCullFace);
    EXPORT_GL(glDeleteLists);
    EXPORT_GL(glDeleteTextures);
    EXPORT_GL(glDepthFunc);
    EXPORT_GL(glDepthMask);
    EXPORT_GL(glDepthRange);
    EXPORT_GL(glDisable);
    EXPORT_GL(glDisableClientState);
    EXPORT_GL(glDrawArrays);
    EXPORT_GL(glDrawBuffer);
    EXPORT_GL(glDrawElements);
    EXPORT_GL(glDrawPixels);
    EXPORT_GL(glEdgeFlag);
    EXPORT_GL(glEdgeFlagPointer);
    EXPORT_GL(glEdgeFlagv);
    EXPORT_GL(glEnable);
    EXPORT_GL(glEnableClientState);
    EXPORT_GL(glEnd);
    EXPORT_GL(glEndList);
    EXPORT_GL(glEvalCoord1d);
    EXPORT_GL(glEvalCoord1dv);
    EXPORT_GL(glEvalCoord1f);
    EXPORT_GL(glEvalCoord1fv);
    EXPORT_GL(glEvalCoord2d);
    EXPORT_GL(glEvalCoord2dv);
    EXPORT_GL(glEvalCoord2f);
    EXPORT_GL(glEvalCoord2fv);
    EXPORT_GL(glEvalMesh1);
    EXPORT_GL(glEvalMesh2);
    EXPORT_GL(glEvalPoint1);
    EXPORT_GL(glEvalPoint2);
    EXPORT_GL(glFeedbackBuffer);
    EXPORT_GL(glFinish);
    EXPORT_GL(glFlush);
    EXPORT_GL(glFogf);
    EXPORT_GL(glFogfv);
    EXPORT_GL(glFogi);
    EXPORT_GL(glFogiv);
    EXPORT_GL(glFrontFace);
    EXPORT_GL(glFrustum);
    EXPORT_GL(glGenLists);
    EXPORT_GL(glGenTextures);
    EXPORT_GL(glGetBooleanv);
    EXPORT_GL(glGetClipPlane);
    EXPORT_GL(glGetDoublev);
    EXPORT_GL(glGetError);
    EXPORT_GL(glGetFloatv);
    EXPORT_GL(glGetIntegerv);
    EXPORT_GL(glGetLightfv);
    EXPORT_GL(glGetLightiv);
    EXPORT_GL(glGetMapdv);
    EXPORT_GL(glGetMapfv);
    EXPORT_GL(glGetMapiv);
    EXPORT_GL(glGetMaterialfv);
    EXPORT_GL(glGetMaterialiv);
    EXPORT_GL(glGetPixelMapfv);
    EXPORT_GL(glGetPixelMapuiv);
    EXPORT_GL(glGetPixelMapusv);
    EXPORT_GL(glGetPointerv);
    EXPORT_GL(glGetPolygonStipple);
    EXPORT_GL(glGetString);
    EXPORT_GL(glGetTexEnvfv);
    EXPORT_GL(glGetTexEnviv);
    EXPORT_GL(glGetTexGendv);
    EXPORT_GL(glGetTexGenfv);
    EXPORT_GL(glGetTexGeniv);
    EXPORT_GL(glGetTexImage);
    EXPORT_GL(glGetTexLevelParameterfv);
    EXPORT_GL(glGetTexLevelParameteriv);
    EXPORT_GL(glGetTexParameterfv);
    EXPORT_GL(glGetTexParameteriv);
    EXPORT_GL(glHint);
    EXPORT_GL(glIndexMask);
    EXPORT_GL(glIndexPointer);
    EXPORT_GL(glIndexd);
    EXPORT_GL(glIndexdv);
    EXPORT_GL(glIndexf);
    EXPORT_GL(glIndexfv);
    EXPORT_GL(glIndexi);
    EXPORT_GL(glIndexiv);
    EXPORT_GL(glIndexs);
    EXPORT_GL(glIndexsv);
    EXPORT_GL(glIndexub);
    EXPORT_GL(glIndexubv);
    EXPORT_GL(glInitNames);
    EXPORT_GL(glInterleavedArrays);
    EXPORT_GL(glIsEnabled);
    EXPORT_GL(glIsList);
    EXPORT_GL(glIsTexture);
    EXPORT_GL(glLightModelf);
    EXPORT_GL(glLightModelfv);
    EXPORT_GL(glLightModeli);
    EXPORT_GL(glLightModeliv);
    EXPORT_GL(glLightf);
    EXPORT_GL(glLightfv);
    EXPORT_GL(glLighti);
    EXPORT_GL(glLightiv);
    EXPORT_GL(glLineStipple);
    EXPORT_GL(glLineWidth);
    EXPORT_GL(glListBase);
    EXPORT_GL(glLoadIdentity);
    EXPORT_GL(glLoadMatrixd);
    EXPORT_GL(glLoadMatrixf);
    EXPORT_GL(glLoadName);
    EXPORT_GL(glLogicOp);
    EXPORT_GL(glMap1d);
    EXPORT_GL(glMap1f);
    EXPORT_GL(glMap2d);
    EXPORT_GL(glMap2f);
    EXPORT_GL(glMapGrid1d);
    EXPORT_GL(glMapGrid1f);
    EXPORT_GL(glMapGrid2d);
    EXPORT_GL(glMapGrid2f);
    EXPORT_GL(glMaterialf);
    EXPORT_GL(glMaterialfv);
    EXPORT_GL(glMateriali);
    EXPORT_GL(glMaterialiv);
    EXPORT_GL(glMatrixMode);
    EXPORT_GL(glMultMatrixd);
    EXPORT_GL(glMultMatrixf);
    EXPORT_GL(glNewList);
    EXPORT_GL(glNormal3b);
    EXPORT_GL(glNormal3bv);
    EXPORT_GL(glNormal3d);
    EXPORT_GL(glNormal3dv);
    EXPORT_GL(glNormal3f);
    EXPORT_GL(glNormal3fv);
    EXPORT_GL(glNormal3i);
    EXPORT_GL(glNormal3iv);
    EXPORT_GL(glNormal3s);
    EXPORT_GL(glNormal3sv);
    EXPORT_GL(glNormalPointer);
    EXPORT_GL(glOrtho);
    EXPORT_GL(glPassThrough);
    EXPORT_GL(glPixelMapfv);
    EXPORT_GL(glPixelMapuiv);
    EXPORT_GL(glPixelMapusv);
    EXPORT_GL(glPixelStoref);
    EXPORT_GL(glPixelStorei);
    EXPORT_GL(glPixelTransferf);
    EXPORT_GL(glPixelTransferi);
    EXPORT_GL(glPixelZoom);
    EXPORT_GL(glPointSize);
    EXPORT_GL(glPolygonMode);
    EXPORT_GL(glPolygonOffset);
    EXPORT_GL(glPolygonStipple);
    EXPORT_GL(glPopAttrib);
    EXPORT_GL(glPopClientAttrib);
    EXPORT_GL(glPopMatrix);
    EXPORT_GL(glPopName);
    EXPORT_GL(glPrioritizeTextures);
    EXPORT_GL(glPushAttrib);
    EXPORT_GL(glPushClientAttrib);
    EXPORT_GL(glPushMatrix);
    EXPORT_GL(glPushName);
    EXPORT_GL(glRasterPos2d);
    EXPORT_GL(glRasterPos2dv);
    EXPORT_GL(glRasterPos2f);
    EXPORT_GL(glRasterPos2fv);
    EXPORT_GL(glRasterPos2i);
    EXPORT_GL(glRasterPos2iv);
    EXPORT_GL(glRasterPos2s);
    EXPORT_GL(glRasterPos2sv);
    EXPORT_GL(glRasterPos3d);
    EXPORT_GL(glRasterPos3dv);
    EXPORT_GL(glRasterPos3f);
    EXPORT_GL(glRasterPos3fv);
    EXPORT_GL(glRasterPos3i);
    EXPORT_GL(glRasterPos3iv);
    EXPORT_GL(glRasterPos3s);
    EXPORT_GL(glRasterPos3sv);
    EXPORT_GL(glRasterPos4d);
    EXPORT_GL(glRasterPos4dv);
    EXPORT_GL(glRasterPos4f);
    EXPORT_GL(glRasterPos4fv);
    EXPORT_GL(glRasterPos4i);
    EXPORT_GL(glRasterPos4iv);
    EXPORT_GL(glRasterPos4s);
    EXPORT_GL(glRasterPos4sv);
    EXPORT_GL(glReadBuffer);
    EXPORT_GL(glReadPixels);
    EXPORT_GL(glRectd);
    EXPORT_GL(glRectdv);
    EXPORT_GL(glRectf);
    EXPORT_GL(glRectfv);
    EXPORT_GL(glRecti);
    EXPORT_GL(glRectiv);
    EXPORT_GL(glRects);
    EXPORT_GL(glRectsv);
    EXPORT_GL(glRenderMode);
    EXPORT_GL(glRotated);
    EXPORT_GL(glRotatef);
    EXPORT_GL(glScaled);
    EXPORT_GL(glScalef);
    EXPORT_GL(glScissor);
    EXPORT_GL(glSelectBuffer);
    EXPORT_GL(glShadeModel);
    EXPORT_GL(glStencilFunc);
    EXPORT_GL(glStencilMask);
    EXPORT_GL(glStencilOp);
    EXPORT_GL(glTexCoord1d);
    EXPORT_GL(glTexCoord1dv);
    EXPORT_GL(glTexCoord1f);
    EXPORT_GL(glTexCoord1fv);
    EXPORT_GL(glTexCoord1i);
    EXPORT_GL(glTexCoord1iv);
    EXPORT_GL(glTexCoord1s);
    EXPORT_GL(glTexCoord1sv);
    EXPORT_GL(glTexCoord2d);
    EXPORT_GL(glTexCoord2dv);
    EXPORT_GL(glTexCoord2f);
    EXPORT_GL(glTexCoord2fv);
    EXPORT_GL(glTexCoord2i);
    EXPORT_GL(glTexCoord2iv);
    EXPORT_GL(glTexCoord2s);
    EXPORT_GL(glTexCoord2sv);
    EXPORT_GL(glTexCoord3d);
    EXPORT_GL(glTexCoord3dv);
    EXPORT_GL(glTexCoord3f);
    EXPORT_GL(glTexCoord3fv);
    EXPORT_GL(glTexCoord3i);
    EXPORT_GL(glTexCoord3iv);
    EXPORT_GL(glTexCoord3s);
    EXPORT_GL(glTexCoord3sv);
    EXPORT_GL(glTexCoord4d);
    EXPORT_GL(glTexCoord4dv);
    EXPORT_GL(glTexCoord4f);
    EXPORT_GL(glTexCoord4fv);
    EXPORT_GL(glTexCoord4i);
    EXPORT_GL(glTexCoord4iv);
    EXPORT_GL(glTexCoord4s);
    EXPORT_GL(glTexCoord4sv);
    EXPORT_GL(glTexCoordPointer);
    EXPORT_GL(glTexEnvf);
    EXPORT_GL(glTexEnvfv);
    EXPORT_GL(glTexEnvi);
    EXPORT_GL(glTexEnviv);
    EXPORT_GL(glTexGend);
    EXPORT_GL(glTexGendv);
    EXPORT_GL(glTexGenf);
    EXPORT_GL(glTexGenfv);
    EXPORT_GL(glTexGeni);
    EXPORT_GL(glTexGeniv);
    EXPORT_GL(glTexImage1D);
    EXPORT_GL(glTexImage2D);
    EXPORT_GL(glTexParameterf);
    EXPORT_GL(glTexParameterfv);
    EXPORT_GL(glTexParameteri);
    EXPORT_GL(glTexParameteriv);
    EXPORT_GL(glTexSubImage1D);
    EXPORT_GL(glTexSubImage2D);
    EXPORT_GL(glTranslated);
    EXPORT_GL(glTranslatef);
    EXPORT_GL(glVertex2d);
    EXPORT_GL(glVertex2dv);
    EXPORT_GL(glVertex2f);
    EXPORT_GL(glVertex2fv);
    EXPORT_GL(glVertex2i);
    EXPORT_GL(glVertex2iv);
    EXPORT_GL(glVertex2s);
    EXPORT_GL(glVertex2sv);
    EXPORT_GL(glVertex3d);
    EXPORT_GL(glVertex3dv);
    EXPORT_GL(glVertex3f);
    EXPORT_GL(glVertex3fv);
    EXPORT_GL(glVertex3i);
    EXPORT_GL(glVertex3iv);
    EXPORT_GL(glVertex3s);
    EXPORT_GL(glVertex3sv);
    EXPORT_GL(glVertex4d);
    EXPORT_GL(glVertex4dv);
    EXPORT_GL(glVertex4f);
    EXPORT_GL(glVertex4fv);
    EXPORT_GL(glVertex4i);
    EXPORT_GL(glVertex4iv);
    EXPORT_GL(glVertex4s);
    EXPORT_GL(glVertex4sv);
    EXPORT_GL(glVertexPointer);
    EXPORT_GL(glViewport);

    // OpenGL 1.2 methods
    EXPORT_GL(glCopyTexSubImage3D);
    EXPORT_GL(glDrawRangeElements);
    EXPORT_GL(glTexImage3D);
    EXPORT_GL(glTexSubImage3D);

    // OpenGL 1.3 methods
    EXPORT_GL(glActiveTexture);
    EXPORT_GL(glClientActiveTexture);
    EXPORT_GL(glCompressedTexImage1D);
    EXPORT_GL(glCompressedTexImage2D);
    EXPORT_GL(glCompressedTexImage3D);
    EXPORT_GL(glCompressedTexSubImage1D);
    EXPORT_GL(glCompressedTexSubImage2D);
    EXPORT_GL(glCompressedTexSubImage3D);
    EXPORT_GL(glGetCompressedTexImage);
    EXPORT_GL(glLoadTransposeMatrixd);
    EXPORT_GL(glLoadTransposeMatrixf);
    EXPORT_GL(glMultTransposeMatrixd);
    EXPORT_GL(glMultTransposeMatrixf);
    EXPORT_GL(glMultiTexCoord1d);
    EXPORT_GL(glMultiTexCoord1dv);
    EXPORT_GL(glMultiTexCoord1f);
    EXPORT_GL(glMultiTexCoord1fv);
    EXPORT_GL(glMultiTexCoord1i);
    EXPORT_GL(glMultiTexCoord1iv);
    EXPORT_GL(glMultiTexCoord1s);
    EXPORT_GL(glMultiTexCoord1sv);
    EXPORT_GL(glMultiTexCoord2d);
    EXPORT_GL(glMultiTexCoord2dv);
    EXPORT_GL(glMultiTexCoord2f);
    EXPORT_GL(glMultiTexCoord2fv);
    EXPORT_GL(glMultiTexCoord2i);
    EXPORT_GL(glMultiTexCoord2iv);
    EXPORT_GL(glMultiTexCoord2s);
    EXPORT_GL(glMultiTexCoord2sv);
    EXPORT_GL(glMultiTexCoord3d);
    EXPORT_GL(glMultiTexCoord3dv);
    EXPORT_GL(glMultiTexCoord3f);
    EXPORT_GL(glMultiTexCoord3fv);
    EXPORT_GL(glMultiTexCoord3i);
    EXPORT_GL(glMultiTexCoord3iv);
    EXPORT_GL(glMultiTexCoord3s);
    EXPORT_GL(glMultiTexCoord3sv);
    EXPORT_GL(glMultiTexCoord4d);
    EXPORT_GL(glMultiTexCoord4dv);
    EXPORT_GL(glMultiTexCoord4f);
    EXPORT_GL(glMultiTexCoord4fv);
    EXPORT_GL(glMultiTexCoord4i);
    EXPORT_GL(glMultiTexCoord4iv);
    EXPORT_GL(glMultiTexCoord4s);
    EXPORT_GL(glMultiTexCoord4sv);
    EXPORT_GL(glSampleCoverage);

    // OpenGL 1.4 methods
    EXPORT_GL(glBlendColor);
    EXPORT_GL(glBlendEquation);
    EXPORT_GL(glBlendFuncSeparate);
    EXPORT_GL(glFogCoordPointer);
    EXPORT_GL(glFogCoordd);
    EXPORT_GL(glFogCoorddv);
    EXPORT_GL(glFogCoordf);
    EXPORT_GL(glFogCoordfv);
    EXPORT_GL(glMultiDrawArrays);
    EXPORT_GL(glMultiDrawElements);
    EXPORT_GL(glPointParameterf);
    EXPORT_GL(glPointParameterfv);
    EXPORT_GL(glPointParameteri);
    EXPORT_GL(glPointParameteriv);
    EXPORT_GL(glSecondaryColor3b);
    EXPORT_GL(glSecondaryColor3bv);
    EXPORT_GL(glSecondaryColor3d);
    EXPORT_GL(glSecondaryColor3dv);
    EXPORT_GL(glSecondaryColor3f);
    EXPORT_GL(glSecondaryColor3fv);
    EXPORT_GL(glSecondaryColor3i);
    EXPORT_GL(glSecondaryColor3iv);
    EXPORT_GL(glSecondaryColor3s);
    EXPORT_GL(glSecondaryColor3sv);
    EXPORT_GL(glSecondaryColor3ub);
    EXPORT_GL(glSecondaryColor3ubv);
    EXPORT_GL(glSecondaryColor3ui);
    EXPORT_GL(glSecondaryColor3uiv);
    EXPORT_GL(glSecondaryColor3us);
    EXPORT_GL(glSecondaryColor3usv);
    EXPORT_GL(glSecondaryColorPointer);
    EXPORT_GL(glWindowPos2d);
    EXPORT_GL(glWindowPos2dv);
    EXPORT_GL(glWindowPos2f);
    EXPORT_GL(glWindowPos2fv);
    EXPORT_GL(glWindowPos2i);
    EXPORT_GL(glWindowPos2iv);
    EXPORT_GL(glWindowPos2s);
    EXPORT_GL(glWindowPos2sv);
    EXPORT_GL(glWindowPos3d);
    EXPORT_GL(glWindowPos3dv);
    EXPORT_GL(glWindowPos3f);
    EXPORT_GL(glWindowPos3fv);
    EXPORT_GL(glWindowPos3i);
    EXPORT_GL(glWindowPos3iv);
    EXPORT_GL(glWindowPos3s);
    EXPORT_GL(glWindowPos3sv);

    // OpenGL 1.5 methods
    EXPORT_GL(glBeginQuery);
    EXPORT_GL(glBindBuffer);
    EXPORT_GL(glBufferData);
    EXPORT_GL(glBufferSubData);
    EXPORT_GL(glDeleteBuffers);
    EXPORT_GL(glDeleteQueries);
    EXPORT_GL(glEndQuery);
    EXPORT_GL(glGenBuffers);
    EXPORT_GL(glGenQueries);
    EXPORT_GL(glGetBufferParameteriv);
    EXPORT_GL(glGetBufferPointerv);
    EXPORT_GL(glGetBufferSubData);
    EXPORT_GL(glGetQueryObjectiv);
    EXPORT_GL(glGetQueryObjectuiv);
    EXPORT_GL(glGetQueryiv);
    EXPORT_GL(glIsBuffer);
    EXPORT_GL(glIsQuery);
    EXPORT_GL(glMapBuffer);
    EXPORT_GL(glUnmapBuffer);

    // OpenGL 2.0 methods
    EXPORT_GL(glAttachShader);
    EXPORT_GL(glBindAttribLocation);
    EXPORT_GL(glBlendEquationSeparate);
    EXPORT_GL(glCompileShader);
    EXPORT_GL(glCreateProgram);
    EXPORT_GL(glCreateShader);
    EXPORT_GL(glDeleteProgram);
    EXPORT_GL(glDeleteShader);
    EXPORT_GL(glDetachShader);
    EXPORT_GL(glDisableVertexAttribArray);
    EXPORT_GL(glDrawBuffers);
    EXPORT_GL(glEnableVertexAttribArray);
    EXPORT_GL(glGetActiveAttrib);
    EXPORT_GL(glGetActiveUniform);
    EXPORT_GL(glGetAttachedShaders);
    EXPORT_GL(glGetAttribLocation);
    EXPORT_GL(glGetProgramInfoLog);
    EXPORT_GL(glGetProgramiv);
    EXPORT_GL(glGetShaderInfoLog);
    EXPORT_GL(glGetShaderSource);
    EXPORT_GL(glGetShaderiv);
    EXPORT_GL(glGetUniformLocation);
    EXPORT_GL(glGetUniformfv);
    EXPORT_GL(glGetUniformiv);
    EXPORT_GL(glGetVertexAttribPointerv);
    EXPORT_GL(glGetVertexAttribdv);
    EXPORT_GL(glGetVertexAttribfv);
    EXPORT_GL(glGetVertexAttribiv);
    EXPORT_GL(glIsProgram);
    EXPORT_GL(glIsShader);
    EXPORT_GL(glLinkProgram);
    EXPORT_GL(glShaderSource);
    EXPORT_GL(glStencilFuncSeparate);
    EXPORT_GL(glStencilMaskSeparate);
    EXPORT_GL(glStencilOpSeparate);
    EXPORT_GL(glUniform1f);
    EXPORT_GL(glUniform1fv);
    EXPORT_GL(glUniform1i);
    EXPORT_GL(glUniform1iv);
    EXPORT_GL(glUniform2f);
    EXPORT_GL(glUniform2fv);
    EXPORT_GL(glUniform2i);
    EXPORT_GL(glUniform2iv);
    EXPORT_GL(glUniform3f);
    EXPORT_GL(glUniform3fv);
    EXPORT_GL(glUniform3i);
    EXPORT_GL(glUniform3iv);
    EXPORT_GL(glUniform4f);
    EXPORT_GL(glUniform4fv);
    EXPORT_GL(glUniform4i);
    EXPORT_GL(glUniform4iv);
    EXPORT_GL(glUniformMatrix2fv);
    EXPORT_GL(glUniformMatrix3fv);
    EXPORT_GL(glUniformMatrix4fv);
    EXPORT_GL(glUseProgram);
    EXPORT_GL(glValidateProgram);
    EXPORT_GL(glVertexAttrib1d);
    EXPORT_GL(glVertexAttrib1dv);
    EXPORT_GL(glVertexAttrib1f);
    EXPORT_GL(glVertexAttrib1fv);
    EXPORT_GL(glVertexAttrib1s);
    EXPORT_GL(glVertexAttrib1sv);
    EXPORT_GL(glVertexAttrib2d);
    EXPORT_GL(glVertexAttrib2dv);
    EXPORT_GL(glVertexAttrib2f);
    EXPORT_GL(glVertexAttrib2fv);
    EXPORT_GL(glVertexAttrib2s);
    EXPORT_GL(glVertexAttrib2sv);
    EXPORT_GL(glVertexAttrib3d);
    EXPORT_GL(glVertexAttrib3dv);
    EXPORT_GL(glVertexAttrib3f);
    EXPORT_GL(glVertexAttrib3fv);
    EXPORT_GL(glVertexAttrib3s);
    EXPORT_GL(glVertexAttrib3sv);
    EXPORT_GL(glVertexAttrib4Nbv);
    EXPORT_GL(glVertexAttrib4Niv);
    EXPORT_GL(glVertexAttrib4Nsv);
    EXPORT_GL(glVertexAttrib4Nub);
    EXPORT_GL(glVertexAttrib4Nubv);
    EXPORT_GL(glVertexAttrib4Nuiv);
    EXPORT_GL(glVertexAttrib4Nusv);
    EXPORT_GL(glVertexAttrib4bv);
    EXPORT_GL(glVertexAttrib4d);
    EXPORT_GL(glVertexAttrib4dv);
    EXPORT_GL(glVertexAttrib4f);
    EXPORT_GL(glVertexAttrib4fv);
    EXPORT_GL(glVertexAttrib4iv);
    EXPORT_GL(glVertexAttrib4s);
    EXPORT_GL(glVertexAttrib4sv);
    EXPORT_GL(glVertexAttrib4ubv);
    EXPORT_GL(glVertexAttrib4uiv);
    EXPORT_GL(glVertexAttrib4usv);
    EXPORT_GL(glVertexAttribPointer);

    // OpenGL 2.1 methods
    EXPORT_GL(glUniformMatrix2x3fv);
    EXPORT_GL(glUniformMatrix2x4fv);
    EXPORT_GL(glUniformMatrix3x2fv);
    EXPORT_GL(glUniformMatrix3x4fv);
    EXPORT_GL(glUniformMatrix4x2fv);
    EXPORT_GL(glUniformMatrix4x3fv);

    // OpenGL 3.0 methods
    EXPORT_GL(glBeginConditionalRender);
    EXPORT_GL(glBeginTransformFeedback);
    EXPORT_GL(glBindFragDataLocation);
    EXPORT_GL(glClampColor);
    EXPORT_GL(glClearBufferfi);
    EXPORT_GL(glClearBufferfv);
    EXPORT_GL(glClearBufferiv);
    EXPORT_GL(glClearBufferuiv);
    EXPORT_GL(glColorMaski);
    EXPORT_GL(glDisablei);
    EXPORT_GL(glEnablei);
    EXPORT_GL(glEndConditionalRender);
    EXPORT_GL(glEndTransformFeedback);
    EXPORT_GL(glGetBooleani_v);
    EXPORT_GL(glGetFragDataLocation);
    EXPORT_GL(glGetStringi);
    EXPORT_GL(glGetTexParameterIiv);
    EXPORT_GL(glGetTexParameterIuiv);
    EXPORT_GL(glGetTransformFeedbackVarying);
    EXPORT_GL(glGetUniformuiv);
    EXPORT_GL(glGetVertexAttribIiv);
    EXPORT_GL(glGetVertexAttribIuiv);
    EXPORT_GL(glIsEnabledi);
    EXPORT_GL(glTexParameterIiv);
    EXPORT_GL(glTexParameterIuiv);
    EXPORT_GL(glTransformFeedbackVaryings);
    EXPORT_GL(glUniform1ui);
    EXPORT_GL(glUniform1uiv);
    EXPORT_GL(glUniform2ui);
    EXPORT_GL(glUniform2uiv);
    EXPORT_GL(glUniform3ui);
    EXPORT_GL(glUniform3uiv);
    EXPORT_GL(glUniform4ui);
    EXPORT_GL(glUniform4uiv);
    EXPORT_GL(glVertexAttribI1i);
    EXPORT_GL(glVertexAttribI1iv);
    EXPORT_GL(glVertexAttribI1ui);
    EXPORT_GL(glVertexAttribI1uiv);
    EXPORT_GL(glVertexAttribI2i);
    EXPORT_GL(glVertexAttribI2iv);
    EXPORT_GL(glVertexAttribI2ui);
    EXPORT_GL(glVertexAttribI2uiv);
    EXPORT_GL(glVertexAttribI3i);
    EXPORT_GL(glVertexAttribI3iv);
    EXPORT_GL(glVertexAttribI3ui);
    EXPORT_GL(glVertexAttribI3uiv);
    EXPORT_GL(glVertexAttribI4bv);
    EXPORT_GL(glVertexAttribI4i);
    EXPORT_GL(glVertexAttribI4iv);
    EXPORT_GL(glVertexAttribI4sv);
    EXPORT_GL(glVertexAttribI4ubv);
    EXPORT_GL(glVertexAttribI4ui);
    EXPORT_GL(glVertexAttribI4uiv);
    EXPORT_GL(glVertexAttribI4usv);
    EXPORT_GL(glVertexAttribIPointer);

    // OpenGL 3.1 methods
    EXPORT_GL(glDrawArraysInstanced);
    EXPORT_GL(glDrawElementsInstanced);
    EXPORT_GL(glPrimitiveRestartIndex);
    EXPORT_GL(glTexBuffer);

    // OpenGL 3.2 methods
    EXPORT_GL(glFramebufferTexture);
    EXPORT_GL(glGetBufferParameteri64v);
    EXPORT_GL(glGetInteger64i_v);

    // OpenGL 3.3 methods
    EXPORT_GL(glVertexAttribDivisor);

    // OpenGL 4.0 methods
    EXPORT_GL(glBlendEquationSeparatei);
    EXPORT_GL(glBlendEquationi);
    EXPORT_GL(glBlendFuncSeparatei);
    EXPORT_GL(glBlendFunci);
    EXPORT_GL(glMinSampleShading);

    // OpenGL 4.5 methods
    EXPORT_GL(glGetGraphicsResetStatus);
    EXPORT_GL(glGetnCompressedTexImage);
    EXPORT_GL(glGetnTexImage);
    EXPORT_GL(glGetnUniformdv);

    // OpenGL 4.6 methods
    EXPORT_GL(glMultiDrawArraysIndirectCount);
    EXPORT_GL(glMultiDrawElementsIndirectCount);
    EXPORT_GL(glSpecializeShader);

    // Extensions

    // GL_ARB_vertex_array_object

    EXPORT_GL(glBindVertexArray);
    EXPORT_GL(glDeleteVertexArrays);
    EXPORT_GL(glGenVertexArrays);
    EXPORT_GL(glIsVertexArray);

    exports.Set("glew", glew);
    exports.Set("gl", gl);
    return exports;
}

NODE_API_MODULE(NODE_GYP_MODULE_NAME, init)