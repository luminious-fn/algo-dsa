
#=================================
# This for software branch creation
git checkout master
git checkout -b software/master
git checkout -b software/develop

git branch software/feature/my_gsm_feature
git branch software/feature/util-script
git branch software/bugfix/my_gsm_bug
git branch software/release/1.0
git branch software/release/2.0

#=================================
# This for doc branch creation
git checkout master
git checkout -b doc/master
git checkout -b doc/develop

git branch doc/feature/my-doc-files
git branch doc/release/1.0
git branch doc/release/2.0

git push origin -u doc/master 
git push origin -u doc/develop 
git push origin -u doc/feature/my-doc-files 
git push origin -u doc/release/1.0
git push origin -u doc/release/2.0



