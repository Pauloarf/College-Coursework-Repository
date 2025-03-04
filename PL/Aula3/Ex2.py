import re

file_names = [
  "document.txt", # válido
  "file name.docx", # inválido
  "image_001.jpg", # válido
  "script.sh.txt", # válido
  "test_file.txt", # válido
  "file_name.", # inválido
  "my_resume.docx", # válido
  ".hidden-file.txt", # válido
  "important-file.text file", # inválido
  "file%name.jpg" # inválido
]

print("Ex2:")
for file_name in file_names:
    print(file_name, end=': ')
    print("Válido" if re.match(r"[\w\-\.]+.\w+$", file_name) != None else "Inválido")


print("Ex2.1:")
ficheiros_agrupados = dict()

for file_name in file_names:
    match = re.match(r"[\w\-\.]+(\.\w+)$", file_name)
    if(match != None):
        ext = match.group(1)
        if ext not in ficheiros_agrupados:
            ficheiros_agrupados[ext] = []    
        ficheiros_agrupados[ext].append(file_name)
print(ficheiros_agrupados)