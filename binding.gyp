{
  "targets": [
    {
      "target_name": "DCRead",
      "sources": [ "src/DCRead.cc", "src/Thread.cc" ],
      "include_dirs": [
      'tmp/include',
	  'src'
      ],
      'link_settings': {
        'libraries': [
          '-ldcrf32'
        ],
        'library_dirs': [
          'tmp/lib'
        ]
      },
	  "msbuild_settings": {
			"Link": {
				"ImageHasSafeExceptionHandlers": "false"
			}
		}
    }
  ]
}
