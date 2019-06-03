@echo on
del "A:\Projects\Personal\C++\AriEngine\AriEngine.sln"
del "A:\Projects\Personal\C++\AriEngine\AriEngine\AriEngine.vcxproj"
del "A:\Projects\Personal\C++\AriEngine\AriEngine\AriEngine.vcxproj.filters"
del "A:\Projects\Personal\C++\AriEngine\AriEngine\AriEngine.vcxproj.user"
del "A:\Projects\Personal\C++\AriEngine\SandBox\Sandbox.vcxproj"
del "A:\Projects\Personal\C++\AriEngine\SandBox\Sandbox.vcxproj.filters"
del "A:\Projects\Personal\C++\AriEngine\SandBox\Sandbox.vcxproj.user"

rmdir /Q /S bin
rmdir /Q /S bin-int

call vendor\bin\premake\premake5.exe vs2017
pause