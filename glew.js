const bindings = require("bindings")("opengl.node").glew;

module.exports.GLEW_OK = 0;
module.exports.GLEW_NO_ERROR = 0;
module.exports.GLEW_ERROR_NO_GL_VERSION = 1;
module.exports.GLEW_ERROR_VERSION_10_ONLY = 2;
module.exports.GLEW_ERROR_GLX_VERSION_11_ONLY = 3;
module.exports.GLEW_ERROR_NO_GLX_DISPLAY = 4;
module.exports.GLEW_VERSION = 1;
module.exports.GLEW_VERSION_MAJOR = 2;
module.exports.GLEW_VERSION_MINOR = 3;
module.exports.GLEW_VERSION_MICRO = 4;

module.exports = {
    ...module.exports,
    ...bindings
};