@echo off
echo ��ȷ�������ļ��Ѿ��ύ��
pause
git push --force --verbose --dry-run
git push --force
git reflog expire --expire=now --all
git gc --prune=now