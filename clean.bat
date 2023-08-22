@echo off
echo 请确保所有文件已经提交，
pause
git reflog expire --expire=now --all
git gc --prune=now
git push --force --verbose --dry-run
git push --force