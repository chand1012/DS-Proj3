@echo off
msbuild .\hashtabletest.vcxproj
echo Running tests.
.\Debug\hashtabletest.exe
echo Done.