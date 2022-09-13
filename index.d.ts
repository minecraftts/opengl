type Pointer<T> = {
    $: T;
};

type Nullable<T> = T | null;

// OpenGL Core 1.1 Constants

export const GL_VERSION_1_1 = 1;
export const GL_ZERO = 0;
export const GL_FALSE = 0;
export const GL_LOGIC_OP = 0x0BF1;
export const GL_NONE = 0;
export const GL_TEXTURE_COMPONENTS = 0x1003;
export const GL_POINTS = 0x0000;
export const GL_CURRENT_BIT = 0x00000001;
export const GL_TRUE = 1;
export const GL_ONE = 1;
export const GL_CLIENT_PIXEL_STORE_BIT = 0x00000001;
export const GL_LINES = 0x0001;
export const GL_LINE_LOOP = 0x0002;
export const GL_POINT_BIT = 0x00000002;
export const GL_CLIENT_VERTEX_ARRAY_BIT = 0x00000002;
export const GL_LINE_STRIP = 0x0003;
export const GL_LINE_BIT = 0x00000004;
export const GL_TRIANGLES = 0x0004;
export const GL_TRIANGLE_STRIP = 0x0005;
export const GL_TRIANGLE_FAN = 0x0006;
export const GL_QUADS = 0x0007;
export const GL_QUAD_STRIP = 0x0008;
export const GL_POLYGON_BIT = 0x00000008;
export const GL_POLYGON = 0x0009;
export const GL_POLYGON_STIPPLE_BIT = 0x00000010;
export const GL_PIXEL_MODE_BIT = 0x00000020;
export const GL_LIGHTING_BIT = 0x00000040;
export const GL_FOG_BIT = 0x00000080;
export const GL_DEPTH_BUFFER_BIT = 0x00000100;
export const GL_ACCUM = 0x0100;
export const GL_LOAD = 0x0101;
export const GL_RETURN = 0x0102;
export const GL_MULT = 0x0103;
export const GL_ADD = 0x0104;
export const GL_NEVER = 0x0200;
export const GL_ACCUM_BUFFER_BIT = 0x00000200;
export const GL_LESS = 0x0201;
export const GL_EQUAL = 0x0202;
export const GL_LEQUAL = 0x0203;
export const GL_GREATER = 0x0204;
export const GL_NOTEQUAL = 0x0205;
export const GL_GEQUAL = 0x0206;
export const GL_ALWAYS = 0x0207;
export const GL_SRC_COLOR = 0x0300;
export const GL_ONE_MINUS_SRC_COLOR = 0x0301;
export const GL_SRC_ALPHA = 0x0302;
export const GL_ONE_MINUS_SRC_ALPHA = 0x0303;
export const GL_DST_ALPHA = 0x0304;
export const GL_ONE_MINUS_DST_ALPHA = 0x0305;
export const GL_DST_COLOR = 0x0306;
export const GL_ONE_MINUS_DST_COLOR = 0x0307;
export const GL_SRC_ALPHA_SATURATE = 0x0308;
export const GL_STENCIL_BUFFER_BIT = 0x00000400;
export const GL_FRONT_LEFT = 0x0400;
export const GL_FRONT_RIGHT = 0x0401;
export const GL_BACK_LEFT = 0x0402;
export const GL_BACK_RIGHT = 0x0403;
export const GL_FRONT = 0x0404;
export const GL_BACK = 0x0405;
export const GL_LEFT = 0x0406;
export const GL_RIGHT = 0x0407;
export const GL_FRONT_AND_BACK = 0x0408;
export const GL_AUX0 = 0x0409;
export const GL_AUX1 = 0x040A;
export const GL_AUX2 = 0x040B;
export const GL_AUX3 = 0x040C;
export const GL_INVALID_ENUM = 0x0500;
export const GL_INVALID_VALUE = 0x0501;
export const GL_INVALID_OPERATION = 0x0502;
export const GL_STACK_OVERFLOW = 0x0503;
export const GL_STACK_UNDERFLOW = 0x0504;
export const GL_OUT_OF_MEMORY = 0x0505;
export const GL_2D = 0x0600;
export const GL_3D = 0x0601;
export const GL_3D_COLOR = 0x0602;
export const GL_3D_COLOR_TEXTURE = 0x0603;
export const GL_4D_COLOR_TEXTURE = 0x0604;
export const GL_PASS_THROUGH_TOKEN = 0x0700;
export const GL_POINT_TOKEN = 0x0701;
export const GL_LINE_TOKEN = 0x0702;
export const GL_POLYGON_TOKEN = 0x0703;
export const GL_BITMAP_TOKEN = 0x0704;
export const GL_DRAW_PIXEL_TOKEN = 0x0705;
export const GL_COPY_PIXEL_TOKEN = 0x0706;
export const GL_LINE_RESET_TOKEN = 0x0707;
export const GL_EXP = 0x0800;
export const GL_VIEWPORT_BIT = 0x00000800;
export const GL_EXP2 = 0x0801;
export const GL_CW = 0x0900;
export const GL_CCW = 0x0901;
export const GL_COEFF = 0x0A00;
export const GL_ORDER = 0x0A01;
export const GL_DOMAIN = 0x0A02;
export const GL_CURRENT_COLOR = 0x0B00;
export const GL_CURRENT_INDEX = 0x0B01;
export const GL_CURRENT_NORMAL = 0x0B02;
export const GL_CURRENT_TEXTURE_COORDS = 0x0B03;
export const GL_CURRENT_RASTER_COLOR = 0x0B04;
export const GL_CURRENT_RASTER_INDEX = 0x0B05;
export const GL_CURRENT_RASTER_TEXTURE_COORDS = 0x0B06;
export const GL_CURRENT_RASTER_POSITION = 0x0B07;
export const GL_CURRENT_RASTER_POSITION_VALID = 0x0B08;
export const GL_CURRENT_RASTER_DISTANCE = 0x0B09;
export const GL_POINT_SMOOTH = 0x0B10;
export const GL_POINT_SIZE = 0x0B11;
export const GL_POINT_SIZE_RANGE = 0x0B12;
export const GL_POINT_SIZE_GRANULARITY = 0x0B13;
export const GL_LINE_SMOOTH = 0x0B20;
export const GL_LINE_WIDTH = 0x0B21;
export const GL_LINE_WIDTH_RANGE = 0x0B22;
export const GL_LINE_WIDTH_GRANULARITY = 0x0B23;
export const GL_LINE_STIPPLE = 0x0B24;
export const GL_LINE_STIPPLE_PATTERN = 0x0B25;
export const GL_LINE_STIPPLE_REPEAT = 0x0B26;
export const GL_LIST_MODE = 0x0B30;
export const GL_MAX_LIST_NESTING = 0x0B31;
export const GL_LIST_BASE = 0x0B32;
export const GL_LIST_INDEX = 0x0B33;
export const GL_POLYGON_MODE = 0x0B40;
export const GL_POLYGON_SMOOTH = 0x0B41;
export const GL_POLYGON_STIPPLE = 0x0B42;
export const GL_EDGE_FLAG = 0x0B43;
export const GL_CULL_FACE = 0x0B44;
export const GL_CULL_FACE_MODE = 0x0B45;
export const GL_FRONT_FACE = 0x0B46;
export const GL_LIGHTING = 0x0B50;
export const GL_LIGHT_MODEL_LOCAL_VIEWER = 0x0B51;
export const GL_LIGHT_MODEL_TWO_SIDE = 0x0B52;
export const GL_LIGHT_MODEL_AMBIENT = 0x0B53;
export const GL_SHADE_MODEL = 0x0B54;
export const GL_COLOR_MATERIAL_FACE = 0x0B55;
export const GL_COLOR_MATERIAL_PARAMETER = 0x0B56;
export const GL_COLOR_MATERIAL = 0x0B57;
export const GL_FOG = 0x0B60;
export const GL_FOG_INDEX = 0x0B61;
export const GL_FOG_DENSITY = 0x0B62;
export const GL_FOG_START = 0x0B63;
export const GL_FOG_END = 0x0B64;
export const GL_FOG_MODE = 0x0B65;
export const GL_FOG_COLOR = 0x0B66;
export const GL_DEPTH_RANGE = 0x0B70;
export const GL_DEPTH_TEST = 0x0B71;
export const GL_DEPTH_WRITEMASK = 0x0B72;
export const GL_DEPTH_CLEAR_VALUE = 0x0B73;
export const GL_DEPTH_FUNC = 0x0B74;
export const GL_ACCUM_CLEAR_VALUE = 0x0B80;
export const GL_STENCIL_TEST = 0x0B90;
export const GL_STENCIL_CLEAR_VALUE = 0x0B91;
export const GL_STENCIL_FUNC = 0x0B92;
export const GL_STENCIL_VALUE_MASK = 0x0B93;
export const GL_STENCIL_FAIL = 0x0B94;
export const GL_STENCIL_PASS_DEPTH_FAIL = 0x0B95;
export const GL_STENCIL_PASS_DEPTH_PASS = 0x0B96;
export const GL_STENCIL_REF = 0x0B97;
export const GL_STENCIL_WRITEMASK = 0x0B98;
export const GL_MATRIX_MODE = 0x0BA0;
export const GL_NORMALIZE = 0x0BA1;
export const GL_VIEWPORT = 0x0BA2;
export const GL_MODELVIEW_STACK_DEPTH = 0x0BA3;
export const GL_PROJECTION_STACK_DEPTH = 0x0BA4;
export const GL_TEXTURE_STACK_DEPTH = 0x0BA5;
export const GL_MODELVIEW_MATRIX = 0x0BA6;
export const GL_PROJECTION_MATRIX = 0x0BA7;
export const GL_TEXTURE_MATRIX = 0x0BA8;
export const GL_ATTRIB_STACK_DEPTH = 0x0BB0;
export const GL_CLIENT_ATTRIB_STACK_DEPTH = 0x0BB1;
export const GL_ALPHA_TEST = 0x0BC0;
export const GL_ALPHA_TEST_FUNC = 0x0BC1;
export const GL_ALPHA_TEST_REF = 0x0BC2;
export const GL_DITHER = 0x0BD0;
export const GL_BLEND_DST = 0x0BE0;
export const GL_BLEND_SRC = 0x0BE1;
export const GL_BLEND = 0x0BE2;
export const GL_LOGIC_OP_MODE = 0x0BF0;
export const GL_INDEX_LOGIC_OP = 0x0BF1;
export const GL_COLOR_LOGIC_OP = 0x0BF2;
export const GL_AUX_BUFFERS = 0x0C00;
export const GL_DRAW_BUFFER = 0x0C01;
export const GL_READ_BUFFER = 0x0C02;
export const GL_SCISSOR_BOX = 0x0C10;
export const GL_SCISSOR_TEST = 0x0C11;
export const GL_INDEX_CLEAR_VALUE = 0x0C20;
export const GL_INDEX_WRITEMASK = 0x0C21;
export const GL_COLOR_CLEAR_VALUE = 0x0C22;
export const GL_COLOR_WRITEMASK = 0x0C23;
export const GL_INDEX_MODE = 0x0C30;
export const GL_RGBA_MODE = 0x0C31;
export const GL_DOUBLEBUFFER = 0x0C32;
export const GL_STEREO = 0x0C33;
export const GL_RENDER_MODE = 0x0C40;
export const GL_PERSPECTIVE_CORRECTION_HINT = 0x0C50;
export const GL_POINT_SMOOTH_HINT = 0x0C51;
export const GL_LINE_SMOOTH_HINT = 0x0C52;
export const GL_POLYGON_SMOOTH_HINT = 0x0C53;
export const GL_FOG_HINT = 0x0C54;
export const GL_TEXTURE_GEN_S = 0x0C60;
export const GL_TEXTURE_GEN_T = 0x0C61;
export const GL_TEXTURE_GEN_R = 0x0C62;
export const GL_TEXTURE_GEN_Q = 0x0C63;
export const GL_PIXEL_MAP_I_TO_I = 0x0C70;
export const GL_PIXEL_MAP_S_TO_S = 0x0C71;
export const GL_PIXEL_MAP_I_TO_R = 0x0C72;
export const GL_PIXEL_MAP_I_TO_G = 0x0C73;
export const GL_PIXEL_MAP_I_TO_B = 0x0C74;
export const GL_PIXEL_MAP_I_TO_A = 0x0C75;
export const GL_PIXEL_MAP_R_TO_R = 0x0C76;
export const GL_PIXEL_MAP_G_TO_G = 0x0C77;
export const GL_PIXEL_MAP_B_TO_B = 0x0C78;
export const GL_PIXEL_MAP_A_TO_A = 0x0C79;
export const GL_PIXEL_MAP_I_TO_I_SIZE = 0x0CB0;
export const GL_PIXEL_MAP_S_TO_S_SIZE = 0x0CB1;
export const GL_PIXEL_MAP_I_TO_R_SIZE = 0x0CB2;
export const GL_PIXEL_MAP_I_TO_G_SIZE = 0x0CB3;
export const GL_PIXEL_MAP_I_TO_B_SIZE = 0x0CB4;
export const GL_PIXEL_MAP_I_TO_A_SIZE = 0x0CB5;
export const GL_PIXEL_MAP_R_TO_R_SIZE = 0x0CB6;
export const GL_PIXEL_MAP_G_TO_G_SIZE = 0x0CB7;
export const GL_PIXEL_MAP_B_TO_B_SIZE = 0x0CB8;
export const GL_PIXEL_MAP_A_TO_A_SIZE = 0x0CB9;
export const GL_UNPACK_SWAP_BYTES = 0x0CF0;
export const GL_UNPACK_LSB_FIRST = 0x0CF1;
export const GL_UNPACK_ROW_LENGTH = 0x0CF2;
export const GL_UNPACK_SKIP_ROWS = 0x0CF3;
export const GL_UNPACK_SKIP_PIXELS = 0x0CF4;
export const GL_UNPACK_ALIGNMENT = 0x0CF5;
export const GL_PACK_SWAP_BYTES = 0x0D00;
export const GL_PACK_LSB_FIRST = 0x0D01;
export const GL_PACK_ROW_LENGTH = 0x0D02;
export const GL_PACK_SKIP_ROWS = 0x0D03;
export const GL_PACK_SKIP_PIXELS = 0x0D04;
export const GL_PACK_ALIGNMENT = 0x0D05;
export const GL_MAP_COLOR = 0x0D10;
export const GL_MAP_STENCIL = 0x0D11;
export const GL_INDEX_SHIFT = 0x0D12;
export const GL_INDEX_OFFSET = 0x0D13;
export const GL_RED_SCALE = 0x0D14;
export const GL_RED_BIAS = 0x0D15;
export const GL_ZOOM_X = 0x0D16;
export const GL_ZOOM_Y = 0x0D17;
export const GL_GREEN_SCALE = 0x0D18;
export const GL_GREEN_BIAS = 0x0D19;
export const GL_BLUE_SCALE = 0x0D1A;
export const GL_BLUE_BIAS = 0x0D1B;
export const GL_ALPHA_SCALE = 0x0D1C;
export const GL_ALPHA_BIAS = 0x0D1D;
export const GL_DEPTH_SCALE = 0x0D1E;
export const GL_DEPTH_BIAS = 0x0D1F;
export const GL_MAX_EVAL_ORDER = 0x0D30;
export const GL_MAX_LIGHTS = 0x0D31;
export const GL_MAX_CLIP_PLANES = 0x0D32;
export const GL_MAX_TEXTURE_SIZE = 0x0D33;
export const GL_MAX_PIXEL_MAP_TABLE = 0x0D34;
export const GL_MAX_ATTRIB_STACK_DEPTH = 0x0D35;
export const GL_MAX_MODELVIEW_STACK_DEPTH = 0x0D36;
export const GL_MAX_NAME_STACK_DEPTH = 0x0D37;
export const GL_MAX_PROJECTION_STACK_DEPTH = 0x0D38;
export const GL_MAX_TEXTURE_STACK_DEPTH = 0x0D39;
export const GL_MAX_VIEWPORT_DIMS = 0x0D3A;
export const GL_MAX_CLIENT_ATTRIB_STACK_DEPTH = 0x0D3B;
export const GL_SUBPIXEL_BITS = 0x0D50;
export const GL_INDEX_BITS = 0x0D51;
export const GL_RED_BITS = 0x0D52;
export const GL_GREEN_BITS = 0x0D53;
export const GL_BLUE_BITS = 0x0D54;
export const GL_ALPHA_BITS = 0x0D55;
export const GL_DEPTH_BITS = 0x0D56;
export const GL_STENCIL_BITS = 0x0D57;
export const GL_ACCUM_RED_BITS = 0x0D58;
export const GL_ACCUM_GREEN_BITS = 0x0D59;
export const GL_ACCUM_BLUE_BITS = 0x0D5A;
export const GL_ACCUM_ALPHA_BITS = 0x0D5B;
export const GL_NAME_STACK_DEPTH = 0x0D70;
export const GL_AUTO_NORMAL = 0x0D80;
export const GL_MAP1_COLOR_4 = 0x0D90;
export const GL_MAP1_INDEX = 0x0D91;
export const GL_MAP1_NORMAL = 0x0D92;
export const GL_MAP1_TEXTURE_COORD_1 = 0x0D93;
export const GL_MAP1_TEXTURE_COORD_2 = 0x0D94;
export const GL_MAP1_TEXTURE_COORD_3 = 0x0D95;
export const GL_MAP1_TEXTURE_COORD_4 = 0x0D96;
export const GL_MAP1_VERTEX_3 = 0x0D97;
export const GL_MAP1_VERTEX_4 = 0x0D98;
export const GL_MAP2_COLOR_4 = 0x0DB0;
export const GL_MAP2_INDEX = 0x0DB1;
export const GL_MAP2_NORMAL = 0x0DB2;
export const GL_MAP2_TEXTURE_COORD_1 = 0x0DB3;
export const GL_MAP2_TEXTURE_COORD_2 = 0x0DB4;
export const GL_MAP2_TEXTURE_COORD_3 = 0x0DB5;
export const GL_MAP2_TEXTURE_COORD_4 = 0x0DB6;
export const GL_MAP2_VERTEX_3 = 0x0DB7;
export const GL_MAP2_VERTEX_4 = 0x0DB8;
export const GL_MAP1_GRID_DOMAIN = 0x0DD0;
export const GL_MAP1_GRID_SEGMENTS = 0x0DD1;
export const GL_MAP2_GRID_DOMAIN = 0x0DD2;
export const GL_MAP2_GRID_SEGMENTS = 0x0DD3;
export const GL_TEXTURE_1D = 0x0DE0;
export const GL_TEXTURE_2D = 0x0DE1;
export const GL_FEEDBACK_BUFFER_POINTER = 0x0DF0;
export const GL_FEEDBACK_BUFFER_SIZE = 0x0DF1;
export const GL_FEEDBACK_BUFFER_TYPE = 0x0DF2;
export const GL_SELECTION_BUFFER_POINTER = 0x0DF3;
export const GL_SELECTION_BUFFER_SIZE = 0x0DF4;
export const GL_TEXTURE_WIDTH = 0x1000;
export const GL_TRANSFORM_BIT = 0x00001000;
export const GL_TEXTURE_HEIGHT = 0x1001;
export const GL_TEXTURE_INTERNAL_FORMAT = 0x1003;
export const GL_TEXTURE_BORDER_COLOR = 0x1004;
export const GL_TEXTURE_BORDER = 0x1005;
export const GL_DONT_CARE = 0x1100;
export const GL_FASTEST = 0x1101;
export const GL_NICEST = 0x1102;
export const GL_AMBIENT = 0x1200;
export const GL_DIFFUSE = 0x1201;
export const GL_SPECULAR = 0x1202;
export const GL_POSITION = 0x1203;
export const GL_SPOT_DIRECTION = 0x1204;
export const GL_SPOT_EXPONENT = 0x1205;
export const GL_SPOT_CUTOFF = 0x1206;
export const GL_CONSTANT_ATTENUATION = 0x1207;
export const GL_LINEAR_ATTENUATION = 0x1208;
export const GL_QUADRATIC_ATTENUATION = 0x1209;
export const GL_COMPILE = 0x1300;
export const GL_COMPILE_AND_EXECUTE = 0x1301;
export const GL_BYTE = 0x1400;
export const GL_UNSIGNED_BYTE = 0x1401;
export const GL_SHORT = 0x1402;
export const GL_UNSIGNED_SHORT = 0x1403;
export const GL_INT = 0x1404;
export const GL_UNSIGNED_INT = 0x1405;
export const GL_FLOAT = 0x1406;
export const GL_2_BYTES = 0x1407;
export const GL_3_BYTES = 0x1408;
export const GL_4_BYTES = 0x1409;
export const GL_DOUBLE = 0x140A;
export const GL_CLEAR = 0x1500;
export const GL_AND = 0x1501;
export const GL_AND_REVERSE = 0x1502;
export const GL_COPY = 0x1503;
export const GL_AND_INVERTED = 0x1504;
export const GL_NOOP = 0x1505;
export const GL_XOR = 0x1506;
export const GL_OR = 0x1507;
export const GL_NOR = 0x1508;
export const GL_EQUIV = 0x1509;
export const GL_INVERT = 0x150A;
export const GL_OR_REVERSE = 0x150B;
export const GL_COPY_INVERTED = 0x150C;
export const GL_OR_INVERTED = 0x150D;
export const GL_NAND = 0x150E;
export const GL_SET = 0x150F;
export const GL_EMISSION = 0x1600;
export const GL_SHININESS = 0x1601;
export const GL_AMBIENT_AND_DIFFUSE = 0x1602;
export const GL_COLOR_INDEXES = 0x1603;
export const GL_MODELVIEW = 0x1700;
export const GL_PROJECTION = 0x1701;
export const GL_TEXTURE = 0x1702;
export const GL_COLOR = 0x1800;
export const GL_DEPTH = 0x1801;
export const GL_STENCIL = 0x1802;
export const GL_COLOR_INDEX = 0x1900;
export const GL_STENCIL_INDEX = 0x1901;
export const GL_DEPTH_COMPONENT = 0x1902;
export const GL_RED = 0x1903;
export const GL_GREEN = 0x1904;
export const GL_BLUE = 0x1905;
export const GL_ALPHA = 0x1906;
export const GL_RGB = 0x1907;
export const GL_RGBA = 0x1908;
export const GL_LUMINANCE = 0x1909;
export const GL_LUMINANCE_ALPHA = 0x190A;
export const GL_BITMAP = 0x1A00;
export const GL_POINT = 0x1B00;
export const GL_LINE = 0x1B01;
export const GL_FILL = 0x1B02;
export const GL_RENDER = 0x1C00;
export const GL_FEEDBACK = 0x1C01;
export const GL_SELECT = 0x1C02;
export const GL_FLAT = 0x1D00;
export const GL_SMOOTH = 0x1D01;
export const GL_KEEP = 0x1E00;
export const GL_REPLACE = 0x1E01;
export const GL_INCR = 0x1E02;
export const GL_DECR = 0x1E03;
export const GL_VENDOR = 0x1F00;
export const GL_RENDERER = 0x1F01;
export const GL_VERSION = 0x1F02;
export const GL_EXTENSIONS = 0x1F03;
export const GL_S = 0x2000;
export const GL_ENABLE_BIT = 0x00002000;
export const GL_T = 0x2001;
export const GL_R = 0x2002;
export const GL_Q = 0x2003;
export const GL_MODULATE = 0x2100;
export const GL_DECAL = 0x2101;
export const GL_TEXTURE_ENV_MODE = 0x2200;
export const GL_TEXTURE_ENV_COLOR = 0x2201;
export const GL_TEXTURE_ENV = 0x2300;
export const GL_EYE_LINEAR = 0x2400;
export const GL_OBJECT_LINEAR = 0x2401;
export const GL_SPHERE_MAP = 0x2402;
export const GL_TEXTURE_GEN_MODE = 0x2500;
export const GL_OBJECT_PLANE = 0x2501;
export const GL_EYE_PLANE = 0x2502;
export const GL_NEAREST = 0x2600;
export const GL_LINEAR = 0x2601;
export const GL_NEAREST_MIPMAP_NEAREST = 0x2700;
export const GL_LINEAR_MIPMAP_NEAREST = 0x2701;
export const GL_NEAREST_MIPMAP_LINEAR = 0x2702;
export const GL_LINEAR_MIPMAP_LINEAR = 0x2703;
export const GL_TEXTURE_MAG_FILTER = 0x2800;
export const GL_TEXTURE_MIN_FILTER = 0x2801;
export const GL_TEXTURE_WRAP_S = 0x2802;
export const GL_TEXTURE_WRAP_T = 0x2803;
export const GL_CLAMP = 0x2900;
export const GL_REPEAT = 0x2901;
export const GL_POLYGON_OFFSET_UNITS = 0x2A00;
export const GL_POLYGON_OFFSET_POINT = 0x2A01;
export const GL_POLYGON_OFFSET_LINE = 0x2A02;
export const GL_R3_G3_B2 = 0x2A10;
export const GL_V2F = 0x2A20;
export const GL_V3F = 0x2A21;
export const GL_C4UB_V2F = 0x2A22;
export const GL_C4UB_V3F = 0x2A23;
export const GL_C3F_V3F = 0x2A24;
export const GL_N3F_V3F = 0x2A25;
export const GL_C4F_N3F_V3F = 0x2A26;
export const GL_T2F_V3F = 0x2A27;
export const GL_T4F_V4F = 0x2A28;
export const GL_T2F_C4UB_V3F = 0x2A29;
export const GL_T2F_C3F_V3F = 0x2A2A;
export const GL_T2F_N3F_V3F = 0x2A2B;
export const GL_T2F_C4F_N3F_V3F = 0x2A2C;
export const GL_T4F_C4F_N3F_V4F = 0x2A2D;
export const GL_CLIP_PLANE0 = 0x3000;
export const GL_CLIP_PLANE1 = 0x3001;
export const GL_CLIP_PLANE2 = 0x3002;
export const GL_CLIP_PLANE3 = 0x3003;
export const GL_CLIP_PLANE4 = 0x3004;
export const GL_CLIP_PLANE5 = 0x3005;
export const GL_LIGHT0 = 0x4000;
export const GL_COLOR_BUFFER_BIT = 0x00004000;
export const GL_LIGHT1 = 0x4001;
export const GL_LIGHT2 = 0x4002;
export const GL_LIGHT3 = 0x4003;
export const GL_LIGHT4 = 0x4004;
export const GL_LIGHT5 = 0x4005;
export const GL_LIGHT6 = 0x4006;
export const GL_LIGHT7 = 0x4007;
export const GL_HINT_BIT = 0x00008000;
export const GL_POLYGON_OFFSET_FILL = 0x8037;
export const GL_POLYGON_OFFSET_FACTOR = 0x8038;
export const GL_ALPHA4 = 0x803B;
export const GL_ALPHA8 = 0x803C;
export const GL_ALPHA12 = 0x803D;
export const GL_ALPHA16 = 0x803E;
export const GL_LUMINANCE4 = 0x803F;
export const GL_LUMINANCE8 = 0x8040;
export const GL_LUMINANCE12 = 0x8041;
export const GL_LUMINANCE16 = 0x8042;
export const GL_LUMINANCE4_ALPHA4 = 0x8043;
export const GL_LUMINANCE6_ALPHA2 = 0x8044;
export const GL_LUMINANCE8_ALPHA8 = 0x8045;
export const GL_LUMINANCE12_ALPHA4 = 0x8046;
export const GL_LUMINANCE12_ALPHA12 = 0x8047;
export const GL_LUMINANCE16_ALPHA16 = 0x8048;
export const GL_INTENSITY = 0x8049;
export const GL_INTENSITY4 = 0x804A;
export const GL_INTENSITY8 = 0x804B;
export const GL_INTENSITY12 = 0x804C;
export const GL_INTENSITY16 = 0x804D;
export const GL_RGB4 = 0x804F;
export const GL_RGB5 = 0x8050;
export const GL_RGB8 = 0x8051;
export const GL_RGB10 = 0x8052;
export const GL_RGB12 = 0x8053;
export const GL_RGB16 = 0x8054;
export const GL_RGBA2 = 0x8055;
export const GL_RGBA4 = 0x8056;
export const GL_RGB5_A1 = 0x8057;
export const GL_RGBA8 = 0x8058;
export const GL_RGB10_A2 = 0x8059;
export const GL_RGBA12 = 0x805A;
export const GL_RGBA16 = 0x805B;
export const GL_TEXTURE_RED_SIZE = 0x805C;
export const GL_TEXTURE_GREEN_SIZE = 0x805D;
export const GL_TEXTURE_BLUE_SIZE = 0x805E;
export const GL_TEXTURE_ALPHA_SIZE = 0x805F;
export const GL_TEXTURE_LUMINANCE_SIZE = 0x8060;
export const GL_TEXTURE_INTENSITY_SIZE = 0x8061;
export const GL_PROXY_TEXTURE_1D = 0x8063;
export const GL_PROXY_TEXTURE_2D = 0x8064;
export const GL_TEXTURE_PRIORITY = 0x8066;
export const GL_TEXTURE_RESIDENT = 0x8067;
export const GL_TEXTURE_BINDING_1D = 0x8068;
export const GL_TEXTURE_BINDING_2D = 0x8069;
export const GL_VERTEX_ARRAY = 0x8074;
export const GL_NORMAL_ARRAY = 0x8075;
export const GL_COLOR_ARRAY = 0x8076;
export const GL_INDEX_ARRAY = 0x8077;
export const GL_TEXTURE_COORD_ARRAY = 0x8078;
export const GL_EDGE_FLAG_ARRAY = 0x8079;
export const GL_VERTEX_ARRAY_SIZE = 0x807A;
export const GL_VERTEX_ARRAY_TYPE = 0x807B;
export const GL_VERTEX_ARRAY_STRIDE = 0x807C;
export const GL_NORMAL_ARRAY_TYPE = 0x807E;
export const GL_NORMAL_ARRAY_STRIDE = 0x807F;
export const GL_COLOR_ARRAY_SIZE = 0x8081;
export const GL_COLOR_ARRAY_TYPE = 0x8082;
export const GL_COLOR_ARRAY_STRIDE = 0x8083;
export const GL_INDEX_ARRAY_TYPE = 0x8085;
export const GL_INDEX_ARRAY_STRIDE = 0x8086;
export const GL_TEXTURE_COORD_ARRAY_SIZE = 0x8088;
export const GL_TEXTURE_COORD_ARRAY_TYPE = 0x8089;
export const GL_TEXTURE_COORD_ARRAY_STRIDE = 0x808A;
export const GL_EDGE_FLAG_ARRAY_STRIDE = 0x808C;
export const GL_VERTEX_ARRAY_POINTER = 0x808E;
export const GL_NORMAL_ARRAY_POINTER = 0x808F;
export const GL_COLOR_ARRAY_POINTER = 0x8090;
export const GL_INDEX_ARRAY_POINTER = 0x8091;
export const GL_TEXTURE_COORD_ARRAY_POINTER = 0x8092;
export const GL_EDGE_FLAG_ARRAY_POINTER = 0x8093;
export const GL_COLOR_INDEX1_EXT = 0x80E2;
export const GL_COLOR_INDEX2_EXT = 0x80E3;
export const GL_COLOR_INDEX4_EXT = 0x80E4;
export const GL_COLOR_INDEX8_EXT = 0x80E5;
export const GL_COLOR_INDEX12_EXT = 0x80E6;
export const GL_COLOR_INDEX16_EXT = 0x80E7;
export const GL_EVAL_BIT = 0x00010000;
export const GL_LIST_BIT = 0x00020000;
export const GL_TEXTURE_BIT = 0x00040000;
export const GL_SCISSOR_BIT = 0x00080000;
export const GL_ALL_ATTRIB_BITS = 0x000fffff;
export const GL_CLIENT_ALL_ATTRIB_BITS = 0xffffffff;

// OpenGL Core 1.2 Constants

export const GL_SMOOTH_POINT_SIZE_RANGE = 0x0B12;
export const GL_SMOOTH_POINT_SIZE_GRANULARITY = 0x0B13;
export const GL_SMOOTH_LINE_WIDTH_RANGE = 0x0B22;
export const GL_SMOOTH_LINE_WIDTH_GRANULARITY = 0x0B23;
export const GL_UNSIGNED_BYTE_3_3_2 = 0x8032;
export const GL_UNSIGNED_SHORT_4_4_4_4 = 0x8033;
export const GL_UNSIGNED_SHORT_5_5_5_1 = 0x8034;
export const GL_UNSIGNED_INT_8_8_8_8 = 0x8035;
export const GL_UNSIGNED_INT_10_10_10_2 = 0x8036;
export const GL_RESCALE_NORMAL = 0x803A;
export const GL_TEXTURE_BINDING_3D = 0x806A;
export const GL_PACK_SKIP_IMAGES = 0x806B;
export const GL_PACK_IMAGE_HEIGHT = 0x806C;
export const GL_UNPACK_SKIP_IMAGES = 0x806D;
export const GL_UNPACK_IMAGE_HEIGHT = 0x806E;
export const GL_TEXTURE_3D = 0x806F;
export const GL_PROXY_TEXTURE_3D = 0x8070;
export const GL_TEXTURE_DEPTH = 0x8071;
export const GL_TEXTURE_WRAP_R = 0x8072;
export const GL_MAX_3D_TEXTURE_SIZE = 0x8073;
export const GL_BGR = 0x80E0;
export const GL_BGRA = 0x80E1;
export const GL_MAX_ELEMENTS_VERTICES = 0x80E8;
export const GL_MAX_ELEMENTS_INDICES = 0x80E9;
export const GL_CLAMP_TO_EDGE = 0x812F;
export const GL_TEXTURE_MIN_LOD = 0x813A;
export const GL_TEXTURE_MAX_LOD = 0x813B;
export const GL_TEXTURE_BASE_LEVEL = 0x813C;
export const GL_TEXTURE_MAX_LEVEL = 0x813D;
export const GL_LIGHT_MODEL_COLOR_CONTROL = 0x81F8;
export const GL_SINGLE_COLOR = 0x81F9;
export const GL_SEPARATE_SPECULAR_COLOR = 0x81FA;
export const GL_UNSIGNED_BYTE_2_3_3_REV = 0x8362;
export const GL_UNSIGNED_SHORT_5_6_5 = 0x8363;
export const GL_UNSIGNED_SHORT_5_6_5_REV = 0x8364;
export const GL_UNSIGNED_SHORT_4_4_4_4_REV = 0x8365;
export const GL_UNSIGNED_SHORT_1_5_5_5_REV = 0x8366;
export const GL_UNSIGNED_INT_8_8_8_8_REV = 0x8367;
export const GL_ALIASED_POINT_SIZE_RANGE = 0x846D;
export const GL_ALIASED_LINE_WIDTH_RANGE = 0x846E;

// OpenGL Core 1.3 Constants

export const GL_MULTISAMPLE = 0x809D;
export const GL_SAMPLE_ALPHA_TO_COVERAGE = 0x809E;
export const GL_SAMPLE_ALPHA_TO_ONE = 0x809F;
export const GL_SAMPLE_COVERAGE = 0x80A0;
export const GL_SAMPLE_BUFFERS = 0x80A8;
export const GL_SAMPLES = 0x80A9;
export const GL_SAMPLE_COVERAGE_VALUE = 0x80AA;
export const GL_SAMPLE_COVERAGE_INVERT = 0x80AB;
export const GL_CLAMP_TO_BORDER = 0x812D;
export const GL_TEXTURE0 = 0x84C0;
export const GL_TEXTURE1 = 0x84C1;
export const GL_TEXTURE2 = 0x84C2;
export const GL_TEXTURE3 = 0x84C3;
export const GL_TEXTURE4 = 0x84C4;
export const GL_TEXTURE5 = 0x84C5;
export const GL_TEXTURE6 = 0x84C6;
export const GL_TEXTURE7 = 0x84C7;
export const GL_TEXTURE8 = 0x84C8;
export const GL_TEXTURE9 = 0x84C9;
export const GL_TEXTURE10 = 0x84CA;
export const GL_TEXTURE11 = 0x84CB;
export const GL_TEXTURE12 = 0x84CC;
export const GL_TEXTURE13 = 0x84CD;
export const GL_TEXTURE14 = 0x84CE;
export const GL_TEXTURE15 = 0x84CF;
export const GL_TEXTURE16 = 0x84D0;
export const GL_TEXTURE17 = 0x84D1;
export const GL_TEXTURE18 = 0x84D2;
export const GL_TEXTURE19 = 0x84D3;
export const GL_TEXTURE20 = 0x84D4;
export const GL_TEXTURE21 = 0x84D5;
export const GL_TEXTURE22 = 0x84D6;
export const GL_TEXTURE23 = 0x84D7;
export const GL_TEXTURE24 = 0x84D8;
export const GL_TEXTURE25 = 0x84D9;
export const GL_TEXTURE26 = 0x84DA;
export const GL_TEXTURE27 = 0x84DB;
export const GL_TEXTURE28 = 0x84DC;
export const GL_TEXTURE29 = 0x84DD;
export const GL_TEXTURE30 = 0x84DE;
export const GL_TEXTURE31 = 0x84DF;
export const GL_ACTIVE_TEXTURE = 0x84E0;
export const GL_CLIENT_ACTIVE_TEXTURE = 0x84E1;
export const GL_MAX_TEXTURE_UNITS = 0x84E2;
export const GL_TRANSPOSE_MODELVIEW_MATRIX = 0x84E3;
export const GL_TRANSPOSE_PROJECTION_MATRIX = 0x84E4;
export const GL_TRANSPOSE_TEXTURE_MATRIX = 0x84E5;
export const GL_TRANSPOSE_COLOR_MATRIX = 0x84E6;
export const GL_SUBTRACT = 0x84E7;
export const GL_COMPRESSED_ALPHA = 0x84E9;
export const GL_COMPRESSED_LUMINANCE = 0x84EA;
export const GL_COMPRESSED_LUMINANCE_ALPHA = 0x84EB;
export const GL_COMPRESSED_INTENSITY = 0x84EC;
export const GL_COMPRESSED_RGB = 0x84ED;
export const GL_COMPRESSED_RGBA = 0x84EE;
export const GL_TEXTURE_COMPRESSION_HINT = 0x84EF;
export const GL_NORMAL_MAP = 0x8511;
export const GL_REFLECTION_MAP = 0x8512;
export const GL_TEXTURE_CUBE_MAP = 0x8513;
export const GL_TEXTURE_BINDING_CUBE_MAP = 0x8514;
export const GL_TEXTURE_CUBE_MAP_POSITIVE_X = 0x8515;
export const GL_TEXTURE_CUBE_MAP_NEGATIVE_X = 0x8516;
export const GL_TEXTURE_CUBE_MAP_POSITIVE_Y = 0x8517;
export const GL_TEXTURE_CUBE_MAP_NEGATIVE_Y = 0x8518;
export const GL_TEXTURE_CUBE_MAP_POSITIVE_Z = 0x8519;
export const GL_TEXTURE_CUBE_MAP_NEGATIVE_Z = 0x851A;
export const GL_PROXY_TEXTURE_CUBE_MAP = 0x851B;
export const GL_MAX_CUBE_MAP_TEXTURE_SIZE = 0x851C;
export const GL_COMBINE = 0x8570;
export const GL_COMBINE_RGB = 0x8571;
export const GL_COMBINE_ALPHA = 0x8572;
export const GL_RGB_SCALE = 0x8573;
export const GL_ADD_SIGNED = 0x8574;
export const GL_INTERPOLATE = 0x8575;
export const GL_CONSTANT = 0x8576;
export const GL_PRIMARY_COLOR = 0x8577;
export const GL_PREVIOUS = 0x8578;
export const GL_SOURCE0_RGB = 0x8580;
export const GL_SOURCE1_RGB = 0x8581;
export const GL_SOURCE2_RGB = 0x8582;
export const GL_SOURCE0_ALPHA = 0x8588;
export const GL_SOURCE1_ALPHA = 0x8589;
export const GL_SOURCE2_ALPHA = 0x858A;
export const GL_OPERAND0_RGB = 0x8590;
export const GL_OPERAND1_RGB = 0x8591;
export const GL_OPERAND2_RGB = 0x8592;
export const GL_OPERAND0_ALPHA = 0x8598;
export const GL_OPERAND1_ALPHA = 0x8599;
export const GL_OPERAND2_ALPHA = 0x859A;
export const GL_TEXTURE_COMPRESSED_IMAGE_SIZE = 0x86A0;
export const GL_TEXTURE_COMPRESSED = 0x86A1;
export const GL_NUM_COMPRESSED_TEXTURE_FORMATS = 0x86A2;
export const GL_COMPRESSED_TEXTURE_FORMATS = 0x86A3;
export const GL_DOT3_RGB = 0x86AE;
export const GL_DOT3_RGBA = 0x86AF;
export const GL_MULTISAMPLE_BIT = 0x20000000;

// OpenGL Core 1.4 Constants

export const GL_BLEND_DST_RGB = 0x80C8;
export const GL_BLEND_SRC_RGB = 0x80C9;
export const GL_BLEND_DST_ALPHA = 0x80CA;
export const GL_BLEND_SRC_ALPHA = 0x80CB;
export const GL_POINT_SIZE_MIN = 0x8126;
export const GL_POINT_SIZE_MAX = 0x8127;
export const GL_POINT_FADE_THRESHOLD_SIZE = 0x8128;
export const GL_POINT_DISTANCE_ATTENUATION = 0x8129;
export const GL_GENERATE_MIPMAP = 0x8191;
export const GL_GENERATE_MIPMAP_HINT = 0x8192;
export const GL_DEPTH_COMPONENT16 = 0x81A5;
export const GL_DEPTH_COMPONENT24 = 0x81A6;
export const GL_DEPTH_COMPONENT32 = 0x81A7;
export const GL_MIRRORED_REPEAT = 0x8370;
export const GL_FOG_COORDINATE_SOURCE = 0x8450;
export const GL_FOG_COORDINATE = 0x8451;
export const GL_FRAGMENT_DEPTH = 0x8452;
export const GL_CURRENT_FOG_COORDINATE = 0x8453;
export const GL_FOG_COORDINATE_ARRAY_TYPE = 0x8454;
export const GL_FOG_COORDINATE_ARRAY_STRIDE = 0x8455;
export const GL_FOG_COORDINATE_ARRAY_POINTER = 0x8456;
export const GL_FOG_COORDINATE_ARRAY = 0x8457;
export const GL_COLOR_SUM = 0x8458;
export const GL_CURRENT_SECONDARY_COLOR = 0x8459;
export const GL_SECONDARY_COLOR_ARRAY_SIZE = 0x845A;
export const GL_SECONDARY_COLOR_ARRAY_TYPE = 0x845B;
export const GL_SECONDARY_COLOR_ARRAY_STRIDE = 0x845C;
export const GL_SECONDARY_COLOR_ARRAY_POINTER = 0x845D;
export const GL_SECONDARY_COLOR_ARRAY = 0x845E;
export const GL_MAX_TEXTURE_LOD_BIAS = 0x84FD;
export const GL_TEXTURE_FILTER_CONTROL = 0x8500;
export const GL_TEXTURE_LOD_BIAS = 0x8501;
export const GL_INCR_WRAP = 0x8507;
export const GL_DECR_WRAP = 0x8508;
export const GL_TEXTURE_DEPTH_SIZE = 0x884A;
export const GL_DEPTH_TEXTURE_MODE = 0x884B;
export const GL_TEXTURE_COMPARE_MODE = 0x884C;
export const GL_TEXTURE_COMPARE_FUNC = 0x884D;
export const GL_COMPARE_R_TO_TEXTURE = 0x884E;

// OpenGL Core 1.5 Constants

export const GL_CURRENT_FOG_COORD = 0x8453;
export const GL_FOG_COORD = 0x8451;
export const GL_FOG_COORD_ARRAY = 0x8457;
export const GL_FOG_COORD_ARRAY_BUFFER_BINDING = 0x889D;
export const GL_FOG_COORD_ARRAY_POINTER = 0x8456;
export const GL_FOG_COORD_ARRAY_STRIDE = 0x8455;
export const GL_FOG_COORD_ARRAY_TYPE = 0x8454;
export const GL_FOG_COORD_SRC = 0x8450;
export const GL_SRC0_ALPHA = 0x8588;
export const GL_SRC1_ALPHA = 0x8589;
export const GL_SRC2_ALPHA = 0x858A;
export const GL_BUFFER_SIZE = 0x8764;
export const GL_BUFFER_USAGE = 0x8765;
export const GL_QUERY_COUNTER_BITS = 0x8864;
export const GL_CURRENT_QUERY = 0x8865;
export const GL_QUERY_RESULT = 0x8866;
export const GL_QUERY_RESULT_AVAILABLE = 0x8867;
export const GL_ARRAY_BUFFER = 0x8892;
export const GL_ELEMENT_ARRAY_BUFFER = 0x8893;
export const GL_ARRAY_BUFFER_BINDING = 0x8894;
export const GL_ELEMENT_ARRAY_BUFFER_BINDING = 0x8895;
export const GL_VERTEX_ARRAY_BUFFER_BINDING = 0x8896;
export const GL_NORMAL_ARRAY_BUFFER_BINDING = 0x8897;
export const GL_COLOR_ARRAY_BUFFER_BINDING = 0x8898;
export const GL_INDEX_ARRAY_BUFFER_BINDING = 0x8899;
export const GL_TEXTURE_COORD_ARRAY_BUFFER_BINDING = 0x889A;
export const GL_EDGE_FLAG_ARRAY_BUFFER_BINDING = 0x889B;
export const GL_SECONDARY_COLOR_ARRAY_BUFFER_BINDING = 0x889C;
export const GL_FOG_COORDINATE_ARRAY_BUFFER_BINDING = 0x889D;
export const GL_WEIGHT_ARRAY_BUFFER_BINDING = 0x889E;
export const GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING = 0x889F;
export const GL_READ_ONLY = 0x88B8;
export const GL_WRITE_ONLY = 0x88B9;
export const GL_READ_WRITE = 0x88BA;
export const GL_BUFFER_ACCESS = 0x88BB;
export const GL_BUFFER_MAPPED = 0x88BC;
export const GL_BUFFER_MAP_POINTER = 0x88BD;
export const GL_STREAM_DRAW = 0x88E0;
export const GL_STREAM_READ = 0x88E1;
export const GL_STREAM_COPY = 0x88E2;
export const GL_STATIC_DRAW = 0x88E4;
export const GL_STATIC_READ = 0x88E5;
export const GL_STATIC_COPY = 0x88E6;
export const GL_DYNAMIC_DRAW = 0x88E8;
export const GL_DYNAMIC_READ = 0x88E9;
export const GL_DYNAMIC_COPY = 0x88EA;
export const GL_SAMPLES_PASSED = 0x8914;

// OpenGL Core 2.0 Constants

export const GL_BLEND_EQUATION_RGB = 0x8009;
export const GL_VERTEX_ATTRIB_ARRAY_ENABLED = 0x8622;
export const GL_VERTEX_ATTRIB_ARRAY_SIZE = 0x8623;
export const GL_VERTEX_ATTRIB_ARRAY_STRIDE = 0x8624;
export const GL_VERTEX_ATTRIB_ARRAY_TYPE = 0x8625;
export const GL_CURRENT_VERTEX_ATTRIB = 0x8626;
export const GL_VERTEX_PROGRAM_POINT_SIZE = 0x8642;
export const GL_VERTEX_PROGRAM_TWO_SIDE = 0x8643;
export const GL_VERTEX_ATTRIB_ARRAY_POINTER = 0x8645;
export const GL_STENCIL_BACK_FUNC = 0x8800;
export const GL_STENCIL_BACK_FAIL = 0x8801;
export const GL_STENCIL_BACK_PASS_DEPTH_FAIL = 0x8802;
export const GL_STENCIL_BACK_PASS_DEPTH_PASS = 0x8803;
export const GL_MAX_DRAW_BUFFERS = 0x8824;
export const GL_DRAW_BUFFER0 = 0x8825;
export const GL_DRAW_BUFFER1 = 0x8826;
export const GL_DRAW_BUFFER2 = 0x8827;
export const GL_DRAW_BUFFER3 = 0x8828;
export const GL_DRAW_BUFFER4 = 0x8829;
export const GL_DRAW_BUFFER5 = 0x882A;
export const GL_DRAW_BUFFER6 = 0x882B;
export const GL_DRAW_BUFFER7 = 0x882C;
export const GL_DRAW_BUFFER8 = 0x882D;
export const GL_DRAW_BUFFER9 = 0x882E;
export const GL_DRAW_BUFFER10 = 0x882F;
export const GL_DRAW_BUFFER11 = 0x8830;
export const GL_DRAW_BUFFER12 = 0x8831;
export const GL_DRAW_BUFFER13 = 0x8832;
export const GL_DRAW_BUFFER14 = 0x8833;
export const GL_DRAW_BUFFER15 = 0x8834;
export const GL_BLEND_EQUATION_ALPHA = 0x883D;
export const GL_POINT_SPRITE = 0x8861;
export const GL_COORD_REPLACE = 0x8862;
export const GL_MAX_VERTEX_ATTRIBS = 0x8869;
export const GL_VERTEX_ATTRIB_ARRAY_NORMALIZED = 0x886A;
export const GL_MAX_TEXTURE_COORDS = 0x8871;
export const GL_MAX_TEXTURE_IMAGE_UNITS = 0x8872;
export const GL_FRAGMENT_SHADER = 0x8B30;
export const GL_VERTEX_SHADER = 0x8B31;
export const GL_MAX_FRAGMENT_UNIFORM_COMPONENTS = 0x8B49;
export const GL_MAX_VERTEX_UNIFORM_COMPONENTS = 0x8B4A;
export const GL_MAX_VARYING_FLOATS = 0x8B4B;
export const GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS = 0x8B4C;
export const GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS = 0x8B4D;
export const GL_SHADER_TYPE = 0x8B4F;
export const GL_FLOAT_VEC2 = 0x8B50;
export const GL_FLOAT_VEC3 = 0x8B51;
export const GL_FLOAT_VEC4 = 0x8B52;
export const GL_INT_VEC2 = 0x8B53;
export const GL_INT_VEC3 = 0x8B54;
export const GL_INT_VEC4 = 0x8B55;
export const GL_BOOL = 0x8B56;
export const GL_BOOL_VEC2 = 0x8B57;
export const GL_BOOL_VEC3 = 0x8B58;
export const GL_BOOL_VEC4 = 0x8B59;
export const GL_FLOAT_MAT2 = 0x8B5A;
export const GL_FLOAT_MAT3 = 0x8B5B;
export const GL_FLOAT_MAT4 = 0x8B5C;
export const GL_SAMPLER_1D = 0x8B5D;
export const GL_SAMPLER_2D = 0x8B5E;
export const GL_SAMPLER_3D = 0x8B5F;
export const GL_SAMPLER_CUBE = 0x8B60;
export const GL_SAMPLER_1D_SHADOW = 0x8B61;
export const GL_SAMPLER_2D_SHADOW = 0x8B62;
export const GL_DELETE_STATUS = 0x8B80;
export const GL_COMPILE_STATUS = 0x8B81;
export const GL_LINK_STATUS = 0x8B82;
export const GL_VALIDATE_STATUS = 0x8B83;
export const GL_INFO_LOG_LENGTH = 0x8B84;
export const GL_ATTACHED_SHADERS = 0x8B85;
export const GL_ACTIVE_UNIFORMS = 0x8B86;
export const GL_ACTIVE_UNIFORM_MAX_LENGTH = 0x8B87;
export const GL_SHADER_SOURCE_LENGTH = 0x8B88;
export const GL_ACTIVE_ATTRIBUTES = 0x8B89;
export const GL_ACTIVE_ATTRIBUTE_MAX_LENGTH = 0x8B8A;
export const GL_FRAGMENT_SHADER_DERIVATIVE_HINT = 0x8B8B;
export const GL_SHADING_LANGUAGE_VERSION = 0x8B8C;
export const GL_CURRENT_PROGRAM = 0x8B8D;
export const GL_POINT_SPRITE_COORD_ORIGIN = 0x8CA0;
export const GL_LOWER_LEFT = 0x8CA1;
export const GL_UPPER_LEFT = 0x8CA2;
export const GL_STENCIL_BACK_REF = 0x8CA3;
export const GL_STENCIL_BACK_VALUE_MASK = 0x8CA4;
export const GL_STENCIL_BACK_WRITEMASK = 0x8CA5;

// OpenGL Core 2.1 Constants

export const GL_CURRENT_RASTER_SECONDARY_COLOR = 0x845F;
export const GL_PIXEL_PACK_BUFFER = 0x88EB;
export const GL_PIXEL_UNPACK_BUFFER = 0x88EC;
export const GL_PIXEL_PACK_BUFFER_BINDING = 0x88ED;
export const GL_PIXEL_UNPACK_BUFFER_BINDING = 0x88EF;
export const GL_FLOAT_MAT2x3 = 0x8B65;
export const GL_FLOAT_MAT2x4 = 0x8B66;
export const GL_FLOAT_MAT3x2 = 0x8B67;
export const GL_FLOAT_MAT3x4 = 0x8B68;
export const GL_FLOAT_MAT4x2 = 0x8B69;
export const GL_FLOAT_MAT4x3 = 0x8B6A;
export const GL_SRGB = 0x8C40;
export const GL_SRGB8 = 0x8C41;
export const GL_SRGB_ALPHA = 0x8C42;
export const GL_SRGB8_ALPHA8 = 0x8C43;
export const GL_SLUMINANCE_ALPHA = 0x8C44;
export const GL_SLUMINANCE8_ALPHA8 = 0x8C45;
export const GL_SLUMINANCE = 0x8C46;
export const GL_SLUMINANCE8 = 0x8C47;
export const GL_COMPRESSED_SRGB = 0x8C48;
export const GL_COMPRESSED_SRGB_ALPHA = 0x8C49;
export const GL_COMPRESSED_SLUMINANCE = 0x8C4A;
export const GL_COMPRESSED_SLUMINANCE_ALPHA = 0x8C4B;

// OpenGL Core 3.0 Constants

export const GL_CLIP_DISTANCE0 = 0x3000;
export const GL_CLIP_DISTANCE1 = 0x3001;
export const GL_CLIP_DISTANCE2 = 0x3002;
export const GL_CLIP_DISTANCE3 = 0x3003;
export const GL_CLIP_DISTANCE4 = 0x3004;
export const GL_CLIP_DISTANCE5 = 0x3005;
export const GL_COMPARE_REF_TO_TEXTURE = 0x884E;
export const GL_MAX_CLIP_DISTANCES = 0x0D32;
export const GL_MAX_VARYING_COMPONENTS = 0x8B4B;
export const GL_CONTEXT_FLAG_FORWARD_COMPATIBLE_BIT = 0x0001;
export const GL_MAJOR_VERSION = 0x821B;
export const GL_MINOR_VERSION = 0x821C;
export const GL_NUM_EXTENSIONS = 0x821D;
export const GL_CONTEXT_FLAGS = 0x821E;
export const GL_DEPTH_BUFFER = 0x8223;
export const GL_STENCIL_BUFFER = 0x8224;
export const GL_RGBA32F = 0x8814;
export const GL_RGB32F = 0x8815;
export const GL_RGBA16F = 0x881A;
export const GL_RGB16F = 0x881B;
export const GL_VERTEX_ATTRIB_ARRAY_INTEGER = 0x88FD;
export const GL_MAX_ARRAY_TEXTURE_LAYERS = 0x88FF;
export const GL_MIN_PROGRAM_TEXEL_OFFSET = 0x8904;
export const GL_MAX_PROGRAM_TEXEL_OFFSET = 0x8905;
export const GL_CLAMP_VERTEX_COLOR = 0x891A;
export const GL_CLAMP_FRAGMENT_COLOR = 0x891B;
export const GL_CLAMP_READ_COLOR = 0x891C;
export const GL_FIXED_ONLY = 0x891D;
export const GL_TEXTURE_RED_TYPE = 0x8C10;
export const GL_TEXTURE_GREEN_TYPE = 0x8C11;
export const GL_TEXTURE_BLUE_TYPE = 0x8C12;
export const GL_TEXTURE_ALPHA_TYPE = 0x8C13;
export const GL_TEXTURE_LUMINANCE_TYPE = 0x8C14;
export const GL_TEXTURE_INTENSITY_TYPE = 0x8C15;
export const GL_TEXTURE_DEPTH_TYPE = 0x8C16;
export const GL_TEXTURE_1D_ARRAY = 0x8C18;
export const GL_PROXY_TEXTURE_1D_ARRAY = 0x8C19;
export const GL_TEXTURE_2D_ARRAY = 0x8C1A;
export const GL_PROXY_TEXTURE_2D_ARRAY = 0x8C1B;
export const GL_TEXTURE_BINDING_1D_ARRAY = 0x8C1C;
export const GL_TEXTURE_BINDING_2D_ARRAY = 0x8C1D;
export const GL_R11F_G11F_B10F = 0x8C3A;
export const GL_UNSIGNED_INT_10F_11F_11F_REV = 0x8C3B;
export const GL_RGB9_E5 = 0x8C3D;
export const GL_UNSIGNED_INT_5_9_9_9_REV = 0x8C3E;
export const GL_TEXTURE_SHARED_SIZE = 0x8C3F;
export const GL_TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH = 0x8C76;
export const GL_TRANSFORM_FEEDBACK_BUFFER_MODE = 0x8C7F;
export const GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS = 0x8C80;
export const GL_TRANSFORM_FEEDBACK_VARYINGS = 0x8C83;
export const GL_TRANSFORM_FEEDBACK_BUFFER_START = 0x8C84;
export const GL_TRANSFORM_FEEDBACK_BUFFER_SIZE = 0x8C85;
export const GL_PRIMITIVES_GENERATED = 0x8C87;
export const GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN = 0x8C88;
export const GL_RASTERIZER_DISCARD = 0x8C89;
export const GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS = 0x8C8A;
export const GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS = 0x8C8B;
export const GL_INTERLEAVED_ATTRIBS = 0x8C8C;
export const GL_SEPARATE_ATTRIBS = 0x8C8D;
export const GL_TRANSFORM_FEEDBACK_BUFFER = 0x8C8E;
export const GL_TRANSFORM_FEEDBACK_BUFFER_BINDING = 0x8C8F;
export const GL_RGBA32UI = 0x8D70;
export const GL_RGB32UI = 0x8D71;
export const GL_RGBA16UI = 0x8D76;
export const GL_RGB16UI = 0x8D77;
export const GL_RGBA8UI = 0x8D7C;
export const GL_RGB8UI = 0x8D7D;
export const GL_RGBA32I = 0x8D82;
export const GL_RGB32I = 0x8D83;
export const GL_RGBA16I = 0x8D88;
export const GL_RGB16I = 0x8D89;
export const GL_RGBA8I = 0x8D8E;
export const GL_RGB8I = 0x8D8F;
export const GL_RED_INTEGER = 0x8D94;
export const GL_GREEN_INTEGER = 0x8D95;
export const GL_BLUE_INTEGER = 0x8D96;
export const GL_ALPHA_INTEGER = 0x8D97;
export const GL_RGB_INTEGER = 0x8D98;
export const GL_RGBA_INTEGER = 0x8D99;
export const GL_BGR_INTEGER = 0x8D9A;
export const GL_BGRA_INTEGER = 0x8D9B;
export const GL_SAMPLER_1D_ARRAY = 0x8DC0;
export const GL_SAMPLER_2D_ARRAY = 0x8DC1;
export const GL_SAMPLER_1D_ARRAY_SHADOW = 0x8DC3;
export const GL_SAMPLER_2D_ARRAY_SHADOW = 0x8DC4;
export const GL_SAMPLER_CUBE_SHADOW = 0x8DC5;
export const GL_UNSIGNED_INT_VEC2 = 0x8DC6;
export const GL_UNSIGNED_INT_VEC3 = 0x8DC7;
export const GL_UNSIGNED_INT_VEC4 = 0x8DC8;
export const GL_INT_SAMPLER_1D = 0x8DC9;
export const GL_INT_SAMPLER_2D = 0x8DCA;
export const GL_INT_SAMPLER_3D = 0x8DCB;
export const GL_INT_SAMPLER_CUBE = 0x8DCC;
export const GL_INT_SAMPLER_1D_ARRAY = 0x8DCE;
export const GL_INT_SAMPLER_2D_ARRAY = 0x8DCF;
export const GL_UNSIGNED_INT_SAMPLER_1D = 0x8DD1;
export const GL_UNSIGNED_INT_SAMPLER_2D = 0x8DD2;
export const GL_UNSIGNED_INT_SAMPLER_3D = 0x8DD3;
export const GL_UNSIGNED_INT_SAMPLER_CUBE = 0x8DD4;
export const GL_UNSIGNED_INT_SAMPLER_1D_ARRAY = 0x8DD6;
export const GL_UNSIGNED_INT_SAMPLER_2D_ARRAY = 0x8DD7;
export const GL_QUERY_WAIT = 0x8E13;
export const GL_QUERY_NO_WAIT = 0x8E14;
export const GL_QUERY_BY_REGION_WAIT = 0x8E15;
export const GL_QUERY_BY_REGION_NO_WAIT = 0x8E16;

// OpenGL Core 3.1 Constants

export const GL_TEXTURE_RECTANGLE = 0x84F5;
export const GL_TEXTURE_BINDING_RECTANGLE = 0x84F6;
export const GL_PROXY_TEXTURE_RECTANGLE = 0x84F7;
export const GL_MAX_RECTANGLE_TEXTURE_SIZE = 0x84F8;
export const GL_SAMPLER_2D_RECT = 0x8B63;
export const GL_SAMPLER_2D_RECT_SHADOW = 0x8B64;
export const GL_TEXTURE_BUFFER = 0x8C2A;
export const GL_MAX_TEXTURE_BUFFER_SIZE = 0x8C2B;
export const GL_TEXTURE_BINDING_BUFFER = 0x8C2C;
export const GL_TEXTURE_BUFFER_DATA_STORE_BINDING = 0x8C2D;
export const GL_TEXTURE_BUFFER_FORMAT = 0x8C2E;
export const GL_SAMPLER_BUFFER = 0x8DC2;
export const GL_INT_SAMPLER_2D_RECT = 0x8DCD;
export const GL_INT_SAMPLER_BUFFER = 0x8DD0;
export const GL_UNSIGNED_INT_SAMPLER_2D_RECT = 0x8DD5;
export const GL_UNSIGNED_INT_SAMPLER_BUFFER = 0x8DD8;
export const GL_RED_SNORM = 0x8F90;
export const GL_RG_SNORM = 0x8F91;
export const GL_RGB_SNORM = 0x8F92;
export const GL_RGBA_SNORM = 0x8F93;
export const GL_R8_SNORM = 0x8F94;
export const GL_RG8_SNORM = 0x8F95;
export const GL_RGB8_SNORM = 0x8F96;
export const GL_RGBA8_SNORM = 0x8F97;
export const GL_R16_SNORM = 0x8F98;
export const GL_RG16_SNORM = 0x8F99;
export const GL_RGB16_SNORM = 0x8F9A;
export const GL_RGBA16_SNORM = 0x8F9B;
export const GL_SIGNED_NORMALIZED = 0x8F9C;
export const GL_PRIMITIVE_RESTART = 0x8F9D;
export const GL_PRIMITIVE_RESTART_INDEX = 0x8F9E;
export const GL_BUFFER_ACCESS_FLAGS = 0x911F;
export const GL_BUFFER_MAP_LENGTH = 0x9120;
export const GL_BUFFER_MAP_OFFSET = 0x9121;

// OpenGL Core 3.2 constants

export const GL_CONTEXT_CORE_PROFILE_BIT = 0x00000001;
export const GL_CONTEXT_COMPATIBILITY_PROFILE_BIT = 0x00000002;
export const GL_LINES_ADJACENCY = 0x000A;
export const GL_LINE_STRIP_ADJACENCY = 0x000B;
export const GL_TRIANGLES_ADJACENCY = 0x000C;
export const GL_TRIANGLE_STRIP_ADJACENCY = 0x000D;
export const GL_PROGRAM_POINT_SIZE = 0x8642;
export const GL_GEOMETRY_VERTICES_OUT = 0x8916;
export const GL_GEOMETRY_INPUT_TYPE = 0x8917;
export const GL_GEOMETRY_OUTPUT_TYPE = 0x8918;
export const GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS = 0x8C29;
export const GL_FRAMEBUFFER_ATTACHMENT_LAYERED = 0x8DA7;
export const GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS = 0x8DA8;
export const GL_GEOMETRY_SHADER = 0x8DD9;
export const GL_MAX_GEOMETRY_UNIFORM_COMPONENTS = 0x8DDF;
export const GL_MAX_GEOMETRY_OUTPUT_VERTICES = 0x8DE0;
export const GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS = 0x8DE1;
export const GL_MAX_VERTEX_OUTPUT_COMPONENTS = 0x9122;
export const GL_MAX_GEOMETRY_INPUT_COMPONENTS = 0x9123;
export const GL_MAX_GEOMETRY_OUTPUT_COMPONENTS = 0x9124;
export const GL_MAX_FRAGMENT_INPUT_COMPONENTS = 0x9125;
export const GL_CONTEXT_PROFILE_MASK = 0x9126;

// OpenGL Core 3.3 constants

export const GL_VERTEX_ATTRIB_ARRAY_DIVISOR = 0x88FE;
export const GL_RGB10_A2UI = 0x906F;

// OpenGL Core 4.0 constants

export const GL_SAMPLE_SHADING = 0x8C36;
export const GL_MIN_SAMPLE_SHADING_VALUE = 0x8C37;
export const GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET = 0x8E5E;
export const GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET = 0x8E5F;
export const GL_MAX_PROGRAM_TEXTURE_GATHER_COMPONENTS = 0x8F9F;
export const GL_TEXTURE_CUBE_MAP_ARRAY = 0x9009;
export const GL_TEXTURE_BINDING_CUBE_MAP_ARRAY = 0x900A;
export const GL_PROXY_TEXTURE_CUBE_MAP_ARRAY = 0x900B;
export const GL_SAMPLER_CUBE_MAP_ARRAY = 0x900C;
export const GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW = 0x900D;
export const GL_INT_SAMPLER_CUBE_MAP_ARRAY = 0x900E;
export const GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY = 0x900F;

// OpenGL Core 4.2 constants

export const GL_TRANSFORM_FEEDBACK_PAUSED = 0x8E23;
export const GL_TRANSFORM_FEEDBACK_ACTIVE = 0x8E24;
export const GL_COMPRESSED_RGBA_BPTC_UNORM = 0x8E8C;
export const GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM = 0x8E8D;
export const GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT = 0x8E8E;
export const GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT = 0x8E8F;
export const GL_COPY_READ_BUFFER_BINDING = 0x8F36;
export const GL_COPY_WRITE_BUFFER_BINDING = 0x8F37;

// OpenGL Core 4.3 constants

export const GL_NUM_SHADING_LANGUAGE_VERSIONS = 0x82E9;
export const GL_VERTEX_ATTRIB_ARRAY_LONG = 0x874E;

// OpenGL Core 4.4 constants

export const GL_PRIMITIVE_RESTART_FOR_PATCHES_SUPPORTED = 0x8221;
export const GL_MAX_VERTEX_ATTRIB_STRIDE = 0x82E5;
export const GL_TEXTURE_BUFFER_BINDING = 0x8C2A;

// OpenGL Core 4.5 constants

export const GL_CONTEXT_FLAG_ROBUST_ACCESS_BIT = 0x00000004;

// OpenGL Core 4.6 constants

export const GL_CONTEXT_FLAG_NO_ERROR_BIT = 0x00000008;
export const GL_PARAMETER_BUFFER = 0x80EE;
export const GL_PARAMETER_BUFFER_BINDING = 0x80EF;
export const GL_TRANSFORM_FEEDBACK_OVERFLOW = 0x82EC;
export const GL_TRANSFORM_FEEDBACK_STREAM_OVERFLOW = 0x82ED;
export const GL_VERTICES_SUBMITTED = 0x82EE;
export const GL_PRIMITIVES_SUBMITTED = 0x82EF;
export const GL_VERTEX_SHADER_INVOCATIONS = 0x82F0;
export const GL_TESS_CONTROL_SHADER_PATCHES = 0x82F1;
export const GL_TESS_EVALUATION_SHADER_INVOCATIONS = 0x82F2;
export const GL_GEOMETRY_SHADER_PRIMITIVES_EMITTED = 0x82F3;
export const GL_FRAGMENT_SHADER_INVOCATIONS = 0x82F4;
export const GL_COMPUTE_SHADER_INVOCATIONS = 0x82F5;
export const GL_CLIPPING_INPUT_PRIMITIVES = 0x82F6;
export const GL_CLIPPING_OUTPUT_PRIMITIVES = 0x82F7;
export const GL_TEXTURE_MAX_ANISOTROPY = 0x84FE;
export const GL_MAX_TEXTURE_MAX_ANISOTROPY = 0x84FF;
export const GL_POLYGON_OFFSET_CLAMP = 0x8E1B;
export const GL_SHADER_BINARY_FORMAT_SPIR_V = 0x9551;
export const GL_SPIR_V_BINARY = 0x9552;
export const GL_SPIR_V_EXTENSIONS = 0x9553;
export const GL_NUM_SPIR_V_EXTENSIONS = 0x9554;

// OpenGL Core 1.1 functions

export function glAccum(op: number, value: number): void;
export function glAlphaFunc(func: number, ref: number): void;
export function glAreTexturesResident(n: number, textures: Uint32Array, residences: boolean[]): boolean;
export function glArrayElement(i: number): void;
export function glBegin(mode: number): void;
export function glBindTexture(target: number, texture: number): void;
export function glBitmap(width: number, height: number, xorig: number, yorig: number, xmove: number, ymove: number, bitmap: Uint8Array): void;
export function glBlendFunc(sfactor: number, dfactor: number): void;
export function glCallList(list: number): void;
export function glCallLists(n: number, type: typeof GL_BYTE | typeof GL_2_BYTES | typeof GL_3_BYTES | typeof GL_4_BYTES, lists: Int8Array): void;
export function glCallLists(n: number, type: typeof GL_UNSIGNED_BYTE, lists: Uint8Array): void;
export function glCallLists(n: number, type: typeof GL_UNSIGNED_SHORT, lists: Uint16Array): void;
export function glCallLists(n: number, type: typeof GL_UNSIGNED_INT, lists: Uint32Array): void;
export function glCallLists(n: number, type: typeof GL_FLOAT, lists: Float32Array): void;
export function glClear(mask: number): void;
export function glClearAccum(red: number, green: number, blue: number, alpha: number): void;
export function glClearColor(red: number, green: number, blue: number, alpha: number): void;
export function glClearDepth(depth: number): void;
export function glClearIndex(index: number): void;
export function glClearStencil(s: number): void;
export function glClipPlane(plane: number, equation: Float64Array): void;
export function glColor3b(red: number, green: number, blue: number): void;
export function glColor3bv(v: Int8Array): void;
export function glColor3d(red: number, green: number, blue: number): void;
export function glColor3dv(v: Float64Array): void;
export function glColor3f(red: number, green: number, blue: number): void;
export function glColor3fv(v: Float32Array): void;
export function glColor3i(red: number, green: number, blue: number): void;
export function glColor3iv(v: Int32Array): void;
export function glColor3s(red: number, green: number, blue: number): void;
export function glColor3sv(v: Int16Array): void;
export function glColor3ub(red: number, green: number, blue: number): void;
export function glColor3ubv(v: Uint8Array): void;
export function glColor3ui(red: number, green: number, blue: number): void;
export function glColor3uiv(v: Uint32Array): void;
export function glColor3us(red: number, green: number, blue: number): void;
export function glColor3usv(v: Uint16Array): void;
export function glColor4b(red: number, green: number, blue: number, alpha: number): void;
export function glColor4bv(v: Int8Array): void;
export function glColor4d(red: number, green: number, blue: number, alpha: number): void;
export function glColor4dv(v: Float64Array): void;
export function glColor4f(red: number, green: number, blue: number, alpha: number): void;
export function glColor4fv(v: Float32Array): void;
export function glColor4i(red: number, green: number, blue: number, alpha: number): void;
export function glColor4iv(v: Int32Array): void;
export function glColor4s(red: number, green: number, blue: number, alpha: number): void;
export function glColor4sv(v: Int16Array): void;
export function glColor4ub(red: number, green: number, blue: number, alpha: number): void;
export function glColor4ubv(v: Uint8Array): void;
export function glColor4ui(red: number, green: number, blue: number, alpha: number): void;
export function glColor4uiv(v: Uint32Array): void;
export function glColor4us(red: number, green: number, blue: number, alpha: number): void;
export function glColor4usv(v: Uint16Array): void;
export function glColorMask(red: boolean, green: boolean, blue: boolean, alpha: boolean): void;
export function glColorMaterial(face: number, mode: number): void;
export function glColorPointer(size: number, type: typeof GL_BYTE, stride: number, pointer: Int8Array): void;
export function glColorPointer(size: number, type: typeof GL_UNSIGNED_BYTE, stride: number, pointer: Uint8Array): void;
export function glColorPointer(size: number, type: typeof GL_SHORT, stride: number, pointer: Int16Array): void;
export function glColorPointer(size: number, type: typeof GL_UNSIGNED_SHORT, stride: number, pointer: Uint16Array): void;
export function glColorPointer(size: number, type: typeof GL_INT, stride: number, pointer: Int32Array): void;
export function glColorPointer(size: number, type: typeof GL_UNSIGNED_INT, stride: number, pointer: Uint32Array): void;
export function glColorPointer(size: number, type: typeof GL_FLOAT, stride: number, pointer: Float32Array): void;
export function glColorPointer(size: number, type: typeof GL_DOUBLE, stride: number, pointer: Float64Array): void;
export function glCopyPixels(x: number, y: number, width: number, height: number, type: number): void;
export function glCopyTexImage1D(target: number, level: number, internalFormat: number, x: number, y: number, width: number, border: number): void;
export function glCopyTexImage2D(target: number, level: number, internalFormat: number, x: number, y: number, width: number, height: number, border: number): void;
export function glCopyTexSubImage1D(target: number, level: number, xoffset: number, x: number, y: number, width: number): void;
export function glCopyTexSubImage2D(target: number, level: number, xoffset: number, yoffset: number, x: number, y: number, width: number, height: number): void;
export function glCullFace(mode: number): void;
export function glDeleteLists(list: number, range: number): void;
export function glDeleteTextures(n: number, textures: Uint32Array): void;
export function glDepthFunc(func: number): void;
export function glDepthMask(flag: boolean): void;
export function glDepthRange(zNear: number, zFar: number): void;
export function glDisable(cap: number): void;
export function glDisableClientState(array: number): void;
export function glDrawArrays(mode: number, first: number, count: number): void;
export function glDrawBuffer(mode: number): void;
export function glDrawElements(mode: number, count: number, type: number, elements: number): void;
export function glDrawPixels(
    width: number,
    height: number,
    format: number,
    type: typeof GL_UNSIGNED_BYTE
        | typeof GL_UNSIGNED_BYTE_3_3_2
        | typeof GL_UNSIGNED_BYTE_2_3_3_REV,
    data: Uint8Array): void;
export function glDrawPixels(width: number, height: number, format: number, type: typeof GL_BYTE, data: Int8Array): void;
export function glDrawPixels(
    width: number,
    height: number,
    format: number,
    type: typeof GL_UNSIGNED_SHORT
        | typeof GL_UNSIGNED_SHORT_5_6_5
        | typeof GL_UNSIGNED_SHORT_5_6_5_REV
        | typeof GL_UNSIGNED_SHORT_4_4_4_4
        | typeof GL_UNSIGNED_SHORT_4_4_4_4_REV
        | typeof GL_UNSIGNED_SHORT_5_5_5_1
        | typeof GL_UNSIGNED_SHORT_1_5_5_5_REV,
    data: Uint16Array): void;
export function glDrawPixels(width: number, height: number, format: number, type: typeof GL_SHORT, data: Int16Array): void;
export function glDrawPixels(
    width: number,
    height: number,
    format: number,
    type: typeof GL_UNSIGNED_INT
        | typeof GL_UNSIGNED_INT_8_8_8_8
        | typeof GL_UNSIGNED_INT_8_8_8_8_REV
        | typeof GL_UNSIGNED_INT_10_10_10_2
        /* | typeof GL_UNSIGNED_INT_2_10_10_10_REV */,
    data: Uint32Array): void;
export function glDrawPixels(width: number, height: number, format: number, type: typeof GL_INT, data: Int32Array): void;
export function glDrawPixels(width: number, height: number, format: number, type: typeof GL_FLOAT, data: Float32Array): void;
export function glEdgeFlag(flag: boolean): void;
export function glEdgeFlagPointer(stride: number, pointer: Uint8Array): void;
export function glEdgeFlagv(flag: boolean[]): void;
export function glEnable(cap: number): void;
export function glEnableClientState(array: number): void;
export function glEnd(): void;
export function glEndList(): void;
export function glEvalCoord1d(u: number): void;
export function glEvalCoord1dv(u: Float64Array): void;
export function glEvalCoord1f(u: number): void;
export function glEvalCoord1fv(u: Float32Array): void;
export function glEvalCoord2d(u: number, v: number): void;
export function glEvalCoord2dv(u: Float64Array): void;
export function glEvalCoord2f(u: number, v: number): void;
export function glEvalCoord2fv(u: Float32Array): void;
export function glEvalMesh1(mode: number, i1: number, i2: number): void;
export function glEvalMesh2(mode: number, i1: number, i2: number, j1: number, j2: number): void;
export function glEvalPoint1(i: number): void;
export function glEvalPoint2(i: number, j: number): void;
export function glFeedbackBuffer(size: number, type: number, buffer: Float32Array): void;
export function glFinish(): void;
export function glFlush(): void;
export function glFogf(pname: number, param: number): void;
export function glFogfv(pname: number, params: Float32Array): void;
export function glFogi(pname: number, param: number): void;
export function glFogiv(pname: number, params: Int32Array): void;
export function glFrontFace(mode: number): void;
export function glFrustum(left: number, right: number, bottom: number, top: number, zNear: number, zFar: number): void;
export function glGenLists(range: number): number;
export function glGenTextures(n: number, textures: Uint32Array): void;
export function glGetBooleanv(pname: number, params: boolean[]): void;
export function glGetClipPlane(plane: number, equation: Float32Array): void;
export function glGetDoublev(pname: number, params: Float64Array): void;
export function glGetError(): number;
export function glGetFloatv(pname: number, params: Float32Array): void;
export function glGetIntegerv(pname: number, params: Int32Array): void;
export function glGetLightfv(light: number, pname: number, params: Float32Array): void;
export function glGetLightiv(light: number, pname: number, params: Int32Array): void;
export function glGetMapdv(target: number, query: number, v: Float64Array): void;
export function glGetMapfv(target: number, query: number, v: Float32Array): void;
export function glGetMapiv(target: number, query: number, v: Int32Array): void;
export function glGetMaterialfv(face: number, pname: number, params: Float32Array): void;
export function glGetMaterialiv(face: number, pname: number, params: Int32Array): void;
export function glGetPixelMapfv(map: number, values: Float32Array): void;
export function glGetPixelMapuiv(map: number, values: Uint32Array): void;
export function glGetPixelMapusv(map: number, values: Uint16Array): void;
export function glGetPointerv(pname: number, params: Uint8Array): void;
export function glGetPolygonStipple(mask: Uint8Array): void;
export function glGetString(name: number): string;
export function glGetTexEnvfv(target: number, pname: number, params: Float32Array): void;
export function glGetTexEnviv(target: number, pname: number, params: Int32Array): void;
export function glGetTexGendv(coord: number, pname: number, params: Float64Array): void;
export function glGetTexGenfv(coord: number, pname: number, params: Float32Array): void;
export function glGetTexGeniv(coord: number, pname: number, params: Int32Array): void;
export function glGetTexImage(
    target: number,
    level: number,
    format: number,
    type: typeof GL_UNSIGNED_BYTE
        | typeof GL_UNSIGNED_BYTE_3_3_2
        | typeof GL_UNSIGNED_BYTE_2_3_3_REV,
    data: Uint8Array): void;
export function glGetTexImage(width: number, height: number, format: number, type: typeof GL_BYTE, data: Int8Array): void;
export function glGetTexImage(
    target: number,
    level: number,
    format: number,
    type: typeof GL_UNSIGNED_SHORT
        | typeof GL_UNSIGNED_SHORT_5_6_5
        | typeof GL_UNSIGNED_SHORT_5_6_5_REV
        | typeof GL_UNSIGNED_SHORT_4_4_4_4
        | typeof GL_UNSIGNED_SHORT_4_4_4_4_REV
        | typeof GL_UNSIGNED_SHORT_5_5_5_1
        | typeof GL_UNSIGNED_SHORT_1_5_5_5_REV,
    data: Uint16Array): void;
export function glGetTexImage(width: number, height: number, format: number, type: typeof GL_SHORT, data: Int16Array): void;
export function glGetTexImage(
    target: number,
    level: number,
    format: number,
    type: typeof GL_UNSIGNED_INT
        | typeof GL_UNSIGNED_INT_8_8_8_8
        | typeof GL_UNSIGNED_INT_8_8_8_8_REV
        | typeof GL_UNSIGNED_INT_10_10_10_2
        /* | typeof GL_UNSIGNED_INT_2_10_10_10_REV */,
    data: Uint32Array): void;
export function glGetTexImage(target: number, level: number, format: number, type: typeof GL_INT, data: Int32Array): void;
export function glGetTexImage(target: number, level: number, format: number, type: typeof GL_FLOAT, data: Float32Array): void;
export function glGetTexLevelParameterfv(target: number, level: number, pname: number, params: Float32Array): void;
export function glGetTexLevelParameteriv(target: number, level: number, pname: number, params: Int32Array): void;
export function glGetTexParameterfv(target: number, pname: number, params: Float32Array): void;
export function glGetTexParameteriv(target: number, pname: number, params: Int32Array): void;
export function glHint(target: number, mode: number): void;
export function glIndexMask(mask: number): void;
export function glIndexPointer(type: number, stride: number, pointer: Uint8Array): void;
export function glIndexd(c: number): void;
export function glIndexdv(c: Float64Array): void;
export function glIndexf(c: number): void;
export function glIndexfv(c: Float32Array): void;
export function glIndexi(c: number): void;
export function glIndexiv(c: Int32Array): void;
export function glIndexs(c: number): void;
export function glIndexsv(c: Int16Array): void;
export function glIndexub(c: number): void;
export function glIndexubv(c: Uint8Array): void;
export function glInitNames(): void;
export function glInterleavedArrays(format: number, stride: number, pointer: Uint8Array): void;
export function glIsEnabled(cap: number): boolean;
export function glIsList(list: number): boolean;
export function glIsTexture(texture: number): boolean;
export function glLightModelf(pname: number, param: number): void;
export function glLightModelfv(pname: number, params: Float32Array): void;
export function glLightModeli(pname: number, param: number): void;
export function glLightModeliv(pname: number, params: Int32Array): void;
export function glLightf(light: number, pname: number, param: number): void;
export function glLightfv(light: number, pname: number, params: Float32Array): void;
export function glLighti(light: number, pname: number, param: number): void;
export function glLightiv(light: number, pname: number, params: Int32Array): void;
export function glLineStipple(factor: number, pattern: number): void;
export function glLineWidth(width: number): void;
export function glListBase(base: number): void;
export function glLoadIdentity(): void;
export function glLoadMatrixd(m: Float64Array): void;
export function glLoadMatrixf(m: Float32Array): void;
export function glLoadName(name: number): void;
export function glLogicOp(opcode: number): void;
export function glMap1d(target: number, u1: number, u2: number, stride: number, order: number, points: Float64Array): void;
export function glMap1f(target: number, u1: number, u2: number, stride: number, order: number, points: Float32Array): void;
export function glMap2d(target: number, u1: number, u2: number, ustride: number, uorder: number, v1: number, v2: number, vstride: number, vorder: number, points: Float64Array): void;
export function glMap2f(target: number, u1: number, u2: number, ustride: number, uorder: number, v1: number, v2: number, vstride: number, vorder: number, points: Float32Array): void;
export function glMapGrid1d(un: number, u1: number, u2: number): void;
export function glMapGrid1f(un: number, u1: number, u2: number): void;
export function glMapGrid2d(un: number, u1: number, u2: number, vn: number, v1: number, v2: number): void;
export function glMapGrid2f(un: number, u1: number, u2: number, vn: number, v1: number, v2: number): void;
export function glMaterialf(face: number, pname: number, param: number): void;
export function glMaterialfv(face: number, pname: number, params: Float32Array): void;
export function glMateriali(face: number, pname: number, param: number): void;
export function glMaterialiv(face: number, pname: number, params: Int32Array): void;
export function glMatrixMode(mode: number): void;
export function glMultMatrixd(m: Float64Array): void;
export function glMultMatrixf(m: Float32Array): void;
export function glNewList(list: number, mode: number): void;
export function glNormal3b(nx: number, ny: number, nz: number): void;
export function glNormal3bv(v: Int8Array): void;
export function glNormal3d(nx: number, ny: number, nz: number): void;
export function glNormal3dv(v: Float64Array): void;
export function glNormal3f(nx: number, ny: number, nz: number): void;
export function glNormal3fv(v: Float32Array): void;
export function glNormal3i(nx: number, ny: number, nz: number): void;
export function glNormal3iv(v: Int32Array): void;
export function glNormal3s(nx: number, ny: number, nz: number): void;
export function glNormal3sv(v: Int16Array): void;
export function glNormalPointer(type: typeof GL_BYTE, stride: number, pointer: Int8Array): void;
export function glNormalPointer(type: typeof GL_SHORT, stride: number, pointer: Int16Array): void;
export function glNormalPointer(type: typeof GL_INT, stride: number, pointer: Int32Array): void;
export function glNormalPointer(type: typeof GL_FLOAT, stride: number, pointer: Float32Array): void;
export function glNormalPointer(type: typeof GL_DOUBLE, stride: number, pointer: Float64Array): void;
export function glOrtho(left: number, right: number, bottom: number, top: number, zNear: number, zFar: number): void;
export function glPassThrough(token: number): void;
export function glPixelMapfv(map: number, mapsize: number, values: Float32Array): void;
export function glPixelMapuiv(map: number, mapsize: number, values: Uint32Array): void;
export function glPixelMapusv(map: number, mapsize: number, values: Uint16Array): void;
export function glPixelStoref(pname: number, param: number): void;
export function glPixelStorei(pname: number, param: number): void;
export function glPixelTransferf(pname: number, param: number): void;
export function glPixelTransferi(pname: number, param: number): void;
export function glPixelZoom(xfactor: number, yfactor: number): void;
export function glPointSize(size: number): void;
export function glPolygonMode(face: number, mode: number): void;
export function glPolygonOffset(factor: number, units: number): void;
export function glPolygonStipple(mask: Uint8Array): void;
export function glPopAttrib(): void;
export function glPopClientAttrib(): void;
export function glPopMatrix(): void;
export function glPopName(): void;
export function glPrioritizeTextures(n: number, textures: Uint32Array, priorities: Float32Array): void;
export function glPushAttrib(mask: number): void;
export function glPushClientAttrib(mask: number): void;
export function glPushMatrix(): void;
export function glPushName(name: number): void;
export function glRasterPos2d(x: number, y: number): void;
export function glRasterPos2dv(v: Float64Array): void;
export function glRasterPos2f(x: number, y: number): void;
export function glRasterPos2fv(v: Float32Array): void;
export function glRasterPos2i(x: number, y: number): void;
export function glRasterPos2iv(v: Int32Array): void;
export function glRasterPos2s(x: number, y: number): void;
export function glRasterPos2sv(v: Int16Array): void;
export function glRasterPos3d(x: number, y: number, z: number): void;
export function glRasterPos3dv(v: Float64Array): void;
export function glRasterPos3f(x: number, y: number, z: number): void;
export function glRasterPos3fv(v: Float32Array): void;
export function glRasterPos3i(x: number, y: number, z: number): void;
export function glRasterPos3iv(v: Int32Array): void;
export function glRasterPos3s(x: number, y: number, z: number): void;
export function glRasterPos3sv(v: Int16Array): void;
export function glRasterPos4d(x: number, y: number, z: number, w: number): void;
export function glRasterPos4dv(v: Float64Array): void;
export function glRasterPos4f(x: number, y: number, z: number, w: number): void;
export function glRasterPos4fv(v: Float32Array): void;
export function glRasterPos4i(x: number, y: number, z: number, w: number): void;
export function glRasterPos4iv(v: Int32Array): void;
export function glRasterPos4s(x: number, y: number, z: number, w: number): void;
export function glRasterPos4sv(v: Int16Array): void;
export function glReadBuffer(mode: number): void;
export function glReadPixels(
    x: number,
    y: number,
    width: number,
    height: number,
    format: number,
    type: typeof GL_UNSIGNED_BYTE
        | typeof GL_UNSIGNED_BYTE_3_3_2
        | typeof GL_UNSIGNED_BYTE_2_3_3_REV,
    data: Uint8Array): void;
export function glReadPixels(x: number, y: number, width: number, height: number, format: number, type: typeof GL_BYTE, data: Int8Array): void;
export function glReadPixels(
    x: number,
    y: number,
    width: number,
    height: number,
    format: number,
    type: typeof GL_UNSIGNED_SHORT
        | typeof GL_UNSIGNED_SHORT_5_6_5
        | typeof GL_UNSIGNED_SHORT_5_6_5_REV
        | typeof GL_UNSIGNED_SHORT_4_4_4_4
        | typeof GL_UNSIGNED_SHORT_4_4_4_4_REV
        | typeof GL_UNSIGNED_SHORT_5_5_5_1
        | typeof GL_UNSIGNED_SHORT_1_5_5_5_REV,
    data: Uint16Array): void;
export function glReadPixels(x: number, y: number, width: number, height: number, format: number, type: typeof GL_SHORT, data: Int16Array): void;
export function glReadPixels(
    x: number,
    y: number,
    width: number,
    height: number,
    format: number,
    type: typeof GL_UNSIGNED_INT
        | typeof GL_UNSIGNED_INT_8_8_8_8
        | typeof GL_UNSIGNED_INT_8_8_8_8_REV
        | typeof GL_UNSIGNED_INT_10_10_10_2
        /* | typeof GL_UNSIGNED_INT_2_10_10_10_REV */,
    data: Uint32Array): void;
export function glReadPixels(x: number, y: number, width: number, height: number, format: number, type: typeof GL_INT, data: Int32Array): void;
export function glReadPixels(x: number, y: number, width: number, height: number, format: number, type: typeof GL_FLOAT, data: Float32Array): void;
export function glRectd(x1: number, y1: number, x2: number, y2: number): void;
export function glRectdv(v1: Float64Array, v2: Float64Array): void;
export function glRectf(x1: number, y1: number, x2: number, y2: number): void;
export function glRectfv(v1: Float32Array, v2: Float32Array): void;
export function glRecti(x1: number, y1: number, x2: number, y2: number): void;
export function glRectiv(v1: Int32Array, v2: Int32Array): void;
export function glRects(x1: number, y1: number, x2: number, y2: number): void;
export function glRectsv(v1: Int16Array, v2: Int16Array): void;
export function glRenderMode(mode: number): number;
export function glRotated(angle: number, x: number, y: number, z: number): void;
export function glRotatef(angle: number, x: number, y: number, z: number): void;
export function glScaled(x: number, y: number, z: number): void;
export function glScalef(x: number, y: number, z: number): void;
export function glScissor(x: number, y: number, width: number, height: number): void;
export function glSelectBuffer(size: number, buffer: Uint32Array): void;
export function glShadeModel(mode: number): void;
export function glStencilFunc(func: number, ref: number, mask: number): void;
export function glStencilMask(mask: number): void;
export function glStencilOp(fail: number, zfail: number, zpass: number): void;
export function glTexCoord1d(s: number): void;
export function glTexCoord1dv(v: Float64Array): void;
export function glTexCoord1f(s: number): void;
export function glTexCoord1fv(v: Float32Array): void;
export function glTexCoord1i(s: number): void;
export function glTexCoord1iv(v: Int32Array): void;
export function glTexCoord1s(s: number): void;
export function glTexCoord1sv(v: Int16Array): void;
export function glTexCoord2d(s: number, t: number): void;
export function glTexCoord2dv(v: Float64Array): void;
export function glTexCoord2f(s: number, t: number): void;
export function glTexCoord2fv(v: Float32Array): void;
export function glTexCoord2i(s: number, t: number): void;
export function glTexCoord2iv(v: Int32Array): void;
export function glTexCoord2s(s: number, t: number): void;
export function glTexCoord2sv(v: Int16Array): void;
export function glTexCoord3d(s: number, t: number, r: number): void;
export function glTexCoord3dv(v: Float64Array): void;
export function glTexCoord3f(s: number, t: number, r: number): void;
export function glTexCoord3fv(v: Float32Array): void;
export function glTexCoord3i(s: number, t: number, r: number): void;
export function glTexCoord3iv(v: Int32Array): void;
export function glTexCoord3s(s: number, t: number, r: number): void;
export function glTexCoord3sv(v: Int16Array): void;
export function glTexCoord4d(s: number, t: number, r: number, q: number): void;
export function glTexCoord4dv(v: Float64Array): void;
export function glTexCoord4f(s: number, t: number, r: number, q: number): void;
export function glTexCoord4fv(v: Float32Array): void;
export function glTexCoord4i(s: number, t: number, r: number, q: number): void;
export function glTexCoord4iv(v: Int32Array): void;
export function glTexCoord4s(s: number, t: number, r: number, q: number): void;
export function glTexCoord4sv(v: Int16Array): void;
export function glTexCoordPointer(size: number, type: typeof GL_SHORT, stride: number, pointer: Int16Array): void;
export function glTexCoordPointer(size: number, type: typeof GL_INT, stride: number, pointer: Int32Array): void;
export function glTexCoordPointer(size: number, type: typeof GL_FLOAT, stride: number, pointer: Float32Array): void;
export function glTexCoordPointer(size: number, type: typeof GL_DOUBLE, stride: number, pointer: Float64Array): void;
export function glTexEnvf(target: number, pname: number, param: number): void;
export function glTexEnvfv(target: number, pname: number, params: Float32Array): void;
export function glTexEnvi(target: number, pname: number, param: number): void;
export function glTexEnviv(target: number, pname: number, params: Int32Array): void;
export function glTexGend(coord: number, pname: number, param: number): void;
export function glTexGendv(coord: number, pname: number, params: Float64Array): void;
export function glTexGenf(coord: number, pname: number, param: number): void;
export function glTexGenfv(coord: number, pname: number, params: Float32Array): void;
export function glTexGeni(coord: number, pname: number, param: number): void;
export function glTexGeniv(coord: number, pname: number, params: Int32Array): void;
export function glTexImage1D(target: number,
    level: number,
    internalformat: number,
    width: number,
    border: number,
    format: number,
    type: typeof GL_UNSIGNED_BYTE
        | typeof GL_UNSIGNED_BYTE_3_3_2
        | typeof GL_UNSIGNED_BYTE_2_3_3_REV,
    data: Uint8Array): void;
export function glTexImage1D(target: number, level: number, internalformat: number, width: number, format: number, type: typeof GL_BYTE, data: Int8Array): void;
export function glTexImage1D(target: number,
    level: number,
    internalformat: number,
    width: number,
    border: number,
    format: number,
    type: typeof GL_UNSIGNED_SHORT
        | typeof GL_UNSIGNED_SHORT_5_6_5
        | typeof GL_UNSIGNED_SHORT_5_6_5_REV
        | typeof GL_UNSIGNED_SHORT_4_4_4_4
        | typeof GL_UNSIGNED_SHORT_4_4_4_4_REV
        | typeof GL_UNSIGNED_SHORT_5_5_5_1
        | typeof GL_UNSIGNED_SHORT_1_5_5_5_REV,
    data: Uint16Array): void;
export function glTexImage1D(target: number, level: number, internalformat: number, width: number, format: number, type: typeof GL_SHORT, data: Int16Array): void;
export function glTexImage1D(target: number,
    level: number,
    internalformat: number,
    width: number,
    height: number,
    border: number,
    format: number,
    type: typeof GL_UNSIGNED_INT
        | typeof GL_UNSIGNED_INT_8_8_8_8
        | typeof GL_UNSIGNED_INT_8_8_8_8_REV
        | typeof GL_UNSIGNED_INT_10_10_10_2
        /* | typeof GL_UNSIGNED_INT_2_10_10_10_REV */,
    data: Uint32Array): void;
export function glTexImage1D(target: number, level: number, internalformat: number, width: number, format: number, type: typeof GL_INT, data: Int32Array): void;
export function glTexImage1D(target: number, level: number, internalformat: number, width: number, format: number, type: typeof GL_FLOAT, data: Float32Array): void;
export function glTexImage2D(target: number,
    level: number,
    internalformat: number,
    width: number,
    height: number,
    border: number,
    format: number,
    type: typeof GL_UNSIGNED_BYTE
        | typeof GL_UNSIGNED_BYTE_3_3_2
        | typeof GL_UNSIGNED_BYTE_2_3_3_REV,
    data: Uint8Array): void;
export function glTexImage2D(target: number, level: number, internalformat: number, width: number, height: number, format: number, type: typeof GL_BYTE, data: Int8Array): void;
export function glTexImage2D(target: number,
    level: number,
    internalformat: number,
    width: number,
    height: number,
    border: number,
    format: number,
    type: typeof GL_UNSIGNED_SHORT
        | typeof GL_UNSIGNED_SHORT_5_6_5
        | typeof GL_UNSIGNED_SHORT_5_6_5_REV
        | typeof GL_UNSIGNED_SHORT_4_4_4_4
        | typeof GL_UNSIGNED_SHORT_4_4_4_4_REV
        | typeof GL_UNSIGNED_SHORT_5_5_5_1
        | typeof GL_UNSIGNED_SHORT_1_5_5_5_REV,
    data: Uint16Array): void;
export function glTexImage2D(target: number, level: number, internalformat: number, width: number, height: number, format: number, type: typeof GL_SHORT, data: Int16Array): void;
export function glTexImage2D(target: number,
    level: number,
    internalformat: number,
    width: number,
    height: number,
    border: number,
    format: number,
    type: typeof GL_UNSIGNED_INT
        | typeof GL_UNSIGNED_INT_8_8_8_8
        | typeof GL_UNSIGNED_INT_8_8_8_8_REV
        | typeof GL_UNSIGNED_INT_10_10_10_2
        /* | typeof GL_UNSIGNED_INT_2_10_10_10_REV */,
    data: Uint32Array): void;
export function glTexImage2D(target: number, level: number, internalformat: number, width: number, height: number, format: number, type: typeof GL_INT, data: Int32Array): void;
export function glTexImage2D(target: number, level: number, internalformat: number, width: number, height: number, format: number, type: typeof GL_FLOAT, data: Float32Array): void;
export function glTexParameterf(target: number, pname: number, param: number): void;
export function glTexParameterfv(target: number, pname: number, params: Float32Array): void;
export function glTexParameteri(target: number, pname: number, param: number): void;
export function glTexParameteriv(target: number, pname: number, params: Int32Array): void;
export function glTexSubImage1D(target: number,
    level: number,
    xoffset: number,
    width: number,
    border: number,
    format: number,
    type: typeof GL_UNSIGNED_BYTE
        | typeof GL_UNSIGNED_BYTE_3_3_2
        | typeof GL_UNSIGNED_BYTE_2_3_3_REV,
    data: Uint8Array): void;
export function glTexSubImage1D(target: number, level: number, xoffset: number, width: number, format: number, type: typeof GL_BYTE, data: Int8Array): void;
export function glTexSubImage1D(target: number,
    level: number,
    xoffset: number,
    width: number,
    border: number,
    format: number,
    type: typeof GL_UNSIGNED_SHORT
        | typeof GL_UNSIGNED_SHORT_5_6_5
        | typeof GL_UNSIGNED_SHORT_5_6_5_REV
        | typeof GL_UNSIGNED_SHORT_4_4_4_4
        | typeof GL_UNSIGNED_SHORT_4_4_4_4_REV
        | typeof GL_UNSIGNED_SHORT_5_5_5_1
        | typeof GL_UNSIGNED_SHORT_1_5_5_5_REV,
    data: Uint16Array): void;
export function glTexSubImage1D(target: number, level: number, xoffset: number, width: number, format: number, type: typeof GL_SHORT, data: Int16Array): void;
export function glTexSubImage1D(target: number,
    level: number,
    xoffset: number,
    width: number,
    height: number,
    border: number,
    format: number,
    type: typeof GL_UNSIGNED_INT
        | typeof GL_UNSIGNED_INT_8_8_8_8
        | typeof GL_UNSIGNED_INT_8_8_8_8_REV
        | typeof GL_UNSIGNED_INT_10_10_10_2
        /* | typeof GL_UNSIGNED_INT_2_10_10_10_REV */,
    data: Uint32Array): void;
export function glTexSubImage1D(target: number, level: number, xoffset: number, width: number, format: number, type: typeof GL_INT, data: Int32Array): void;
export function glTexSubImage1D(target: number, level: number, xoffset: number, width: number, format: number, type: typeof GL_FLOAT, data: Float32Array): void;
export function glTexSubImage2D(target: number,
    level: number,
    xoffset: number,
    yoffset: number,
    width: number,
    height: number,
    border: number,
    format: number,
    type: typeof GL_UNSIGNED_BYTE
        | typeof GL_UNSIGNED_BYTE_3_3_2
        | typeof GL_UNSIGNED_BYTE_2_3_3_REV,
    data: Uint8Array): void;
export function glTexSubImage2D(target: number, level: number, xoffset: number, yoffset: number, width: number, height: number, format: number, type: typeof GL_BYTE, data: Int8Array): void;
export function glTexSubImage2D(target: number,
    level: number,
    xoffset: number,
    yoffset: number,
    width: number,
    height: number,
    border: number,
    format: number,
    type: typeof GL_UNSIGNED_SHORT
        | typeof GL_UNSIGNED_SHORT_5_6_5
        | typeof GL_UNSIGNED_SHORT_5_6_5_REV
        | typeof GL_UNSIGNED_SHORT_4_4_4_4
        | typeof GL_UNSIGNED_SHORT_4_4_4_4_REV
        | typeof GL_UNSIGNED_SHORT_5_5_5_1
        | typeof GL_UNSIGNED_SHORT_1_5_5_5_REV,
    data: Uint16Array): void;
export function glTexSubImage2D(target: number, level: number, xoffset: number, yoffset: number, width: number, height: number, format: number, type: typeof GL_SHORT, data: Int16Array): void;
export function glTexSubImage2D(target: number,
    level: number,
    xoffset: number,
    yoffset: number,
    width: number,
    height: number,
    border: number,
    format: number,
    type: typeof GL_UNSIGNED_INT
        | typeof GL_UNSIGNED_INT_8_8_8_8
        | typeof GL_UNSIGNED_INT_8_8_8_8_REV
        | typeof GL_UNSIGNED_INT_10_10_10_2
        /* | typeof GL_UNSIGNED_INT_2_10_10_10_REV */,
    data: Uint32Array): void;
export function glTexSubImage2D(target: number, level: number, xoffset: number, yoffset: number, width: number, height: number, format: number, type: typeof GL_INT, data: Int32Array): void;
export function glTexSubImage2D(target: number, level: number, xoffset: number, yoffset: number, width: number, height: number, format: number, type: typeof GL_FLOAT, data: Float32Array): void;
export function glTranslated(x: number, y: number, z: number): void;
export function glTranslatef(x: number, y: number, z: number): void;
export function glVertex2d(x: number, y: number): void;
export function glVertex2dv(v: Float64Array): void;
export function glVertex2f(x: number, y: number): void;
export function glVertex2fv(v: Float32Array): void;
export function glVertex2i(x: number, y: number): void;
export function glVertex2iv(v: Int32Array): void;
export function glVertex2s(x: number, y: number): void;
export function glVertex2sv(v: Int16Array): void;
export function glVertex3d(x: number, y: number, z: number): void;
export function glVertex3dv(v: Float64Array): void;
export function glVertex3f(x: number, y: number, z: number): void;
export function glVertex3fv(v: Float32Array): void;
export function glVertex3i(x: number, y: number, z: number): void;
export function glVertex3iv(v: Int32Array): void;
export function glVertex3s(x: number, y: number, z: number): void;
export function glVertex3sv(v: Int16Array): void;
export function glVertex4d(x: number, y: number, z: number, w: number): void;
export function glVertex4dv(v: Float64Array): void;
export function glVertex4f(x: number, y: number, z: number, w: number): void;
export function glVertex4fv(v: Float32Array): void;
export function glVertex4i(x: number, y: number, z: number, w: number): void;
export function glVertex4iv(v: Int32Array): void;
export function glVertex4s(x: number, y: number, z: number, w: number): void;
export function glVertex4sv(v: Int16Array): void;
export function glVertexPointer(size: number, type: typeof GL_SHORT, stride: number, pointer: Int16Array): void;
export function glVertexPointer(size: number, type: typeof GL_INT, stride: number, pointer: Int32Array): void;
export function glVertexPointer(size: number, type: typeof GL_FLOAT, stride: number, pointer: Float32Array): void;
export function glVertexPointer(size: number, type: typeof GL_DOUBLE, stride: number, pointer: Float64Array): void;
export function glViewport(x: number, y: number, width: number, height: number): void;

// OpenGL Core 1.2 Functions

export function glCopyTexSubImage3D(
    target: number,
    level: number,
    xoffset: number,
    yoffset: number,
    zoffset: number,
    x: number,
    y: number,
    width: number,
    height: number): void;
export function glDrawRangeElements(
    mode: number,
    start: number,
    end: number,
    count: number,
    type: number): void;
export function glTexImage3D(target: number,
    level: number,
    internalformat: number,
    width: number,
    height: number,
    depth: number,
    border: number,
    format: number,
    type: typeof GL_UNSIGNED_BYTE
        | typeof GL_UNSIGNED_BYTE_3_3_2
        | typeof GL_UNSIGNED_BYTE_2_3_3_REV,
    data: Uint8Array): void;
export function glTexImage3D(target: number,
    level: number,
    internalformat: number,
    width: number,
    height: number,
    depth: number,
    format: number,
    type: typeof GL_BYTE,
    data: Int8Array): void;
export function glTexImage3D(target: number,
    level: number,
    internalformat: number,
    width: number,
    height: number,
    depth: number,
    border: number,
    format: number,
    type: typeof GL_UNSIGNED_SHORT
        | typeof GL_UNSIGNED_SHORT_5_6_5
        | typeof GL_UNSIGNED_SHORT_5_6_5_REV
        | typeof GL_UNSIGNED_SHORT_4_4_4_4
        | typeof GL_UNSIGNED_SHORT_4_4_4_4_REV
        | typeof GL_UNSIGNED_SHORT_5_5_5_1
        | typeof GL_UNSIGNED_SHORT_1_5_5_5_REV,
    data: Uint16Array): void;
export function glTexImage3D(target: number,
    level: number,
    internalformat: number,
    width: number,
    height: number,
    depth: number,
    format: number,
    type: typeof GL_SHORT,
    data: Int16Array): void;
export function glTexImage3D(target: number,
    level: number,
    internalformat: number,
    width: number,
    height: number,
    depth: number,
    border: number,
    format: number,
    type: typeof GL_UNSIGNED_INT
        | typeof GL_UNSIGNED_INT_8_8_8_8
        | typeof GL_UNSIGNED_INT_8_8_8_8_REV
        | typeof GL_UNSIGNED_INT_10_10_10_2
            /* | typeof GL_UNSIGNED_INT_2_10_10_10_REV */,
    data: Uint32Array): void;
export function glTexSubImage3D(target: number,
    level: number,
    xoffset: number,
    yoffset: number,
    width: number,
    height: number,
    depth: number,
    border: number,
    format: number,
    type: typeof GL_UNSIGNED_BYTE
        | typeof GL_UNSIGNED_BYTE_3_3_2
        | typeof GL_UNSIGNED_BYTE_2_3_3_REV,
    data: Uint8Array): void;
export function glTexSubImage3D(target: number,
    level: number, 
    xoffset: number, 
    yoffset: number, 
    width: number, 
    height: number,
    depth: number, 
    format: number, 
    type: typeof GL_BYTE,
    data: Int8Array): void;
export function glTexSubImage3D(target: number,
    level: number,
    xoffset: number,
    yoffset: number,
    width: number,
    height: number,
    depth: number,
    border: number,
    format: number,
    type: typeof GL_UNSIGNED_SHORT
        | typeof GL_UNSIGNED_SHORT_5_6_5
        | typeof GL_UNSIGNED_SHORT_5_6_5_REV
        | typeof GL_UNSIGNED_SHORT_4_4_4_4
        | typeof GL_UNSIGNED_SHORT_4_4_4_4_REV
        | typeof GL_UNSIGNED_SHORT_5_5_5_1
        | typeof GL_UNSIGNED_SHORT_1_5_5_5_REV,
    data: Uint16Array): void;
export function glTexSubImage3D(target: number, 
    level: number, 
    xoffset: number,
    yoffset: number, 
    width: number, 
    height: number,
    depth: number, 
    format: number, 
    type: typeof GL_SHORT, 
    data: Int16Array): void;
export function glTexSubImage3D(target: number,
    level: number,
    xoffset: number,
    yoffset: number,
    width: number,
    height: number,
    depth: number,
    border: number,
    format: number,
    type: typeof GL_UNSIGNED_INT
        | typeof GL_UNSIGNED_INT_8_8_8_8
        | typeof GL_UNSIGNED_INT_8_8_8_8_REV
        | typeof GL_UNSIGNED_INT_10_10_10_2
            /* | typeof GL_UNSIGNED_INT_2_10_10_10_REV */,
    data: Uint32Array): void;
export function glTexSubImage3D(target: number,
    level: number,
    xoffset: number, 
    yoffset: number, 
    width: number, 
    height: number,
    depth: number, 
    format: number, 
    type: typeof GL_INT, 
    data: Int32Array): void;
export function glTexSubImage3D(target: number, 
    level: number, 
    xoffset: number, 
    yoffset: number, 
    width: number, 
    height: number,
    depth: number, 
    format: number, 
    type: typeof GL_FLOAT, 
    data: Float32Array): void;

// OpenGL Core 1.3 functions
export function glActiveTexture(texture: number): void;
export function glClientActiveTexture(texture: number): void;
export function glCompressedTexImage1D(target: number, level: number, internalformat: number, width: number, imageSize: number, border: number, data: Uint8Array): void;
export function glCompressedTexImage2D(target: number, level: number, internalformat: number, width: number, height: number, imageSize: number, border: number, data: Uint8Array): void;
export function glCompressedTexImage3D(target: number,
    level: number,
    internalformat: number,
    width: number,
    height: number,
    depth: number,
    border: number,
    imageSize: number,
    data: Uint8Array): void;
export function glCompressedTexSubImage1D(target: number, level: number, xoffset: number, width: number, format: number, imageSize: number, data: Uint8Array): void;
export function glCompressedTexSubImage2D(target: number, level: number, xoffset: number, yoffset: number, width: number, height: number, format: number, imageSize: number, data: Uint8Array): void;
export function glCompressedTexSubImage3D(target: number,
    level: number,
    xoffset: number,
    yoffset: number,
    zoffset: number,
    width: number,
    height: number,
    depth: number,
    format: number,
    imageSize: number,
    data: Uint8Array): void;
export function glGetCompressedTexImage(target: number, level: number, data: Uint8Array): void;
export function glLoadTransposeMatrixd(m: Float64Array): void;
export function glLoadTransposeMatrixf(m: Float32Array): void;
export function glMultTransposeMatrixd(m: Float64Array): void;
export function glMultTransposeMatrixf(m: Float32Array): void;
export function glMultiTexCoord1d(target: number, s: number): void;
export function glMultiTexCoord1dv(target: number, v: Float64Array): void;
export function glMultiTexCoord1f(target: number, s: number): void;
export function glMultiTexCoord1fv(target: number, v: Float32Array): void;
export function glMultiTexCoord1i(target: number, s: number): void;
export function glMultiTexCoord1iv(target: number, v: Int32Array): void;
export function glMultiTexCoord1s(target: number, s: number): void;
export function glMultiTexCoord1sv(target: number, v: Int16Array): void;
export function glMultiTexCoord2d(target: number, s: number, t: number): void;
export function glMultiTexCoord2dv(target: number, v: Float64Array): void;
export function glMultiTexCoord2f(target: number, s: number, t: number): void;
export function glMultiTexCoord2fv(target: number, v: Float32Array): void;
export function glMultiTexCoord2i(target: number, s: number, t: number): void;
export function glMultiTexCoord2iv(target: number, v: Int32Array): void;
export function glMultiTexCoord2s(target: number, s: number, t: number): void;
export function glMultiTexCoord2sv(target: number, v: Int16Array): void;
export function glMultiTexCoord3d(target: number, s: number, t: number, r: number): void;
export function glMultiTexCoord3dv(target: number, v: Float64Array): void;
export function glMultiTexCoord3f(target: number, s: number, t: number, r: number): void;
export function glMultiTexCoord3fv(target: number, v: Float32Array): void;
export function glMultiTexCoord3i(target: number, s: number, t: number, r: number): void;
export function glMultiTexCoord3iv(target: number, v: Int32Array): void;
export function glMultiTexCoord3s(target: number, s: number, t: number, r: number): void;
export function glMultiTexCoord3sv(target: number, v: Int16Array): void;
export function glMultiTexCoord4d(target: number, s: number, t: number, r: number, q: number): void;
export function glMultiTexCoord4dv(target: number, v: Float64Array): void;
export function glMultiTexCoord4f(target: number, s: number, t: number, r: number, q: number): void;
export function glMultiTexCoord4fv(target: number, v: Float32Array): void;
export function glMultiTexCoord4i(target: number, s: number, t: number, r: number, q: number): void;
export function glMultiTexCoord4iv(target: number, v: Int32Array): void;
export function glMultiTexCoord4s(target: number, s: number, t: number, r: number, q: number): void;
export function glMultiTexCoord4sv(target: number, v: Int16Array): void;
export function glSampleCoverage(value: number, invert: boolean): void;

// OpenGL Core 1.4 functions

export function glBlendColor(red: number, green: number, blue: number, alpha: number): void;
export function glBlendEquation(mode: number): void;
export function glBlendFuncSeparate(srcRGB: number, dstRGB: number, srcAlpha: number, dstAlpha: number): void;
export function glFogCoordPointer(type: typeof GL_FLOAT, stride: number, pointer: Float32Array): void;
export function glFogCoordPointer(type: typeof GL_DOUBLE, stride: number, pointer: Float64Array): void;
export function glFogCoordd(coord: number): void;
export function glFogCoorddv(coord: Float64Array): void;
export function glFogCoordf(coord: number): void;
export function glFogCoordfv(coord: Float32Array): void;
export function glMultiDrawArrays(mode: number, first: Int32Array, count: Int32Array, drawcount: number): void;
export function glMultiDrawElements(mode: number, count: Int32Array, type: typeof GL_UNSIGNED_BYTE, indices: Uint8Array[], drawcount: number): void;
export function glMultiDrawElements(mode: number, count: Int32Array, type: typeof GL_UNSIGNED_SHORT, indices: Uint16Array, drawcount: number): void;
export function glMultiDrawElements(mode: number, count: Int32Array, type: typeof GL_UNSIGNED_INT, indices: Uint32Array, drawcount: number): void;
export function glPointParameterf(pname: number, param: number): void;
export function glPointParameterfv(pname: number, param: Float32Array): void;
export function glPointParameteri(pname: number, param: number): void;
export function glPointParameteriv(pname: number, param: Int32Array): void;
export function glSecondaryColor3b(red: number, green: number, blue: number): void;
export function glSecondaryColor3bv(v: Int8Array): void;
export function glSecondaryColor3d(red: number, green: number, blue: number): void;
export function glSecondaryColor3dv(v: Float64Array): void;
export function glSecondaryColor3f(red: number, green: number, blue: number): void;
export function glSecondaryColor3fv(v: Float32Array): void;
export function glSecondaryColor3i(red: number, green: number, blue: number): void;
export function glSecondaryColor3iv(v: Int32Array): void;
export function glSecondaryColor3s(red: number, green: number, blue: number): void;
export function glSecondaryColor3sv(v: Int16Array): void;
export function glSecondaryColor3ub(red: number, green: number, blue: number): void;
export function glSecondaryColor3ubv(v: Uint8Array): void;
export function glSecondaryColor3ui(red: number, green: number, blue: number): void;
export function glSecondaryColor3uiv(v: Uint32Array): void;
export function glSecondaryColor3us(red: number, green: number, blue: number): void;
export function glSecondaryColor3usv(v: Uint16Array): void;
export function glSecondaryColorPointer(size: number, type: typeof GL_BYTE, stride: number, pointer: Int8Array): void;
export function glSecondaryColorPointer(size: number, type: typeof GL_UNSIGNED_BYTE, stride: number, pointer: Uint8Array): void;
export function glSecondaryColorPointer(size: number, type: typeof GL_SHORT, stride: number, pointer: Int16Array): void;
export function glSecondaryColorPointer(size: number, type: typeof GL_UNSIGNED_SHORT, stride: number, pointer: Uint16Array): void;
export function glSecondaryColorPointer(size: number, type: typeof GL_INT, stride: number, pointer: Int32Array): void;
export function glSecondaryColorPointer(size: number, type: typeof GL_UNSIGNED_INT, stride: number, pointer: Uint32Array): void;
export function glSecondaryColorPointer(size: number, type: typeof GL_FLOAT, stride: number, pointer: Float32Array): void;
export function glSecondaryColorPointer(size: number, type: typeof GL_DOUBLE, stride: number, pointer: Float64Array): void;
export function glWindowPos2d(x: number, y: number): void;
export function glWindowPos2dv(v: Float64Array): void;
export function glWindowPos2f(x: number, y: number): void;
export function glWindowPos2fv(v: Float32Array): void;
export function glWindowPos2i(x: number, y: number): void;
export function glWindowPos2iv(v: Int32Array): void;
export function glWindowPos2s(x: number, y: number): void;
export function glWindowPos2sv(v: Int16Array): void;
export function glWindowPos3d(x: number, y: number, z: number): void;
export function glWindowPos3dv(v: Float64Array): void;
export function glWindowPos3f(x: number, y: number, z: number): void;
export function glWindowPos3fv(v: Float32Array): void;
export function glWindowPos3i(x: number, y: number, z: number): void;
export function glWindowPos3iv(v: Int32Array): void;
export function glWindowPos3s(x: number, y: number, z: number): void;
export function glWindowPos3sv(v: Int16Array): void;

// OpenGL 1.5 core functions

export function glBeginQuery(target: number, id: number): void;
export function glBindBuffer(target: number, buffer: number): void;
export function glBufferData(target: number, size: number, data: ArrayBuffer, usage: number): void;
export function glBufferSubData(target: number, offset: number, size: number, data: Uint8Array): void;
export function glDeleteBuffers(n: number, buffers: Uint32Array): void;
export function glDeleteQueries(n: number, ids: Uint32Array): void;
export function glEndQuery(target: number): void;
export function glGenBuffers(n: number, buffers: Uint32Array): void;
export function glGenQueries(n: number, ids: Uint32Array): void;
export function glGetBufferParameteriv(target: number, pname: number, params: Int32Array): void;
export function glGetBufferPointerv(target: number, pname: number, params: Uint8Array): void;
export function glGetBufferSubData(target: number, offset: number, size: number, data: Uint8Array): void;
export function glGetQueryObjectiv(id: number, pname: number, params: Int32Array): void;
export function glGetQueryObjectuiv(id: number, pname: number, params: Uint32Array): void;
export function glGetQueryiv(target: number, pname: number, params: Int32Array): void;
export function glIsBuffer(buffer: number): boolean;
export function glIsQuery(id: number): boolean;
export function glMapBuffer(target: number, access: number): Pointer<void>;
export function glUnmapBuffer(target: number): boolean;

// OpenGL 2.0 core functions

export function glAttachShader(program: number, shader: number): void;
export function glBindAttribLocation(program: number, index: number, name: string): void;
export function glBlendEquationSeparate(modeRGB: number, modeAlpha: number): void;
export function glCompileShader(shader: number): void;
export function glCreateProgram(): number;
export function glCreateShader(type: number): number;
export function glDeleteProgram(program: number): void;
export function glDeleteShader(shader: number): void;
export function glDetachShader(program: number, shader: number): void;
export function glDisableVertexAttribArray(index: number): void;
export function glDrawBuffers(n: number, bufs: Uint32Array): void;
export function glEnableVertexAttribArray(index: number): void;
export function glGetActiveAttrib(program: number,
    index: number,
    maxLength: number,
    length: Pointer<number>,
    size: Pointer<number>,
    type: Pointer<number>,
    name: Pointer<string>): void;
export function glGetActiveUniform(program: number,
    index: number,
    maxLength: number,
    length: Pointer<number>,
    size: Pointer<number>,
    type: Pointer<number>,
    name: Pointer<string>): void;
export function glGetAttachedShaders(program: number, maxCount: number, count: Pointer<number>, shaders: Uint32Array): void;
export function glGetAttribLocation(program: number, name: string): number;
export function glGetProgramInfoLog(program: number, maxLength: number, length: Pointer<number>, infoLog: Pointer<string>): void;
export function glGetProgramiv(program: number, pname: number, params: Int32Array): void;
export function glGetShaderInfoLog(shader: number, maxLength: number, length: Pointer<number>, infoLog: Pointer<string>): void;
export function glGetShaderSource(shader: number, maxLength: number, length: Pointer<number>, source: Pointer<string>): void;
export function glGetShaderiv(shader: number, pname: number, params: Int32Array): void;
export function glGetUniformLocation(program: number, name: string): number;
export function glGetUniformfv(program: number, location: number, params: Float32Array): void;
export function glGetUniformiv(program: number, location: number, params: Int32Array): void;
export function glGetVertexAttribPointerv(index: number, pname: number, params: Uint8Array): void;
export function glGetVertexAttribdv(index: number, pname: number, params: Float64Array): void;
export function glGetVertexAttribfv(index: number, pname: number, params: Float32Array): void;
export function glGetVertexAttribiv(index: number, pname: number, params: Int32Array): void;
export function glIsProgram(program: number): boolean;
export function glIsShader(shader: number): boolean;
export function glLinkProgram(program: number): void;
export function glShaderSource(shader: number, count: number, string: string, length: number): void;
export function glStencilFuncSeparate(face: number, func: number, ref: number, mask: number): void;
export function glStencilMaskSeparate(face: number, mask: number): void;
export function glStencilOpSeparate(face: number, fail: number, zfail: number, zpass: number): void;
export function glUniform1f(location: number, x: number): void;
export function glUniform1fv(location: number, count: number, v: Float32Array): void;
export function glUniform1i(location: number, x: number): void;
export function glUniform1iv(location: number, count: number, v: Int32Array): void;
export function glUniform2f(location: number, x: number, y: number): void;
export function glUniform2fv(location: number, count: number, v: Float32Array): void;
export function glUniform2i(location: number, x: number, y: number): void;
export function glUniform2iv(location: number, count: number, v: Int32Array): void;
export function glUniform3f(location: number, x: number, y: number, z: number): void;
export function glUniform3fv(location: number, count: number, v: Float32Array): void;
export function glUniform3i(location: number, x: number, y: number, z: number): void;
export function glUniform3iv(location: number, count: number, v: Int32Array): void;
export function glUniform4f(location: number, x: number, y: number, z: number, w: number): void;
export function glUniform4fv(location: number, count: number, v: Float32Array): void;
export function glUniform4i(location: number, x: number, y: number, z: number, w: number): void;
export function glUniform4iv(location: number, count: number, v: Int32Array): void;
export function glUniformMatrix2fv(location: number, count: number, transpose: boolean, value: Float32Array): void;
export function glUniformMatrix3fv(location: number, count: number, transpose: boolean, value: Float32Array): void;
export function glUniformMatrix4fv(location: number, count: number, transpose: boolean, value: Float32Array): void;
export function glUseProgram(program: number): void;
export function glValidateProgram(program: number): void;
export function glVertexAttrib1d(index: number, x: number): void;
export function glVertexAttrib1dv(index: number, v: Float64Array): void;
export function glVertexAttrib1f(index: number, x: number): void;
export function glVertexAttrib1fv(index: number, v: Float32Array): void;
export function glVertexAttrib1s(index: number, x: number): void;
export function glVertexAttrib1sv(index: number, v: Int16Array): void;
export function glVertexAttrib2d(index: number, x: number, y: number): void;
export function glVertexAttrib2dv(index: number, v: Float64Array): void;
export function glVertexAttrib2f(index: number, x: number, y: number): void;
export function glVertexAttrib2fv(index: number, v: Float32Array): void;
export function glVertexAttrib2s(index: number, x: number, y: number): void;
export function glVertexAttrib2sv(index: number, v: Int16Array): void;
export function glVertexAttrib3d(index: number, x: number, y: number, z: number): void;
export function glVertexAttrib3dv(index: number, v: Float64Array): void;
export function glVertexAttrib3f(index: number, x: number, y: number, z: number): void;
export function glVertexAttrib3fv(index: number, v: Float32Array): void;
export function glVertexAttrib3s(index: number, x: number, y: number, z: number): void;
export function glVertexAttrib3sv(index: number, v: Int16Array): void;
export function glVertexAttrib4bv(index: number, v: Int8Array): void;
export function glVertexAttrib4d(index: number, x: number, y: number, z: number, w: number): void;
export function glVertexAttrib4dv(index: number, v: Float64Array): void;
export function glVertexAttrib4f(index: number, x: number, y: number, z: number, w: number): void;
export function glVertexAttrib4fv(index: number, v: Float32Array): void;
export function glVertexAttrib4iv(index: number, v: Int32Array): void;
export function glVertexAttrib4Nbv(index: number, v: Uint8Array): void;
export function glVertexAttrib4Niv(index: number, v: Int32Array): void;
export function glVertexAttrib4Nsv(index: number, v: Int16Array): void;
export function glVertexAttrib4Nub(index: number, x: number, y: number, z: number, w: number): void;
export function glVertexAttrib4Nubv(index: number, v: Uint8Array): void;
export function glVertexAttrib4Nuiv(index: number, v: Int32Array): void;
export function glVertexAttrib4Nusv(index: number, v: Uint16Array): void;
export function glVertexAttrib4bv(index: number, v: Int8Array): void;
export function glVertexAttrib4dv(index: number, v: Float64Array): void;
export function glVertexAttrib4fv(index: number, v: Float32Array): void;
export function glVertexAttrib4iv(index: number, v: Int32Array): void;
export function glVertexAttrib4s(index: number, x: number, y: number, z: number, w: number): void;
export function glVertexAttrib4sv(index: number, v: Int16Array): void;
export function glVertexAttrib4ubv(index: number, v: Uint8Array): void;
export function glVertexAttrib4uiv(index: number, v: Int32Array): void;
export function glVertexAttrib4usv(index: number, v: Uint16Array): void;
export function glVertexAttribPointer(index: number, size: number, type: number, normalized: boolean, stride: number, offset: number): void;

// OpenGL core 2.1 functions

export function glUniformMatrix2x3fv(location: number, count: number, transpose: boolean, value: Float32Array): void;
export function glUniformMatrix2x4fv(location: number, count: number, transpose: boolean, value: Float32Array): void;
export function glUniformMatrix3x2fv(location: number, count: number, transpose: boolean, value: Float32Array): void;
export function glUniformMatrix3x4fv(location: number, count: number, transpose: boolean, value: Float32Array): void;
export function glUniformMatrix4x2fv(location: number, count: number, transpose: boolean, value: Float32Array): void;
export function glUniformMatrix4x3fv(location: number, count: number, transpose: boolean, value: Float32Array): void;

// OpenGL core 3.0 functions

export function glBeginConditionalRender(id: number, mode: number): void;
export function glBeginTransformFeedback(primitiveMode: number): void;
export function glBindFragDataLocation(program: number, colorNumber: number, name: string): void;
export function glClampColor(target: number, clamp: number): void;
export function glClearBufferfi(buffer: number, drawbuffer: number, depth: number, stencil: number): void;
export function glClearBufferfv(buffer: number, drawbuffer: number, value: Float32Array): void;
export function glClearBufferiv(buffer: number, drawbuffer: number, value: Int32Array): void;
export function glClearBufferuiv(buffer: number, drawbuffer: number, value: Uint32Array): void;
export function glColorMaski(index: number, r: boolean, g: boolean, b: boolean, a: boolean): void;
export function glDisablei(target: number, index: number): void;
export function glEnablei(target: number, index: number): void;
export function glEndConditionalRender(): void;
export function glEndTransformFeedback(): void;
export function glGetBooleani_v(target: number, index: number, data: boolean[]): void;
export function glGetFragDataLocation(program: number, name: string): number;
export function glGetStringi(name: number, index: number): string;
export function glGetTexParameterIiv(target: number, pname: number, params: Int32Array): void;
export function glGetTexParameterIuiv(target: number, pname: number, params: Uint32Array): void;
export function glGetTransformFeedbackVarying(program: number,
    index: number,
    bufSize: number,
    length: Int32Array,
    size: Int32Array,
    type: Int32Array,
    name: string): void;
export function glGetUniformuiv(program: number, location: number, params: Uint32Array): void;
export function glGetVertexAttribIiv(index: number, pname: number, params: Int32Array): void;
export function glGetVertexAttribIuiv(index: number, pname: number, params: Uint32Array): void;
export function glIsEnabledi(target: number, index: number): boolean;
export function glTexParameterIiv(target: number, pname: number, params: Int32Array): void;
export function glTexParameterIuiv(target: number, pname: number, params: Uint32Array): void;
export function glTransformFeedbackVaryings(program: number, count: number, names: string[], bufferMode: number): void;
export function glUniform1ui(location: number, v0: number): void;
export function glUniform1uiv(location: number, count: number, value: Uint32Array): void;
export function glUniform2ui(location: number, v0: number, v1: number): void;
export function glUniform2uiv(location: number, count: number, value: Uint32Array): void;
export function glUniform3ui(location: number, v0: number, v1: number, v2: number): void;
export function glUniform3uiv(location: number, count: number, value: Uint32Array): void;
export function glUniform4ui(location: number, v0: number, v1: number, v2: number, v3: number): void;
export function glUniform4uiv(location: number, count: number, value: Uint32Array): void;
export function glVertexAttribI1i(index: number, x: number): void;
export function glVertexAttribI1iv(index: number, v: Int32Array): void;
export function glVertexAttribI1ui(index: number, x: number): void;
export function glVertexAttribI1uiv(index: number, v: Uint32Array): void;
export function glVertexAttribI2i(index: number, x: number, y: number): void;
export function glVertexAttribI2iv(index: number, v: Int32Array): void;
export function glVertexAttribI2ui(index: number, x: number, y: number): void;
export function glVertexAttribI2uiv(index: number, v: Uint32Array): void;
export function glVertexAttribI3i(index: number, x: number, y: number, z: number): void;
export function glVertexAttribI3iv(index: number, v: Int32Array): void;
export function glVertexAttribI3ui(index: number, x: number, y: number, z: number): void;
export function glVertexAttribI3uiv(index: number, v: Uint32Array): void;
export function glVertexAttribI4bv(index: number, v: Int8Array): void;
export function glVertexAttribI4i(index: number, x: number, y: number, z: number, w: number): void;
export function glVertexAttribI4iv(index: number, v: Int32Array): void;
export function glVertexAttribI4sv(index: number, v: Int16Array): void;
export function glVertexAttribI4ubv(index: number, v: Uint8Array): void;
export function glVertexAttribI4ui(index: number, x: number, y: number, z: number, w: number): void;
export function glVertexAttribI4uiv(index: number, v: Uint32Array): void;
export function glVertexAttribI4usv(index: number, v: Uint16Array): void;
export function glVertexAttribIPointer(index: number, size: number, type: typeof GL_BYTE, stride: number, pointer: Int8Array): void;
export function glVertexAttribIPointer(index: number, size: number, type: typeof GL_UNSIGNED_BYTE, stride: number, pointer: Uint8Array): void;
export function glVertexAttribIPointer(index: number, size: number, type: typeof GL_SHORT, stride: number, pointer: Int16Array): void;
export function glVertexAttribIPointer(index: number, size: number, type: typeof GL_UNSIGNED_SHORT, stride: number, pointer: Uint16Array): void;
export function glVertexAttribIPointer(index: number, size: number, type: typeof GL_INT, stride: number, pointer: Int32Array): void;
export function glVertexAttribIPointer(index: number, size: number, type: typeof GL_UNSIGNED_INT, stride: number, pointer: Uint32Array): void;

// OpenGL 3.1 core functions

export function glDrawArraysInstanced(mode: number, first: number, count: number, instanceCount: number): void;
export function glDrawElementsInstanced(mode: number, count: number, type: typeof GL_UNSIGNED_BYTE, data: Uint8Array, instanceCount: number): void;
export function glDrawElementsInstanced(mode: number, count: number, type: typeof GL_UNSIGNED_SHORT, data: Uint16Array, instanceCount: number): void;
export function glDrawElementsInstanced(mode: number, count: number, type: typeof GL_UNSIGNED_INT, data: Uint32Array, instanceCount: number): void;
export function glPrimitiveRestartIndex(index: number): void;
export function glTexBuffer(target: number, internalformat: number, buffer: number): void;

// OpenGL 3.2 core functions

export function glFramebufferTexture(target: number, attachment: number, texture: number, level: number): void;
export function glGetBufferParameteri64v(target: number, pname: number, params: BigInt64Array): void;
export function glGetInteger64i_v(target: number, index: number, data: BigInt64Array): void;

// OpenGL 3.3 core functions

export function glVertexAttribDivisor(index: number, divisor: number): void;

// OpenGL 4.0 core functions

export function glBlendEquationSeparatei(buf: number, modeRGB: number, modeAlpha: number): void;
export function glBlendEquationi(buf: number, mode: number): void;
export function glBlendFuncSeparatei(buf: number, srcRGB: number, dstRGB: number, srcAlpha: number, dstAlpha: number): void;
export function glBlendFunci(buf: number, src: number, dst: number): void;
export function glMinSampleShading(value: number): void;

// OpenGL 4.5 core functions

export function glGetGraphicsResetStatus(): number;
export function glGetnCompressedTexImage(target: number, level: number, bufSize: number, pixels: Uint8Array): void;
export function glGetnTexImage(
    target: number,
    level: number,
    format: number,
    type: typeof GL_UNSIGNED_BYTE
        | typeof GL_UNSIGNED_BYTE_3_3_2
        | typeof GL_UNSIGNED_BYTE_2_3_3_REV,
    bufSize: number,
    data: Uint8Array): void;
export function glGetnTexImage(target: number, level: number, format: number, type: typeof GL_BYTE, bufSize: number, data: Int8Array): void;
export function glGetnTexImage(
    target: number,
    level: number,
    format: number,
    type: typeof GL_UNSIGNED_SHORT
        | typeof GL_UNSIGNED_SHORT_5_6_5
        | typeof GL_UNSIGNED_SHORT_5_6_5_REV
        | typeof GL_UNSIGNED_SHORT_4_4_4_4
        | typeof GL_UNSIGNED_SHORT_4_4_4_4_REV
        | typeof GL_UNSIGNED_SHORT_5_5_5_1
        | typeof GL_UNSIGNED_SHORT_1_5_5_5_REV,
    bufSize: number,
    data: Uint16Array): void;
export function glGetnTexImage(target: number, level: number, format: number, type: typeof GL_SHORT, bufSize: number, data: Int16Array): void;
export function glGetnTexImage(
    target: number,
    level: number,
    format: number,
    type: typeof GL_UNSIGNED_INT
        | typeof GL_UNSIGNED_INT_8_8_8_8
        | typeof GL_UNSIGNED_INT_8_8_8_8_REV
        | typeof GL_UNSIGNED_INT_10_10_10_2
        /* | typeof GL_UNSIGNED_INT_2_10_10_10_REV */,
    bufSize: number,
    data: Uint32Array): void;
export function glGetnTexImage(target: number, level: number, format: number, type: typeof GL_INT, bufSize: number, data: Int32Array): void;
export function glGetnTexImage(target: number, level: number, format: number, type: typeof GL_FLOAT, bufSize: number, data: Float32Array): void;
export function glGetnUniformdv(program: number, location: number, bufSize: number, params: Float64Array): void;

// OpenGL 4.6

export function glMultiDrawArraysIndirectCount(mode: number, indirect: Int32Array, drawcount: number, maxdrawcount: number, stride: number): void;
export function glMultiDrawElementsIndirectCount(mode: number, type: number, indirect: Int32Array, drawcount: number, maxdrawcount: number, stride: number): void;
export function glSpecializeShader(shader: number,
    pEntryPoint: string,
    numSpecializationConstants: number,
    pConstantIndex: Uint32Array,
    pConstantValue: Uint32Array): void;

// Extensions

// GL_ARB_vertex_array_object

export function glBindVertexArray(array: number): void;
export function glDeleteVertexArrays(n: number, arrays: Uint32Array): void;
export function glGenVertexArrays(n: number, arrays: Uint32Array): void;
export function glIsVertexArray(array: number): boolean;