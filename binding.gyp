{
    "targets": [
        {
            "target_name": "opengl",
            "sources": [
                "src/bindings.cc"
            ],
            "include_dirs": [
                "<!(node -p \"require('node-addon-api').include_dir\")",
                "<(module_root_dir)/include"
            ],
            "defines": [
                "_HAS_EXCEPTIONS=1"
            ],
            "cflags!": [
                "-fno-exceptions"
            ],
            "cflags_cc!": [
                "-fno-exceptions"
            ],
            "conditions": [
                ["OS=='win'",
                {
                    "defines": [
                        "_WIN32",
                    ],
                    "libraries": [
                        "<(module_root_dir)/lib/win32/x86_64/glew32.lib",
                        "opengl32.lib"
                    ],
                    "copies": [{
                        "destination": "<(PRODUCT_DIR)",
                        "files": [
                            "<(module_root_dir)/lib/win32/x86_64/glew32.dll"
                        ]
                    }],
                    "msvs_settings": {
                        "VCCLCompilerTool": {
                            "ExceptionHandling": 1,
                            "AdditionalOptions": [
                                "/O2",
                                "/Oy",
                                "/GL",
                                "/GF",
                                "/Gm-",
                                "/EHsc",
                                "/MT",
                                "/GS",
                                "/Gy",
                                "/GR-",
                                "/Gd"
                            ]
                        },
                        "VCLinkerTool": {
                            "AdditionalOptions": [
                                "/OPT:REF",
                                "/OPT:ICF",
                                "/LTCG"
                            ]
                        }
                    }
                }]
            ]
        }
    ]
}