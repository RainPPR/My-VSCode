@echo off
echo ��ȷ�������ļ��Ѿ��ύ��
pause
git reflog expire --expire=now --all
git gc --prune=now
git push --force --verbose --dry-run
git push --force