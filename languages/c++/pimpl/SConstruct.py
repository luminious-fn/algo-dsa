print("Building world")
env = Environment()
env.Append(CPPFLAGS='-O3')
env.Program(target='pimple', source = ['pimpl.cpp'])