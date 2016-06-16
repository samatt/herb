{
  "targets": [
   {
    "target_name": "Herbivore",
    "conditions": [
        ['OS=="mac"', {
            "xcode_settings": {
                "OTHER_CPLUSPLUSFLAGS": ["-std=c++11", "-stdlib=libc++"],
                "OTHER_LDFLAGS": ["-stdlib=libc++"],
                "MACOSX_DEPLOYMENT_TARGET": "10.11",
                'GCC_ENABLE_CPP_EXCEPTIONS': 'YES'
            }
            }]],
    "sources": [
        "c++/src/Interface.cxx",
        "c++/src/HerbivoreUtils.cxx",
        "c++/src/Herbivore_wrap.cxx"
    ],
    "include_dirs": [
        "/Users/surya/Documents/Projects/Herbivore/c++/include"
    ],
    "libraries": [
        '/Users/surya/Documents/Projects/Herbivore/c++/lib/osx/libtins.a', '-ltins', '-lpthread'
    ]
   }]
 }
