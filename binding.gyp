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
                '<(module_root_dir)/include',
            ],
            'conditions': [
                ['OS=="win"', {
                    'library_dirs': ['<(module_root_dir)/lib/'],
                    'libraries': ['openvr_api.lib'],
                    'defines': ['WIN32_LEAN_AND_MEAN', 'VC_EXTRALEAN', 'NOMINMAX'],
                    'msvs_settings': {
                        'VCCLCompilerTool': {
                            'AdditionalOptions': ['/O2','/Oy','/GL','/GF','/Gm-','/EHsc','/MT','/GS','/Gy','/GR-','/Gd'],
                        },
                        'VCLinkerTool': {
                            'AdditionalOptions': ['/OPT:REF','/OPT:ICF','/LTCG'],
                        },
                    },
                    'copies': [
                        {
                            'destination': '<(module_root_dir)/build/Release/',
                            'files': ['<(module_root_dir)/bin/openvr_api.dll']
                        }
                    ]
                }]
            ]
        }
    ]
}