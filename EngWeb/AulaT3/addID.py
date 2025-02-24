import json

f = open("DB/treinos_dataset.json", encoding='utf-8')
bd = json.load(f)
f.close()

for i,reg in enumerate(bd['treinos']):
    reg['id'] = 't' + str(i)

f = open("DB/treinos_dataset.json", "w", encoding='utf-8')
json.dump(bd,f, ensure_ascii=False)
f.close()
