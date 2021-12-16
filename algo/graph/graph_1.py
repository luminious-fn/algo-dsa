#!/usr/bin/env python
""" 
A basic graph `adjecency list` example.

Add nodes and edges to graph.
Dictionary is used to stor graph info.
dict[key] contains the all neighbours of the node = key
"""
class Graph():
    """ Grpah class """
    def __init__(self):        
        self.graph = dict()       

    def add_edge(self, node, neighbour):
        if node not in self.graph:
            self.graph[node] = list()

        self.graph[node].append(neighbour)

    def show_edges(self):
        for node in self.graph.keys():
            for neighbour in self.graph[node]:
                print(f'{node}--{neighbour}, ', end = '')
            print("")
        pass

    def find_path(self, start, end, path):        
        path = path.copy() + [start] # a new list gets created here, even without copy()
        # print(f'find_path2 :{path=}')
        if start == end:
            #print('return path')
            return path

        # following can not be put above. Reason is, end may not listend into
        # vertice list since, it may only have one way edges.
        # like (a,b) (a,c) here, b and c are vertices yet not listed in adjeancy 
        # list as vertices. (but only edges...)        
        if start not in self.graph.keys():
            #print('return None')            
            return None

        for node in self.graph[start]:
            if node in path:
                # this node is already searched, so dont do it again.
                # earlier, this node had reached by some other nodes.
                continue
            # Now this node is not yet made into path.
            # print(f'recursive: {node=} {path=}')
            newpath = self.find_path(node, end, path)
            if newpath:                    
                print(f'newpath ===> {newpath}')
                # return newpath
            else:
                print(f' will got next key')
        # if there is no path at all, return
        # print("return 2: None")
        return None    

g= Graph()
g.add_edge('a', 'b')
g.add_edge('a', 'c')
g.add_edge('a', 'd')
g.add_edge('b', 'c')
g.add_edge('b', 'd')
g.show_edges()
path = g.find_path('a', 'd', path = list())
print(path)
