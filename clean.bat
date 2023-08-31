@echo off
setlocal

for /f "usebackq" %%a in (`dir /s /a /w /b ^| find /v /c ""`) do set "size_before=%%a"

git push --force --verbose --dry-run
git push --force
git reflog expire --expire=now --all
git gc --prune=now

for /f "usebackq" %%a in (`dir /s /a /w /b ^| find /v /c ""`) do set "size_after=%%a"

set /a size_difference=size_after-size_before

echo.
echo The folder size has changed by %size_difference% bytes.

endlocal
pause