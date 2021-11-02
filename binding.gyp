{
    'variables': {
        'platform': '<(OS)',
    },
    'conditions': [
        ['platform == "win"', {'variables': {'platform': 'win32'}}]
    ],
    'targets': [
        {
            'target_name': 'openvr',
            'sources': [
                'src/bindings.cpp',
                'src/util.cpp',
                'src/ivrsystem.cpp',
                'src/openvr.cpp',
                'src/ivroverlay.cpp',
            ],
            'include_dirs': [
                "<!(node -e \"require('nan')\")",
                '<(module_root_dir)/openvr/',
            ],
            'conditions': [
                ['OS=="win"', {
                    'library_dirs': ['<(module_root_dir)/openvr/'],
                    'libraries': ['openvr_api.lib'],
                    'defines': ['WIN32_LEAN_AND_MEAN', 'VC_EXTRALEAN', 'NOMINMAX'],
                    'msvs_settings': {
                        'VCCLCompilerTool': {
                            'AdditionalOptions': ['/O2','/Oy','/GL','/GF','/Gm-','/EHsc','/MT','/GS','/Gy','/GR-','/Gd'],
                        },
                        'VCLinkerTool': {
                            'AdditionalOptions': ['/OPT:REF','/OPT:ICF','/LTCG'],
                        },
                    }
                }]
            ]
        }
    ]
}