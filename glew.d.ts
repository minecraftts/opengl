export const GLEW_OK = 0;
export const GLEW_NO_ERROR = 0;
export const GLEW_ERROR_NO_GL_VERSION = 1;
export const GLEW_ERROR_VERSION_10_ONLY = 2;
export const GLEW_ERROR_GLX_VERSION_11_ONLY = 3;
export const GLEW_ERROR_NO_GLX_DISPLAY = 4;
export const GLEW_VERSION = 1;
export const GLEW_VERSION_MAJOR = 2;
export const GLEW_VERSION_MINOR = 3;
export const GLEW_VERSION_MICRO = 4;

export function glewInit(): 0 | 1 | 2 | 3 | 4;
export function glewIsSupported(name: string): boolean;
export function glewIsExtensionSupported(name: string): boolean;
export function glewGetExtension(name: string): boolean;
export function glewGetErrorString(error: number): string;
export function glewGetString(name: number): string;