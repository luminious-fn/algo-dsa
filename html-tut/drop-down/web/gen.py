from mako.template import Template
from mako.lookup import TemplateLookup

'''
To start a webserve to test html pages locally,
python -m http.server 5000
and use http://localhost:5000
'''
mylookup = TemplateLookup(directories=[ '.', 'articles', 'projects', 'resume' ])

files_list = [
    {   'input'  : 'index-template.html', },

    {   'input'  : 'articles/articles-template.html', },
    {   'input'  : 'articles/programming-lang/python/why-scripting-template.html', },
    {   'input'  : 'articles/git/git-local-mirror-worktree-mono-repo-template.html', },
    {   'input'  : 'articles/git/git-rebase-template.html', },
    {   'input'  : 'articles/tips/windows-shortcuts-template.html', },

    {   'input'  : 'projects/projects-template.html', },
    {   'input'  : 'resume/resume-template.html', },
]

for item in files_list:
    mytemplate = Template(
        filename = item['input'],
        module_directory = 'mako-modules',
        lookup = mylookup)
    s = mytemplate.render()
    s = s.replace('\r', '')

    output_filename = item['input'].replace('-template', '')
    with open(output_filename, 'w', encoding="utf-8") as f:
        f.write(s)
