{
  "variables": {
    "platform": "<(OS)"
  },
  "conditions": [
    [
      "platform == 'win'",
      {
        "variables": {
          "platform": "win32"
        }
      }
    ],
    [
      "platform == 'linux'",
      {
        "variables": {
          "platform": "linux"
        }
      }
    ]
  ],
  "targets": [
    {
      "target_name": "openvr",
      "sources": [
        "src/ivrsystem.cpp",
        "src/ivroverlay.cpp",
        "src/ivrdebug.cpp",
        "src/bindings.cpp",
        "src/util.cpp",
        "src/openvr.cpp"
      ],
      "include_dirs": [
        "<!(node -e \"require('nan')\")",
        "<(module_root_dir)/openvr/"
      ],
      "conditions": [
        [
          "OS=='win'",
          {
            "library_dirs": [
              "<(module_root_dir)/openvr/lib/"
            ],
            "libraries": [
              "openvr_api.lib"
            ],
            "defines": [
              "WIN32_LEAN_AND_MEAN",
              "VC_EXTRALEAN",
              "NOMINMAX"
            ],
            "msvs_settings": {
              "VCCLCompilerTool": {
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
            },
            "actions": [
              {
                "action_name": "copy_openvr_libs",
                "inputs": [
                  "<(module_root_dir)/openvr/bin/openvr_api.dll"
                ],
                "outputs": [
                  "<(module_root_dir)/build/Release/openvr_api.dll"
                ],
                "action": [
                  "cp",
                  "<@(_inputs)",
                  "<@(_outputs)"
                ]
              }
            ]
          }
        ],
        [
          "OS=='linux'",
          {
            "libraries": [
              "-lopenvr_api",
              "-L<(module_root_dir)/openvr/lib/"
            ],
            "defines": [
              "LINUX"
            ],
            "actions": [
              {
                "action_name": "copy_openvr_libs",
                "inputs": [
                  "<(module_root_dir)/openvr/bin/libopenvr_api.so"
                ],
                "outputs": [
                  "<(module_root_dir)/build/Release/libopenvr_api.so"
                ],
                "action": [
                  "cp",
                  "<@(_inputs)",
                  "<@(_outputs)"
                ]
              }
            ]
          }
        ]
      ]
    }
  ]
}