echo "Pushing to Github---------------------------"
rm .DS_Store
echo "--------------------------------------------"
echo "\nAdding--------------------------------------\n"
git add -A
echo "\nShowing status------------------------------\n"
git status
echo "\nCommitting----------------------------------\n"
git commit -m "auto"
echo "\nShowing status------------------------------\n"
git status
echo "\nPushing-------------------------------------\n"
git push
echo "\nDouble push to check if push ok-------------\n"
git push
