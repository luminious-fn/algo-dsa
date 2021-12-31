#!/usr/bin/env python
import json
x = ['a', 'b'] 
print(json.dumps(x))
f_obj = open('serialized.json', 'w')
json.dump(x, f_obj)
f_obj.close()

f_obj = open('serialized.json', 'r')
f_obj.seek(0,0)
s = json.load(f_obj)
f_obj.close()
print(s)
