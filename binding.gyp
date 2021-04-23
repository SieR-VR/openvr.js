{
    'variables': {
        'platform': '<(OS)',
    },
    'conditions': [
        ['platform == "mac"', {'variables': {'platform': 'darwin'}}],
        ['platform == "win"', {'variables': {'platform': 'win32'}}],
    ],
    'targets': [
        {
            'target_name': 'openvr',
            'defines': [
                'VERSION=0.4.6',
            ],
            'sources': [
                'src/bindings.cpp',
                'src/ivrsystem.cpp',
                'src/openvr.cpp',
            ],
            'include_dirs': [
                "<!(node -e \"require('nan')\")",
                '<(module_root_dir)/openvr/headers',
            ],
            'conditions': [
                ['OS=="win"', {
                    'library_dirs': ['<(module_root_dir)/openvr/lib/win64'],
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
                            'destination': '<(module_root_dir)/build/Release',
                            'files': ['<(module_root_dir)/openvr/bin/win64/openvr_api.dll']
                        }
                    ]
                }]
            ]
        }
    ]
}